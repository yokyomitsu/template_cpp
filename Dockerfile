# ベースイメージとしてUbuntuを使用
FROM ubuntu:20.04

# タイムゾーンの設定
ENV TZ=Asia/Tokyo
RUN apt-get update && \
    apt-get install -y tzdata && \
    ln -fs /usr/share/zoneinfo/$TZ /etc/localtime && \
    dpkg-reconfigure --frontend noninteractive tzdata

# 必要なパッケージをインストール
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    gdb

# 作業ディレクトリを設定
WORKDIR /app

# デフォルトの実行コマンドを指定
CMD ["bash"]
