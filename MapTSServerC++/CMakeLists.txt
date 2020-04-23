# CMakeList.txt : projet CMake pour MapTSServerC++, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.15)

set(Boost_USE_MULTITHREADED ON)

FILE(GLOB SRC *.cpp)
FILE(GLOB SRC_ENTITY entity/*.cpp)
FILE(GLOB SRC_UNIT entity/unit/*.cpp)
FILE(GLOB SRC_SERVER server/*.cpp)

find_package(Boost REQUIRED COMPONENTS log log_setup system)
find_package(Flatbuffers CONFIG REQUIRED)

find_path(EVPP_INCLUDE_DIR evpp/tcp_server.h)
find_path(FLATBUFFERS_INCLUDE_DIR NAMES flatbuffers/flatbuffers.h)

find_library(EVPP_LIBRARY evpp_static)
find_library(GLOG_LIBRARY glog)
find_library(EVENT_LIBRARY event)
find_library(EVENT_CORE_LIBRARY event_core)
find_library(EVENT_EXTRA_LIBRARY event_extra)

include_directories(${EVPP_INCLUDE_DIR})
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${FLATBUFFERS_INCLUDE_DIR})
# Ajoutez une source à l'exécutable de ce projet.
add_executable (MapTSServerC++ ${SRC} ${SRC_ENTITY} ${SRC_UNIT} ${SRC_SERVER})

target_link_libraries(MapTSServerC++ ${Boost_LIBRARIES} flatbuffers::flatbuffers ${EVPP_LIBRARY} ${GLOG_LIBRARY} ${EVENT_LIBRARY} ${EVENT_CORE_LIBRARY} ${EVENT_EXTRA_LIBRARY})


set_property(TARGET MapTSServerC++ PROPERTY CXX_STANDARD 20)

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
