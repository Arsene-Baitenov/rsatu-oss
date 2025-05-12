import platform
import os


print("OS:", platform.system())
print("OS version:", platform.version())
print("Architecture:", platform.machine())

print("Executable ext:", ".exe" if os.name == "nt" else "no ext")
