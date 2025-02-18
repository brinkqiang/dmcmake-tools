### `dmcmake-tools` Usage Guide

**English** · [简体中文](./README.zh-CN.md) 

#### Command: `cmake-init --help`

- **-IN_FILTER** (Ignore paths)  
  Type: `string`  
  Default: `.git;.svn;CMakeFiles`  
- **-OUT_FILTER** (Ignore paths)  
  Type: `string`  
  Default: ``  

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
