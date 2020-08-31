import subprocess
import time

cmd=["node","webSocket.js"]
proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)

while True:
    line = proc.stdout.readline().decode("utf8")
    line = line.replace("\n","")
    if line=="light on":
        print("light on")
        result=subprocess.run(["sudo","./ir","0"],stdout=subprocess.PIPE)
    elif line=="light off":
        print("light off")
        result=subprocess.run(["sudo","./ir","1"],stdout=subprocess.PIPE)
    elif line=="air con on":
        print("air con on")
        result=subprocess.run(["sudo","./ir","2"],stdout=subprocess.PIPE)
    elif line=="air con off":
        print("air con off")
        result=subprocess.run(["sudo","./ir","3"],stdout=subprocess.PIPE)
    else:
        print("error : "+line)
    time.sleep(1)
