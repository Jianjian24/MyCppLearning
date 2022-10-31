class DataWriterListener
{
private:
    /* data */
public:
    DataWriterListener(/* args */);
    ~DataWriterListener();

    virtual bool on_data_write() = 0;
};
