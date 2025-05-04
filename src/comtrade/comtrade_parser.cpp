//
// Created by zagorodnikov on 02.04.2025.
//

#include <iostream>
#include <fstream>
#include "comtrade.h"
#include "comtrade_parser.h"

namespace comtrade {

static size_t str_counter_for_exceptions = 2; // счетчик строк в файле .CFG стандарта Comtrade

/**
 * Данная функция переводит считанную строку из файла со значением в тип int8_t
  * @param ifs ссылка на поток ввода
  * @param param ссылка на считываемое значение
  * @param sep разделитель между считываемым и следующим значениями
 */
void TranformParam(std::ifstream& ifs, int8_t& param, char sep=',') {
  std::string buff;
  std::getline(ifs, buff, sep);
  try {
    if(buff.empty()) {
      throw std::invalid_argument("Lack of value!");
    }
    param = static_cast<int8_t>(stoi(buff));
  } catch (const std::out_of_range& e) {
    std::cerr << "Exception out_of_range: " << e.what() << " Number of line: " 
    << str_counter_for_exceptions << std::endl;
    throw ParseException("Reading file error!");
  } catch (const std::invalid_argument& e) {
    std::cerr << "Exception invalid_argument: " << e.what() << " Number of line: " 
    << str_counter_for_exceptions << std::endl;
    throw ParseException("Reading file error!");
  }
  if (sep == '\n') {
    str_counter_for_exceptions++;
  }
}
/**
 * Данная функция переводит считанную строку из файла со значением в тип int32_t
  * @param ifs ссылка на поток ввода
  * @param param ссылка на считываемое значение
  * @param sep разделитель между считываемым и следующим значениями
  * @param extra_sym специаьное условие для считывания параметров An и Dn
 */
void TranformParam(std::ifstream& ifs, int32_t& param, char sep=',', bool extra_sym=false) {
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
    std::cerr << "Exception out_of_range: " << e.what() << " Number of line: " 
    << str_counter_for_exceptions << std::endl;
    throw ParseException("Reading file error!");
  } catch (const std::invalid_argument& e) {
    std::cerr << "Exception invalid_argument: " << e.what() << " Number of line: " 
    << str_counter_for_exceptions << std::endl;
    throw ParseException("Reading file error!");
  }
  if (sep == '\n') {
    str_counter_for_exceptions++;
  }
}
/**
 * Данная функция переводит считанную строку из файла со значением в тип int64_t
  * @param ifs ссылка на поток ввода
  * @param param ссылка на считываемое значение
  * @param sep разделитель между считываемым и следующим значениями
 */
void TranformParam(std::ifstream& ifs, int64_t& param, char sep=',') {
  std::string buff;
  std::getline(ifs, buff, sep);
  try {
    if(buff.empty()) {
      throw std::invalid_argument("Lack of value!");
    }
    param = static_cast<int64_t>(stol(buff));
  } catch (const std::out_of_range& e) {
    std::cerr << "Exception out_of_range: " << e.what() << " Number of line: " 
    << str_counter_for_exceptions << std::endl;
    throw ParseException("Reading file error!");
  } catch (const std::invalid_argument& e) {
    std::cerr << "Exception invalid_argument: " << e.what() << " Number of line: " 
    << str_counter_for_exceptions << std::endl;
    throw ParseException("Reading file error!");
  }
  if (sep == '\n') {
    str_counter_for_exceptions++;
  }
}
/**
 * Данная функция переводит считанную строку из файла со значением в тип float
  * @param ifs ссылка на поток ввода
  * @param param ссылка на считываемое значение
  * @param sep разделитель между считываемым и следующим значениями
 */
void TranformParam(std::ifstream& ifs, float& param, char sep=',') {
  std::string buff;
  std::getline(ifs, buff, sep);
  try {
    if(buff.empty()) {
      throw std::invalid_argument("Lack of value!");
    }
    param = stof(buff);
  } catch (const std::out_of_range& e) {
    std::cerr << "Exception out_of_range: " << e.what() << " Number of line: " 
    << str_counter_for_exceptions << std::endl;
    throw ParseException("Reading file error!");
  } catch (const std::invalid_argument& e) {
    std::cerr << "Exception invalid_argument: " << e.what() << " Number of line: " 
    << str_counter_for_exceptions << std::endl;
    throw ParseException("Reading file error!");
  }
  if (sep == '\n') {
    str_counter_for_exceptions++;
  }
}
/**
 * Данная функция переводит считанную строку из файла со значением в тип char
  * @param ifs ссылка на поток ввода
  * @param param ссылка на считываемое значение
  * @param sep разделитель между считываемым и следующим значениями
 */
void TranformParam(std::ifstream& ifs, char& param, char sep=',') {
  std::string buff;
  std::getline(ifs, buff, sep);
  try {
    if(buff.empty()) {
      throw std::invalid_argument("Lack of value!");
    }
    param = buff[0];
  } catch (const std::invalid_argument& e) {
    std::cerr << "Exception invalid_argument: " << e.what() << " Number of line: " 
    << str_counter_for_exceptions << std::endl;
    throw ParseException("Reading file error!");
  }
  if (sep == '\n') {
    str_counter_for_exceptions++;
  }
}
/**
 * Данная функция переводит считанную строку из файла со значением в тип bool
  * @param ifs ссылка на поток ввода
  * @param param ссылка на считываемое значение
  * @param sep разделитель между считываемым и следующим значениями
 */
