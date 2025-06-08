### `dmcmake-tools` 使用说明

 **简体中文** [English](./README.en.md) ·


## 功能特性

- 🚀 **自动生成CMake项目结构**
  - 采用现代CMake最佳实践生成标准化工程文件
  - 自动生成Windows(build.bat), Unix-like系统(build.sh), CMakeLists.txt 等构建脚本

- 🔧 **智能源码检测**
  - 自动扫描src/, test/等源码目录
  - 支持C++头文件/源文件自动关联

- 🛡️ **跨平台支持**
  - 生成平台无关的构建配置
  - 兼容Windows(MSVC)、Linux(GCC/Clang)和macOS(Clang)

- ⚙️ **过滤配置**
  - `-IN_FILTER`: 排除指定目录的源码检测
  - `-OUT_FILTER`: 过滤生成的构建脚本

- 🔄 **强制覆盖模式**
  - `-force=true` 选项可覆盖现有工程文件
  - 非强制模式会检测CMakeLists.txt是否存在, 防止误操作

## 基础用法

#### 安装 (管理员权限)
win
```shell
install.bat
```

linux
```shell
./install.sh
```

#### 命令：`cmake-init --help`

- **-IN_FILTER** (忽略路径)  
  类型: `string`  
  默认: `.git;.svn;CMakeFiles`  
- **-OUT_FILTER** (忽略路径)  
  类型: `string`  
  默认: `""`  

- **-PATH** (需要生成 CMakeLists.txt 的工程路径)  
  类型: `string`  
  默认: `""`（即当前工作路径）

- **-force** (强制生成)  
  类型: `bool`  
  默认: `false`

- **-name** (项目名称)  
  类型: `string`  
  默认: `dmcmake`

- **-cpp** (C++版本 支持17/20/23/26)  
  类型: `string`  
  默认: `17`

---

#### 示例命令：  
在你的项目的根目录执行下面命令, 会生成一个名为 `dmmath` 的项目，强制覆盖已有文件：

```shell
cmake-init -name=dmmath -cpp=20 -force=true
```

#### 生成的文件结构：

```
│  build.bat                         # windows默认 编译
│  build.sh                          # unix-like系统 编译
│  build_mingw.bat                   # win mingw 编译 (用的Unix Makefiles形式)
│  build_ninja.bat                   # win ninja 编译
│  CMakeLists.txt                    # cmake 主配置
├─cmake
│      cmake_uninstall.cmake.in       # 卸载依赖文件
│      ModuleCompileOptions.cmake     # 常规环境设置
│      ModuleImport.cmake             # 模块导入接口
|      launch.cmake                   # cmake vscode 调试接口设置
|      launch.json.in                 # vscode 调试配置模版
```

##### 如果希望不生成其中的某些文件 比如 build.bat build.sh 可以使用
```
cmake-init -OUT_FILTER="build.bat;build.sh"
```

```shell
chmod +x build.sh
```

#### 执行 `build.bat` 或 `build.sh` 后生成的输出：

```
bin\RelWithDebInfo\main
```

输出内容:

```
hello world # 2025
```
#### 环境设置注意事项
1. **Windows Visual Studio环境**: 请确保已安装 Visual Studio 和 CMake (设置bin目录到环境变量path中)
2. **Windows mingw 环境**: 请确保已安装 mingw(推荐用msys2安装) 和 CMake (设置bin目录到环境变量path中, 即命令行可以识别cmake make gcc g++)
   
```
https://github.com/msys2/msys2-installer/releases/download/2024-01-13/msys2-x86_64-20240113.exe
```

##### 安装好之后打开msys2控制台 输入
```
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain

copy C:\msys64\ucrt64\bin\mingw32-make.exe C:\msys64\ucrt64\bin\make.exe
```
3. **默认编译之后生成的vscode调试配置, 有两套, 一套是mingw环境, 一套是vs环境, 启动时请根据自己的需求设置**
--- 

🎉 **总结**:  
通过 `cmake-init` 命令，可以快速生成 CMake 工程文件和相关构建脚本，支持自定义项目名称、路径和类型，并且可以强制覆盖现有文件，方便项目构建与管理！🚀


## 视频预览 

[![](https://bb-embed.herokuapp.com/embed?v=BV1tST9zPEBz)](https://player.bilibili.com/player.html?isOutside=true&aid=114648347055343&bvid=BV1tST9zPEBz&cid=30392651593&p=1)

[![](https://bb-embed.herokuapp.com/embed?v=BV1tST9zPEZL)](https://player.bilibili.com/player.html?isOutside=true&aid=114648347054256&bvid=BV1tST9zPEZL&cid=30392648657&p=1)
