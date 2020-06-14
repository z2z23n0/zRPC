#include "zrpcApplication.h"
#include "user.pb.h"

#include <iostream>

int main(int argc, char **argv)
{
    // 整个程序启动后，想使用zrpc框架来享受rpc服务调用，一定需要先调用框架的初始化函数（只初始化一次）
    ZrpcApplication::Init(argc, argv);

    // 演示调用远程发布的rpc方法Login
    chat::UserServiceRpc_Stub stub(new ZrpcChannel());
    // rpc方法的请求参数
    chat::LoginRequest request;
    request.set_name("zhang san");
    request.set_pwd("123456");
    // rpc方法的响应
    chat::LoginResponse response;

    ZrpcController controller; // controller可以获取调用过程中的状态信息
    // 发起rpc方法的调用 同步的rpc调用过程 ZrpcChannel::callMethod
    stub.Login(&controller, &request, &response, nullptr); // RpcChannel->RpcChannel::callMethod 集中来做所有rpc方法调用的参数序列化和网络发送

    // 一次rpc调用完成，读调用的结果
    if (controller.Failed())
    {
        std::cout << controller.ErrorText() << std::endl;
    }
    else
    {
        if (0 == response.result().errcode())
        {
            std::cout << "rpc Login response success:" << response.success() << std::endl;
        }
        else
        {
            std::cout << "rpc Login response error :" << response.result().errmsg() << std::endl;
        }
    }

    // 演示调用远程发布的rpc方法Register
    chat::RegisterRequest req;
    req.set_id(10001);
    req.set_name("zeno");
    req.set_pwd("123456");
    chat::RegisterResponse rsp;

    ZrpcController controller2; // controller可以获取调用过程中的状态信息
    // 以同步的方式发起rpc调用请求，等待返回结果
    stub.Register(&controller2, &req, &rsp, nullptr);

    // 一次rpc调用完成，读调用的结果
    if (controller2.Failed())
    {
        std::cout << controller.ErrorText() << std::endl;
    }
    else
    {
        if (0 == rsp.result().errcode())
        {
            std::cout << "rpc register response success:" << rsp.success() << std::endl;
        }
        else
        {
            std::cout << "rpc register response error : " << rsp.result().errmsg() << std::endl;
        }
    }

    return 0;
}