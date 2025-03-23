cmake_minimum_required(VERSION 3.5)

project(Desert_SSV_2025_STEP2)

#set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")

set(TEST_DIR "${PROJECT_SOURCE_DIR}/Tests")
set(CACHE_DIR "${PROJECT_SOURCE_DIR}/../extlib/Catch/include")


include_directories(${PROJECT_SOURCE_DIR})
include_directories(${CACHE_DIR})
include_directories(${TEST_DIR})

file(GLOB UTILITY_SOURCES
     "${PROJECT_SOURCE_DIR}/Utility/*.cpp"
     "${PROJECT_SOURCE_DIR}/Utility/*.hpp"
     "${PROJECT_SOURCE_DIR}/JSON/*.cpp"
     "${PROJECT_SOURCE_DIR}/JSON/*.hpp"
     "${PROJECT_SOURCE_DIR}/Random/*.cpp"
     "${PROJECT_SOURCE_DIR}/Random/*.hpp"
      "${PROJECT_SOURCE_DIR}/Types/*.cpp"
      "${PROJECT_SOURCE_DIR}/Types/*.hpp"
     )


file(GLOB PROJECT_SOURCES
     "${PROJECT_SOURCE_DIR}/*.cpp"
     "${PROJECT_SOURCE_DIR}/*.hpp"
      "${PROJECT_SOURCE_DIR}/Environment/*.hpp"
       "${PROJECT_SOURCE_DIR}/Environment/*.cpp"
      "${PROJECT_SOURCE_DIR}/Animal/*.cpp"
      "${PROJECT_SOURCE_DIR}/Animal/*.hpp"
      "${PROJECT_SOURCE_DIR}/Obstacle/*.cpp"
      "${PROJECT_SOURCE_DIR}/Obstacle/*.hpp"
      ${UTILITY_SOURCES}
      )

file(GLOB SOURCES
     ${PROJECT_SOURCES}
)


list(REMOVE_ITEM PROJECT_SOURCES "${PROJECT_SOURCE_DIR}/main.cpp")


file (GLOB CACHE_SOURCES
  "${CACHE_DIR}/catch.hpp"
   "${TEST_DIR}/UnitTests/CheckUtility.hpp"
   "${TEST_DIR}/UnitTests/CatchTests.cpp"
   #   ${SOURCES}
   ${UTILITY_SOURCES}
    )


file(GLOB SOURCES_GFX
         ${SOURCES}
)

add_custom_target(application-run
    COMMAND ./application
    DEPENDS application
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
    )

# Find any version 2.X of SFML, first trying 2.5 or above (for which CMake configuration changed)
find_package(SFML 2.5 QUIET COMPONENTS graphics window system)
    if(SFML_FOUND)
      message(STATUS "Found SFML ${SFML_VERSION_MAJOR}.${SFML_VERSION_MINOR}.${SFML_VERSION_PATCH}")

      ##Units tests:

#       add_executable (jsonTest  ${TEST_DIR}/UnitTests/JSONTest.cpp ${SOURCES} ${CACHE_SOURCES})
#       target_link_libraries(jsonTest sfml-graphics sfml-window sfml-system)

#       ##Vec2d
#      add_executable (vec2dTest  ${TEST_DIR}/UnitTests/Vec2dTest.cpp ${SOURCES} ${CACHE_SOURCES})
#     target_link_libraries(vec2dTest sfml-graphics sfml-window sfml-system)

#        ## collider
#       add_executable (colliderTest  ${TEST_DIR}/UnitTests/ColliderTest.cpp ${SOURCES} ${CACHE_SOURCES})
#       target_link_libraries(colliderTest sfml-graphics sfml-window sfml-system)

#       ## targets
#     add_executable (targetInSightTest  ${TEST_DIR}/UnitTests/TargetInSightTest.cpp ${SOURCES} ${CACHE_SOURCES})
#     target_link_libraries(targetInSightTest sfml-graphics sfml-window sfml-system)

   
        ### Graphical tests:
        ## chasing
#         add_executable (chasingTest  ${TEST_DIR}/GraphicalTests/ChasingTest.cpp ${SOURCES_GFX})
#         target_link_libraries(chasingTest sfml-graphics sfml-window sfml-system)

#	 ## environment
#        add_executable (envTest  ${TEST_DIR}/GraphicalTests/EnvTest.cpp ${SOURCES_GFX})
#       target_link_libraries(envTest sfml-graphics sfml-window sfml-system)

#	## animal
#        add_executable (animalTest  ${TEST_DIR}/GraphicalTests/AnimalTest.cpp ${SOURCES_GFX})
#        target_link_libraries(animalTest sfml-graphics sfml-window sfml-system)


    else()
        set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
        find_package(SFML 2  COMPONENTS graphics window system)
        if(SFML_FOUND)

            message(STATUS "SFML_INCLUDE_DIR : ${SFML_INCLUDE_DIR}")
            message(STATUS "SFML_LIBRARIES   : ${SFML_LIBRARIES}")
            message(STATUS "SFML_DEPENDENCIES: ${SFML_DEPENDENCIES}")

            include_directories(${SFML_INCLUDE_DIR})

	    ##Units tests:

#       add_executable (jsonTest  ${TEST_DIR}/UnitTests/JSONTest.cpp ${SOURCES} ${CACHE_SOURCES})
#        target_link_libraries(jsonTest ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

#       ##Vec2d
#      add_executable (vec2dTest  ${TEST_DIR}/UnitTests/Vec2dTest.cpp ${SOURCES} ${CACHE_SOURCES})
#     target_link_libraries(vec2dTest ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

#        ## collider
#       add_executable (colliderTest  ${TEST_DIR}/UnitTests/ColliderTest.cpp ${SOURCES} ${CACHE_SOURCES})
#      target_link_libraries(colliderTest ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

#       ## targets
#     add_executable (targetInSightTest  ${TEST_DIR}/UnitTests/TargetInSightTest.cpp ${SOURCES} ${CACHE_SOURCES})
#     target_link_libraries(targetInSightTest ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

   
        ### Graphical tests:
        ## chasing
#         add_executable (chasingTest  ${TEST_DIR}/GraphicalTests/ChasingTest.cpp ${SOURCES_GFX})
#         target_link_libraries(chasingTest ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

#	 ## environment
#        add_executable (envTest  ${TEST_DIR}/GraphicalTests/EnvTest.cpp ${SOURCES_GFX})
#        target_link_libraries(envTest  ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
#	## animal
#        add_executable (animalTest  ${TEST_DIR}/GraphicalTests/AnimalTest.cpp ${SOURCES_GFX})
 #       target_link_libraries(animalTest  ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
 
        else()
            message(STATUS "SFML NOT FOUND ! ")
        endif() ## SFML 2
endif() ## SFML 2.5
