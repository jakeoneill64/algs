#include "gtest/gtest.h"
#include "NthPalindromeLength.h"

#include <string>

TEST(nth_palindrome_suite, provided_examples) {
    const std::string with_palindromes{"memory ordering in programs is often a complex area to deal with. malayalam and madam are palindromes. refer c++ books"};
    const std::string no_palindromes{"hey i'm a no palindrome string"};

    ASSERT_EQ(getLengthOfNthPalindromeFromLast(with_palindromes, 3), 9);
    ASSERT_EQ(getLengthOfNthPalindromeFromLast(with_palindromes, 1), 5);
    ASSERT_EQ(getLengthOfNthPalindromeFromLast(with_palindromes, 5), -1);

    ASSERT_EQ(getLengthOfNthPalindromeFromLast(no_palindromes, 3), -1);

}

TEST(nth_palindrome_suite, further_cases) {
    const std::string with_palindromes{"Some words are not palindromes but words like deed rotor and stats are definitely palindromes."};

    ASSERT_EQ(getLengthOfNthPalindromeFromLast(with_palindromes, 3), 4);

}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}