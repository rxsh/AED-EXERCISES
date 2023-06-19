#include <iostream>
#include <thread>
#include <vector>

using namespace std;

struct CBinNode {
  CBinNode(int _v) {
    value = _v;
    nodes[0] = nodes[1] = nullptr;
  }
  int value;
  CBinNode *nodes[2];
};

void createBinaryTreeH(vector<int> &arr, int size, int index, CBinNode *&node) {
  if (size == 0) {
    node = nullptr;
    return;
  }

  int sum = 0;
  for (int i = index; i < index + size; i++) {
    sum += arr[i];
  }

  node = new CBinNode(sum);
  int leftSize = size / 2;
  int rightSize = size - leftSize - 1;

  thread leftThread(createBinaryTreeH, ref(arr), leftSize, index,
                    ref(node->nodes[0]));
  thread rightThread(createBinaryTreeH, ref(arr), rightSize,
                     index + leftSize + 1, ref(node->nodes[1]));

  leftThread.join();
  rightThread.join();
}

CBinNode *createBinaryTree(vector<int> &arr, int size, int index) {
  CBinNode *root;
  createBinaryTreeH(arr, size, index, root);
  return root;
}

void printBinaryTree(CBinNode *node, int level = 0) {
  if (node == nullptr) {
    return;
  }

  printBinaryTree(node->nodes[1], level + 1);
  for (int i = 0; i < level; i++) {
    cout << "   ";
  }
  cout << node->value << endl;
  printBinaryTree(node->nodes[0], level + 1);
}

int main() {
  vector<int> arr = {2, 4, 6, 8, 10, 12, 14, 16};
  int size = arr.size();
  CBinNode *root = createBinaryTree(arr, size, 0);
  printBinaryTree(root);

  return 0;
}
