#pragma once

#include "zrpcConfig.h"

// zrpc框架的基础类，负责框架的一些初始化操作
class ZrpcApplication
{
public:
    static void Init(int argc, char **argv);
    static ZrpcApplication &GetInstance();
    static ZrpcConfig &GetConfig();

private:
    static ZrpcConfig m_config;

    ZrpcApplication() {}
    ZrpcApplication(const ZrpcApplication &) = delete;
    ZrpcApplication(ZrpcApplication &&) = delete;
};