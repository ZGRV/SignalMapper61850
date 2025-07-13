//
// Created by zagorodnikov on 02.04.2025.
//

#ifndef COMTRADE_H
#define COMTRADE_H

#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <utility>
#include <format>
#include <limits>

namespace comtrade {

class ComtradeData;
class ComtradeFile;


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
 * Объект класса создается на основе файла с расширением .CFG, описываемого в этом же стандарте
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
 * Объект класса создается на основе файла с расширением .CFG, описываемого в этом же стандарте
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

// Класс предоставляет интерфейс для инициализации атрибутов после создания объектов классов ComtradeData, ComtradeFile
class ComtradeInitializer {
public:
  // Реализует метод PushAnalog объекта класса ComtradeFile
  static void PushAnalog(ComtradeFile& comp_file, const AnalogSignal& signal);
  // Реализует метод PushDigital объекта класса ComtradeFile
  static void PushDigital(ComtradeFile& comp_file, const DigitalSignal& signal);
  // Реализует метод PushDataset объекта класса ComtradeFile
  static void PushDataset(ComtradeFile& comp_file, const ComtradeData& dataset);

  /**
   * Реализует метод PushData объекта класса ComtradeData
   * (Метод копирует значения из внешнего вектора и записывает их в атрибут dataset класса)
   * @param comp_data ссылка на объект класса ComtradeData
   * @param begin итератор начала копируемого вектора
   * @param end итератор конца копируемого вектора
   */
  static void PushData(ComtradeData& comp_data,
                       std::vector<int32_t>::iterator begin,
                       std::vector<int32_t>::iterator end);
};


// Класс создает объект, содержащий все данные из файла .DAT стандарта IEC COMTRADE
class ComtradeData {
  std::vector<std::vector<int32_t>> dataset_;
  std::vector<int32_t> buffer_vec_;
  int32_t analog_count_{};
  int32_t digital_count_{};
  int32_t nrates_{};
  std::vector<std::pair<float, int64_t>> vec_of_samps_;

  /**
   * Метод копирует значения из внешнего вектора и записывает их в атрибут dataset класса
   * @param begin итератор начала копируемого вектора
   * @param end итератор конца копируемого вектора
   */
  void PushData(std::vector<int32_t>::iterator begin, std::vector<int32_t>::iterator end);
  friend void ComtradeInitializer::PushData(ComtradeData& comp_data,
                                            std::vector<int32_t>::iterator begin,
                                            std::vector<int32_t>::iterator end);
 public:
  ComtradeData() = default;
  ComtradeData(int32_t analog_count, int32_t digital_count, int32_t nrates, const std::vector<std::pair<float, int64_t>>& vec_of_samps);

  // Геттер выборки аналоговых и дискретных значений по номеру выборки
  const std::vector<int32_t>& GetDataLineById(int32_t id) const;
  // Геттер выборки аналоговых и дискретных значений по метке времени
  const std::vector<int32_t>& GetDataLineByTimestamp(int32_t timestamp) const;
  // Геттер выборки аналоговых и дискретных значений по абсолютному времени
  const std::vector<int32_t>& GetDataLineByAbsTime(std::string data) const;

