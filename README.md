# README

## 依赖

* `autotools`
* `java`
* `doxygen`
* `graphviz`

详见[安装方法](https://github.com/gnsyxiang/autotools_demo_lib/blob/main/README.md)


## 使用说明

* 执行`./autogen.sh`，生成`configure`脚本

* 三部曲编译源码并生成对应文件

```shell
$ ./configure
$ make
$ make install
```

## 配置相关选项

* `--prefix=PREFIX`: 指定安装路径

* `--enable-doxygen-doc`: 生成html帮助文档

* `--disable-hy_utils`: 默认打开`hy_utils`检测，需要关闭时启用该选项

* `--disable-event`: 默认打开`event`检测，需要关闭时启用该选项

* `--disable-event_pthread`: 默认打开`event_pthread`检测，需要关闭时启用该选项

## 交叉编译

详见`build.sh`

