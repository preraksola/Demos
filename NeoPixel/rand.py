import requests
from random import randint
for i in range(64):
    r=randint(0,127)
    g=randint(0,(127-r))
    b=randint(0,(127-g))
    payload={'led':i,'R':str(r),'G':str(g),'B':str(b)}
    requests.post("https://api.onion.io/v2/devices/kfItpX9p/set",data=payload)
