#include <iostream>
#include <string>
using namespace std;

class cbuff {
 public:
  int* arr;
  int count, head, tail, size;
  cbuff(int size) {
    arr = new int[size];
    count = 0;
    head = size / 2 + 1;
    tail = size / 2;
    this->size = size;
  }
  void PushTail(int num) {
    if (tail + 1 == size)
      tail = 0;
    else
      tail++;
    arr[tail] = num;
    count++;
  }
  void PushHead(int num) {
    if (head - 1 < 0)
      head = size - 1;
    else
      head--;
    arr[head] = num;
    count++;
  }
  int PopTail() {
    int ret = arr[tail];
    if (tail - 1 < 0)
      tail = size - 1;
    else
      tail--;
    count--;
    return ret;
  }
  int PopHead() {
    int ret = arr[head];
    if (head + 1 == size)
      head = 0;
    else
      head++;
    count--;
    return ret;
  }
  void Print() {
    for (int i = head, j = head + count - 1; i <= j; i++) {
      if (i == size) {
        i = 0;
        j = tail;
      }
      cout << arr[i] << " ";
    }
    cout << "\n";
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  cbuff* kolkart = new cbuff(n * 2 + 1);
  cbuff* numperf = new cbuff(n * 2 + 1);
  for (int i = 1; i <= n; i++) {
    kolkart->PushTail(i);
    numperf->PushTail(-i);
  }
  for (int i = 0; i < m; i++) {
    char ch = cin.get();
    if (ch == '\n') {
      if (i > 0) break;
      i--;
      continue;
    }
    string temp = "";
    switch (ch) {
      case '0':
        continue;
        break;
      case '1':
        temp = "0001";
        break;
      case '2':
        temp = "0010";
        break;
      case '3':
        temp = "0011";
        break;
      case '4':
        temp = "0100";
        break;
      case '5':
        continue;
        break;
      case '6':
        temp = "0110";
        break;
      case '7':
        temp = "0111";
        break;
      case '8':
        temp = "1000";
        break;
      case '9':
        temp = "1001";
        break;
      case 'A':
        continue;
        break;
      case 'B':
        temp = "1011";
        break;
      case 'C':
        temp = "1100";
        break;
      case 'D':
        temp = "1101";
        break;
      case 'E':
        temp = "1110";
        break;
      case 'F':
        continue;
        break;
    }
    bool Vright = false, Vbott = false, Pright = false, Pbott = false;
    if (temp[0] == '1') {
      Vright = true;
    }
    if (temp[1] == '1') {
      Vbott = true;
    }
    if (temp[2] == '1') {
      Pright = true;
    }
    if (temp[3] == '1') {
      Pbott = true;
    }
    if (Vright) {
      if (numperf->count == 0) continue;
      int item = 0;
      if (Vbott) {
        item = numperf->PopTail();
      } else {
        item = numperf->PopHead();
      }
      if (Pright) {
        if (Pbott) {
          numperf->PushTail(item);
        } else {
          numperf->PushHead(item);
        }
      } else {
        if (Pbott) {
          kolkart->PushTail(item);
        } else {
          kolkart->PushHead(item);
        }
      }

    } else {
      if (kolkart->count == 0) continue;
      int item = 0;
      if (Vbott) {
        item = kolkart->PopTail();
      } else {
        item = kolkart->PopHead();
      }
      if (Pright) {
        if (Pbott) {
          numperf->PushTail(item);
        } else {
          numperf->PushHead(item);
        }
      } else {
        if (Pbott) {
          kolkart->PushTail(item);
        } else {
          kolkart->PushHead(item);
        }
      }
    }
  }

  cout << kolkart->count << ' ';
  kolkart->Print();
  cout << numperf->count << ' ';
  numperf->Print();
}