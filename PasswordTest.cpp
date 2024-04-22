/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, no_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}


TEST(PasswordTest, weird_letter_pwd)
{
	Password my_password;
	int actual = my_password.count_leading_characters("[[[[[[[[989073204987123321/][ckmlx,palj]");
	ASSERT_EQ(8, actual);
}

TEST(PasswordTest, escape_letter_pwd) 
{
	Password my_password;
	int actual = my_password.count_leading_characters("\\\\");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, hex_letter_pwd) 
{
	Password my_password;
	int actual = my_password.count_leading_characters("\x8C\x8C");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, tricky_letter_pwd) //tricky test
{
	Password my_password;
	int actual = my_password.count_leading_characters("AAaBAAA");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, simple_mixer) 
{
	Password my_password;
	bool actual = my_password.has_mixed_case("AA");
	ASSERT_EQ(false, actual);
}
TEST(PasswordTest, simple_mixer2) 
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Aa");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, large_mixer) 
{
	Password my_password;
	bool actual = my_password.has_mixed_case("AAeeeAEeX");
	ASSERT_EQ(true, actual);
}
TEST(PasswordTest, large_mixer2) 
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aeeeeexeea");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, large_mixer_tricky) 
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aeeeeexeea!!!!^");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, large_mixer_tricky2) 
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aEeeeexeea!!&!^");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, large_mixer_tricky3) 
{
	Password my_password;
	bool actual = my_password.has_mixed_case("!!!!!!!!!");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, large_mixer_tricky4) 
{
	Password my_password;
	bool actual = my_password.has_mixed_case("!!...!!");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, set1) 
{
	Password my_password;
	my_password.set("Abcdefghi");
	bool actual = my_password.authenticate("Abcdefghi");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, combined1) 
{
	Password my_password;
	my_password.set("Abcdefghi");
	bool actual = my_password.authenticate("Abcdefghi");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, combined2) 
{
	Password my_password;
	my_password.set("abcdefghi");
	bool actual = my_password.authenticate("abcdefghi");
	ASSERT_EQ(false, actual);
}