#ifndef GREETING_HPP
#define GREETING_HPP

#include <string>

class Greeting {
public:
    // コンストラクタとデストラクタ
    Greeting(const std::string& message);
    ~Greeting();

    // メッセージを出力するメソッド
    void say() const;

private:
    std::string* message;
};

#endif // GREETING_HPP
