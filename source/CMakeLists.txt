project(sl_container LANGUAGES CXX)


add_library(sl_container STATIC 
    " "
)

file(GLOB_RECURSE _sources 
  *.cpp 
  *.h
  *.inl
  *.hpp  
)

target_sources(sl_container PRIVATE
${_sources}
)

