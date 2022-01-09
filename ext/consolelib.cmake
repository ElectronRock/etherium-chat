# Download hope
ExternalProject_Add(
    consolelib
    PREFIX "ext"
    GIT_REPOSITORY "https://github.com/glensand/congenial-disco"
    GIT_TAG v0.1.0-alfa
    TIMEOUT 10
    CMAKE_ARGS
        -DDISCO_BUILD_TESTS=OFF
        -DDISCO_BUILD_EXAMPLES=OFF
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    UPDATE_COMMAND ""
)

ExternalProject_Get_Property(consolelib source_dir binary_dir)
set(CCL_LIB_INCLUDE_DIR ${source_dir}/lib)
set(CCL_LIB_DIR ${binary_dir})