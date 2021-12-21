#include <cstdio>
#include <filesystem>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include "homework_3.h"

void image_browser::AddFullRow(const ImageRow &row, bool first_row) {
  if (first_row) {
    html_writer::OpenRow();
    for (const auto &i : row) {
      if (first_row && i == row[0]) {
        html_writer::AddImage(std::get<0>(i), std::get<1>(i), true);
      } else {
        html_writer::AddImage(std::get<0>(i), std::get<1>(i), false);
      }
    }
    // html_writer::AddImage(std::get<0>(row[0]), std::get<1>(row[0]), true);
    // html_writer::AddImage(std::get<0>(row[1]), std::get<1>(row[1]), false);
    // html_writer::AddImage(std::get<0>(row[2]), std::get<1>(row[2]), false);
    html_writer::CloseRow();
  } else {
    html_writer::OpenRow();
    for (const auto &i : row) {
      html_writer::AddImage(std::get<0>(i), std::get<1>(i), false);
    }
    html_writer::CloseRow();
  }
}

void image_browser::CreateImageBrowser(const std::string &title,
                                       const std::string &stylesheet,
                                       const std::vector<ImageRow> &rows) {
  html_writer::OpenDocument();
  html_writer::AddTitle(title);
  html_writer::AddCSSStyle(stylesheet);
  html_writer::OpenBody();
  for (const auto &i : rows) {
    if (i == rows[0]) {
      AddFullRow(i, true);
    } else {
      AddFullRow(i, false);
    }
  }
  // AddFullRow(rows[0], true);
  // AddFullRow(rows[1], false);
  // AddFullRow(rows[2], false);

  html_writer::CloseBody();
  html_writer::CloseDocument();
}
