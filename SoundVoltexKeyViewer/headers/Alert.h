#ifndef ALERT_HEADER_N
#define ALERT_HEADER_N
#include "..\headers\ErrorCode.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <iostream>

class Alert
{
public:
    void MakeAlertFIle(const std::vector<int>& errorCode);
};

#endif // !ALERT_HEADER_N
