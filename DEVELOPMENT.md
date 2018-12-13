**Week 1 Progress**  
Found library ofxBox2d and implemented a simple simulation that involved two balls colliding.  
**Week 2 Progress**  
Created new Pendulum Simulation that simulates the movement of a simple pendulum.  
Moved the Two Balls simulation to its own class.  
Created simple object decomposition that involves putting each simulation into it's own class and having it's own setup, draw, and update methods.  
Added test cases to test simple helper functions and instantiating variable values.  
**Week 3 Progress**  
Created 3 new Simulations: Chaotic Pendulum Simulation, Buoyancy Simulation, Mirror Lens Simulation.  
Chaotic Pendulum builds upon the first pendulum simulation, just adding another pendulum to the end of the original one.  
Buoyancy Simulation is a work in progress, but is intended to use the ofxbox2d library to create simulation of a box dropping in water.  
The Mirror Lens Simulation is intended to display what happens to the image in a mirror or lens when the object height or distance or the focal length is changed.
**Week 4 Progress**  
All simulations have been finished.  
The Buoyancy Simulation now works as intended, and the Mirror Simulation now has ray tracing to show the correlation between the object and the image.  
A constants file has been added for each simulation, where constants such as parameter bounds and background colors have been stored. 
