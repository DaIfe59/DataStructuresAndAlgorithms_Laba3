#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2\catch.hpp>
#include "TESTFOR3/OneList.h" 

unsigned int Factorial(unsigned int number) {
	return number <= 1 ? number : Factorial(number - 1) * number;
}
TEST_CASE("constructor", "[OneList]") {
	OneList<int> list;
	REQUIRE(list.size() == 0);
}

TEST_CASE("copy constructor", "[OneList]") {
    OneList<int> originalList;
    originalList.push_back(1);
    originalList.push_back(2);
    originalList.push_back(3);
    OneList<int> copiedList(originalList);
    REQUIRE(copiedList.size() == originalList.size());
    for (int i = 0; i < originalList.size(); i++) {
        REQUIRE(copiedList[i] == originalList[i]);
    }
}

TEST_CASE("destructor", "[OneList]") {
    OneList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    REQUIRE(list.size() > 0);
    list.~OneList();
    REQUIRE(list.size() == 0);
}

TEST_CASE("push_front", "[OneList]") {
    OneList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    REQUIRE(list.size() == 3);
    REQUIRE(list[0] == 3);
    REQUIRE(list[1] == 2);
    REQUIRE(list[2] == 1);
}

TEST_CASE("push_back", "[OneList]") {
    OneList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    REQUIRE(list.size() == 3);
    REQUIRE(list[0] == 1);
    REQUIRE(list[1] == 2);
    REQUIRE(list[2] == 3);
}

TEST_CASE("insert", "[OneList]") {
    // Create a OneList object
    OneList<int> list;

    // Add elements to the list using push_back
    list.push_back(1);
    list.push_back(3);

    // Insert an element at index 1
    list.insert(1, 2);

    // Check if the size of the list is correct
    REQUIRE(list.size() == 3);

    // Check if the elements are in the correct order
    REQUIRE(list[0] == 1);
    REQUIRE(list[1] == 2);
    REQUIRE(list[2] == 3);
}

TEST_CASE("pop_front", "[OneList]") {
    OneList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_front();
    REQUIRE(list.size() == 2);
    REQUIRE(list[0] == 2);
    REQUIRE(list[1] == 3);
}

TEST_CASE("pop_back", "[OneList]") {
    OneList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_back();
    REQUIRE(list.size() == 2);
    REQUIRE(list[0] == 1);
    REQUIRE(list[1] == 2);
}

TEST_CASE("remove", "[OneList]") {
    OneList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.remove(2);
    REQUIRE(list.size() == 2);
    REQUIRE(list[0] == 1);
    REQUIRE(list[1] == 3);
}

TEST_CASE("clear", "[OneList]") {
    OneList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.clear();
    REQUIRE(list.size() == 0);
}

TEST_CASE("front", "[OneList]") {
    OneList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    int frontElement = list.front();
    REQUIRE(frontElement == 1);
}

TEST_CASE("back ", "[OneList]") {
    OneList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    int backElement = list.back();
    REQUIRE(backElement == 3);
}

TEST_CASE("size", "[OneList]") {
    OneList<int> list;
    REQUIRE(list.size() == 0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    REQUIRE(list.size() == 3);
}

TEST_CASE("operator[]", "[OneList]") {
    OneList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    int element1 = list[0];
    int element2 = list[1];
    int element3 = list[2];
    REQUIRE(element1 == 1);
    REQUIRE(element2 == 2);
    REQUIRE(element3 == 3);
}

TEST_CASE("increment and decrement", "[OneList]") {
    OneList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    ++list;
    REQUIRE(list.size() == 3);
    --list;
    REQUIRE(list.size() == 3);
}
TEST_CASE("Factorials are computed", "[factorial]") {
	REQUIRE(Factorial(1) == 1);
	REQUIRE(Factorial(2) == 2);
	REQUIRE(Factorial(3) == 6);
	REQUIRE(Factorial(10) == 3628800);
}