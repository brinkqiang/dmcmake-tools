### `dmcmake-tools` Usage Guide

**English** · [简体中文](./README.zh-CN.md) 

## Features

- 🚀 **Auto-generate CMake Project Structure**
  - Creates standardized CMakeLists.txt with modern CMake practices
  - Generates build scripts for Windows (build.bat) and Unix-like systems (build.sh)
  
- 🔧 **Smart Source Detection**
  - Automatically scans source directories (src/, test/, etc.)
  - Supports C++ header/source file detection with proper target linking
  
- 🛡️ **Cross-platform Support**
  - Generates platform-agnostic build configurations
  - Compatible with Windows (MSVC), Linux (GCC/Clang) and macOS (Clang)

- ⚙️ **Customizable Filters**
  - `-IN_FILTER`: Exclude specific directories from source detection
  - `-OUT_FILTER`: Exclude generated build scripts from final output

- 🔄 **Force Overwrite**
  - `-force=true` option to overwrite existing project files
  - Preserves existing configurations when not forced

## Basic Usage

#### Set current path to PATH(admin)

```shell
install.bat
```

#### Command: `cmake-init --help`

- **-IN_FILTER** (Ignore paths)  
  Type: `string`  
  Default: `.git;.svn;CMakeFiles`  
- **-OUT_FILTER** (Ignore paths)  
  Type: `string`  
  Default: `""`  

- **-PATH** (Path to generate the CMakeLists.txt project)  
  Type: `string`  
  Default: `""` (current working directory)

- **-force** (Force generation)  
  Type: `bool`  
  Default: `false`

- **-name** (Project name)  
  Type: `string`  
  Default: `dmcmake`

---

#### Example Command:  
Generate a project named `dmmath` and force overwrite existing files:

```shell
cmake-init -name=dmmath -force=true
```

#### Generated File Structure:

```
│  build.bat
│  build.sh
│  CMakeLists.txt
├─cmake
│      cmake_uninstall.cmake.in
│      ModuleCompileOptions.cmake
│      ModuleImport.cmake
```

##### If you want to exclude certain files, such as `build.bat` and `build.sh`, you can use

```
cmake-init -OUT_FILTER="build.bat;build.sh"
```


```shell
chmod +x build.sh
```

#### Output after running `build.bat` or `build.sh`:

```
bin\relwithdebinfo\main
```

Output content:

```
hello world # 2025
```

--- 

🎉 **Summary**:  
With the `cmake-init` command, you can quickly generate CMake project files and related build scripts. It supports custom project names, paths, and types, and allows you to force overwrite existing files, making project setup and management more convenient! 🚀
