#include <iostream>
#include<thread>//多线程
#include<chrono>//时间相关
#include <functional>//函数包装器
#include "cpp-httplib/httplib.h"//下载相关

class Download
{
private:
    /* data */
public:
    void download(const std::string& host, const std::string& path,const std::function<void(const std::string&, const std::string&) > &callback_word_count)
    {
        std::cout<<"线程"<<std::this_thread::get_id()<<std::endl;
        httplib::Client client(host);
        auto response = client.Get(path);
        if(response && response->status==200)
        {
            callback_word_count(path,response->body);
        }

    };
    void start_downlaod(const std::string &host, const std::string &path, const std::function<void
    (const std::string &, const std::string &)> &callback_word_count)
    {
        auto download_fun = std::bind(&Download::download,this,std::placeholders::_1,
        std::placeholders::_2,std::placeholders::_3);
        std::thread thread(download_fun,host,path,callback_word_count);
        thread.detach();
    };
};

int main()
{
    auto d = Download();
    auto word_count = [](const std::string &path, const std::string &result) -> void{
        std::cout << "下载完成" <<path<< ":" << result.length() << "->" << result.substr(0,5) << std::endl;

    };
    d.start_downlaod("http://0.0.0.0:8000","/nove1.txt",word_count);
    d.start_downlaod("http://0.0.0.0:8000","/nove2.txt",word_count);
    d.start_downlaod("http://0.0.0.0:8000","/nove3.txt",word_count);

    std::this_thread::sleep_for(std::chrono::milliseconds(1000*10));
    return 0;
}