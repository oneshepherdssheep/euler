#!/bin/bash

#################################################
# Generates an empty CMake Project containing   #
# - main.cpp					#
# - CMakeLists.txt				#
#						#
# Takes as argument the number of the project	#
#################################################

TRUE=1
FALSE=0

#################################################
# GenerateCmakelistsDotTxt			#
#################################################

GenerateCmakelistsDotTxt () {
	fileName="$1/CMakeLists.txt"
	projectLine="project(challenge$2)"
	executableLine="add_executable(challenge$2 main.cpp)"
	cat <<- EOF > $fileName
	cmake_minimum_required(VERSION 3.20)
	$projectLine
	set(CMAKE_CXX_STANDARD 11)
	link_libraries(nanobench)
	$executableLine
	EOF
	chmod 644 $fileName
}

#################################################
# GenerateMainDotCpp				#
#################################################

GenerateMainDotCpp () {
	fileName="$1/main.cpp"
	cat << EOF > $fileName
#include <iostream>
#include <cstdint>

int main(){
	return EXIT_SUCCESS;
}
EOF
	chmod 644 $fileName
}

#################################################
# GenerateDotGitignore                          #
#################################################

GenerateDotGitignore () {
	fileName="$1/.gitignore"
	cat <<- EOF > $fileName
  # ignore build directory
  cmake-*
  # ignore IDE specific directory
  .idea*
  # ignore .i files
  *.i
  # ignore .cfg files
  *.cfg
	EOF
	chmod 644 $fileName
}

#################################################
# GenerateReadme                                #
#################################################

GenerateReadme () {
	fileName="$1/README.md"
	cat <<- EOF > $fileName
	<a id="top"></a>
	# <Challenge Title Here>
	## Description
	Description here
	## Understanding
	Understanding here
	## Benchmarking
	EOF
	chmod 644 $fileName
}

#################################################
# CreateChallengeDirectory                      #
#################################################

CreateChallengeDirectory () {
	mkdir --mode=755 $1
}

#################################################
# IsAnUnsignedNumber                            #
#################################################

IsAnUnsignedNumber () {
	if [[ $1 =~ ^[0-9]+$ ]]; then
		echo $TRUE
	else
		echo $FALSE
	fi
}

#################################################
# PrintHelp					#
#################################################

PrintHelp () {
	echo " ---------------------- "
        echo " Wrong calling. "
        echo " usage: $0 <n> "
        echo " with <n> being a digit "
        echo " E.g: $0 7 "
	echo " ---------------------- "
}

#################################################
# Script starts here    			#
#################################################

if [ $# -eq 1 ]; then
	if [ "$(IsAnUnsignedNumber $1)" -eq "$TRUE" ]; then
		ChallengeDirectoryName="challenge"$1
		if [ -d "$ChallengeDirectoryName" ]; then
			echo "$ChallengeDirectoryName already exists."
		else
			echo "Creating project folder $ChallengeDirectoryName ..."
			CreateChallengeDirectory $ChallengeDirectoryName
			GenerateCmakelistsDotTxt $ChallengeDirectoryName $1
			GenerateReadme $ChallengeDirectoryName $1
			GenerateMainDotCpp $ChallengeDirectoryName
			GenerateDotGitignore $ChallengeDirectoryName
		fi
	else
		PrintHelp
	fi
else
	PrintHelp
fi
