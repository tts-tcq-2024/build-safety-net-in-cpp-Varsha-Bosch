#include <gtest/gtest.h>
#include "Soundex.h"


TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
}

TEST(SoundexTest, HandlesDifferentStartingCharacterSameSoundex) {
    EXPECT_EQ(generateSoundex("Robert"), "R163");
    EXPECT_EQ(generateSoundex("Rupert"), "R163");
}
     
TEST(SoundexTest, HandleLongName){
    EXPECT_EQ(generateSoundex("Ashcraft"),"A261");
   EXPECT_EQ(generateSoundex("Ashcroft"), "A261");
}
