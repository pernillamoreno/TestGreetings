/**
 * @file main.cpp

 * @brief 
 *Using TDD and googletest develop and test a greeting function according to the following requirements.

    The function prototype shall be: const std::string &greet(const std::string &name);
        The function shall interpolate the name in a simple greeting
            For example, if name is "Bob", the method shall return a string "Hello, Bob.".
        The function shall handle nulls.
            For example, if name is an empty string, then the method shall return the string "Hello, my friend."
        The function shall handle shouting. If name is all uppercase, then it should shout back to the user.
            For example, if name is "JERRY", the method shall return the string "HELLO JERRY!"
        The function shall handle two names. If name is a string of two names, then both names should be printed.
            For example, if name is "Jill, Jane", the method shall return the string "Hello, Jill and Jane."
        The function shall handle an arbitrary number of names.  If name represents more than two names, separate them with commas and close with an Oxford comma and "and".
            For example, if name is "Amy, Brian, Charlotte", the method shall return the string "Hello, Amy, Brian, and Charlotte."
        The function shall allow mixing of normal and shouted names by separating the response into two greetings.
            For example, if name is "Amy, BRIAN, Charlotte", the method shall return the string "Hello, Amy and Charlotte. AND HELLO BRIAN!"
    To build and run the test, use a cmake file.
 * dod
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <gtest/gtest.h> 
#include "greet.h"

// Unit tests for the greeting strategies
TEST(GreetingTest, EmptyName) {
    SimpleGreet greeter; // Create an instance of SimpleGreet
    EXPECT_EQ("Hello, my friend.", greeter.greet("")); // Test empty name greeting
}

TEST(GreetingTest, SingleName) {
    SimpleGreet greeter; // Create an instance of SimpleGreet
    EXPECT_EQ("Hello, Bob", greeter.greet("Bob")); // Test single name greeting
}
TEST(GreetingTest, ShoutName){
    ShoutNameGreet greeter;
    EXPECT_EQ("HELLO JERRY!", greeter.greet("JERRY"));
}

TEST(GreetingTest, twoNames){
    MultiNamesGreet greeter;
    EXPECT_EQ("Hello, Jill and Jane.", greeter.greet("Jill and Jane"));
}

TEST(GreetingTest, MultipleNames) {
    MultiNamesGreet greeter; 
    EXPECT_EQ("Hello, Amy, Brian, and Charlotte.", greeter.greet("Amy,Brian,Charlotte")); // Test multiple names greeting
}


// Main function to run all the tests
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv); // Initialize Google Test
    return RUN_ALL_TESTS(); // Run all tests and return the result
}