void TranformParam(std::ifstream& ifs, bool& param, char sep=',') {
  std::string buff;
  std::getline(ifs, buff, sep);
  try {
    if(buff.empty()) {
      throw std::invalid_argument("Lack of value!");
    }
    param = static_cast<bool>(stoi(buff));
  } catch (const std::out_of_range& e) {
    std::cerr << "Exception out_of_range: " << e.what() << " Number of line: " 
    << str_counter_for_exceptions << std::endl;
    throw ParseException("Reading file error!");
  } catch (const std::invalid_argument& e) {
    std::cerr << "Exception invalid_argument: " << e.what() << " Number of line: " 
    << str_counter_for_exceptions << std::endl;
    throw ParseException("Reading file error!");
  }
  if (sep == '\n') {
    str_counter_for_exceptions++;
  }
}
/**
 * Данная функция создает и проверяет на соответствие стандарту IEC COMTRADE объект типа AnalogSignal
  * @param ifs ссылка на поток ввода
  * @return объект типа AnalogSignal
 */
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
  TranformParam(ifs, An);
  std::getline(ifs, ch_id, ',');
  std::getline(ifs, ph, ',');
  std::getline(ifs, ccbm, ',');
  std::getline(ifs, uu, ',');
  TranformParam(ifs, a);
  TranformParam(ifs, b);
  TranformParam(ifs, skew);
  TranformParam(ifs, min);
  TranformParam(ifs, max);
  TranformParam(ifs, primary);
  TranformParam(ifs, secondary);
  TranformParam(ifs, PS, '\n'); 
  return AnalogSignal(An, ch_id, ph, ccbm, uu, a, b, skew, min, max, primary, secondary, PS);
}
/**
 * Данная функция создает и проверяет на соответствие стандарту IEC COMTRADE объект типа DigitalSignal
  * @param ifs ссылка на поток ввода
  * @return объект типа DigitalSignal
 */
DigitalSignal DigSigParser(std::ifstream& ifs) {
  std::string buff;
  int32_t Dn;
  std::string ch_id;
  std::string ph;
  std::string ccbm;
  bool y;
  TranformParam(ifs, Dn);
  std::getline(ifs, ch_id, ',');
  std::getline(ifs, ph, ',');
  std::getline(ifs, ccbm, ',');
  TranformParam(ifs, y, '\n');
  return DigitalSignal(Dn, ch_id, ph, ccbm, y);
}
/**
 * Данная функция создает и проверяет на соответствие стандарту IEC COMTRADE объект типа TimeMark
  * @param ifs ссылка на поток ввода
  * @return объект типа TimeMark
 */
TimeMark TimeParser(std::ifstream& ifs) {
  std::string buff;
  int8_t day;
  int8_t month;
  int32_t year;
  int8_t hours;
  int8_t minutes;
  int8_t seconds;
  int64_t mcseconds;
  TranformParam(ifs, day, '/');
  TranformParam(ifs, month, '/');
  TranformParam(ifs, year);
  TranformParam(ifs, hours, ':');
  TranformParam(ifs, minutes, ':');
  TranformParam(ifs, seconds, '.');
  TranformParam(ifs, mcseconds, '\n');
  return TimeMark(day, month, year, hours, minutes, seconds, mcseconds);
}


std::optional<ComtradeFile> ComtradeParser::Parse(const std::string& file_name) {
  std::ifstream ifs;
  ifs.open(file_name, std::ios::in | std::ios::binary);
  try {
    ifs.exceptions(ifs.failbit);
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
    str_counter_for_exceptions++;
    TranformParam(ifs, TT);
    TranformParam(ifs, analog_count, ',', true);
    TranformParam(ifs, digital_count, '\n', true);
    analog_vector.reserve(analog_count);
    digital_vector.reserve(digital_count);

    for(size_t i=0; i < analog_count; i++) {
      analog_vector.push_back(AnSigParser(ifs));
    }
    for(size_t i=0; i < digital_count; i++) {
      digital_vector.push_back(DigSigParser(ifs));
    }

    TranformParam(ifs, lf, '\n');
    TranformParam(ifs, nrates, '\n');  
    TranformParam(ifs, samp);
    TranformParam(ifs, endsamp, '\n');
    time_start = TimeParser(ifs);
    trigger_point = TimeParser(ifs);
    std::getline(ifs, ft);
    str_counter_for_exceptions++;
    TranformParam(ifs, timemult, '\n');
    std::getline(ifs, time_code, ',');
    std::getline(ifs, local_code);
    str_counter_for_exceptions++;
    TranformParam(ifs, tmq_code);
    TranformParam(ifs, leapsec, '\n');

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
  } catch(const std::ios_base::failure& e) {
    std::cerr << "Caught an ios_base::failure. File could not be opened!" << std::endl;
  } catch (const ParseException& e) {
    std::cerr << "Exception ParseException: " << e.what() << std::endl;
  }
  return {};
}

} // comtrade
