# build the image 
📝open the terminal inside this folder 
```
docker build -t nvidia_ros:focal . #this used to build the image 
```
# Run the image 
## windows
### With Nvidia GPU and GUI
1. Install Xserver from the following link : [https://sourceforge.net/projects/vcxsrv/](Xserver)
2. Run the following command ```docker run --runtime=nvidia -e DISPLAY=host.docker.internal:0.0 -it nvidia_ros:focal```
#### Setup the Xserver
Watch the following video from 18:14 min
https://youtu.be/qWuudNxFGOQ