  // Геттер значения аналогового сигнала по номеру выборки и номеру сигнала
  int32_t GetAnalogSampById(int32_t id, int32_t an) const;
  // Геттер значения дискретного сигнала по номеру выборки и номеру сигнала
  bool GetDigitalSampById(int32_t id, int32_t dn) const;
  // Геттер значения аналогового сигнала по метке времени и номеру сигнала
  int32_t GetAnalogSampByTimestamp(int32_t timestamp, int32_t an) const;
  // Геттер значения дискретного сигнала по метке времени и номеру сигнала
  bool GetDigitalSampByTimestamp(int32_t timestamp, int32_t dn) const;
  // Геттер значения аналогового сигнала по абсолютному времени и номеру сигнала
  int32_t GetAnalogSampByAbsTime(std::string data, int32_t an) const;
  // Геттер значения дискретного сигнала по абсолютному времени и номеру сигнала
  bool GetDigitalSampByAbsTime(std::string data, int32_t dn) const;

};


// Класс создает объект, содержащий все данные из файла .CFG стандарта IEC COMTRADE
class ComtradeFile {
  std::string station_name_; // Название подстанции, или местонахождение подстанции, или место, где были записаны файлы. Критичные данные, буквенно-цифровые
  std::string rec_dev_id_; // Идентификационный номер или имя записывающего устройства. Критичные данные, буквенно-цифровые
  /**
   * Год редакции стандарта, указывающий версию файла COMTRADE. Критичные данные, целое число (1991/1999/2013).
   * При отсутвиии значения принимается как 1991 
   */
  std::string rev_year_ = "1991"; 
  int32_t TT_{}; // Общее количество каналов. Критичные данные, целое число
  int32_t analog_count_{}; // Количество аналоговых каналов, за которым следует идентификатор A. Критичные данные, буквенно-цифровые
  int32_t digital_count_{}; // Количество дискретных каналов, за которым следует идентификатор D. Критичные данные, буквенно-цифровые
  float lf_{}; // Номинальная частота в Гц сети, в которой были получены выборки. Критичные данные, действительное число
  int32_t nrates_{}; // Число частот дискретизации в файле данных. Критичные данные, целое число
  float samp_{}; // Частота дискретизации в Гц. Критичные данные, действительное число
  int64_t endsamp_{}; // Номер последней выборки на этой частоте дискретизации. Критичные данные, целое число
  std::vector<std::pair<float, int64_t>> vec_of_samps_; // Вектор пар частоты дискретизации и номера последней выборки (размер зависит от nrates_)
  TimeMark time_start_{}; // Время первого значения данных, содержащихся в файле данных (.DAT)
  TimeMark trigger_point_{}; // Время момента пуска записи осциллограммы (trigger point)
  std::string ft_; // Тип файла данных. Критичные данные, буквенная величина (ASCII/binary/binary32/float32)
  float timemult_{}; // Коэффициент умножения для поля разности времени (метки времени) в файле данных. Критичные данные, действительное число
  std::string time_code_; // Код времени, определенный в стандарте IEEE Std C37.232-2007. Критичные данные, буквенно-цифровые
  std::string local_code_; // Разность времени между местным часовым поясом места проведения записи и UTC; формат тот же, что и для time_code. Критичные данные, буквенно-цифровые
  char tmq_code_{}; // Код признака качества времени таймера записывающего устройства. Критичные данные, шестнадцатеричное число
  int8_t leapsec_{}; // Показатель корректировочной секунды (leap second). Критичные данные, целое число

  std::vector<AnalogSignal> analog_vector_; // Вектор состоящий из аналоговых сигналов
  std::vector<DigitalSignal> digital_vector_; // Вектор состоящий из цифровых сигналов
  
  ComtradeData comtrade_dataset_; // Объект класса, хранящего набор выборок из файла .DAT


  /**
   * Функция добавляет аналоговый сигнал в конец вектора аналоговых сигналов
   * @param signal аналоговый сигнал, который нужно добавить
   */
  void PushAnalog(const AnalogSignal& signal) {
    analog_vector_.push_back(signal);
  }
  friend void ComtradeInitializer::PushAnalog(ComtradeFile& comp_file, const AnalogSignal& signal);
  /**
   * Функция добавляет дискретный сигнал в конец вектора дискретных сигналов
   * @param signal дискретный сигнал, который нужно добавить
   */
  void PushDigital(const DigitalSignal& signal) {
    digital_vector_.push_back(signal);
  }
  friend void ComtradeInitializer::PushDigital(ComtradeFile& comp_file, const DigitalSignal& signal);
  /**
   * Функция добавляет выборку значений из файла .DAT
   * @param dataset выборка значений, которая должна соответсвовать параметрам из файла .CFG
   */
  void PushDataset(const ComtradeData& dataset) {
    comtrade_dataset_ = dataset;
  }
  friend void ComtradeInitializer::PushDataset(ComtradeFile& comp_file, const ComtradeData& dataset);
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
               const std::vector<std::pair<float, int64_t>>& vec_of_samps,
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
  const std::vector<std::pair<float, int64_t>>& GetVectorOfSamps() const {
    return vec_of_samps_;
  }
  /**
   * Возвращает samp из вектора значений.
   * @param num диапазон: 1 <= num <= nrates
   */
  const float& GetSamp(int32_t num) const { 
    return vec_of_samps_.at(num-1).first; 
  }
  /**
   * Возвращает endsamp из вектора значений.
   * @param num диапазон: 1 <= num <= nrates
   */
  const int64_t& GetEndSamp(int32_t num) const { 
    return vec_of_samps_.at(num-1).second; 
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
  const ComtradeData& GetDataset() const {
    return comtrade_dataset_;
  }
  /**
   * Функция возвращает аналоговый сигнал с порядковым номером an
   * @param an порядковый номер аналогового сигнала
   */
  const AnalogSignal& GetAnalogSignal(size_t an) const {
    return analog_vector_.at(an - 1);
  }
  /**
   * Функция возвращает дискретный сигнал с порядковым номером dn
   * @param dn порядковый номер дискретного сигнала
   */
  const DigitalSignal& GetDigitalSignal(size_t dn) const {
    return digital_vector_.at(dn - 1);
  }

};

} // comtrade

#endif //COMTRADE_H
