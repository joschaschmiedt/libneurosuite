###################
# Build library #
###################
include_directories(gui/page)

set(SOURCE_FILES
    gui/qrecentfileaction.cpp
    gui/qcolorbutton.cpp
    gui/page/qpagedialog.cpp
    gui/page/qpagemodel.cpp
    gui/page/qpageview.cpp
    gui/page/qpageview_p.cpp
    gui/page/qpagewidget.cpp
    gui/page/qpagewidgetmodel.cpp
    gui/page/qextenddialog.cpp
    gui/page/klusterseparator.cpp
    gui/dockarea.cpp
    gui/qextendtabwidget.cpp
    gui/qhelpviewer.cpp
    gui/klusterrubberband.cpp
    shared/channelcolors.cpp
    shared/itemcolors.cpp
    shared/zoomwindow.cpp
    shared/utilities.cpp
)


# Add ressource files
set(RESSOURCE_FILES
    gui/libneurosuite-icons.qrc
    gui/libneurosuite-cursors.qrc
)


# Run compiler
add_library (${PROJECT_NAME} SHARED ${SOURCE_FILES})
set_target_properties(${PROJECT_NAME}
    PROPERTIES CXX_VISIBILITY_PRESET hidden
)

################
# Link library #
################
target_link_libraries(${PROJECT_NAME} Qt6::Widgets Qt6::PrintSupport Qt6::WebEngineWidgets)

###################
# Install library #
###################
# Group headers in subfolder
set(INCLUDE_FILE_DESTINATION "include/${PROJECT_NAME}")

install(TARGETS ${PROJECT_NAME}
        EXPORT LibraryTargets
        DESTINATION lib
        INCLUDES DESTINATION ${INCLUDE_FILE_DESTINATION})

set (HEADER_FILES
     libneurosuite_export.h
     gui/qrecentfileaction.h
     gui/qcolorbutton.h
     gui/page/qpagedialog.h
     gui/page/qextenddialog.h
     gui/page/qpagewidget.h
     gui/page/qpagemodel.h
     gui/page/qpageview.h
     gui/page/qpagewidgetmodel.h
     gui/dockarea.h
     gui/qextendtabwidget.h
     gui/qhelpviewer.h
     gui/klusterrubberband.h
     shared/channelcolors.h
     shared/itemcolors.h
     shared/types.h
     shared/array.h
     shared/utilities.h
     shared/zoomwindow.h
)

install(FILES ${HEADER_FILES}
        DESTINATION ${INCLUDE_FILE_DESTINATION})
