if(QT_VERSION_MAJOR EQUAL 6)
    set_property(TARGET quazip PROPERTY INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}/qt6/include")
    set_property(TARGET quazip PROPERTY IMPORTED_LOCATION "${CMAKE_CURRENT_LIST_DIR}/qt6/lib/libquazip1-qt6.a")
else()
    set_property(TARGET quazip PROPERTY INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}/qt5/include")
    set_property(TARGET quazip PROPERTY IMPORTED_LOCATION "${CMAKE_CURRENT_LIST_DIR}/qt5/lib/libquazip1-qt5.a")
endif()
