#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/include/Camera.o \
	${OBJECTDIR}/include/HitTrace.o \
	${OBJECTDIR}/include/Material.o \
	${OBJECTDIR}/include/Random.o \
	${OBJECTDIR}/include/Ray.o \
	${OBJECTDIR}/include/Renderer.o \
	${OBJECTDIR}/include/Scene.o \
	${OBJECTDIR}/include/Sphere.o \
	${OBJECTDIR}/include/Window.o \
	${OBJECTDIR}/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f2

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/CameraTest.o \
	${TESTDIR}/tests/RotationsTest.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lpthread -lm `pkg-config --libs sdl2`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ray-net

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ray-net: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ray-net ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/include/Camera.o: include/Camera.cpp
	${MKDIR} -p ${OBJECTDIR}/include
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/Camera.o include/Camera.cpp

${OBJECTDIR}/include/HitTrace.o: include/HitTrace.cpp
	${MKDIR} -p ${OBJECTDIR}/include
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/HitTrace.o include/HitTrace.cpp

${OBJECTDIR}/include/Material.o: include/Material.cpp
	${MKDIR} -p ${OBJECTDIR}/include
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/Material.o include/Material.cpp

${OBJECTDIR}/include/Random.o: include/Random.cpp
	${MKDIR} -p ${OBJECTDIR}/include
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/Random.o include/Random.cpp

${OBJECTDIR}/include/Ray.o: include/Ray.cpp
	${MKDIR} -p ${OBJECTDIR}/include
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/Ray.o include/Ray.cpp

${OBJECTDIR}/include/Renderer.o: include/Renderer.cpp
	${MKDIR} -p ${OBJECTDIR}/include
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/Renderer.o include/Renderer.cpp

${OBJECTDIR}/include/Scene.o: include/Scene.cpp
	${MKDIR} -p ${OBJECTDIR}/include
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/Scene.o include/Scene.cpp

${OBJECTDIR}/include/Sphere.o: include/Sphere.cpp
	${MKDIR} -p ${OBJECTDIR}/include
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/Sphere.o include/Sphere.cpp

${OBJECTDIR}/include/Window.o: include/Window.cpp
	${MKDIR} -p ${OBJECTDIR}/include
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/Window.o include/Window.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/CameraTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/RotationsTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS}   


${TESTDIR}/tests/CameraTest.o: tests/CameraTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -I. `pkg-config --cflags sdl2`   -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/CameraTest.o tests/CameraTest.cpp


${TESTDIR}/tests/RotationsTest.o: tests/RotationsTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -I. `pkg-config --cflags sdl2`   -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/RotationsTest.o tests/RotationsTest.cpp


${OBJECTDIR}/include/Camera_nomain.o: ${OBJECTDIR}/include/Camera.o include/Camera.cpp 
	${MKDIR} -p ${OBJECTDIR}/include
	@NMOUTPUT=`${NM} ${OBJECTDIR}/include/Camera.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2`   -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/Camera_nomain.o include/Camera.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/include/Camera.o ${OBJECTDIR}/include/Camera_nomain.o;\
	fi

${OBJECTDIR}/include/HitTrace_nomain.o: ${OBJECTDIR}/include/HitTrace.o include/HitTrace.cpp 
	${MKDIR} -p ${OBJECTDIR}/include
	@NMOUTPUT=`${NM} ${OBJECTDIR}/include/HitTrace.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2`   -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/HitTrace_nomain.o include/HitTrace.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/include/HitTrace.o ${OBJECTDIR}/include/HitTrace_nomain.o;\
	fi

${OBJECTDIR}/include/Material_nomain.o: ${OBJECTDIR}/include/Material.o include/Material.cpp 
	${MKDIR} -p ${OBJECTDIR}/include
	@NMOUTPUT=`${NM} ${OBJECTDIR}/include/Material.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2`   -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/Material_nomain.o include/Material.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/include/Material.o ${OBJECTDIR}/include/Material_nomain.o;\
	fi

${OBJECTDIR}/include/Random_nomain.o: ${OBJECTDIR}/include/Random.o include/Random.cpp 
	${MKDIR} -p ${OBJECTDIR}/include
	@NMOUTPUT=`${NM} ${OBJECTDIR}/include/Random.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2`   -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/Random_nomain.o include/Random.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/include/Random.o ${OBJECTDIR}/include/Random_nomain.o;\
	fi

${OBJECTDIR}/include/Ray_nomain.o: ${OBJECTDIR}/include/Ray.o include/Ray.cpp 
	${MKDIR} -p ${OBJECTDIR}/include
	@NMOUTPUT=`${NM} ${OBJECTDIR}/include/Ray.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2`   -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/Ray_nomain.o include/Ray.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/include/Ray.o ${OBJECTDIR}/include/Ray_nomain.o;\
	fi

${OBJECTDIR}/include/Renderer_nomain.o: ${OBJECTDIR}/include/Renderer.o include/Renderer.cpp 
	${MKDIR} -p ${OBJECTDIR}/include
	@NMOUTPUT=`${NM} ${OBJECTDIR}/include/Renderer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2`   -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/Renderer_nomain.o include/Renderer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/include/Renderer.o ${OBJECTDIR}/include/Renderer_nomain.o;\
	fi

${OBJECTDIR}/include/Scene_nomain.o: ${OBJECTDIR}/include/Scene.o include/Scene.cpp 
	${MKDIR} -p ${OBJECTDIR}/include
	@NMOUTPUT=`${NM} ${OBJECTDIR}/include/Scene.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2`   -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/Scene_nomain.o include/Scene.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/include/Scene.o ${OBJECTDIR}/include/Scene_nomain.o;\
	fi

${OBJECTDIR}/include/Sphere_nomain.o: ${OBJECTDIR}/include/Sphere.o include/Sphere.cpp 
	${MKDIR} -p ${OBJECTDIR}/include
	@NMOUTPUT=`${NM} ${OBJECTDIR}/include/Sphere.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2`   -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/Sphere_nomain.o include/Sphere.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/include/Sphere.o ${OBJECTDIR}/include/Sphere_nomain.o;\
	fi

${OBJECTDIR}/include/Window_nomain.o: ${OBJECTDIR}/include/Window.o include/Window.cpp 
	${MKDIR} -p ${OBJECTDIR}/include
	@NMOUTPUT=`${NM} ${OBJECTDIR}/include/Window.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2`   -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/Window_nomain.o include/Window.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/include/Window.o ${OBJECTDIR}/include/Window_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2`   -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
