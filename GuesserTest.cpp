/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

/* Example test
TEST(GuesserTest, smoke_test)
{
    ASSERT_EQ( 1+1, 2 );
}
*/

TEST(GuesserTest, constructor_test){
    Guesser my_guesser("Hello!");
    bool actual = my_guesser.match("Hello!");
    ASSERT_EQ(true, actual);
}

TEST(GuesserTest, non_match_test){
    Guesser my_guesser("Hello!");
    bool actual = my_guesser.match("Hello");
    ASSERT_EQ(false, actual);
}

TEST(GuesserTest, timeout_test){
    Guesser my_guesser("Hello!");
    my_guesser.match("a");
    my_guesser.match("a");
    my_guesser.match("a");
    bool actual = my_guesser.match("Hello!");
    ASSERT_EQ(false, actual);
}

TEST(GuesserTest, third_try_test){
    Guesser my_guesser("Hello!");
    my_guesser.match("Hello");
    my_guesser.match("Hello");
    bool actual = my_guesser.match("Hello!");
    ASSERT_EQ(true, actual);
}

TEST(GuesserTest, third_and_sixth_test){
    Guesser my_guesser("Hello!");
    my_guesser.match("Hello");
    my_guesser.match("Hello");
    my_guesser.match("Hello!");
    my_guesser.match("Hello");
    my_guesser.match("Hello");
    bool actual = my_guesser.match("Hello!");
ASSERT_EQ(true, actual);
}

TEST(GuesserTest, big_distance_test){
    Guesser my_guesser("Hello!");
    my_guesser.match("RJ");
    bool actual = my_guesser.match("Hello!");
    ASSERT_EQ(false, actual);
}

TEST(GuesserTest, empty_test){
    Guesser my_guesser("");
    bool actual = my_guesser.match("");
    ASSERT_EQ(true, actual);
}

TEST(GuesserTest, repetition_test){
    Guesser my_guesser("");
    my_guesser.match("");
    my_guesser.match("");
    my_guesser.match("");
    my_guesser.match("");
    my_guesser.match("");
    my_guesser.match("");
    my_guesser.match("");
    my_guesser.match("");
    my_guesser.match("");
    my_guesser.match("");
    bool actual = my_guesser.match("");
    ASSERT_EQ(true, actual);
}

TEST(GuesserTest, slam_test){
    Guesser my_guesser("!!nAghjNH^*&");
    bool actual = my_guesser.match("!!nAghjNH^*&");
    ASSERT_EQ(true, actual);
}
TEST(GuesserTest, guess_too_long_test){ //should guesses also be truncated???
    Guesser my_guesser("lllllllllllllllllllllllllllllllll");
    bool actual = my_guesser.match("lllllllllllllllllllllllllllllllll");
    ASSERT_EQ(false, actual);
}

TEST(GuesserTest, guess_too_long_at_first_test){ //should guesses also be truncated???
    Guesser my_guesser("lllllllllllllllllllllllllllllllll");
    my_guesser.match("lllllllllllllllllllllllllllllllll");
    bool actual = my_guesser.match("llllllllllllllllllllllllllllllll");
ASSERT_EQ(true, actual);
}

TEST(GuesserTest, truncate_test){
    Guesser my_guesser("llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll");
    bool actual = my_guesser.match("llllllllllllllllllllllllllllllll");
    ASSERT_EQ(true, actual);
}

TEST(GuesserTest, line_27_test){
    Guesser my_guesser("Hi");
    bool actual = my_guesser.match("Bi   ");
    ASSERT_EQ(false, actual);
}

// ./GuesserTest