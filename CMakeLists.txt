cmake_minimum_required(VERSION 3.15)

project(sl_container_test LANGUAGES CXX)

set(proj_name "sl_container_test")

set(source_dir ${PROJECT_SOURCE_DIR}/source)


add_subdirectory(${source_dir})

add_executable(${proj_name} sl_container_test.cpp)

target_link_libraries(${proj_name} PRIVATE
  sl_container
)

target_include_directories(${proj_name}  PUBLIC
  ${source_dir}
)

# file(GLOB_RECURSE _sources 
#   ${source_dir}/*.cpp 
#   ${source_dir}/*.h
#   ${source_dir}/*.inl
#   ${source_dir}/*.hpp  
#   )
# add_executable(${Application_Name} "")
# target_sources(${Application_Name} PRIVATE
#   ${_sources}
# )
# target_link_libraries(${Application_Name} PRIVATE
#   Message
# )
# target_link_libraries(${Application_Name} PRIVATE
#   glfw
# )
# target_link_libraries(${Application_Name} PRIVATE
#   glad
# )
# target_link_libraries(${Application_Name} PUBLIC
#   imgui
# )
# target_include_directories(${Application_Name}  PUBLIC
#   ${LibraryPath}/glad/include
#   ${LibraryPath}/glfw/include
#   ${LibraryPath}/Message
#   ${LibraryPath}/glm-0.9.9.8/glm
#   ${LibraryPath}/imgui
#   ${EnginePath}
#   ${EnginePath}/Core
#   ${EnginePath}/Platform
#   ${EnginePath}/ThirdParty
#   ${EnginePath}/Resource
# )

# target_compile_definitions(${Application_Name} PRIVATE
#   GLFW_INCLUDE_NONE 
#   RESOURCE_PATH ${ResourcePath}
# )
# else()

# endif()
