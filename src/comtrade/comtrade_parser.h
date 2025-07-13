//
// Created by zagorodnikov on 02.04.2025.
//

#ifndef COMTRADE_PARSER_H
#define COMTRADE_PARSER_H

#include "comtrade.h"

namespace comtrade {

/**
 * Класс для парсинга файлов стандарта Comtrade
 */
class ComtradeParser {
 public:
  /**
   * Функция парсит объект типа ComtradeFile из файла .CFF стандарта IEC COMTRADE
   * @param file_name Имя файла .CFF стандарта IEC COMTRADE
   * @return Объект типа std::optional<ComtradeFile>
   */
  static std::optional<ComtradeFile> Parse(const std::string& file_name);
};

} // comtrade

#endif //COMTRADE_PARSER_H
