#include "Soundex.h"
#include <cctype>
#include <unordered_map>

char getSoundexCode(char character) {
    static const std::unordered_map<char, char> soundexMapping = {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };

    character = toupper(character);
    auto lookupResult = soundexMapping.find(character);
    return lookupResult != soundexMapping.end() ? lookupResult->second : '0';
}


std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, toupper(name[0]));
    char previousCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) 
    {
        char currentCode = getSoundexCode(name[i]);
        if (currentCode != '0' && currentCode != previousCode)
        {
            soundex += currentCode;
            previousCode = currentCode;
        }
    }
    soundex.resize(4, '0');

    return soundex;
}
