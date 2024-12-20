
#ifndef __LOG_DETAIL_MSG_H
#define __LOG_DETAIL_MSG_H

class LogDetailMsg {
public:
    LogDetailMsg(const void* _data) : m_data(_data) {}
   // ~LogDetailMsg() {}

    const void* getData() const { return m_data; }
private:
    const void* m_data;
};

#endif
