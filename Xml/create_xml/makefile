GCC = gcc
target = app

src = $(wildcard ./*.c)

$(target):$(obj)
	$(GCC) $^ -o $@

.PHONY:clean
	-rm $(target) $(obj) -f
