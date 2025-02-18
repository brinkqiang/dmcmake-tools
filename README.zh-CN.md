### `dmcmake-tools` 使用说明

**简体中文** · [English](./README.md) 

#### 命令：`cmake-init --help`

- **-IN_FILTER** (忽略路径)  
  类型: `string`  
  默认: `.git;.svn;CMakeFiles`  
- **-OUT_FILTER** (忽略路径)  
  类型: `string`  
  默认: ``  

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