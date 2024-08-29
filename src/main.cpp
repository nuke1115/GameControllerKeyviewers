#include "..\headers\Application.hpp"

int main()
{
    Application application(960,540,"keyviewer test");
    int returnCode = application.Initialize();
    if (!returnCode&&application.CheckController())
    {
        application.Run();
    }

    return 0;
}
