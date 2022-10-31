#include ".\DataWriterListener.h"
#include <string>
using std::string;

class DataWriter : public DataWriterListener
{
private:
    bool on_data_write(const char* buf) override;
public:
    DataWriter(/* args */);
    ~DataWriter();

    bool write(string topic);
};
