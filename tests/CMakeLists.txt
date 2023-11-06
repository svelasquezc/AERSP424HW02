foreach(X IN ITEMS 5 7)
    add_executable(Question${X} Question${X}.cpp)

    target_include_directories(Question${X} PUBLIC ../include)

    target_link_libraries(Question${X} PRIVATE airportControl)

    add_test(NAME Question${X} COMMAND Question${X})    
endforeach()