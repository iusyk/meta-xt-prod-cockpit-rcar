#ifndef VISSERVICECLIENT_H
#define VISSERVICECLIENT_H

#include <QString>
#include <variant>
#include <memory>

typedef QString vis_string;

template <typename Str>
class TString;

template<>
class TString<QString>
{
public:
    static bool empty(const QString & str){return str.isEmpty();}   
};

struct OutputParam
{
    typedef int my_int;
    typedef std::variant<int, bool, double, vis_string> output_value_type;
    uint32_t id;
    output_value_type value;
};

class OutputDevice
{
public:
    virtual ~OutputDevice() = default;
    virtual OutputDevice& operator << (const OutputParam& op) = 0;
};

class VisMessage
{
public:
    virtual ~VisMessage() = default;
    virtual vis_string toString()const= 0;
    virtual bool empty()const = 0;
};

class VisMessageHandler
{
public:
    VisMessageHandler(const VisMessageHandler&) = delete;
    VisMessageHandler(VisMessageHandler&&) = delete;
    VisMessageHandler() = default;
    virtual ~VisMessageHandler()= default;

    virtual std::unique_ptr<VisMessage> handle(const vis_string & msg)= 0;
};

#endif // VISSERVICECLIENT_H
