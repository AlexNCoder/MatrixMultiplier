if(QT_VERSION VERSION_LESS 6.3)
    macro(qt_standard_project_setup)
        set(CMAKE_AUTOMOC ON)
        set(CMAKE_AUTORCC ON)
        set(CMAKE_AUTOUIC ON)
    endmacro()
endif()

if(QT_VERSION VERSION_LESS 6.0)
    macro(qt_add_executable name)
         if(ANDROID)
            add_library(name SHARED ${ARGN})
        else()
            add_executable(${ARGV} "TaskMaker/Task/Task.h" "TaskMaker/Task/Task.cpp" "Matrix/Matrix.h" "Matrix/Matrix.cpp" "TaskMaker/TaskMaker.h" "TaskMaker/TaskMaker.cpp" "TaskRunner.cpp")
        endif()
    endmacro()
endif()