cmake_minimum_required (VERSION 4.2)

project (
	"anders"
	VERSION 0.0.0
	LANGUAGES C
)

include_directories (include)
add_library (${PROJECT_NAME}
	src/logg.c
	include/anders/logg.h
	src/matrix.c
	src/math.c
	src/vector.c
#	include/anders/matrix.h
#	include/anders/types.h
#	include/anders/util.h
#	include/anders/vector.h
)
target_link_libraries (${PROJECT_NAME} m)

install (
	DIRECTORY   ./include/anders
	DESTINATION /usr/include
)
install (
	TARGETS             ${PROJECT_NAME}
	LIBRARY DESTINATION /usr/lib
)

#install (TARGETS ${PROJECT_NAME} DESTINATION $ENV{HOME}/.local/bin)
#CMAKE_CURRENT_SOURCE_DIR
