#include <iostream>

using namespace std;

class QueueLE {
public:
  int A[10], *ini = A, *fin = A + 9;
  int *head = nullptr, *tail = nullptr;
  int cont = 0;

  int push(int x) {

    if (cont == 10) {
      cout << " full queue " << endl;
      return 0;
    }

    if (head == NULL) {
      head = ini;
      *head = x;
      tail = head;
      cont++;
      cout << " start: " << *head << endl;
      return 1;
    }

    if (tail < fin) {
      tail++;
      *tail = x;
      cont++;
      cout << " add:  " << *tail << endl;
      return 1;
    }
    if (tail == fin && head > ini) {
      tail = ini;
      *tail = x;
      cont++;
      cout << " flip and add: " << *tail << endl;

      return 1;
    }
    return 1;
  }

  int pop() {
    int tmp = 0;
    if (head == NULL) {
      cout << " empty queue " << endl;
      return 0;
    }
    if (head == fin) {
      tmp = *head;
      head = ini;
      return tmp;
    }
    if (head == tail) {
      head = nullptr;
      tail = nullptr;
      return tmp;
    }
    tmp = *head;
    head++;
    cont--;
    cout << " delete: " << tmp << endl;
    cout << " new head: " << *head << endl;
    return tmp;
  }
};

int main() {

  QueueLE c;
  /*c.pop();
  c.push(10);
  c.push(20);
  c.push(30);
  c.pop();
  c.push(40);
  c.push(50);
  c.pop();
  c.push(60);
  c.push(70);
  c.push(80);*/

  for (int i = 0; i < 8; i++) {
    c.push(i);
  }
  for (int i = 0; i < 3; i++) {
    c.pop();
  }
  for (int i = 0; i < 7; i++) {
    c.push(i);
  }
  return 0;
}