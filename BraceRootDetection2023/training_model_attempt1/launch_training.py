from ultralytics import YOLO

model = YOLO("runs/detect/train10/weights/best.pt")

#results = 

#Run the line below to train the model
#model.train(data="config.yaml", epochs=300)

#Run the line below to validate the model
results = model.val()
print("DOne!!!!!!")
print(type(results))
#print(results)
