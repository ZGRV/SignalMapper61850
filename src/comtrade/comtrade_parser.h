//
// Created by zagorodnikov on 02.04.2025.
//
#include <string>
#include <vector>

#ifndef COMTRADE_PARSER_H
#define COMTRADE_PARSER_H

namespace comtrade {

/**
* Исключение выводимое при несоотвествии введенного значения ограничения стандарта IEC COMTRADE
*/
const std::string EXCEPTION_FOR_INIT_PARAM = "Inappropriate value!"; 

/**
  * Данная функция проверяет вводимое значение типа std::string для инициализации атрибута класса 
  * AnalogSignal или DigitalSignal на соотвествие ограничениям стандарта IEC COMTRADE
  * @param con условие проверки вводимого значения для иницилизируемого атрибута класса 
  * AnalogSignal или DigitalSignal согласно стандарту IEC COMTRADE
  * @param var вводимое значения для иницилизируемого атрибута класса AnalogSignal или DigitalSignal
  * @param param указатель на иницилизируемый атрибут класса AnalogSignal или DigitalSignal
  */
inline void con_for_string(bool con, std::string var, std::string* param) {
  if(con) *param = var;
  else throw EXCEPTION_FOR_INIT_PARAM;
}
/**
  * Данная функция проверяет вводимое значение типа int32_t для инициализации атрибута класса 
  * AnalogSignal или DigitalSignal на соотвествие ограничениям стандарта IEC COMTRADE
  * @param con условие проверки вводимого значения для иницилизируемого атрибута класса 
  * AnalogSignal или DigitalSignal согласно стандарту IEC COMTRADE
  * @param var вводимое значения для иницилизируемого атрибута класса AnalogSignal или DigitalSignal
  * @param param указатель на иницилизируемый атрибут класса AnalogSignal или DigitalSignal
  */
inline void con_for_int32(bool con, int32_t var, int32_t* param) {
  if(con) *param = var;
  else throw EXCEPTION_FOR_INIT_PARAM;
}
/**
  * Данная функция проверяет вводимое значение типа float для инициализации атрибута класса 
  * AnalogSignal или DigitalSignal на соотвествие ограничениям стандарта IEC COMTRADE
  * @param con условие проверки вводимого значения для иницилизируемого атрибута класса 
  * AnalogSignal или DigitalSignal согласно стандарту IEC COMTRADE
  * @param var вводимое значения для иницилизируемого атрибута класса AnalogSignal или DigitalSignal
  * @param param указатель на иницилизируемый атрибут класса AnalogSignal или DigitalSignal
  */
inline void con_for_float(bool con, float var, float* param) {
  if(con) *param = var;
  else throw EXCEPTION_FOR_INIT_PARAM;
}
/**
  * Данная функция проверяет вводимое значение типа char для инициализации атрибута класса 
  * AnalogSignal или DigitalSignal на соотвествие ограничениям стандарта IEC COMTRADE
  * @param con условие проверки вводимого значения для иницилизируемого атрибута класса 
  * AnalogSignal или DigitalSignal согласно стандарту IEC COMTRADE
  * @param var вводимое значения для иницилизируемого атрибута класса AnalogSignal или DigitalSignal
  * @param param указатель на иницилизируемый атрибут класса AnalogSignal или DigitalSignal
  */
inline void con_for_char(bool con, char var, char* param) {
  if(con) *param = var;
  else throw EXCEPTION_FOR_INIT_PARAM;
}

class ComtradeParser {
 public:
  ComtradeParser();
};

/**
 * Класс создает вектор аналоговых сигналов и вектор цифровых сигналов
 */
class Signals {
  std::vector<AnalogSignal> analog_vector; // Вектор состоящий из аналоговых сигналов
  std::vector<DigitalSignal> digital_vector; // Вектор состоящий из цифровых сигналов
 public: 
  void push_analog(AnalogSignal signal) {
    analog_vector.push_back(signal);
  }
  void push_digital(DigitalSignal signal) {
    digital_vector.push_back(signal);
  }
  AnalogSignal get_analog_signal(int32_t An) {
    return analog_vector[An];
  }
  DigitalSignal get_digital_signal(int32_t Dn) {
    return digital_vector[Dn];
  }
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
    con_for_int32((An > 0 && An <= 999999), An, &An_); 
    con_for_string((ch_id.length() > 0 && ch_id.length() <= 128), ch_id, &ch_id_);
    con_for_string((ph.length() <= 2), ph, &ph_);
    con_for_string((ccbm.length() <= 64), ccbm, &ccbm_);
    con_for_string((uu.length() > 0 && uu.length() <= 32), uu, &uu_);
    a_ = a;
    b_ = b;
    skew_ = skew;
    if(min > max) throw EXCEPTION_FOR_INIT_PARAM;
    con_for_float((min > -3.4028236e38 && min < 3.4028236e38), min, &min_);
    con_for_float((max > -3.4028236e38 && max < 3.4028236e38), max, &max_);
    primary_ = primary;
    secondary_ = secondary;
    con_for_char((PS == 'P' || PS == 'p' || PS == 'S' || PS == 's'), PS, &PS_);
  }

  int32_t get_An() {
    return An_;
  }
  std::string get_ch_id() {
    return ch_id_;
  }
  std::string get_uu() {
    return uu_;
  }
  float get_a() {
    return a_;
  }
  float get_b() {
    return b_;
  } 
  float get_skew() {
    return skew_;
  }
  float get_min() {
    return min_;
  }
  float get_max() {
    return max_;
  }
  float get_primary() {
    return primary_;
  }
  float get_secondary() {
    return secondary_;
  } 
  char get_PS() {
    return PS_;
  }
  std::string get_ph() {
    return ph_;
  }
  std::string get_ccbm() {
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
    con_for_int32((Dn > 0 && Dn <= 999999), Dn, &Dn_);
    con_for_string((ch_id.length() > 0 && ch_id.length() <= 128), ch_id, &ch_id_);
    con_for_string((ph.length() <= 2), ph, &ph_);
    con_for_string((ccbm.length() <= 64), ccbm, &ccbm_);
    y_ = y;
  }

  int32_t get_Dn() {
    return Dn_;
  }
  std::string get_ch_id() {
    return ch_id_;
  }
  bool get_y() {
    return y_;
  }
  std::string get_ph() {
    return ph_;
  }
  std::string get_ccbm() {
    return ccbm_;
  }
};

} // comtrade

#endif //COMTRADE_PARSER_H
