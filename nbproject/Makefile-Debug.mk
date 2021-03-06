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
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/linkedlist/linklist_sample.o \
	${OBJECTDIR}/src/linkedlist/linklist_head.o \
	${OBJECTDIR}/src/trees/BST.o \
	${OBJECTDIR}/src/basicsort.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/datastructures

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/datastructures: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/datastructures ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/linkedlist/linklist_sample.o: src/linkedlist/linklist_sample.c 
	${MKDIR} -p ${OBJECTDIR}/src/linkedlist
	${RM} $@.d
	$(COMPILE.c) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/linkedlist/linklist_sample.o src/linkedlist/linklist_sample.c

${OBJECTDIR}/src/linkedlist/linklist_head.o: src/linkedlist/linklist_head.c 
	${MKDIR} -p ${OBJECTDIR}/src/linkedlist
	${RM} $@.d
	$(COMPILE.c) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/linkedlist/linklist_head.o src/linkedlist/linklist_head.c

${OBJECTDIR}/src/trees/BST.o: src/trees/BST.c 
	${MKDIR} -p ${OBJECTDIR}/src/trees
	${RM} $@.d
	$(COMPILE.c) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/trees/BST.o src/trees/BST.c

${OBJECTDIR}/src/basicsort.o: src/basicsort.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/basicsort.o src/basicsort.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/datastructures

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
