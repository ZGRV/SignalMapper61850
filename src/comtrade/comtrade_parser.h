//
// Created by zagorodnikov on 02.04.2025.
//
#include <string>
#include <vector>
#include <limits>

#ifndef COMTRADE_PARSER_H
#define COMTRADE_PARSER_H

namespace comtrade {

/**
  * Данная функция проверяет вводимое значение типа std::string для инициализации атрибута класса 
  * AnalogSignal или DigitalSignal на соотвествие ограничениям стандарта IEC COMTRADE
  * @param con условие проверки вводимого значения для иницилизируемого атрибута класса 
  * AnalogSignal или DigitalSignal согласно стандарту IEC COMTRADE
  * @param value вводимое значения для иницилизируемого атрибута класса AnalogSignal или DigitalSignal
  * @param param ссылка на иницилизируемый атрибут класса AnalogSignal или DigitalSignal
  * @param min_value минимальное значение, соответствующее ограничениям стандарта
  * @param max_value максимальное значение, соответствующее ограничениям стандарта
  */
inline void CheckParam(std::string& value, std::string& param, 
                       size_t min_value = std::numeric_limits<uint8_t>::min(),
                       size_t max_value = std::numeric_limits<uint8_t>::max()) {
  if (value.length() >= min_value && value.length() <= max_value) {
    param = value;
  } else {
    throw std::invalid_argument("Inappropriate value!");
  }
}
/**
  * Данная функция проверяет вводимое значение типа int32_t для инициализации атрибута класса 
  * AnalogSignal или DigitalSignal на соотвествие ограничениям стандарта IEC COMTRADE
  * @param con условие проверки вводимого значения для иницилизируемого атрибута класса 
  * AnalogSignal или DigitalSignal согласно стандарту IEC COMTRADE
  * @param value вводимое значения для иницилизируемого атрибута класса AnalogSignal или DigitalSignal
  * @param param ссылка на иницилизируемый атрибут класса AnalogSignal или DigitalSignal
  * @param min_value минимальное значение, соответствующее ограничениям стандарта
  * @param max_value максимальное значение, соответствующее ограничениям стандарта
  */
inline void CheckParam(int32_t& value, int32_t& param,
                       int32_t min_value = std::numeric_limits<int32_t>::min(),
                       int32_t max_value = std::numeric_limits<int32_t>::max()) {  
  if (value >= min_value && value <= max_value) {
    param = value;
  } else {
    throw std::invalid_argument("Inappropriate value!");
  }
}
/**
  * Данная функция проверяет вводимое значение типа float для инициализации атрибута класса 
  * AnalogSignal или DigitalSignal на соотвествие ограничениям стандарта IEC COMTRADE
  * @param con условие проверки вводимого значения для иницилизируемого атрибута класса 
  * AnalogSignal или DigitalSignal согласно стандарту IEC COMTRADE
  * @param value вводимое значения для иницилизируемого атрибута класса AnalogSignal или DigitalSignal
  * @param param ссылка на иницилизируемый атрибут класса AnalogSignal или DigitalSignal
  * @param min_value минимальное значение, соответствующее ограничениям стандарта
  * @param max_value максимальное значение, соответствующее ограничениям стандарта
  */
inline void CheckParam(float& value, float& param,
                       float min_value = std::numeric_limits<float>::min(),
                       float max_value = std::numeric_limits<float>::max()) {
  if (value >= min_value && value <= max_value) {
    param = value;
  } else {
    throw std::invalid_argument("Inappropriate value!");
  }
}
/**
  * Данная функция проверяет вводимое значение типа char для инициализации атрибута класса 
  * AnalogSignal или DigitalSignal на соотвествие ограничениям стандарта IEC COMTRADE
  * @param con условие проверки вводимого значения для иницилизируемого атрибута класса 
  * AnalogSignal или DigitalSignal согласно стандарту IEC COMTRADE
  * @param value вводимое значения для иницилизируемого атрибута класса AnalogSignal или DigitalSignal
  * @param param ссылка на иницилизируемый атрибут класса AnalogSignal или DigitalSignal
  * @param condition условие из стандарта для проверки введенного значения
  */
inline void CheckParam(char& value, char& param, bool condition) {
  if(condition) param = value;
  else throw std::invalid_argument("Inappropriate value!");
}

class ComtradeParser {
 public:
  ComtradeParser();
};


/**
 * Класс является описанием аналогового сигнала согласно стандарту IEC COMTRADE.
 * Объект класса создается на основе файла с расширением .cfg, описываемого в этом же стандарте
 */
class AnalogSignal {   
  int32_t An_; // Порядковый номер аналогового канала. Критичные данные, целое число
  std::string ch_id_; // Идентификатор канала. Критичные данные, буквенно-цифровые
  std::string ph_; // Идентификатор фазы канала. Некритичные данные, буквенно-цифровые
  std::string ccbm_; // Компонент схемы, подвергаемый мониторингу. Некритичные данные, буквенноцифровые
  std::string uu_; //  Единицы измерения канала. Критичные данные, буквенные
  float a_; // Множитель канала (channel multiplier). Критичные данные, действительное число
  float b_; // Слагаемое смещения канала (channel offset adder). Критичные данные, действительное число
  /** 
   * Временной сдвиг (смещение) в данном канале (channel time skew) (в мкс) внутри периода дискретизации 
   * от начала периода выборки. Критичные данные, действительное число
   */
  float skew_; 
  float min_; // Минимальное значение данных в диапазоне для этого канала. Критичные данные, действительное число
  float max_; // Максимальное значение данных в диапазоне для этого канала. Критичные данные, действительное число
  /**
   * Первичный множитель (primary factor) коэффициента трансформации для трансформатора 
   * тока или напряжения. Критичные данные, действительное число
   */
  float primary_;
  /**
   * Вторичный множитель (secondary factor) коэффициента трансформации для трансформатора 
   * тока или напряжения. Критичные данные, действительное число
   */
  float secondary_;
  char PS_; // Идентификатор масштабирования первичных или вторичных величин. Критичные данные, буквенные (p/P/s/S)
 public:
  AnalogSignal(int32_t An, std::string ch_id, std::string uu, float a, float b, 
               float skew, float min, float max, float primary, float secondary, 
               char PS, std::string ph="", std::string ccbm="") {
    CheckParam(An, An_, 1, 999999); 
    CheckParam(ch_id, ch_id_, 1, 128);
    CheckParam(ph, ph_, 0, 2);
    CheckParam(ccbm, ccbm_, 0, 64);
    CheckParam(uu, uu_, 1, 32);
    a_ = a;
    b_ = b;
    skew_ = skew;
    if(min > max) throw std::invalid_argument("Inappropriate value!");
    CheckParam(min, min_);
    CheckParam(max, max_);
    primary_ = primary;
    secondary_ = secondary;
    CheckParam(PS, PS_, (PS == 'P' || PS == 'p' || PS == 'S' || PS == 's'));
  }

