#include <iostream>
#include <numeric>
#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/xfeatures2d.hpp>

#include "homework_6.h"
#include "io_tools.hpp"
// using namespace igg;
namespace igg {
Image::Image(int rows, int cols) {
  rows_ = rows;
  cols_ = cols;
  data_.resize(rows * cols, 0);
}
int Image::rows() const {
  std::cout << rows_ << std::endl;
  return Image::rows_;
}
int Image::cols() const {
  std::cout << cols_ << std::endl;
  // std::cout << int(Image::data_.at(0));
  return Image::cols_;
}

int Image::at(const int& rows, const int& cols) const {
  return int(Image::data_.at(rows * Image::cols_ + cols));
}

uint8_t& Image::at(const int& rows, const int& cols) {
  return Image::data_.at(rows * Image::cols_ + cols);
}

void Image::PrintVec() {
  for (int i = 0; i < Image::rows_; ++i) {
    for (int j = 0; j < Image::cols_; ++j) {
      std::cout << (int)Image::data_.at(i * (Image::cols_) + j) << " ";
    }
    std::cout << std::endl;
  }
}
bool Image::FillFromPgm(const std::string& file_name) {
  Image::struct1 = igg::io_tools::ReadFromPgm(file_name);
  Image::rows_ = struct1.rows;
  Image::cols_ = struct1.cols;
  Image::data_ = struct1.data;
  Image::max_val = struct1.max_val;
  return true;
}
void Image::WriteToPgm(const std::string& file_name) {
  // Image::struct1;
  struct1.cols = Image::cols_;
  struct1.rows = Image::rows_;
  struct1.data = Image::data_;
  struct1.max_val = Image::max_val;
  igg::io_tools::WriteToPgm(struct1, file_name);
}
std::vector<float> Image::ComputeHistogram(int bins) const {  // histogram
  std::vector<float> hist;
  int max_num = Image::max_val;
  int bin_index = 0;
  hist.resize(bins, 0.0);
  float normalizer = 1.00F / (float)(Image::rows_ * Image::cols_);
  int bucket_size = (max_num / bins) + 1;
  // std::cout << bucket_size;
  for (const auto& intensity : Image::data_) {
    bin_index = int(intensity) / bucket_size;
    hist.at(bin_index) = hist.at(bin_index) + normalizer;
  }
  return hist;
}
void Image::DownScale(int scale) {
  int new_row = Image::rows_ / scale;
  int new_cols = Image::cols_ / scale;
  double row_ratio = scale;
  double col_ratio = scale;
  double px = NAN;
  double py = NAN;

  std::vector<uint8_t> temp;
  temp.resize(new_row * new_cols, 0);
  for (int i = 0; i < new_row; ++i) {
    for (int j = 0; j < new_cols; ++j) {
      px = floor(j * col_ratio);
      py = floor(i * row_ratio);
      temp.at((i * new_cols) + j) =
          Image::data_.at((int)(py * Image::cols_) + px);
    }
  }
  Image::rows_ = new_row;
  Image::cols_ = new_cols;
  Image::data_ = temp;
}

void Image::UpScale(int scale) {
  int new_row = Image::rows_ * scale;
  int new_cols = Image::cols_ * scale;
  double row_ratio = 1.0 / scale;
  double col_ratio = 1.0 / scale;
  std::cout << row_ratio << std::endl;
  double px = NAN;
  double py = NAN;

  std::vector<uint8_t> temp;
  temp.resize(new_row * new_cols, 0);
  for (int i = 0; i < new_row; ++i) {
    for (int j = 0; j < new_cols; ++j) {
      px = floor(j * col_ratio);
      py = floor(i * row_ratio);
      temp.at((i * new_cols) + j) =
          Image::data_.at((int)(py * Image::cols_) + px);
    }
  }
  Image::rows_ = new_row;
  Image::cols_ = new_cols;
  Image::data_ = temp;
}
};  // namespace igg
