#include "..\Alert.h"


void Alert::MakeAlertFIle(const std::vector<int>& errorCode)
{
    std::ofstream file("../SoundVoltexKeyViewer/Logs/ERRORS.txt");

    file << "===============================\n";

    for (auto& i : errorCode)
    {

        if (i == ErrorCode::ERR_IN_LOAD_FILE)
        {
            file << "ERROR IN LOAD FILE\n";
        }

        if (i == ErrorCode::ERR_IN_CONTROLLER_CONNECTION)
        {
            file << "ERROR IN CONTROLLER CONNECTION\n";
        }
        
    }
    file.close();
}