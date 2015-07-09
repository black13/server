#ifndef _MYCONNECTION_HPP_
#define _MYCONNECTION_HPP_

#include <string>

#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>

namespace asio = boost::asio;
namespace ip = asio::ip;
namespace placeholders = asio::placeholders;

#ifdef SERVER_SSL
namespace ssl = asio::ssl;
#endif

namespace sys = boost::system;

struct MyConnection
{

    enum class Action
    {
        Read,
        ReadError,
        Process
    };

    virtual void disconnect() = 0;

    virtual void start(
        Action const action
    ) = 0;

    virtual void setId(
        std::string const & id
    ) = 0;

    virtual std::string const & getId() const = 0;

    virtual void read() = 0;

    virtual void response(
        char const * const message,
        std::size_t const size
    ) = 0;

    virtual void unicast(
        std::string const & receiverId,
        char const * const message,
        std::size_t const size
    ) = 0;

    virtual void broadcast(
        char const * const message,
        std::size_t const size
    ) = 0;

    virtual void log(
        char const * const message,
        std::size_t const size 
    ) = 0;

    virtual void const * getState() const = 0;
};

#endif