  int32_t GetAn() {
    return An_;
  }
  std::string GetChId() {
    return ch_id_;
  }
  std::string GetUu() {
    return uu_;
  }
  float GetA() {
    return a_;
  }
  float GetB() {
    return b_;
  } 
  float GetSkew() {
    return skew_;
  }
  float GetMin() {
    return min_;
  }
  float GetMax() {
    return max_;
  }
  float GetPrimary() {
    return primary_;
  }
  float GetSecondary() {
    return secondary_;
  } 
  char GetPS() {
    return PS_;
  }
  std::string GetPh() {
    return ph_;
  }
  std::string GetCcbm() {
    return ccbm_;
  }
};

/**
 * Класс является описанием дискретного сигнала согласно стандарту IEC COMTRADE.
 * Объект класса создается на основе файла с расширением .cfg, описываемого в этом же стандарте
 */
class DigitalSignal {
  int32_t Dn_; // Порядковый номер канала состояния. Критичные данные, целое число
  std::string ch_id_; // Идентификатор канала. Критичные данные, буквенно-цифровые
  std::string ph_; // Идентификатор фазы канала. Некритичные данные, буквенно-цифровые
  std::string ccbm_; // Компонент схемы, подвергаемый мониторингу. Некритичные данные, буквенно-цифровые
  bool y_; // Нормальное состояние канала состояния. Критичные данные, целое число (0/1)
 public:
  DigitalSignal(int32_t Dn, std::string ch_id, bool y, std::string ph="", std::string ccbm="") {
    CheckParam(Dn, Dn_, 1, 999999);
    CheckParam(ch_id, ch_id_, 1, 128);
    CheckParam(ph, ph_, 0, 2);
    CheckParam(ccbm, ccbm_, 0, 64);
    y_ = y;
  }

