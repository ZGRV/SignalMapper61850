//
// Created by zagorodnikov on 02.04.2025.
//

#include <iostream>
#include "comtrade.h"

namespace comtrade {

const std::set<char> kSetPS {'P', 'p', 'S', 's'}; // Множество возможных значений атрибута PS
const std::set<std::string> kSetRevYear {"1991", "1999", "2013"}; // Множество возможных значений атрибута rev_year
const std::set<std::string> kSetFt {"ascii", "binary", "binary32", "float32"}; // Множество возможных значений атрибута ft
const std::set<char> kSetTmqCode {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'F'}; // Множество возможных значений атрибута tmq_code


/**
  * Данная функция проверяет вводимое значение типа std::string для инициализации атрибута класса 
  * AnalogSignal или DigitalSignal на соотвествие ограничениям стандарта IEC COMTRADE
  * @param value вводимое значения для иницилизируемого атрибута класса AnalogSignal или DigitalSignal
  * @param param ссылка на иницилизируемый атрибут класса AnalogSignal или DigitalSignal
  * @param min_value минимальное значение, соответствующее ограничениям стандарта
  * @param max_value максимальное значение, соответствующее ограничениям стандарта
  */
inline void CheckParam(const std::string& value, std::string& param, 
                       size_t min_value = std::numeric_limits<uint8_t>::min(),
                       size_t max_value = std::numeric_limits<uint8_t>::max()) {
  if (value.length() >= min_value && value.length() <= max_value) {
    param = value;
  } else {
    throw std::invalid_argument("Inappropriate value!");
  }
}
/**
  * Данная функция проверяет вводимое значение типа int8_t для инициализации атрибута класса 
  * AnalogSignal или DigitalSignal на соотвествие ограничениям стандарта IEC COMTRADE
  * @param value вводимое значения для иницилизируемого атрибута класса AnalogSignal или DigitalSignal
  * @param param ссылка на иницилизируемый атрибут класса AnalogSignal или DigitalSignal
  * @param min_value минимальное значение, соответствующее ограничениям стандарта
  * @param max_value максимальное значение, соответствующее ограничениям стандарта
  */
inline void CheckParam(const int8_t& value, int8_t& param,
                       int8_t min_value = std::numeric_limits<int8_t>::min(),
                       int8_t max_value = std::numeric_limits<int8_t>::max()) { 
  if (value >= min_value && value <= max_value) {
  param = value;
  } else {
    throw std::invalid_argument("Inappropriate value!");
  }
}
/**
  * Данная функция проверяет вводимое значение типа int32_t для инициализации атрибута класса 
  * AnalogSignal или DigitalSignal на соотвествие ограничениям стандарта IEC COMTRADE
  * @param value вводимое значения для иницилизируемого атрибута класса AnalogSignal или DigitalSignal
  * @param param ссылка на иницилизируемый атрибут класса AnalogSignal или DigitalSignal
  * @param min_value минимальное значение, соответствующее ограничениям стандарта
  * @param max_value максимальное значение, соответствующее ограничениям стандарта
  */
inline void CheckParam(const int32_t& value, int32_t& param,
                       int32_t min_value = std::numeric_limits<int32_t>::min(),
                       int32_t max_value = std::numeric_limits<int32_t>::max()) {  
  if (value >= min_value && value <= max_value) {
    param = value;
  } else {
    throw std::invalid_argument("Inappropriate value!");
  }
}
/**
  * Данная функция проверяет вводимое значение типа int64_t для инициализации атрибута класса 
  * AnalogSignal или DigitalSignal на соотвествие ограничениям стандарта IEC COMTRADE
  * @param value вводимое значения для иницилизируемого атрибута класса AnalogSignal или DigitalSignal
  * @param param ссылка на иницилизируемый атрибут класса AnalogSignal или DigitalSignal
  * @param min_value минимальное значение, соответствующее ограничениям стандарта
  * @param max_value максимальное значение, соответствующее ограничениям стандарта
  */
inline void CheckParam(const int64_t& value, int64_t& param,
                       int64_t min_value = std::numeric_limits<int64_t>::min(),
                       int64_t max_value = std::numeric_limits<int64_t>::max()) {
  if (value >= min_value && value <= max_value) {
  param = value;
  } else {
    throw std::invalid_argument("Inappropriate value!");
  }
}
/**
  * Данная функция проверяет вводимое значение типа float для инициализации атрибута класса 
  * AnalogSignal или DigitalSignal на соотвествие ограничениям стандарта IEC COMTRADE
  * @param value вводимое значения для иницилизируемого атрибута класса AnalogSignal или DigitalSignal
  * @param param ссылка на иницилизируемый атрибут класса AnalogSignal или DigitalSignal
  * @param min_value минимальное значение, соответствующее ограничениям стандарта
  * @param max_value максимальное значение, соответствующее ограничениям стандарта
  */
inline void CheckParam(const float& value, float& param,
                       float min_value = std::numeric_limits<float>::max(),
                       float max_value = std::numeric_limits<float>::max()) {
  if (value >= (-1.f * min_value) && value <= max_value) {
    param = value;
  } else {
    throw std::invalid_argument("Inappropriate value!");
  }
}
/**
  * Данная функция проверяет вводимое значение типа char для инициализации атрибута класса 
  * AnalogSignal или DigitalSignal на соотвествие ограничениям стандарта IEC COMTRADE
  * @param value вводимое значения для иницилизируемого атрибута класса AnalogSignal или DigitalSignal
  * @param param ссылка на иницилизируемый атрибут класса AnalogSignal или DigitalSignal
  * @param keys множество допустимых значений атрибута типа char
  */
inline void CompareParam(const char& value, char& param, const std::set<char>& keys) {
  if(keys.count(value)) {
    param = value;
  } else {
    throw std::invalid_argument("Inappropriate value!");
  }
}
/**
  * Данная функция проверяет вводимое значение типа std::string для инициализации атрибута класса 
  * AnalogSignal или DigitalSignal на соотвествие ограничениям стандарта IEC COMTRADE
  * @param value вводимое значения для иницилизируемого атрибута класса AnalogSignal или DigitalSignal
  * @param param ссылка на иницилизируемый атрибут класса AnalogSignal или DigitalSignal
  * @param keys множество допустимых значений атрибута типа std::string
  * @param default_val есть ли значение по умолчанию при отсутвии данных в файле .cfg
  */
inline void CompareParam(const std::string& value, std::string& param, 
                         const std::set<std::string>& keys, bool default_val=false) {
  if(value == "" && default_val) {
    return;
  }
  std::string copy_val = value;
  std::transform(copy_val.begin(), copy_val.end(), copy_val.begin(), ::tolower);
  if(keys.count(copy_val)) {
    param = value;
  } else {
    throw std::invalid_argument("Inappropriate value!");
  }
}


TimeMark::TimeMark(int8_t day, int8_t month, int32_t year, int8_t hours, 
                   int8_t minutes, int8_t seconds, int64_t mcseconds) {
  try {
    CheckParam(day, day_, 1, 31);
    CheckParam(month, month_, 1, 12);
    CheckParam(year, year_, 1900, 9999);
    CheckParam(hours, hours_, 0, 23);
    CheckParam(minutes, minutes_, 0, 59);
    CheckParam(seconds, seconds_, 0, 59);
    CheckParam(mcseconds, mcseconds_, 0, 999999999);
  } catch (const std::invalid_argument& e) {
    std::cerr << "Exception invalid_argument: " << e.what() << " Datatime problem" << std::endl;
    throw std::runtime_error("Creating object error!");
  }
}


AnalogSignal::AnalogSignal(int32_t An, const std::string& ch_id, const std::string& ph, const std::string& ccbm, 
                           const std::string& uu, float a, float b, float skew, float min, float max, 
                           float primary, float secondary, char PS) {
  try {
    CheckParam(An, An_, 1, 999999); 
    CheckParam(ch_id, ch_id_, 1, 128);
    CheckParam(ph, ph_, 0, 2);
    CheckParam(ccbm, ccbm_, 0, 64);
    CheckParam(uu, uu_, 1, 32);
    a_ = a;
    b_ = b;
    skew_ = skew;  
    // if(min > max) {
    //   throw std::invalid_argument("Min/max problem!");
    // }
    CheckParam(min, min_);
    CheckParam(max, max_);
    primary_ = primary;
    secondary_ = secondary;
    CompareParam(PS, PS_, kSetPS);
  } catch (const std::invalid_argument& e) {
    std::cerr << "Exception invalid_argument: " << e.what() << " Number of analog signal: " 
    << An << std::endl;
    throw std::runtime_error("Creating object error!");
  }
}


DigitalSignal::DigitalSignal(int32_t Dn, const std::string& ch_id, const std::string& ph, const std::string& ccbm, bool y) {
  try {
    CheckParam(Dn, Dn_, 1, 999999);
    CheckParam(ch_id, ch_id_, 1, 128);
    CheckParam(ph, ph_, 0, 2);
    CheckParam(ccbm, ccbm_, 0, 64);
    y_ = y;
  } catch (const std::invalid_argument& e) {
    std::cerr << "Exception invalid_argument: " << e.what() << " Number of digtal signal: " 
    << Dn << std::endl;
    throw std::runtime_error("Creating object error!");
  }
}


ComtradeFile::ComtradeFile(const std::string& station_name,
                           const std::string& rec_dev_id,
                           const std::string& rev_year,
                           int32_t TT,
                           int32_t analog_count,
                           int32_t digital_count,
                           float lf,
                           int32_t nrates,
                           float samp,
                           int64_t endsamp,
                           const TimeMark& time_start,
                           const TimeMark& trigger_point,
                           const std::string& ft,
                           float timemult,
                           const std::string& time_code,
                           const std::string& local_code,
                           char tmq_code,
                           int8_t leapsec) {
  size_t str_counter_for_exceptions = 2;
  try {
    CheckParam(station_name, station_name_, 0, 64);
    CheckParam(rec_dev_id, rec_dev_id_, 0, 64);
    CompareParam(rev_year, rev_year_, kSetRevYear, true);
    str_counter_for_exceptions++;
    if(TT != analog_count + digital_count) {
      throw std::invalid_argument("Inappropriate count of analog or digital signals!");
    }
    CheckParam(TT, TT_, 1, 999999);
    CheckParam(analog_count, analog_count_, 0, 999999);
    CheckParam(digital_count, digital_count_, 0, 999999);
    str_counter_for_exceptions += TT_ + 3;
    CheckParam(lf, lf_);
    str_counter_for_exceptions++;
    CheckParam(nrates, nrates_, 0, 999);
    str_counter_for_exceptions++;
    CheckParam(samp, samp_);
    CheckParam(endsamp, endsamp_, 1, 9999999999);
    str_counter_for_exceptions++;
    time_start_ = time_start;
    trigger_point_ = trigger_point;
    CompareParam(ft, ft_, kSetFt);
    str_counter_for_exceptions++;
    CheckParam(timemult, timemult_);
    str_counter_for_exceptions++;
    CheckParam(time_code, time_code_);
    CheckParam(local_code, local_code_);
    str_counter_for_exceptions++;
    CompareParam(tmq_code, tmq_code_, kSetTmqCode);
    CheckParam(leapsec, leapsec_, 0, 3);

    analog_vector.reserve(analog_count);
    digital_vector.reserve(digital_count);
  } catch (const std::invalid_argument& e) {
    std::cerr << "Exception invalid_argument: " << e.what() << " Number of line " 
    << str_counter_for_exceptions << std::endl;
    throw std::runtime_error("Creating object error!");
  }
}

} // comtrade
