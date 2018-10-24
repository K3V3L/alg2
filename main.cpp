#include <iostream>
void MergeSort(int arr[], int l, int r);
void Merge(int arr[], int l, int m, int r);
void generateArr(int *arr, int n, int range, int type);
void printArr(int arr[], int n);
void swap(int *x, int *y);
void stoogesort(int arr[], int l, int h);
static int CompCNT = 0, CopyCNT = 0;
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
  std::cout << "\nChoose sort method:\n"
               "1.Stoogesort\n"
               "2.Merge sort\n";
  int *temp = new int;
  do {
    std::cin >> *temp;
  } while (*temp < 1 || *temp > 2);
  switch (*temp) {
  case 1:
    std::cout << "\tStooge sort\nInitial array is\n";
    printArr(arr, n);
    std::cout << "\nPress any button to sort:";
    std::cin.ignore();
    std::cin.get();
    stoogesort(arr, 0, n - 1);
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
  std::cout << std::endl << "Compares: " << CompCNT << "\tCopys: " << CopyCNT;
  std::cout << std::endl;
  delete (temp);
  return 0;
}

void MergeSort(int arr[], int l, int r) {
    CompCNT++;
  if (r <= l)return;
  {
    int m = (r + l) / 2;
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
    CompCNT+=3;
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
    CompCNT++;
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    CompCNT++;
    arr[k] = R[j];
    j++;
    k++;
  }
}
void stoogesort(int arr[], int l, int h) {
  CompCNT++;
  if (l >= h) {
    return;
  }
  CompCNT++;
  if (arr[l] > arr[h]) {
    swap(&arr[l], &arr[h]);
    CopyCNT++;
  }
  CompCNT++;
  if (h - l + 1 > 2) {
    int t = (h - l + 1) / 3;
    stoogesort(arr, l, h - t);
    stoogesort(arr, l + t, h);
    stoogesort(arr, l, h - t);
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
