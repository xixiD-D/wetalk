//
// Created by 29697 on 24-11-2.
//

#ifndef STATUSGRPCCLIENT_H
#define STATUSGRPCCLIENT_H

#include "const.h"
#include "Singleton.h"
#include "ConfigManager.h"
#include <grpcpp/grpcpp.h>
#include "Headers/message.grpc.pb.h"
#include "Headers/message.pb.h"

using grpc::Channel;
using grpc::Status;
using grpc::ClientContext;

using message::GetChatServerReq;
using message::GetChatServerRsp;
using message::LoginReq;
using message::LoginRsp;
using message::StatusService;

class StatusConPool {
public:
    StatusConPool(size_t poolSize, std::string &host, std::string &port);

    ~StatusConPool();

    std::unique_ptr<StatusService::Stub> getConnection();

    void returnConnection(std::unique_ptr<StatusService::Stub> context);

    void Close();

private:
    std::atomic<bool> b_stop_;
    size_t poolSize_;
    std::string host_;
    std::string port_;
    std::queue<std::unique_ptr<StatusService::Stub> > connections_;
    std::mutex mutex_;
    std::condition_variable cond_;
};

class StatusGrpcClient : public Singleton<StatusGrpcClient> {
    friend class Singleton<StatusGrpcClient>;

public:
    ~StatusGrpcClient();

    GetChatServerRsp GetChatServer(int uid);

private:
    StatusGrpcClient();

    std::unique_ptr<StatusConPool> pool_;
};


#endif //STATUSGRPCCLIENT_H
