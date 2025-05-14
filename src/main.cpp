//
// Created by zagorodnikov on 02.04.2025.
//

#include <iostream>
#include <string>
#include "comtrade/comtrade.h"
#include "comtrade/comtrade_parser.h"

int main() {
  //std::cout << "Hello, World!" << std::endl;
  comtrade::ComtradeParser parser_instance;
  std::string file_name;
  std::optional<comtrade::ComtradeFile> buff = parser_instance.Parse(file_name);
  try {
    comtrade::ComtradeFile comp_file = buff.value();
    std::cout << comp_file.GetTriggerPoint().GetYear() << std::endl;
    std::cout << comp_file.GetDigitalSignal(8).GetChId() << std::endl;
    std::cout << comp_file.GetEndSamp() << " " << comp_file.GetFt() << std::endl;
  } catch(const std::bad_optional_access& e) {
      std::cerr << "ComtrFile does not exist" << std::endl;
  }
  return 0;
}
