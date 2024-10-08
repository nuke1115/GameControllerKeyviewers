//defined _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
#include <vector>
#include "..\headers\Application.hpp"
#include "..\headers\Alert.h"
#include "..\headers\ErrorCode.hpp"

int main()
{
    Application application(960,540);
    int returnCode = application.Initialize();
    if (!returnCode&&application.CheckController())
    {
        application.Run();
    }
    else
    {
        Alert alert;
        std::vector<int> errVector;
        if (returnCode)
        {
            errVector.push_back(returnCode);
        }

        if (application.CheckController() == false)
        {
            errVector.push_back(ErrorCode::ERR_IN_CONTROLLER_CONNECTION);
        }
        alert.MakeAlertFIle(errVector);
    }

    return 0;
}