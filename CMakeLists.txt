cmake_minimum_required(VERSION 3.10)

# プロジェクト名
project(MyProject)

# インクルードディレクトリを指定
include_directories(include)

# ソースファイルを指定
add_executable(MyProject src/main.cpp src/greeting.cpp)