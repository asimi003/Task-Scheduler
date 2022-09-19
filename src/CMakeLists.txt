set(SOURCES
        main.cpp
        planner/Planner.cpp
        tasks/TaskInterface.cpp
        tasks/Task.cpp
        tasks/TaskList.cpp
        classification/classificationManager.cpp
        builder/TaskBuilder.cpp
        builder/TaskDirector.cpp
        builder/TaskListBuilder.cpp

        )

set(HEADERS
        planner/Planner.h
        tasks/TaskInterface.h
        tasks/Task.h
        tasks/TaskList.cpp
        classification/classification.hpp
        classification/classificationManager.hpp
        builder/TaskBuilder.hpp
        builder/TaskBuilderInterface.hpp
        builder/TaskDirector.hpp
        builder/TaskListBuilder.hpp
        )


add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES} ${HEADERS})