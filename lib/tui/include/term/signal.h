#pragma once

#include <cstdint>
#include <map>
#include <functional>

namespace tui
{



template<typename... Arguments>
class Signal
{
public:
    using Callback = std::function<void (Arguments...)>;
    using CallbackId = uint32_t;

private:
    std::map<CallbackId, Callback> mCallbacks;
    CallbackId mIdCounter;
public:
    Signal() : mIdCounter(0) {}

    CallbackId connect(Callback callback) {
        mCallbacks[mIdCounter] = callback;
        return mIdCounter++; 
    }
    void disconnect(CallbackId id)
    {
        mCallbacks.erase(id);
    }
    
    void emit(Arguments... args)
    {
        for(auto &[id, callback] : mCallbacks)
        {
            callback(args...);
        }
    }

};




} // namespace tui