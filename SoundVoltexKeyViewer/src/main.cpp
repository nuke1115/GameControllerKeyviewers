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
        alert.ShowAlert(returnCode);
        returnCode = application.CheckController() == false ? ErrorCode::ERR_IN_CONTROLLER_CONNECTION:ErrorCode::END;
        alert.ShowAlert(returnCode);
    }

    return 0;
}
