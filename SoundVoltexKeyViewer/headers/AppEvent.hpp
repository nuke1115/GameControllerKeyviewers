#ifndef APP_EVENT_HEADER_N
#define APP_EVENT_HEADER_N

namespace Containers
{
    struct AppEvent
    {
        bool ButtonStates[7] = { false }; // 0~3 => bt 4~5 => fx 6 => start
        int ButtonCountValues[6] = { 0 }; // 0~3 => bt 4~5 => fx
        float KnobStates[2] = { 0.0f,0.0f }; // 0 => knobL 1 => knobR
        bool TerminateEvent = false; //true => terminate program
        bool SettingModeEntryEvent = false;
        bool SettingModeOn = false;
        bool SettingModeGoNextEvent = false;
        unsigned int SettingModeButtonIndex = 0;
        unsigned int SettingModeKnobIndex = 0;

    };
}

#endif // !APP_EVENT_HEADER_N
