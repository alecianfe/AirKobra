# AirKobra 
------installare roamros su ros ------

0.ROS FUNZIONANTE!
1.eseguire "sudo apt-get install libsuitesparse-dev libeigen3-dev libboost-all-dev"
2.copiare il contenuto della cartella "src" all'interno di "catkin_ws"
3.eseguire "cd catkin_ws" poi "catkin_make --pkg roamros -DCMAKE_BUILD_TYPE=Debug"
3.b(Optional).eseguire ". ~/catkin_ws/devel/setup.bash"
4.eseguire "roscore"
5.eseguire "cd catkin_ws/src/roamros/launch" poi "roslaunch roamros roamros.launch"
