# Machine Learning Specs
### Python libraries currently using:
**Yolov8**
ultralytics (v8.0.222)
**Pytorch**
torch (v2.1.1)
torchvision (v0.16.1)

Training images are annotated using CVAT https://app.cvat.ai/

### To begin using models:
- install python and libraries specified above
- adjust config.yaml file to use your file paths
- Ensure images and labels are placed in the "data/images" and "data/labels" folders
- set launch_training.py file to either validate or train a model
- run launch_training.py