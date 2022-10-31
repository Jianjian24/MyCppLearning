class DataReaderListener
{
private:
    /* data */
public:
    DataReaderListener(/* args */);
    ~DataReaderListener();
    virtual bool on_data_available(const char* buf) = 0;
};