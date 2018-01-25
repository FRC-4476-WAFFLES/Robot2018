cmake_minimum_required (VERSION 2.8.11)
project (Robot2018)

set (ENV{WPILIB} $ENV{HOME}/wpilib)
set (CMAKE_CXX_STANDARD 11)

link_directories (
	/usr/arm-frc-linux-gnueabi/lib
	$ENV{WPILIB}/common/current/lib/linux/athena/shared
	$ENV{WPILIB}/cpp/current/reflib/linux/athena/shared
	$ENV{WPILIB}/user/cpp/lib
)

file(GLOB_RECURSE SRCS src/*.cpp)
add_executable (FRCUserProgram ${SRCS})

target_include_directories (FRCUserProgram
	PRIVATE /usr/arm-frc-linux-gnueabi/include
	PRIVATE $ENV{WPILIB}/cpp/current/include
	PRIVATE $ENV{WPILIB}/user/cpp/include
	PRIVATE src
)
target_link_libraries (FRCUserProgram
	LINK_PRIVATE CTRE_Phoenix
	LINK_PRIVATE CTRE_PhoenixCCI
	LINK_PRIVATE wpi
	LINK_PRIVATE pthread
)

