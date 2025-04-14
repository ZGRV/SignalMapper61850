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
* Исключение выводимое при несоотвествии введенного значения ограничения стандарта IEC COMTRADE
*/
const std::string kExceptionForInitParam = "Inappropriate value!"; 

/**
  * Данная функция проверяет вводимое значение типа std::string для инициализации атрибута класса 
  * AnalogSignal или DigitalSignal на соотвествие ограничениям стандарта IEC COMTRADE
  * @param con условие проверки вводимого значения для иницилизируемого атрибута класса 
  * AnalogSignal или DigitalSignal согласно стандарту IEC COMTRADE
  * @param var вводимое значения для иницилизируемого атрибута класса AnalogSignal или DigitalSignal
  * @param param указатель на иницилизируемый атрибут класса AnalogSignal или DigitalSignal
  */
inline void ConForString(bool con, const std::string& var, std::string& param) {
  if(con) param = var;
  else throw std::invalid_argument("Invalid value!");
}
/**
  * Данная функция проверяет вводимое значение типа int32_t для инициализации атрибута класса 
  * AnalogSignal или DigitalSignal на соотвествие ограничениям стандарта IEC COMTRADE
  * @param con условие проверки вводимого значения для иницилизируемого атрибута класса 
  * AnalogSignal или DigitalSignal согласно стандарту IEC COMTRADE
  * @param var вводимое значения для иницилизируемого атрибута класса AnalogSignal или DigitalSignal
  * @param param указатель на иницилизируемый атрибут класса AnalogSignal или DigitalSignal
  */
inline void ConForInt32(bool con, int32_t var, int32_t* param) {
  if(con) *param = var;
  else throw kExceptionForInitParam;
}

void CheckParam(float value, float& out,
  float min_value = std::numeric_limits<float>::min(),
  float max_value = std::numeric_limits<float>::max()) {
  if (value >= min_value && value <= max_value) {
    out = value;
  } else {
    throw std::out_of_range("Float value out of range!");
  }
}

void CheckParam(int32_t value, int32_t& out,
  int32_t min_value = std::numeric_limits<int32_t>::min(),
  int32_t max_value = std::numeric_limits<int32_t>::min()) {
  if (value > min_value && value < max_value) {
    out = value;
  } else {
    throw std::out_of_range("Float value out of range!");
  }
}


/**
  * Данная функция проверяет вводимое значение типа float для инициализации атрибута класса 
  * AnalogSignal или DigitalSignal на соотвествие ограничениям стандарта IEC COMTRADE
  * @param con условие проверки вводимого значения для иницилизируемого атрибута класса 
  * AnalogSignal или DigitalSignal согласно стандарту IEC COMTRADE
  * @param var вводимое значения для иницилизируемого атрибута класса AnalogSignal или DigitalSignal
  * @param param указатель на иницилизируемый атрибут класса AnalogSignal или DigitalSignal
  */
inline void ConForFloat(bool con, float var, float* param) {
  if(con) *param = var;
  else throw kExceptionForInitParam;
}
/**
  * Данная функция проверяет вводимое значение типа char для инициализации атрибута класса 
  * AnalogSignal или DigitalSignal на соотвествие ограничениям стандарта IEC COMTRADE
  * @param con условие проверки вводимого значения для иницилизируемого атрибута класса 
  * AnalogSignal или DigitalSignal согласно стандарту IEC COMTRADE
  * @param var вводимое значения для иницилизируемого атрибута класса AnalogSignal или DigitalSignal
  * @param param указатель на иницилизируемый атрибут класса AnalogSignal или DigitalSignal
  */
inline void ConForChar(bool con, char var, char* param) {
  if(con) *param = var;
  else throw kExceptionForInitParam;
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
    CheckParam(An,An_, 0, 9999);
    ConForString((ch_id.length() > 0 && ch_id.length() <= 128), ch_id, ch_id_);
    ConForString((ph.length() <= 2), ph, ph_);
    ConForString((ccbm.length() <= 64), ccbm, ccbm_);
    ConForString((uu.length() > 0 && uu.length() <= 32), uu, uu_);
    a_ = a;
    b_ = b;
    skew_ = skew;
    if(min > max) throw kExceptionForInitParam;
    ConForFloat((min > -3.4028236e38 && min < 3.4028236e38), min, &min_);
    ConForFloat((max > -3.4028236e38F && max < 3.4028236e38F), max, &max_);
    primary_ = primary;
    secondary_ = secondary;
    ConForChar((PS == 'P' || PS == 'p' || PS == 'S' || PS == 's'), PS, &PS_);
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
    ConForInt32((Dn > 0 && Dn <= 999999), Dn, &Dn_);
    ConForString((ch_id.length() > 0 && ch_id.length() <= 128), ch_id, ch_id_);
    ConForString((ph.length() <= 2), ph, ph_);
    ConForString((ccbm.length() <= 64), ccbm, ccbm_);
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

  std::vector<AnalogSignal> analog_vector; // Вектор состоящий из аналоговых сигналов
  std::vector<DigitalSignal> digital_vector; // Вектор состоящий из цифровых сигналов
public:
  void PushAnalog(const AnalogSignal& signal) {
    analog_vector.push_back(signal);
  }
  void PushDigital(DigitalSignal signal) {
    digital_vector.push_back(signal);
  }
  const AnalogSignal& GetAnalogSignal(std::size_t an) {
    return analog_vector.at(an);
  }
  DigitalSignal GetDigitalSignal(int32_t Dn) {
    return digital_vector[Dn];
  }
};

} // comtrade

#endif //COMTRADE_PARSER_H
