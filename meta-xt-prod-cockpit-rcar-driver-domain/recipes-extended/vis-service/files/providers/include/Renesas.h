#ifndef RENESAS_H
#define RENESAS_H

#include <string>
#include <memory>
#include "VisServiceClient.h"

class RenesasVisMessage: public VisMessage
{
public:
    explicit RenesasVisMessage(const vis_string & msg):
        mMsg(msg)
    {

    }
    ~RenesasVisMessage() override = default;
    vis_string toString()const override { return mMsg;};
    bool empty()const override {return TString<vis_string>::empty(mMsg);}

private:
    vis_string mMsg;
};

class RenesasVisMessageHandler: public VisMessageHandler
{
public:
 /*   enum SubscrState {
        StateInit = 0,
        StateGetValues = 1,
        StateSubscribe = 2,
        StateReady = 3
    };
*/
    RenesasVisMessageHandler(const RenesasVisMessageHandler & )= delete;
    RenesasVisMessageHandler(RenesasVisMessageHandler && )= delete;
    RenesasVisMessageHandler() = delete;

    explicit RenesasVisMessageHandler(std::unique_ptr<OutputDevice> device);
    ~RenesasVisMessageHandler() = default;

    std::unique_ptr<VisMessage>  handle(const vis_string & msg) override;

private:
    std::unique_ptr<OutputDevice> mDevice;
//    QUuid mID;
//    SubscrState mState;
//   vis_string mSubscriptionId;
};

#endif // RENESAS_H
