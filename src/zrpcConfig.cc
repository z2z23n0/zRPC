#include "zrpcConfig.h"

#include <iostream>
#include <string>

// 负责解析加载配置文件
void ZrpcConfig::LoadConfigFile(const char *configFile)
{
    FILE *pf = fopen(configFile, "r");
    if (nullptr == pf)
    {
        std::cout << configFile << " is not exist!" << std::endl;
        exit(EXIT_FAILURE);
    }

    /*
    1. 注释
    2. 正确的配置项
    3. 去掉开头的多余空格
    */
    while (!feof(pf))
    {
        char buf[512] = {0};
        fgets(buf, 512, pf);

        // 去掉字符串前面多余的空格
        std::string readBuf(buf);
        Trim(readBuf);

        // 判断为注释或空行
        if (readBuf[0] == '#' || readBuf.empty())
        {
            continue;
        }

        // 解析配置项
        int idx = readBuf.find('=');
        if (idx == std::string::npos)
        {
            // 配置项不合法
            continue;
        }
        std::string key;
        std::string value;
        key = readBuf.substr(0, idx);
        Trim(key);
        int endIdx = readBuf.find('\n', idx);
        value = readBuf.substr(idx + 1, endIdx - idx - 1);
        Trim(value);
        m_configMap[key] = value;
    }
    fclose(pf);
}
// 查询配置项信息
std::string ZrpcConfig::Load(const std::string &key)
{
    auto it = m_configMap.find(key);
    if (it == m_configMap.end())
    {
        return "";
    }
    return it->second;
}

// 去掉字符串前后的空格
void ZrpcConfig::Trim(std::string &srcBuf)
{
    int idx = srcBuf.find_first_not_of(' ');
    if (idx != std::string::npos)
    {
        // 说明字符串前面有空格
        srcBuf = srcBuf.substr(idx, srcBuf.size() - idx);
    }
    // 去掉字符串后面多余的空格
    idx = srcBuf.find_last_not_of(' ');
    if (idx != std::string::npos)
    {
        // 说明字符串后面有空格
        srcBuf = srcBuf.substr(0, idx + 1);
    }
}