import os
import platform

# OS: UNIX BASED
if (platform.system() != "Windows"):
	os.system("cmake ../Unix/.")
	os.system("make -C ../Unix/.")
	os.system("../Unix/Optimotive")
# OS: WINDOWS
else:
	os.system("../Optimotive/Debug/Optimotive.exe")
