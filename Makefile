VERSION=1.0
MAJOR_VERSION=1
LIB=libcirculer_queue.so

build: 
	@cd objs&&make build&&cd ..
	@./build_dep.sh $(LIB) $(VERSION) $(MAJOR_VERSION)
	@echo "build"

clean:$(wildcard ./objs/*.o)
	@rm -f objs/*.o
	@echo cleaned