#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
using namespace std;

void kill_spaces(string& data) {
  data.erase(remove(data.begin(), data.end(), ' '),
                   data.end());
}

double mult_div(const char*& data);
double min_plus(const char*& data);

double ckob_pref(const char*& data) {
  const auto mesto = data[0];

  if (isdigit(mesto)) {
    return strtod(data, (char**)(&data));
  }

  if (mesto == '-') {
    return -ckob_pref(++data);
  }

  if (mesto == '+') {
    return ckob_pref(++data);
  }

  if (mesto == '(') {
    const auto rez = min_plus(++data);
    if (*data++ == ')') return rez;
  }

}

double min_plus(const char*& data) {
  double rez = mult_div(data);
  while (true) {
    switch (*data) {
      case 0:
        return rez;
      case '+':
        rez += mult_div(++data);
        break;
      case '-':
        rez -= mult_div(++data);
        break;
      default:
        return rez;
    }
  }
}

double mult_div(const char*& data) {
  double rez = ckob_pref(data);
  while (true) {
    switch (*data) {
      case 0:
        return rez;
      case '*':
        rez *= ckob_pref(++data);
        break;
      case '/':
        rez /= ckob_pref(++data);
        break;
      default:
        return rez;
    }
  }
}

double eval(const string& data) {
  auto ptr = data.data();
  return min_plus(ptr);
}

int main() {
  string buff;
  getline(cin, buff);
  kill_spaces(buff);
  cout << fixed << setprecision(10) << eval(buff) << endl;
}