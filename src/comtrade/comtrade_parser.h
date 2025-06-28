//
// Created by zagorodnikov on 02.04.2025.
//
#include "comtrade.h"

#ifndef COMTRADE_PARSER_H
#define COMTRADE_PARSER_H

namespace comtrade {

/**
 * Класс для парсинга файлов стандарта Comtrade
 */
class ComtradeParser {
 public:
  /**
   * Функция парсит объект типа ComtradeFile из файла .CFG стандарта IEC COMTRADE
   * @param адрес файла .CFG стандарта IEC COMTRADE
   * @return объект типа std::optional<ComtradeFile>
   */
  static std::optional<std::pair<ComtradeFile, ComtradeData>> Parse(const std::string& file_name);
};

} // comtrade

#endif //COMTRADE_PARSER_H
