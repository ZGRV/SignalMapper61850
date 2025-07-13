//
// Created by zagorodnikov on 02.04.2025.
//

#include <iostream>
#include <cmath>
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
  * @param default_val есть ли значение по умолчанию при отсутвии данных в файле .CFG
  */
inline void CompareParam(const std::string& value, std::string& param, 
                         const std::set<std::string>& keys, bool default_val=false) {
  if(value.empty() && default_val) {
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
                           const std::vector<std::pair<float, int64_t>>& vec_of_samps,
                           const TimeMark& time_start,
                           const TimeMark& trigger_point,
                           const std::string& ft,
                           float timemult,
                           const std::string& time_code,
                           const std::string& local_code,
                           char tmq_code,
                           int8_t leapsec): comtrade_dataset_() {
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
    vec_of_samps_.reserve(nrates_);
    for (const std::pair<float, int64_t>& pair : vec_of_samps) {
      CheckParam(pair.first, samp_);
      CheckParam(pair.second, endsamp_, 1, 9999999999);
      str_counter_for_exceptions++;
      vec_of_samps_.emplace_back(samp_, endsamp_);
    }
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

    analog_vector_.reserve(analog_count);
    digital_vector_.reserve(digital_count);
  } catch (const std::invalid_argument& e) {
    std::cerr << "Exception invalid_argument: " << e.what() << " Number of line " 
    << str_counter_for_exceptions << std::endl;
    throw std::runtime_error("Creating object error!");
  }
}

ComtradeData::ComtradeData(int32_t analog_count, int32_t digital_count, int32_t nrates,
                           const std::vector<std::pair<float, int64_t>>& vec_of_samps): vec_of_samps_(vec_of_samps) {
  analog_count_ = analog_count;
  digital_count_ = digital_count;
  nrates_ = nrates;
  size_t sum_of_endsamps = 0;
  for(const std::pair<float, int64_t>& pair : vec_of_samps) {
    sum_of_endsamps += pair.second;
  }
  dataset_.reserve(sum_of_endsamps);
  buffer_vec_.resize(analog_count_ + static_cast<int32_t>(std::ceil(digital_count_ / 16.0)) / 2);
}

void ComtradeData::PushData(std::vector<int32_t>::iterator begin, std::vector<int32_t>::iterator end) {
  copy(begin, end, buffer_vec_.begin());
  dataset_.push_back(buffer_vec_);
}

const std::vector<int32_t>& ComtradeData::GetDataLineById(int32_t id) const {
  try {
    return dataset_.at(id - 1);
  } catch (const std::out_of_range& e) {
    std::cerr << "Exception out_of_range: " << e.what() << std::endl;
    throw std::runtime_error("Obtaining dataline error!");
  }
}

int32_t ComtradeData::GetAnalogSampById(int32_t id, int32_t an) const {
  try {
    if (an <= analog_count_) {
      const std::vector<int32_t> &vec = GetDataLineById(id);
      return vec.at(an - 1);
    }
    throw std::out_of_range("Analog sample id is higher than analog count!");
  } catch (const std::out_of_range& e) {
    std::cerr << "Exception out_of_range: " << e.what() << std::endl;
    throw std::runtime_error("Obtaining analog sample error!");
  }
}

bool ComtradeData::GetDigitalSampById(int32_t id, int32_t dn) const {
  try {
    if (dn <= digital_count_) {
      const std::vector<int32_t> &vec = GetDataLineById(id);
      int32_t dig_cell = vec.at(analog_count_ + (dn - 1) / 32);
      dn = (dn - 1) % 32;
      if (dn >= 16) {
        bool ans = dig_cell & (0x00000001 << (dn - 16));
        return ans;
      }
      bool ans = dig_cell & (0x00010000 << dn);
      return ans;
    }
    throw std::out_of_range("Digital sample id is higher than digital count!");
  } catch (const std::out_of_range& e) {
    std::cerr << "Exception out_of_range: " << e.what() << std::endl;
    throw std::runtime_error("Obtaining digital sample error!");
  }
}

void ComtradeInitializer::PushAnalog(ComtradeFile& comp_file, const AnalogSignal& signal) {
  static bool param_is_initialized = false;
  if (!param_is_initialized) {
    comp_file.PushAnalog(signal);
    param_is_initialized = true;
  } else {
    std::cerr << "Analog signal already is initialized!" << std::endl;
  }
}
void ComtradeInitializer::PushDigital(ComtradeFile& comp_file, const DigitalSignal& signal) {
  static bool param_is_initialized = false;
  if (!param_is_initialized) {
    comp_file.PushDigital(signal);
    param_is_initialized = true;
  } else {
    std::cerr << "Digital signal already is initialized!" << std::endl;
  }
}
void ComtradeInitializer::PushDataset(ComtradeFile& comp_file, const ComtradeData& dataset) {
  static bool param_is_initialized = false;
  if (!param_is_initialized) {
    comp_file.PushDataset(dataset);
    param_is_initialized = true;
  } else {
    std::cerr << "Dataset already is initialized!" << std::endl;
  }
}
void ComtradeInitializer::PushData(ComtradeData& comp_data,
                                   std::vector<int32_t>::iterator begin,
                                   std::vector<int32_t>::iterator end) {
  static bool param_is_initialized = false;
  if (!param_is_initialized) {
    comp_data.PushData(begin, end);
    param_is_initialized = true;
  } else {
    std::cerr << "Data already is initialized!" << std::endl;
  }
}

} // comtrade
