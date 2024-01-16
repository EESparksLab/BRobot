from ultralytics import YOLO

#Replace "train10" with the most recent/best model available. Currently, train10 has the best model available
model = YOLO("runs/detect/train10/weights/best.pt")

#Run the line below to train the model
#model.train(data="config.yaml", epochs=300)

#Run the line below to validate the model
results = model.val()
print(results)
