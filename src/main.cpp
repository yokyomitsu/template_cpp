#include "greeting.hpp"

int main() {
    // Greeting オブジェクトを動的に作成
    // Greeting* greeting = new Greeting("Hello, World!"); // 英語
    Greeting* greeting = new Greeting("Hallo Welt!"); // ドイツ語

    // メッセージを表示
    greeting->say();

    // メモリを解放
    delete greeting;

    return 0;
}