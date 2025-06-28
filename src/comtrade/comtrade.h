//
// Created by zagorodnikov on 02.04.2025.
//
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <format>
#include <limits>

#ifndef COMTRADE_H
#define COMTRADE_H

namespace comtrade {


/**
 * Класс для хранения даты и времени
 */
class TimeMark {
  int8_t day_;
  int8_t month_;
  int32_t year_;
  int8_t hours_;
  int8_t minutes_;
  int8_t seconds_;
  int64_t mcseconds_;
 public:
  TimeMark() = default;
  TimeMark(int8_t day, int8_t month, int32_t year, int8_t hours, int8_t minutes, int8_t seconds, int64_t mcseconds);

  const int8_t& GetDay() const {  
    return day_;  
  }
  const int8_t& GetMonth() const {  
    return month_;  
  }
  const int32_t& GetYear() const {  
    return year_;  
  }
  const int8_t& GetHours() const {  
    return hours_;  
  } 
  const int8_t& GetMinutes() const {  
    return minutes_;  
  }
  const int8_t& GetSeconds() const {  
    return seconds_;
  }
  const int64_t& GetMcSeconds() const {  
    return mcseconds_;
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
  AnalogSignal(int32_t An, const std::string& ch_id, const std::string& ph, const std::string& ccbm, 
               const std::string& uu, float a, float b, float skew, float min, float max, 
               float primary, float secondary, char PS);

  const int32_t& GetAn() const { 
    return An_; 
  }
  const std::string& GetChId() const { 
    return ch_id_; 
  }
  const std::string& GetPh() const { 
    return ph_; 
  }
  const std::string& GetCcbm() const { 
    return ccbm_; 
  }
  const std::string& GetUu() const { 
    return uu_; 
  }
  const float& GetA() const { 
    return a_; 
  }
  const float& GetB() const { 
    return b_; 
  }
  const float& GetSkew() const { 
    return skew_; 
  }
  const float& GetMin() const { 
    return min_; 
  }
  const float& GetMax() const { 
    return max_; 
  }
  const float& GetPrimary() const { 
    return primary_; 
  }
  const float& GetSecondary() const { 
    return secondary_; 
  }
  const char& GetPS() const { 
    return PS_; 
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
  DigitalSignal(int32_t Dn, const std::string& ch_id, const std::string& ph, const std::string& ccbm, bool y);

  const int32_t& GetDn() const { 
    return Dn_; 
  }
  const std::string& GetChId() const { 
    return ch_id_; 
  }
  const std::string& GetPh() const { 
    return ph_; 
  }
  const std::string& GetCcbm() const { 
    return ccbm_; 
  }
  const bool& GetY() const { 
    return y_; 
  }
};


/**
 * Класс создает объект, содержащий все данные из файла .cfg стандарта IEC COMTRADE
 */
class ComtradeFile {
  /**
   * Название подстанции, или местонахождение подстанции, или место, где были записаны файлы. Критичные данные, буквенно-цифровые
   */
  std::string station_name_;
  std::string rec_dev_id_; // Идентификационный номер или имя записывающего устройства. Критичные данные, буквенно-цифровые
  /**
   * Год редакции стандарта, указывающий версию файла COMTRADE. Критичные данные, целое число (1991/1999/2013).
   * При отсутвиии значения принимается как 1991 
   */
  std::string rev_year_ = "1991"; 
  int32_t TT_; // Общее количество каналов. Критичные данные, целое число
  int32_t analog_count_; // Количество аналоговых каналов, за которым следует идентификатор A. Критичные данные, буквенно-цифровые
  int32_t digital_count_; // Количество дискретных каналов, за которым следует идентификатор D. Критичные данные, буквенно-цифровые
  float lf_; // Номинальная частота в Гц сети, в которой были получены выборки. Критичные данные, действительное число
  int32_t nrates_; // Число частот дискретизации в файле данных. Критичные данные, целое число
  float samp_; // Частота дискретизации в Гц. Критичные данные, действительное число
  int64_t endsamp_; // Номер последней выборки на этой частоте дискретизации. Критичные данные, целое число
  TimeMark time_start_; // Время первого значения данных, содержащихся в файле данных (.DAT)
  TimeMark trigger_point_; // Время момента пуска записи осциллограммы (trigger point)
  std::string ft_; // Тип файла данных. Критичные данные, буквенная величина (ASCII/binary/binary32/float32)
  float timemult_; // Коэффициент умножения для поля разности времени (метки времени) в файле данных. Критичные данные, действительное число
  std::string time_code_; // Код времени, определенный в стандарте IEEE Std C37.232-2007. Критичные данные, буквенно-цифровые
  std::string local_code_; // Разность времени между местным часовым поясом места проведения записи и UTC; формат тот же, что и для time_code. Критичные данные, буквенно-цифровые
  char tmq_code_; // Код признака качества времени таймера записывающего устройства. Критичные данные, шестнадцатеричное число
  int8_t leapsec_; // Показатель корректировочной секунды (leap second). Критичные данные, целое число

  std::vector<AnalogSignal> analog_vector; // Вектор состоящий из аналоговых сигналов
  std::vector<DigitalSignal> digital_vector; // Вектор состоящий из цифровых сигналов
 public: 
  ComtradeFile() = default; 
  ComtradeFile(const std::string& station_name,
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
               int8_t leapsec);

  const std::string& GetStationName() const { 
    return station_name_; 
  }
  const std::string& GetRecDevId() const { 
    return rec_dev_id_; 
  }
  const std::string& GetRevYear() const { 
    return rev_year_; 
  }
  const int32_t& GetTT() const { 
    return TT_; 
  }
  const int32_t& GetAnalogCount() const { 
    return analog_count_; 
  }
  const int32_t& GetDigitalCount() const { 
    return digital_count_; 
  }
  const float& GetLf() const { 
    return lf_; 
  }
  const int32_t& GetNrates() const { 
    return nrates_; 
  }
  const float& GetSamp() const { 
    return samp_; 
  }
  const int64_t& GetEndSamp() const { 
    return endsamp_; 
  }
  const TimeMark& GetTimeStart() const { 
    return time_start_; 
  }
  const TimeMark& GetTriggerPoint() const { 
    return trigger_point_; 
  }
  const std::string& GetFt() const { 
    return ft_; 
  }
  const float& GetTimeMult() const { 
    return timemult_; 
  }
  const std::string& GetTimeCode() const { 
    return time_code_; 
  }
  const std::string& GetLocalCode() const { 
    return local_code_; 
  }
  const char& GetTmqCode() const { 
    return tmq_code_; 
  }
  const int8_t& GetLeapSec() const { 
    return leapsec_; 
  }
  /**
   * Функция возвращает аналоговый сигнал с порядковым номером an
   * @param an порядковый номер аналогового сигнала
   */
  const AnalogSignal& GetAnalogSignal(size_t an) const {
    return analog_vector.at(an - 1);
  }
  /**
   * Функция возвращает дискретный сигнал с порядковым номером dn
   * @param dn порядковый номер дискретного сигнала
   */
  const DigitalSignal& GetDigitalSignal(size_t dn) const {
    return digital_vector.at(dn - 1);
  }
  /**
   * Функция добавляет аналоговый сигнал в конец вектора аналоговых сигналов
   * @param signal аналоговый сигнал, который нужно добавить
   */
  void PushAnalog(AnalogSignal& signal) {
    analog_vector.push_back(signal);
  }
  /**
   * Функция добавляет дискретный сигнал в конец вектора дискретных сигналов
   * @param signal дискретный сигнал, который нужно добавить
   */
  void PushDigital(DigitalSignal& signal) {
    digital_vector.push_back(signal);
  }
};


class ComtradeData {
  std::vector<std::vector<int32_t>> dataset_;
  std::unordered_map<int32_t, int32_t> timestamp_map_;
  std::vector<int32_t> buffer_vec;
  int32_t analog_count_;
  int32_t digital_count_;
  int32_t nrates_;
  float samp_;
  int64_t endsamp_;
 public:
  ComtradeData() = default;
  ComtradeData(int32_t analog_count, int32_t digital_count, int32_t nrates, float samp, int64_t endsamp);
  void AddData(int32_t timestamp, std::vector<int32_t>::iterator begin, std::vector<int32_t>::iterator end);

  const int32_t& GetAnalogCount() const { 
    return analog_count_; 
  }
  const int32_t& GetDigitalCount() const { 
    return digital_count_; 
  }
  const int32_t& GetNrates() const { 
    return nrates_; 
  }
  const float& GetSamp() const { 
    return samp_; 
  }
  const int64_t& GetEndSamp() const { 
    return endsamp_; 
  }
  const std::vector<int32_t>& GetDataLine(int32_t number, bool default_timestamp=true) const;
};

} // comtrade

#endif //COMTRADE_H
