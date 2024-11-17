#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <set>

void    problem_1()
{
    std::string input;
    std::cout << "Problem 1:\n" << "Enter a string: "; // "a{1+{2}+3}b{4}c"
    std::cin >> input;
    std::string result;
    std::copy_if(   begin(input), 
                    end(input), 
                    std::back_inserter(result), 
                    [](char c) { return std::isalpha(c); });
    std::cout << "The result string is: " << result << std::endl;
}

void    problem_2()
{
    std::string input;
    std::cout << "Problem 2:\n" << "Enter a string: "; // "abbbcaaaad"
    std::cin >> input;
    std::string result;
    auto it = begin(input);
    while (it != end(input))
    {
        auto current = *it;
        auto next = std::find_if(   it, 
                                    end(input),
                                    [current] (char c) { return c != current; });
        
        result += current;
        auto count = std::distance(it, next);
        if (count > 1)
            result += "(" + std::to_string(count) + ")";

        it = next;
    }
    std::cout << "The result string is: " << result << std::endl;
}

void    problem_3()
{
    std::string input;
    std::cout << "Problem 3:\n" << "Enter a string: "; // "alpha gamma alpha delta gamma beta alpha"
    std::getline(std::cin, input);

    std::istringstream stream(input);
    std::vector<std::string> words;

    std::copy(std::istream_iterator<std::string>(stream),
                 std::istream_iterator<std::string>(),
                 std::back_inserter(words));

    std::set<std::string> unique_words;
    std::vector<std::string> result;

    std::copy_if(   begin(words),
                    end(words),
                    std::back_inserter(result),
                    [&unique_words] (const std::string& word) 
                    { return unique_words.insert(word).second; });

    std::cout << "The result string is: ";
    for (const auto& word : result)
        std::cout << word << " ";
    std::cout << std::endl;
}

int main()
{
    problem_1();
    problem_2();
    problem_3();
    
    return 0;
}