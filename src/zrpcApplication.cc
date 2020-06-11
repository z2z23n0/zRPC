#include "zrpcApplication.h"

#include <iostream>
#include <unistd.h>
#include <string>

ZrpcConfig ZrpcApplication::m_config;

void ShowArgsHelp()
{
    std::cout << "Format: command -i <configFile>" << std::endl;
}

void ZrpcApplication::Init(int argc, char **argv)
{
    if (argc < 2)
    {
        ShowArgsHelp();
        exit(EXIT_FAILURE);
    }

    int ch = 0;
    std::string configFile;
    while ((ch = getopt(argc, argv, "i:")) != -1)
    {
        switch (ch)
        {
        case 'i':
            configFile = optarg;
            break;
        case '?':
            ShowArgsHelp();
            exit(EXIT_FAILURE);
        case ':':
            ShowArgsHelp();
            exit(EXIT_FAILURE);
        default:
            break;
        }
    }

    // 开始加载配置文件
    m_config.LoadConfigFile(configFile.c_str());

    //std::cout << "rpcServerIp:" << m_config.Load("rpcServerIp") << std::endl;
    //std::cout << "rpcServerPort:" << m_config.Load("rpcServerPort") << std::endl;
    //std::cout << "zookeeperIp:" << m_config.Load("zookeeperIp") << std::endl;
    //std::cout << "zookeeperPort:" << m_config.Load("zookeeperPort") << std::endl;
}

ZrpcApplication &ZrpcApplication::GetInstance()
{
    static ZrpcApplication app;
    return app;
}

ZrpcConfig &ZrpcApplication::GetConfig()
{
    return m_config;
}