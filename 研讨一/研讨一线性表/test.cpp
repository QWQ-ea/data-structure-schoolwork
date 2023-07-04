#include"Node,LinkList.h"

int main() {
	int n;
	cout << "Please enter number of elements:";
	cin >> n;
	int* arr = new int[n];
	cout << "Please enter elements to the list:";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	LinkList<int> list(arr, n);

	int input;
	while (true) {
		cout << "Please enter a number to select a function: 0 - exit, 1 - GetLength, 2 - IsEmpty, 3 - Clear, 4 - Traverse, 5 - LocateElem, 6 - GetElem, 7 - SetElem, 8 - DeleteElem, 9 - Insert, 10 - Push_back: ";
		cin >> input;
		if (input == 0) {
			cout << "Program is terminated." << endl;
			break;
		}
		else if (input == 1) {
			cout << "The length of the list is " << list.GetLength() << endl;
		}
		else if (input == 2) {
			if (list.IsEmpty()) {
				cout << "The list is empty!" << endl;
			}
			else {
				cout << "The list is not empty!" << endl;
			}
		}
		else if (input == 3) {
			list.Clear();
			cout << "The list has been cleared." << endl;
		}
		else if (input == 4) {
			cout << "The list is: ";
			list.Traverse([](const int& element) { cout << element << " "; });
			cout << endl;
		}
		else if (input == 5) {
			int target;
			cout << "Please enter an element to be located: ";
			cin >> target;
			int result = list.LocateElem(target);
			if (result == -1) {
				cout << "The element is not found!" << endl;
			}
			else {
				cout << "The index of the element is " << result << endl;
			}
		}
		else if (input == 6) {
			int index;
			cout << "Please enter an index: ";
			cin >> index;
			Node<int>* result = list.GetElem(index);
			if (!result) {
				cout << "No such element found!" << endl;
			}
			else {
				cout << "The element is " << result->GetT() << endl;
			}
		}
		else if (input == 7) {
			int index;
			int element;
			cout << "Please enter an index and an element, separated by a space: ";
			cin >> index >> element;
			list.SetElem(index, element);
			cout << "The element at index " << index << " has been changed to " << element << endl;
		}
		else if (input == 8) {
			int index;
			cout << "Please enter an index: ";
			cin >> index;
			list.DeleteElem(index);
			cout << "The element at index " << index << " has been deleted." << endl;
		}
		else if (input == 9) {
			int index;
			int element;
			cout << "Please enter an index and an element, separated by a space: ";
			cin >> index >> element;
			list.Insert(index, element);
			cout << "The element " << element << " has been inserted at index " << index << endl;
		}
		else if (input == 10) {
			int element;
			cout << "Please enter an element: ";
			cin >> element;
			list.Push_back(element);
			cout << "The element " << element << " has been pushed back." << endl;
		}
		else {
			cout << "Invalid input!" << endl;
		}
	}

	delete[] arr;
	return 0;
}