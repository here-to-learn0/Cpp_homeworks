#ifndef IMAGE_CLASS_HPP_
#define IMAGE_CLASS_HPP_

#include <string>
#include <vector>

#include "io_tools.hpp"
namespace igg {
class Image {
  igg::io_tools::ImageData struct1;
  int rows_ = 0;
  int cols_ = 0;
  uint8_t max_val = 0;
  std::vector<uint8_t> data_;

 public:
  Image() {
    rows_ = 0;
    cols_ = 0;
    data_.assign(rows_ * cols_, 0);
  }
  Image(int rows, int cols);
  void PrintVec();
  [[nodiscard]] int rows() const;
  [[nodiscard]] int cols() const;
  [[nodiscard]] int at(const int& rows, const int& cols) const;
  uint8_t& at(const int& rows, const int& cols);
  bool FillFromPgm(const std::string& file_name);  // reading from pgm
  void WriteToPgm(const std::string& file_name);   // writing to pgm
  [[nodiscard]] std::vector<float> ComputeHistogram(
      int bins) const;  // histogram
  void DownScale(int scale);
  void UpScale(int scale);
};
}  // namespace igg
#endif