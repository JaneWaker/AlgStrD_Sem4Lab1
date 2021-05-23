#include "CppUnitTest.h"
#include "..\AlgStrD_4sem_lab1\RB-Tree.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab1sem4test
{
	TEST_CLASS(Empty)
	{
	public:

		TEST_METHOD(insert_empty)
		{
			RedBlackTree<int, char> tree;
			tree.insert(3, 'c');
			Assert::AreEqual(tree.get_color(3), true);
		}

		TEST_METHOD(insert_1) {
			RedBlackTree<int, char> tree;
			for (int i = 1; i < 7; i++) {
				tree.insert(i, (char)i + 56);
			}
			Assert::AreEqual(tree.get_color(1), true);
			Assert::AreEqual(tree.get_color(2), true);
			Assert::AreEqual(tree.get_color(3), true);
			Assert::AreEqual(tree.get_color(4), false);
			Assert::AreEqual(tree.get_color(5), true);
			Assert::AreEqual(tree.get_color(6), false);
		}

		TEST_METHOD(remove_error) {
			RedBlackTree<int, char> tree;
			try {
				tree.remove(1);
			}
			catch (const exception& e) {
				Assert::AreEqual(e.what(), "Is empty");
			}
		}

		TEST_METHOD(size) {
			RedBlackTree<int, char> tree;
			Assert::AreEqual(tree.get_size(), 0);
		}
	};

	TEST_CLASS(NotEmpty) {
		RedBlackTree<int, char> tree;
		TEST_METHOD_INITIALIZE(setup) {
			for (int i = 1; i < 7; i++) {
				tree.insert(i, (char)i + 56);
			}
		}

		TEST_METHOD(size) {
			Assert::AreEqual(tree.get_size(), 6);
		}

		TEST_METHOD(find_error) {
			try {
				tree.find(123);
			}
			catch (exception e) {
				Assert::AreEqual(e.what(), "No element");
			}
		}

		TEST_METHOD(find1) {
			Assert::AreEqual(tree.find(3), (char)59);
		}

		TEST_METHOD(insert) {
			tree.insert(0, 'g');
			Assert::AreEqual(tree.get_size(), 7);
			Assert::AreEqual(tree.get_color(0), false);
		}

		TEST_METHOD(get_keys) {
			int* arr = new int[tree.get_size()];
			arr = tree.get_keys();
			Assert::AreEqual(arr[0], 3);
			Assert::AreEqual(arr[1], 2);
			Assert::AreEqual(arr[2], 4);
			Assert::AreEqual(arr[3], 1);
			Assert::AreEqual(arr[4], 5);
			Assert::AreEqual(arr[5], 6);
		}

		TEST_METHOD(get_values) {
			char* arr = new char[tree.get_size()];
			arr = tree.get_values();
			Assert::AreEqual(arr[0], (char)47);
			Assert::AreEqual(arr[1], (char)50);
			Assert::AreEqual(arr[2], (char)49);
			Assert::AreEqual(arr[3], (char)48);
			Assert::AreEqual(arr[4], (char)51);
			Assert::AreEqual(arr[5], (char)52);
		}

		TEST_METHOD(remove_error) {
			try {
				tree.remove(123);
			}
			catch (exception e) {
				Assert::AreEqual(e.what(), "No element");
			}
		}

		TEST_METHOD(remove_end) {
			tree.remove(6);
			Assert::AreEqual(tree.get_size(), 5);
			Assert::AreEqual(tree.get_color(1), true);
			Assert::AreEqual(tree.get_color(2), true);
			Assert::AreEqual(tree.get_color(3), true);
			Assert::AreEqual(tree.get_color(4), false);
			Assert::AreEqual(tree.get_color(5), true);
		}

		TEST_METHOD(remove_middle) {
			tree.remove(4);
			Assert::AreEqual(tree.get_size(), 5);
			Assert::AreEqual(tree.get_color(1), true);
			Assert::AreEqual(tree.get_color(2), true);
			Assert::AreEqual(tree.get_color(3), true);
			Assert::AreEqual(tree.get_color(5), false);
			Assert::AreEqual(tree.get_color(6), true);
		}

		TEST_METHOD(remove_root) {
			tree.remove(2);
			Assert::AreEqual(tree.get_size(), 5);
			Assert::AreEqual(tree.get_color(1), true);
			Assert::AreEqual(tree.get_color(3), true);
			Assert::AreEqual(tree.get_color(4), true);
			Assert::AreEqual(tree.get_color(5), false);
			Assert::AreEqual(tree.get_color(6), true);
		}

		TEST_METHOD(clear) {
			tree.clear();
			Assert::AreEqual(tree.get_size(), 0);
		}
	};
}