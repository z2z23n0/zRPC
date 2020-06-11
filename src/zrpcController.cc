#include "zrpcController.h"

ZrpcController::ZrpcController()
{
    m_failed = false;
    m_errText = "";
}

void ZrpcController::Reset()
{
    m_failed = false;
    m_errText = "";
}

bool ZrpcController::Failed() const
{
    return m_failed;
}

std::string ZrpcController::ErrorText() const
{
    return m_errText;
}

void ZrpcController::SetFailed(const std::string &reason)
{
    m_failed = true;
    m_errText = reason;
}

// 目前未实现具体的功能
void ZrpcController::StartCancel() {}
bool ZrpcController::IsCanceled() const { return false; }
void ZrpcController::NotifyOnCancel(google::protobuf::Closure *callback) {}