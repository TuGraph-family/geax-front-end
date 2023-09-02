add_subdirectory(parser)

set(ISO_GQL_SRC
    GQLAstVisitor.cpp
    GEAXErrorCode.cpp
)

add_library(ali_isogql
    ${ISO_GQL_SRC}
)
target_compile_features(ali_isogql PRIVATE cxx_std_17)

target_link_libraries(ali_isogql
    PUBLIC
        isogql_parser
        Boost::boost
        Antlr4::runtime
)
if (GEAX_ENABLE_JEMALLOC)
    target_link_libraries(ali_isogql PUBLIC Jemalloc::jemalloc)
endif()
if (GEAX_ENABLE_GLOG)
    target_link_libraries(ali_isogql PUBLIC GLog::glog)
endif()

target_include_directories(ali_isogql
    INTERFACE
        ${GEAX_PROJECT_DIR}/include
)

if(GEAX_INSTALL)
    install(
        TARGETS
            ali_isogql
        LIBRARY DESTINATION lib
    )
endif()
