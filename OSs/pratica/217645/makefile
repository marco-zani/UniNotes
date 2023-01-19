FILE="./log"


SignalProxy:main.c $(FILE)
	@gcc -o SignalProxy main.c


$(FILE):
	@touch $(FILE)
	@echo "start" >> $(FILE)

clean:
	@rm SignalProxy $(FILE)