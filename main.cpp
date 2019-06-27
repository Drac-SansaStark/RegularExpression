#include <iostream>
#include <regex>
#include <string>

int main(int argc, char *argv[]) {
    std::string line;
#if 0
    std::regex email(R"(\w+@(\w+\.)+\w+)");
    while (std::getline(std::cin, line)) {
        /**
         * If successful, it is not empty and contains a series of sub_match objects:
         * the first sub_match element corresponds to the entire match,
         * and, if the regex expression contained sub-expressions to be matched (i.e., parentheses-delimited groups),
         * their corresponding sub-matches are stored as successive sub_match elements in the match_results object.
         * */

        std::smatch matches;
        auto current = line.cbegin();
        auto last = line.cend();
        while (current != last) {
            if (std::regex_search(current, last, matches, email)) {
                // 第一个元素是整个匹配结果，也即是match.str(0)
                std::ssub_match match = matches[0];
                current = match.second;
                std::cout << match.str() << std::endl;
            } else {
                break;
            }
        }

    }
#elif 0
    std::regex words(R"((\S+))");
    while (std::getline(std::cin, line)) {
        auto wordsBegin = std::sregex_iterator(line.cbegin(), line.cend(), words);
        auto wordsEnd = std::sregex_iterator();
        std::cout << "Numbers of Words: " << std::distance(wordsBegin, wordsEnd) << std::endl;
        for (auto i = wordsBegin; i != wordsEnd; ++i) {
            std::smatch match = *i;
            std::cout << match.str() << std::endl;
        }
    }
#else
    // \w{7,}中逗号没有空格，否则会报错
    std::regex longWords(R"((\w{7,}))");
    while (std::getline(std::cin, line)) {
        // 替换字符串
        std::cout << std::regex_replace(line, longWords, "[$&]") << std::endl;
    }
#endif
    return 0;
}