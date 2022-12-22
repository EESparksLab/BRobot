
from usb.core import find as finddev
dev = finddev(idVendor=0x03eb, idProduct=0x2404)
if dev is None:
    print("Not finding the device")
else:
    print(dev)
dev.reset()
