# 라즈베리파이5 TinyOS , NesC , Oscilloscope.py(미들웨어) 설치

## 사전 설치
```
sudo apt-get install emacs gperf bison flex git build-essential automake avarice avr-libc avrdude binutils-avr gcc-avr gdb-avr subversion graphviz checkinstall openjdk-17-jdk git
```

## 사전 설정
  - 1
```
$ vim ~/tinyos.env

export TOSROOT=/opt/tinyos-2.x
export TOSDIR=$TOSROOT/tos
export CLASSPATH=$TOSROOT/support/sdk/java/tinyos.jar:$CLASSPATH
export CLASSPATH=$TOSROOT/support/sdk/java:$CLASSPATH
export CLASSPATH=.:$CLASSPATH
export MAKERULES=$TOSROOT/support/make/Makerules
export PYTHONPATH=$PYTHONPATH:$TOSROOT/support/sdk/python

echo "setting up TinyOS on source path $TOSROOT"
```
  - 2
```
$ vim ~/.bashrc
  끝줄에 추가
  source ~/tinyos.env
```
  - 3 실행
```
$ source ~/.bashrc
```

### 🤗 환경 설정 파일: `.bashrc`

`.bashrc`는 사용자가 터미널을 열 때 자동으로 실행되는 설정 파일입니다. 여기에 필요한 환경 변수나 스크립트를 등록하면, 매번 수동 설정할 필요 없이 자동으로 적용됩니다.


### JNI 파일 복사
```
$ git clone https://github.com/sonnonet/jni.git
$ cd jni/tinyos/
$ sudo mv libtoscomm.so /usr/lib
$ sudo mv libgetenv.so /usr/lib
```
### NesC 설치
```
$ mv ~/sonnonet/jni/tinyos/nesc-1.3.4.tar.gz ~/
$ tar –xvzf nesc-1.3.4.tar.gz
$ cd nesc-1.3.4
$ ./configure --build=aarch64-unknown-linux-gnu
$ make
$ sudo make install
```
### TinyOS-Tools 설치
```
$ cd /home/pi
$ git clone --branch release_tinyos_2_1_2 https://github.com/tinyos/tinyos-release.git
$ mv tinyos-release tinyos-2.x && sudo mv tinyos-2.x /opt/
$ cd /opt/tinyos-2.x/tools/
$ ./Bootstrap
$ ./configure --build=aarch64-unknown-linux-gnu
$ make
$ sudo make install
```

### 테스트 
```
$ motelist
```
<img src="/temp/1.PNG">

### 기본 미들웨어 소스코드 다운
```
$ git clone https://github.com/sonnonet/2024_inhatc
$ cd 2024_inhatc/Zigbee/Oscilloscope/
```
  - 실행방법 (mote 연결후)
```
python oscilloscope.py serial@/dev/ttyUSB0:115200
```
## tos.py 복사
```
$ mv ./tos.py /opt/tinyos-2.x/support/sdk/python/tos.py
```
