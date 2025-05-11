### `dmcmake-tools` 使用说明

[English](./README.md) · **简体中文**

## 功能特性

- 🚀 **自动生成CMake项目结构**
  - 采用现代CMake最佳实践生成标准化工程文件
  - 自动生成Windows(build.bat)和Unix-like系统(build.sh)构建脚本

- 🔧 **智能源码检测**
  - 自动扫描src/, test/等源码目录
  - 支持C++头文件/源文件自动关联

- 🛡️ **跨平台支持**
  - 生成平台无关的构建配置
  - 兼容Windows(MSVC)、Linux(GCC/Clang)和macOS(Clang)

- ⚙️ **灵活过滤配置**
  - `-IN_FILTER`: 排除指定目录的源码检测
  - `-OUT_FILTER`: 过滤生成的构建脚本

- 🔄 **强制覆盖模式**
  - `-force=true` 选项可覆盖现有工程文件
  - 非强制模式保留现有配置

## 基础用法

#### 设置当前路径到PATH (管理员权限)

```shell
install.bat
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

---

#### 示例命令：  
生成一个名为 `dmmath` 的项目，强制覆盖已有文件：

```shell
cmake-init -name=dmmath -force=true
```

#### 生成的文件结构：

```
│  build.bat
│  build.sh
│  CMakeLists.txt
├─cmake
│      cmake_uninstall.cmake.in
│      ModuleCompileOptions.cmake
│      ModuleImport.cmake
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

--- 

🎉 **总结**:  
通过 `cmake-init` 命令，可以快速生成 CMake 工程文件和相关构建脚本，支持自定义项目名称、路径和类型，并且可以强制覆盖现有文件，方便项目构建与管理！🚀
