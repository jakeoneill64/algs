#include <cinttypes>
#include <string>
#include <sstream>
#include <vector>

bool isPalindrome(const std::string& potentialPalindrome)
{
    size_t left = 0;
    size_t right = potentialPalindrome.size() - 1;

    while (left < right) {
        // Compare characters case-insensitively
        if (std::tolower(potentialPalindrome[left]) != std::tolower(potentialPalindrome[right])) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

int32_t getLengthOfNthPalindromeFromLast(const std::string& inputText, u_int32_t n)
{

    std::stringstream streamedInput{inputText};
    std::string token;
    std::vector<std::string> tokenVector{};
    while (std::getline(streamedInput, token, ' ')) {
        tokenVector.push_back(std::move(token));
    }
    for(auto palindromesFound{0}; !tokenVector.empty();){

        const std::string& currentToken{tokenVector.back()};
        if(!isPalindrome(currentToken)){
            // don't pop until we don't need the value anymore.
            tokenVector.pop_back();
            continue;
        }
        if(++palindromesFound ==  n) {
            return int32_t(currentToken.size());
        }
        tokenVector.pop_back();
    }
    return -1;
}