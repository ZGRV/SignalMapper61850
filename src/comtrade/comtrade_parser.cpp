//
// Created by zagorodnikov on 02.04.2025.
//

#include <iostream>
#include <fstream>
#include "comtrade.h"
#include "comtrade_parser.h"

namespace comtrade {

void TranformParam(int8_t& param, std::ifstream& ifs, char sep=',') {
  std::string buff;
  std::getline(ifs, buff, sep);
  try {
    if(buff.empty()) {
      throw std::invalid_argument("Lack of value!");
    }
    param = static_cast<int8_t>(stoi(buff));
  } catch (const std::out_of_range& e) {
    std::cerr << "Exception out_of_range: " << e.what() << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cerr << "Exception invalid_argument: " << e.what() << std::endl;
  }
}

void TranformParam(int32_t& param, std::ifstream& ifs, char sep=',', bool extra_sym=false) {
  std::string buff;
  std::getline(ifs, buff, sep);
  try {
    if(buff.empty()) {
      throw std::invalid_argument("Lack of value!");
    }
    if(!extra_sym) {
      param = static_cast<int32_t>(stoi(buff));
    } else {
      param = static_cast<int32_t>(stoi(buff.substr(0, buff.size() - 1)));
    }
  } catch (const std::out_of_range& e) {
    std::cerr << "Exception out_of_range: " << e.what() << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cerr << "Exception invalid_argument: " << e.what() << std::endl;
  }
}

void TranformParam(int64_t& param, std::ifstream& ifs, char sep=',') {
  std::string buff;
  std::getline(ifs, buff, sep);
  try {
    if(buff.empty()) {
      throw std::invalid_argument("Lack of value!");
    }
    param = static_cast<int64_t>(stol(buff));
  } catch (const std::out_of_range& e) {
    std::cerr << "Exception out_of_range: " << e.what() << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cerr << "Exception invalid_argument: " << e.what() << std::endl;
  }
}

void TranformParam(float& param, std::ifstream& ifs, char sep=',') {
  std::string buff;
  std::getline(ifs, buff, sep);
  try {
    if(buff.empty()) {
      throw std::invalid_argument("Lack of value!");
    }
    param = stof(buff);
  } catch (const std::out_of_range& e) {
    std::cerr << "Exception out_of_range: " << e.what() << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cerr << "Exception invalid_argument: " << e.what() << std::endl;
  }
}

void TranformParam(char& param, std::ifstream& ifs, char sep=',') {
  std::string buff;
  std::getline(ifs, buff, sep);
  try {
    if(buff.empty()) {
      throw std::invalid_argument("Lack of value!");
    }
    param = buff[0];
  } catch (const std::invalid_argument& e) {
    std::cerr << "Exception invalid_argument: " << e.what() << std::endl;
  }
}

void TranformParam(bool& param, std::ifstream& ifs, char sep=',') {
  std::string buff;
  std::getline(ifs, buff, sep);
  try {
    if(buff.empty()) {
      throw std::invalid_argument("Lack of value!");
    }
    param = static_cast<bool>(stoi(buff));
  } catch (const std::out_of_range& e) {
    std::cerr << "Exception out_of_range: " << e.what() << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cerr << "Exception invalid_argument: " << e.what() << std::endl;
  }
}

AnalogSignal AnSigParser(std::ifstream& ifs) {
  std::string buff;
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
  TranformParam(An, ifs);
  std::getline(ifs, ch_id, ',');
  std::getline(ifs, ph, ',');
  std::getline(ifs, ccbm, ',');
  std::getline(ifs, uu, ',');
  TranformParam(a, ifs);
  TranformParam(b, ifs);
  TranformParam(skew, ifs);
  TranformParam(min, ifs);
  TranformParam(max, ifs);
  TranformParam(primary, ifs);
  TranformParam(secondary, ifs);
  TranformParam(PS, ifs, '\n'); 
  return AnalogSignal(An, ch_id, ph, ccbm, uu, a, b, skew, min, max, primary, secondary, PS);
}

DigitalSignal DigSigParser(std::ifstream& ifs) {
  std::string buff;
  int32_t Dn;
  std::string ch_id;
  std::string ph;
  std::string ccbm;
  bool y;
  TranformParam(Dn, ifs);
  std::getline(ifs, ch_id, ',');
  std::getline(ifs, ph, ',');
  std::getline(ifs, ccbm, ',');
  TranformParam(y, ifs, '\n');
  return DigitalSignal(Dn, ch_id, ph, ccbm, y);
}

TimeMark TimeParser(std::ifstream& ifs) {
  std::string buff;
  int8_t day;
  int8_t month;
  int32_t year;
  int8_t hours;
  int8_t minutes;
  int8_t seconds;
  int64_t mcseconds;
  TranformParam(day, ifs, '/');
  TranformParam(month, ifs, '/');
  TranformParam(year, ifs);
  TranformParam(hours, ifs, ':');
  TranformParam(minutes, ifs, ':');
  TranformParam(seconds, ifs, '.');
  TranformParam(mcseconds, ifs, '\n');
  return TimeMark(day, month, year, hours, minutes, seconds, mcseconds);
}


ComtradeFile ComtradeParser::GenerateComtradeParser(const std::string& file_name) {
  std::ifstream ifs;
  ifs.open(file_name, std::ios::in | std::ios::binary);
  if(!ifs.is_open()) {
    std::cerr << "File could not be opened" << std::endl;
    return ComtradeFile();
  }
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
  std::vector<AnalogSignal> analog_vector;
  std::vector<DigitalSignal> digital_vector;

  std::getline(ifs, buffer);
  std::getline(ifs, station_name, ',');
  std::getline(ifs, rec_dev_id, ',');
  std::getline(ifs, rev_year);
  TranformParam(TT, ifs);
  TranformParam(analog_count, ifs, ',', true);
  TranformParam(digital_count, ifs, '\n', true);
  analog_vector.reserve(analog_count);
  digital_vector.reserve(digital_count);

  for(size_t i=0; i < analog_count; i++) {
    analog_vector.push_back(AnSigParser(ifs));
  }
  for(size_t i=0; i < digital_count; i++) {
    digital_vector.push_back(DigSigParser(ifs));
  }

  TranformParam(lf, ifs, '\n');
  TranformParam(nrates, ifs, '\n');  
  TranformParam(samp, ifs);
  TranformParam(endsamp, ifs, '\n');
  time_start = TimeParser(ifs);
  trigger_point = TimeParser(ifs);
  std::getline(ifs, ft);
  TranformParam(timemult, ifs, '\n');
  std::getline(ifs, time_code, ',');
  std::getline(ifs, local_code);
  TranformParam(tmq_code, ifs);
  TranformParam(leapsec, ifs, '\n');

  ifs.close();

  ComtradeFile temp_comp_file = ComtradeFile(station_name, rec_dev_id, rev_year, TT,
                                             analog_count, digital_count, lf, nrates,
                                             samp, endsamp, time_start, trigger_point,
                                             ft, timemult, time_code, local_code,
                                             tmq_code, leapsec);

  for(AnalogSignal sig : analog_vector) {
    temp_comp_file.PushAnalog(sig);
  }
  for(DigitalSignal sig : digital_vector) {
    temp_comp_file.PushDigital(sig);
  }

  return temp_comp_file;
}

} // comtrade