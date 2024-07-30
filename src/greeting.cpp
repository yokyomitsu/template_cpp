#include <iostream>
#include "greeting.hpp"

// コンストラクタ
Greeting::Greeting(const std::string& message) {
    this->message = new std::string(message);
}

// デストラクタ
Greeting::~Greeting() {
    delete message;
}

// メッセージを出力するメソッド
void Greeting::say() const {
    std::cout << *message << std::endl;
}
