#ifndef ALERT_HEADER_N
#define ALERT_HEADER_N
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <iostream>
#include "..\headers\ErrorCode.hpp"


class Alert
{
public:
    void MakeAlertFIle(const std::vector<int>& errorCode);
};

#endif // !ALERT_HEADER_N
