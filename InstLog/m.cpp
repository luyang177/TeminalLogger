#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <string>

int main(int argc, char * argv[])
{
    if(argc < 2)
    {
        return 1;
    }
    
    std::ostringstream msgStream;
    for (int i = 1; i < argc; i++)
    {
        msgStream << argv[i] << " ";
    }
    auto msg = msgStream.str();

    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream ss;
    ss << "[" << std::put_time(&tm, "%Y-%m-%d %H-%M-%S") << "] - [" << msg << "]\n";

    std::ofstream file("InstTrace.log", std::ios::out | std::ios::app);
    if (file.is_open())
    {
        file << ss.str();
        file.close();
    }

    return 0;
}