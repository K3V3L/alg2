#include <iostream>
void GnomeSort(int arr[], int n);
void MergeSort(int arr[], int l, int r);
void Merge(int arr[], int l, int m, int r);
void generateArr(int *arr, int n, int range, int type);
void printArr(int arr[], int n);
void swap(int *x, int *y);
int main() {
  std::cout << "Enter array size:" << std::endl;
  int n;
  do {
    std::cin >> n;
  } while (n < 2);
  std::cout << "Enter value range:" << std::endl;
  int range;
  do {
    std::cin >> range;
  } while (range < 2);
  int type;
  std::cout << "Enter array type:\n"
               "1.Sorted\n"
               "2.Reverse Sorted\n"
               "3.Random"
            << std::endl;
  do {
    std::cin >> type;
  } while (type < 0 || type > 3);
  int *arr = new int[n];
  generateArr(arr, n, range, type);
  std::cout << "Choose sort method:\n"
               "1.Gnome sort\n"
               "2.Merge sort\n";
  int *temp = new int;
  do {
    std::cin >> *temp;
  } while (*temp < 1 || *temp > 2);
  switch (*temp) {
  case 1:
    std::cout << "\tGnome sort\nInitial array is\n";
    printArr(arr, n);
    std::cout << "\nPress any button to sort:";
    std::cin.ignore();
    std::cin.get();
    GnomeSort(arr, n);
    std::cout << "Sorted array:\n";
    printArr(arr, n);
    break;
  case 2:
    std::cout << "\tMerge sort\nInitial array is\n";
    printArr(arr, n);
    std::cout << "\nPress any button to sort:";
    std::cin.ignore();
    std::cin.get();
    MergeSort(arr, 0, n - 1);
    std::cout << "Sorted array:\n";
    printArr(arr, n);
    break;
  default:
    break;
  }
  std::cout << std::endl;
  delete (temp);
  return 0;
}
void GnomeSort(int arr[], int n) {
  int cmpCounter = 0, swapCounter = 0;
  int index = 0;
  while (index < n) {
    if (index == 0) {
      index++;
      cmpCounter++;
    }
    if (arr[index] >= arr[index - 1]) {
      index++;
      cmpCounter++;
    } else {
      swap(&arr[index], &arr[index - 1]);
      swapCounter++;
      index--;
    }
  }
  std::cout << "Compares\tswaps\n"
            << cmpCounter << "\t\t" << swapCounter << std::endl;
}
void MergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    MergeSort(arr, l, m);
    MergeSort(arr, m + 1, r);

    Merge(arr, l, m, r);
  }
}
void Merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  int *L = new int[n1];
  int *R = new int[n2];
  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];
  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}
void generateArr(int *arr, int n, int range, int type) {
  switch (type) {
  case 1:
    for (int i = 0; i < n; i++) {
      arr[i] = (i + 1) * range / n;
    }
    std::cout << "Sorted array generated:\n";
    printArr(arr, n);
    break;
  case 2:
    for (int i = 0; i < n; i++) {
      arr[i] = (n - i) * range / n;
    }
    std::cout << "Reverse sorted array generated:\n";
    printArr(arr, n);
    break;
  case 3:
    for (int i = 0; i < n; i++) {
      arr[i] = rand() % range;
    }
    std::cout << "Random array generated:\n";
    printArr(arr, n);
    break;
  default:
    break;
  }
}
void printArr(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << "\t";
  }
}
void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}
