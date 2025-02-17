# dmcmake-tools

dmgen4cmake --help
    -FILTER (忽略路径) type: string default: ".git;.svn;CMakeFiles"
    -PATH (需要生成CMakeLists.txt工程路径, 如果不设置 默认为工作路径)
      type: string default: ""
    -force (Force) type: bool default: false
    -name (project_name) type: string default: "dmcmake"
    -type (project_type lib/exe) type: string default: "exe"

dmgen4cmake -name dmmath -force=true

这个命令将会生成
│  build.bat
│  build.sh
│  CMakeLists.txt
├─cmake
│      cmake_uninstall.cmake.in
│      ModuleCompileOptions.cmake
│      ModuleImport.cmake

执行 build.bat 或者 build.sh 将会生成工程文件
