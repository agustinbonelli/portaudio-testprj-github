# makefile
#
# Created on: 16 Jun 2014
#     Author: bone
#

BUILD_DIR = build

OUTPUT = portaudio-product.out

SOURCES = bone-main.c

LIBRARIES = -lportaudio

FLAGS = -Wall -pedantic

all:
	gcc -o ${OUTPUT} ${SOURCES} ${LIBRARIES}
	mv ${OUTPUT} ${BUILD_DIR}
	