//
// Created by zagorodnikov on 02.04.2025.
//

#include <iostream>
#include <fstream>
#include "comtrade_parser.h"

namespace comtrade {

  void TranformParam(int8_t& param, std::ifstream& ifs, std::string& buff, char sep=',') {
    std::getline(ifs, buff, sep);
    param = static_cast<int8_t>(stoi(buff));
  }

  void TranformParam(int32_t& param, std::ifstream& ifs, std::string& buff, char sep=',', bool extra_sym=false) {
  std::getline(ifs, buff, sep);
  if(!extra_sym) {
    param = static_cast<int32_t>(stoi(buff));
  } else {
    param = static_cast<int32_t>(stoi(buff.substr(0, buff.size() - 1)));
  }
}

void TranformParam(int64_t& param, std::ifstream& ifs, std::string& buff, char sep=',') {
  std::getline(ifs, buff, sep);
  param = static_cast<int64_t>(stol(buff));
}

void TranformParam(float& param, std::ifstream& ifs, std::string& buff, char sep=',') {
  std::getline(ifs, buff, sep);
  param = stof(buff);
}

void TranformParam(char& param, std::ifstream& ifs, std::string& buff, char sep=',') {
  std::getline(ifs, buff, sep);
  param = buff[0];
}

void TranformParam(bool& param, std::ifstream& ifs, std::string& buff, char sep=',') {
  std::getline(ifs, buff, sep);
  param = static_cast<bool>(stoi(buff));
}

AnalogSignal * AnSigParser(std::ifstream& ifs, std::string& buff) {
  int32_t An;
  std::string ch_id;
  std::string ph;
  std::string ccbm;
  std::string uu;
  float a;
  float b;
  float skew;
  float min;
  float max;
  float primary;
  float secondary;
  char PS;
  TranformParam(An, ifs, buff);
  std::getline(ifs, ch_id, ',');
  std::getline(ifs, ph, ',');
  std::getline(ifs, ccbm, ',');
  std::getline(ifs, uu, ',');
  TranformParam(a, ifs, buff);
  TranformParam(b, ifs, buff);
  TranformParam(skew, ifs, buff);
  TranformParam(min, ifs, buff);
  TranformParam(max, ifs, buff);
  TranformParam(primary, ifs, buff);
  TranformParam(secondary, ifs, buff);
  TranformParam(PS, ifs, buff, '\n');
  static AnalogSignal temp_sig = AnalogSignal(An, ch_id, ph, ccbm, uu, a, b, skew, 
                                              min, max, primary, secondary, PS);
  return &temp_sig;
}

DigitalSignal * DigSigParser(std::ifstream& ifs, std::string& buff) {
  int32_t Dn;
  std::string ch_id;
  std::string ph;
  std::string ccbm;
  bool y;
  TranformParam(Dn, ifs, buff);
  std::getline(ifs, ch_id, ',');
  std::getline(ifs, ph, ',');
  std::getline(ifs, ccbm, ',');
  TranformParam(y, ifs, buff, '\n');
  static DigitalSignal temp_sig = DigitalSignal(Dn, ch_id, ph, ccbm, y);
  return &temp_sig;
}

TimeMark TimeParser(std::ifstream& ifs, std::string& buff) {
  int8_t day;
  int8_t month;
  int32_t year;
  int8_t hours;
  int8_t minutes;
  int8_t seconds;
  int64_t mcseconds;
  TranformParam(day, ifs, buff, '/');
  TranformParam(month, ifs, buff, '/');
  TranformParam(year, ifs, buff);
  TranformParam(hours, ifs, buff, ':');
  TranformParam(minutes, ifs, buff, ':');
  TranformParam(seconds, ifs, buff, '.');
  TranformParam(mcseconds, ifs, buff, '\n');
  return TimeMark(day, month, year, hours, minutes, seconds, mcseconds);
}

ComtradeFile const* ComtradeParser(const std::string& file_name){
  std::ifstream ifs(file_name, std::ios::in | std::ios::binary);
  std::string buffer;

  std::string station_name;
  std::string rec_dev_id;
  std::string rev_year;
  int32_t TT;
  int32_t analog_count;
  int32_t digital_count;
  float lf;
  int32_t nrates;
  float samp;
  int64_t endsamp;
  TimeMark time_start;
  TimeMark trigger_point;
  std::string ft;
  float timemult;
  std::string time_code;
  std::string local_code;
  int8_t tmq_code;
  int8_t leapsec;
  std::vector<AnalogSignal *> analog_vector;
  std::vector<DigitalSignal *> digital_vector;

  if(!ifs.is_open()) {
    std::cerr << "File could not be opened" << std::endl;
    //return;
  }

  std::getline(ifs, buffer);
  std::getline(ifs, station_name, ',');
  std::getline(ifs, rec_dev_id, ',');
  std::getline(ifs, rev_year);
  TranformParam(TT, ifs, buffer);
  TranformParam(analog_count, ifs, buffer, ',', true);
  TranformParam(digital_count, ifs, buffer, '\n', true);
  analog_vector.reserve(analog_count);
  digital_vector.reserve(digital_count);

  for(size_t i=0; i < analog_count; i++) {
    AnalogSignal * signal = AnSigParser(ifs, buffer);
    analog_vector.at(i) = signal;
  }
  for(size_t i=0; i < digital_count; i++) {
    DigitalSignal * signal = DigSigParser(ifs, buffer);
    digital_vector.at(i) = signal;
  }

  TranformParam(lf, ifs, buffer, '\n');
  TranformParam(nrates, ifs, buffer, '\n');  
  TranformParam(samp, ifs, buffer);
  TranformParam(endsamp, ifs, buffer, '\n');
  time_start = TimeParser(ifs, buffer);
  trigger_point = TimeParser(ifs, buffer);
  std::getline(ifs, ft);
  TranformParam(timemult, ifs, buffer, '\n');
  std::getline(ifs, time_code, ',');
  std::getline(ifs, local_code);
  TranformParam(tmq_code, ifs, buffer);
  TranformParam(leapsec, ifs, buffer, '\n');

  ifs.close();

  static ComtradeFile temp_comp_file = ComtradeFile(station_name, rec_dev_id, rev_year, TT,
                                                    analog_count, digital_count, lf, nrates,
                                                    samp, endsamp, time_start, trigger_point,
                                                    ft, timemult, time_code, local_code,
                                                    tmq_code, leapsec);

  for (AnalogSignal* ptr_sig : analog_vector) {
    temp_comp_file.PushAnalog(*ptr_sig);
    free(ptr_sig);
  }
  for (DigitalSignal* ptr_sig : digital_vector) {
    temp_comp_file.PushDigital(*ptr_sig);
    free(ptr_sig);
  }

  return &temp_comp_file;
}

} // comtrade