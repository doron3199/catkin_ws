in this porject I build a program that make the turtule bot navigate in my ER.world
using the turtule bot simolator that use the packege slam_gmappoing I mapped my world.
then i cheked if the navigation works using tutlebot navigation that using amcl.
now with both of them i build pick objects, that sending navigation goals and tha packege drive
the robot to them.  
localization - 
the turtule bot localization package using amcl algorithm to determent where the robot is.
the amcl algorithm "sprades" particles in the world and for each one calcultes its chanses to be the robot location using mesurments from the particles to fixed known points. by that the algorithm is giving a score to each patrical. we can see that as the score is red arond the robot in rviz.
mapping - 
the slam gmapping using gmapping packege, the algorithm gets a laser scan and pose data
and creates 2-D occupancy grid map, similarly to amcl this method also uses particels to navigate and also to save data and detement the map. for more imformation visit gmapping of open slam 
https://openslam-org.github.io/gmapping.html
navigation -
from http://wiki.ros.org/turtlebot_navigation 
"This package includes demos of map building using gmapping and localization with amcl, while running the navigation stack."
this packege let you to create map with slam, and after the map is created you can give the robot instruction and it will autonemsly go to the location you gave to it.