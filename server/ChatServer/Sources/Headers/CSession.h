//
// Created by 29697 on 24-11-25.
//

#ifndef CSESSION_H
#define CSESSION_H

#include <boost/asio.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast.hpp>
#include <boost/asio.hpp>
#include <queue>
#include <mutex>
#include <memory>
#include "const.h"
#include "ConfigManager.h"
#include "MsgNode.h"

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;

using tcp = boost::asio::ip::tcp;

class CServer;
class LogicSystem;

class CSession : public std::enable_shared_from_this<CSession> {
public:
    CSession(boost::asio::io_context &io_context, CServer *server);

    ~CSession();

    tcp::socket &GetSocket();

    std::string &GetSessionId();

    void SetUserId(int uid);

    int GetUserId();

    void Start();

    void Send(char *msg, short max_length, short msgid);

    void Send(std::string msg, short msgid);

    void Close();

    std::shared_ptr<CSession> SharedSelf();

    void AsyncReadBody(int length);

    void AsyncReadHead(int total_len);

private:
    void asyncReadFull(std::size_t maxlength,
                       std::function<void(const boost::system::error_code &, std::size_t)> handler);

    void asyncReadLen(std::size_t read_len, std::size_t total_len,
                      std::function<void(const boost::system::error_code &, std::size_t)> handler);

    void HandleWrite(const boost::system::error_code &error, std::shared_ptr<CSession> shared_self);

    tcp::socket _socket;
    std::string _session_id;
    char _data[MAX_LENGTH];
    CServer *_server;
    bool _b_close;
    std::queue<std::shared_ptr<SendNode> > _send_que;
    std::mutex _send_lock;
    std::shared_ptr<RecvNode> _recv_msg_node;
    bool _b_head_parse;
    std::shared_ptr<MsgNode> _recv_head_node;
    int _user_uid;
};

class LogicNode {
    friend class LogicSystem;

public:
    LogicNode(std::shared_ptr<CSession>, std::shared_ptr<RecvNode>);

private:
    std::shared_ptr<CSession> _session;
    std::shared_ptr<RecvNode> _recvnode{};
};


#endif //CSESSION_H