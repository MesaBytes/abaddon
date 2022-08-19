function (add_imported_library headers)
    add_library(nlohmann_json::nlohmann_json INTERFACE IMPORTED)
    set_target_properties(nlohmann_json::nlohmann_json PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES ${headers}
    )
    set(nlohmann_json_FOUND 1 CACHE
        INTERNAL "nlohmann_json found" FORCE)
    set(nlohmann_json_INCLUDES ${headers}
        CACHE STRING "Path to nlohmann_json headers" FORCE)
    mark_as_advanced(FORCE nlohmann_json_INCLUDES)
endfunction ()

if (nlohmann_json_INCLUDES)
    add_imported_library(${nlohmann_json_INCLUDES})
    return()
endif ()

file(TO_CMAKE_PATH "$ENV{nlohmann_json_DIR}" _nlohmann_json_DIR)
find_path(nlohmann_json_HEADER_PATH NAMES nlohmann/json.hpp
    PATHS
        ${_nlohmann_json_DIR}/include
        /usr/include
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
    nlohmann_json
    DEFAULT_MSG
    nlohmann_json_HEADER_PATH
)

if (nlohmann_json_FOUND)
    add_imported_library("${nlohmann_json_HEADER_PATH}")
endif ()
