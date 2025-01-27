// Recursive function to count the number of occurrences of a specific element in an array
#include <iostream>

// Function to count occurrences of a specific element in an array
int countOccurrences(int nums[], int size, int element) {
  // Base case: if the array is empty, return 0
  if (size == 0)
    return 0;

  // Recursive case: if the first element matches the target element,
  // increment the count and recursively search in the rest of the array
  if (nums[0] == element)
    return 1 + countOccurrences(nums + 1, size - 1, element);
  else
    return countOccurrences(nums + 1, size - 1, element);
}

int main() {
  int nums[] = {3, 4, 5, 7, 3, 9, 5, 3, 5, 9, 3, 4, 3, 5};
  int size = sizeof(nums) / sizeof(nums[0]);
  std::cout << "Array elements: " << std::endl;
  // loop through the array elements
  for (size_t i = 0; i < size; i++) {
    std::cout << nums[i] << ' ';
  }

  int element;
  std::cout << "\nCount the number of occurrences of a specific element in the said array:";
  std::cout << "\nInput an element: ";
  std::cin >> element;

  // Count the occurrences of the element using recursion
  int count = countOccurrences(nums, size, element);

  std::cout << "Number of occurrences of " << element << ": " << count << std::endl;

  return 0;
}