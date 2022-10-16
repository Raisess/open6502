CXX=clang++ -std=c++14

SRC_DIR=./src
SRC=$(SRC_DIR)/main.cpp \
		$(SRC_DIR)/CPU.cpp \
		$(SRC_DIR)/Stack.cpp \
		$(SRC_DIR)/DataBus.cpp \
		$(SRC_DIR)/Instruction.cpp

OUT_DIR=./build
OUT=$(OUT_DIR)/main.o

fun:
	make clean
	make build
	make run

build:
	mkdir -p $(OUT_DIR)
	$(CXX) $(SRC) -o $(OUT)

run:
	$(OUT)

clean:
	rm -rf $(OUT_DIR)

test:
	make clean
	make build
	echo -e "LDA #$0A\nLDX #$05\nORA #$01\nINX\nBRK\n"
	$(OUT) A9 0A A2 05 09 01 E8 00
