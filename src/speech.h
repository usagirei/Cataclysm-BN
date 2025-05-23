#pragma once

#include "translations.h"

#include <string>

class JsonObject;

struct SpeechBubble {
    translation text;
    int volume;
};

void load_speech( const JsonObject &jo );
void reset_speech();
const SpeechBubble &get_speech( const std::string &label );


