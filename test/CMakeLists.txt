set(TEST_SOURCE_FILES
    main.cpp
    listview.cpp
    mainview.cpp
    scrollarea.cpp
    itemgroupview.cpp
)

add_executable(test_scrollview ${TEST_SOURCE_FILES})

target_link_libraries(test_scrollview Qt6::Widgets)

install(TARGETS test_scrollview
        DESTINATION bin
)
