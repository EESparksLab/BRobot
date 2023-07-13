img = ImageGrab.grab(mask)
 pixels = img.load()
 width, height = img.size
 coords = []

for x in range(width):
     for y in range(height): 
         if pixels[x,y] == (255, 255, 255):
             coords.append((x))
 def Average(lst):
     return sum(lst) / len(lst)
 
 avg = Average(coords)
 print(coords)
 print(avg)
 
 