  int32_t GetDn() {
    return Dn_;
  }
  std::string GetChId() {
    return ch_id_;
  }
  bool GetY() {
    return y_;
  }
  std::string GetPh() {
    return ph_;
  }
  std::string GetCcbm() {
    return ccbm_;
  }
};

/**
 * Класс создает вектор аналоговых сигналов и вектор цифровых сигналов
 */
class ComtradeFile {
  std::string station_name_;
  std::string rec_dev_id_;
  short rev_year_ = (short)1991;
  int32_t TT_;
  int32_t analog_count_;
  int32_t digital_count_;
  float lf_;
  uint8_t nrates_;
  float samp_;
  int64_t endsamp_;
  std::string time_start_;
  std::string trigger_point_;
  std::string ft_;
  float timemult_;
  std::string time_code_;
  std::string local_code_;
  int8_t tmq_code_;
  int8_t leapsec_;

  std::vector<AnalogSignal> analog_vector; // Вектор состоящий из аналоговых сигналов
  std::vector<DigitalSignal> digital_vector; // Вектор состоящий из цифровых сигналов
 public: 
  ComtradeFile(std::string station_name,
               std::string rec_dev_id,
               short rev_year,
               int32_t TT,
               int32_t analog_count,
               int32_t digital_count,
               float lf,
               uint8_t nrates,
               float samp,
               int64_t endsamp,
               std::string time_start,
               std::string trigger_point,
               std::string ft,
               float timemult,
               std::string time_code,
               std::string local_code,
               int8_t tmq_code,
               int8_t leapsec) {
    CheckParam(station_name, station_name_, 0, 64);
    CheckParam(rec_dev_id, rec_dev_id_, 0, 64);
    //CheckParam(rev_year, rev_year, 0, 64);
    if(TT != analog_count + digital_count) throw std::invalid_argument("Inappropriate count of analog or digital signals!");
    CheckParam(TT, TT_, 1, 999999);
    CheckParam(analog_count, analog_count_, 0, 999999);
    CheckParam(digital_count, digital_count_, 0, 999999);
    CheckParam(lf, lf_);
    //nrates
    CheckParam(samp, samp_);
    //endsamp
    //function for time
    //function for time
    CheckParam(ft, ft_, 5, 8); // доппроверки
    CheckParam(timemult, timemult_);
    CheckParam(time_code, time_code_);
    CheckParam(local_code, local_code_);
    //CheckParam(tmq_code, tmq_code_, (tmq_code >= 0 && tmq_code < 16));
    //CheckParam();

    analog_vector.reserve(analog_count);
    digital_vector.reserve(digital_count);
  }
  
  void PushAnalog(AnalogSignal& signal) {
    static int32_t number = 0;
    analog_vector.at(number++) = signal;
  }
  void PushDigital(DigitalSignal& signal) {
    static int32_t number = 0;
    digital_vector.at(number++) = signal;
  }
  const AnalogSignal& GetAnalogSignal(size_t an) {
    return analog_vector.at(an);
  }
  const DigitalSignal& GetDigitalSignal(size_t dn) {
    return digital_vector.at(dn);
  }
};

} // comtrade

#endif //COMTRADE_PARSER_H
