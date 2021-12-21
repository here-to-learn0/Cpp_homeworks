#include <cstdio>
#include <filesystem>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include "homework_3.h"

using std::cout;
void html_writer::OpenDocument() {
  std::cout << "<!DOCTYPE html>" << std::endl;
  std::cout << "<html>" << std::endl;
}

void html_writer::AddTitle(const std::string& title) {
  std::cout << "<title>" << title << "</title>" << std::endl;
}
void html_writer::CloseDocument() { cout << "</html>\n" << std::endl; }

void html_writer::AddCSSStyle(const std::string& stylesheet) {
  std::cout << "<head>" << std::endl;
  std::cout << R"(<link rel="stylesheet" type="text/css" href=")" << stylesheet
            << R"(" />)" << std::endl;
  std::cout << "</head>" << std::endl;
}

void html_writer::OpenBody() { cout << "<body>" << std::endl; }

void html_writer::OpenRow() { cout << R"(<div class="row">)" << std::endl; }

void html_writer::AddImage(const std::string& img_path, float score,
                           bool highlight) {
  if ((score > 1.0 || score < 0.0) ||
      (std::filesystem::path(img_path).extension() != ".png" &&
       std::filesystem::path(img_path).extension() != ".jpg")) {
    std::cerr << "ERROR";
    // std::cout << R"(<div class="column">)" << std::endl;
    // std::cout << "<h2>filename.png</h2>" << std::endl;
    // std::cout << R"(<img src="data/filename.png" />)" << std::endl;
    // std::cout << "<p>score = 0.12";
    // std::cout << "</p>" << std::endl;
    // std::cout << "</div>" << std::endl;
  } else {
    if (highlight) {
      std::cout << R"(<div class="column" style="border: 5px solid green;">)"
                << std::endl;
    } else {
      std::cout << R"(<div class="column">)" << std::endl;
    }
    std::cout << "<h2>" << html_writer::FileNameWithExtension(img_path)
              << "</h2>" << std::endl;
    std::cout << R"(<img src=")" << img_path << R"(" />)" << std::endl;
    std::cout << "<p>score = ";
    std::cout << std::setprecision(2) << std::fixed << score;
    // fmt::print("{:.2f}", score);
    std::cout << "</p>" << std::endl;
    std::cout << "</div>" << std::endl;
  }
}

std::string html_writer::ExtractName(const std::string& img_path) {
  return std::filesystem::path(img_path).stem();
}

void html_writer::CloseBody() { cout << "</body>\n"; }
std::string html_writer::FileNameWithExtension(const std::string& img_path) {
  return std::filesystem::path(img_path).filename();
}

void html_writer::CloseRow() { cout << "</div>\n"; }

// int CheckExtension(const std::string& img_path) {
//   int check_png_jpg = 0;
//   std::stringstream filename{html_writer::FileNameWithExtension(img_path)};
//   int num = 0;
//   std::string ext;
//   filename >> num >> ext;
//   if (ext == ".png" || ext == ".jpg") {
//     check_png_jpg++;
//   }
//   return check_png_jpg;
// }
// void html_writer::AddImage(const std::string& img_path, float score,
//                            bool highlight) {
//   std::cout << "<div class=\" column \">\n";
//   if (highlight) {
//     cout << R"(style="border: 5px solid green;">)" << std::endl;
//   }
//   std::stringstream Photoname{img_path};
//   int num = 0;
//   std::string ext;
//   Photoname >> num >> ext;
//
//   std::cout << "</div>\n";
// }
// int html_writer::ExtractName(const std::string& img_path) {
//
// }