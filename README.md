# template_cpp

このリポジトリは、Cpp開発環境用テンプレートです。

## 事前準備

初めてGitHubとDockerを使用する場合は、以下の手順に従ってインストールしてください。

### GitHubのインストール
1. GitHubの公式サイトにアクセスし、アカウントを作成します: [GitHub](https://github.com/)
2. Gitをインストールします:
    - **Windows**: [Git for Windows](https://gitforwindows.org/) からインストーラをダウンロードし、インストールします。
    - **Mac**: ターミナルを開き、以下のコマンドを実行します:
        ```sh
        brew install git
        ```
    - **Linux**: ターミナルを開き、以下のコマンドを実行します:
        ```sh
        sudo apt-get install git
        ```

### Dockerのインストール
1. Dockerの公式サイトにアクセスし、Docker Desktopをダウンロードします: [Docker](https://www.docker.com/products/docker-desktop)
2. インストーラの指示に従って、Docker Desktopをインストールします。

インストール後、Docker Desktopを起動し、設定を完了します。

## インストール

1. リポジトリをクローンします:

    ```sh
    git clone https://github.com/yokyomitsu/template_cpp.git
    cd template_cpp
    ```

2. イメージのビルド:
    ```bash
    docker build -t mydevenv .  
    ```

3. イメージの実行とホストマシンの作業ディレクトリをマウントします。
    ```bash
    docker run -it --rm -v $(pwd):/app mydevenv
    ```

## 使い方
クローンした時点では、下記の構成となっています。

1. ディレクトリ構造:
    ```
    project/
    │
    ├── src/
    │   ├── main.cpp
    │   └── greetings.cpp
    │
    └── include/
        └── greetings.hpp
    ```

2. `CMakeLists.txt` の内容（CMakeを使用する場合）:
    ```cmake
    cmake_minimum_required(VERSION 3.10)

    # プロジェクト名
    project(MyProject)

    # インクルードディレクトリを指定
    include_directories(include)

    # ソースファイルを指定
    add_executable(MyProject src/main.cpp src/greetings.cpp)
    ```

3. ビルドと実行
ビルドするには、以下のようにします。

    ```bash
    cmake . && make
    ./MyProject
    ```

    `MyProject` 実行ファイルが生成され、コンソールに`Hello, World!` と出力されます

4. あいさつの内容を変更して実行
    あいさつの内容をドイツ語に変更してみます。
    これで変更内容が反映されることを確認します。

    ```cpp
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
    ```
    変更後に、再度cmakeします。(マウント済みなので即座にmain.cppの変更が反映されています)
    ```bash
    cmake . && make
    ./MyProject
    ```

    `MyProject` 実行ファイルが生成され、コンソールに`Hallo Welt!!` と出力されます