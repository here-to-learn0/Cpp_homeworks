#include <cstdlib>
#include <iostream>
#include <iterator>
#include <random>

using namespace std;
int number_generator(int upper_limit) {
  std::random_device num;
  std::mt19937 generator(num());
  std::uniform_int_distribution<int> distribution(0, upper_limit);
  return distribution(generator);
}

int main() {
  const int upper_bound = 99;
  const int lower_bound = 0;
  int number_generated = number_generator(upper_bound);
  int i = 0;
  int number = 0;
  while (i == 0) {
    cout << "Enter the number: ";
    cin >> noskipws >> number;
    cin.ignore();
    if (cin.fail()) {
      cerr << "Error encountered, exiting...";
      cout << number_generated;
      exit(EXIT_FAILURE);
    } else if (number < lower_bound || number >= upper_bound) {
      cerr << "[WARNING] : Number must be between 0 and 99";
      cout << number_generated;
      exit(EXIT_FAILURE);
    } else if (number == number_generated) {
      cout << "Your are correct!" << endl;
      i++;
      cout << number_generated;
      exit(EXIT_SUCCESS);
    } else if (number <= number_generated) {
      cout << "Your number is smaller!" << endl;
    } else if (number >= number_generated) {
      cout << "Your number is greater!" << endl;
    }
  }
  return 0;
}
