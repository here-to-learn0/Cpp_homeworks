#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
  string first_argument;
  string second_argument;
  if (argc != 3) {
    cerr << "Error encountered!!" << endl;
    return 1;
  }
  first_argument = argv[1];
  second_argument = argv[2];

  stringstream filename0{first_argument};

  stringstream filename1{second_argument};
  int num0 = 0;
  int num1 = 0;
  string ext0;
  string ext1;
  filename0 >> num0 >> ext0;
  filename1 >> num1 >> ext1;
  if (ext0 == ".txt" && ext1 == ".txt") {
    cout << (num0 + num1) / 2 << endl;
  } else if (ext0 == ".png" && ext1 == ".png") {
    cout << num0 + num1 << endl;
  } else if (ext0 == ".txt" && ext1 == ".png") {
    cout << num0 % num1 << endl;
  } else {
    cerr << "Error encountered again man!" << endl;
    return 1;
  }
  return 0;
}