# Safe-Sense
 For a tkkyia project

# Problem-Analysis
 PMD accidents have been on the rise as of late, due to its adoption in other countries.<br>
 - USA: 70 644 emergency department visits for e-scooter cases from 2014-2019<br>
 - South Korea: amount of reported accidents rose 4.6 times from 2017 to 2019, <br>
 - 8 deaths involving PMDs in 2019 <br>
 PMD accidents can range from minor abrasion to head trauma and fractures and even death. <br>
 Citizens should not only be protected from these accidents, <br>
 but also have the right to feel safe on walkways. <br>

# Methodology-preramble
 The idea of solving PMD accidents is very broad. <br>
 Current solutions and methods all target the education of humans, <br>
 having them take mandotary classes and tests before being able to even own a PMD, <br>
 posters and advertisement trying to teach people. <br>
 However, this has proven to be rather ineffective. <br>

# Methodology
 Thus, to solve this, instead of targeting the human, <br>
 I've decided to target the computer instead. <br>
 How can the PMD be coded to prevent accidents? <br>
 Well, the system that I've landed on works on 2 layers of protection: <br>
 1. The camera <br>
    - A camera installed on the PMD has built in human detection AI. <br>
    - When a human is detected, the PMD is slowed down to a speed of 15km/h. <br>
        - 15km/h was decided because this speed is still relatively fast, but mitigates damages on impact and allows for the human to react.
2. The ultrasonic sensor <br>
    - If an object is detected 1m in front of the PMD, all actions in part 1 is negated. <br>
    - Instead, the PMD will match the speed of the detected object. <br>
    - How is this done with just an ultrasonic sensor? <br>
        - The algorithm works as such. <br>
        - Imagine you and your friend are both walking, your friend being in front of you. <br>
        - Say you both walks at a speed of 6km/h. <br>
            - In that case, take yourself as a reference point and ask, "how fast is he moving in reference to me?" <br>
            - The answer is that he is stationary with reference to you(, while everything else is moving backwards, at a speed of 6km/h). <br>
        - Now, say you walk at a speed of 6km/h while he walks at a speed of 5km/h. <br> 
            - Again, take yourself as a reference point and ask, "how fast is he moving in reference to me?" <br>
            - The answer is that he is moving at a speed of -1km/h, or in other words, you are moving towards him at a speed of 1km/h(, and everything else is moving backwards, at a speed of 6km/h.) <br>
        - With this logic, we know that if the PMD is moving towards an object going slower than it, <br>
         their distance will start reducing (obviously). <br>
        - Thus, the PMD needs to keep slowing down until it their distance remains constant. <br>
        - Therefore, the algorithm for this is that the PMD keeps reading a distance and slowing down until their distance remains constant/  doesn't get smaller, <br>
        which means their speed matches up/ the PMD is slwer than the object. <br>
    - Now if you are wondering, what if the PMD is not moving towards a human, wouldn't it still slow down? <br>
    - Yes, yes it will, but if you are speeding towards a stationary object just 1m in front of you, you still need to slow down. <br>

# Final Product
 The final product is an attachment to PMDs that include:
 - An arduino (Leonardo) <br>
 - an ultrasonic sensor, <br>
 - a HuskyLens (which is the camera sensor), <br>
 - wires, resistors, diodes, a breadboard <br>
 - and a battery. <br>
 As the hardware, <br>
 Using Arduino IDE as the software. <br>
 Which will: <br>
 - Slow down to 15km/h <br>
    - when there is a person detected, more than 1m away. <br>
 - And will slow down to match the speed of any object 1m in front of the PMD. <br>
All the hardware will be seated in specially designed and 3d-printed cases to protect from the elements and possible impacts. <br>

# Outstanding Issues
 While it is all tested in theory, using a simulation (using a motor in place of a PMD) <br>
 It has yet to be tested on an actual PMD due to: <br>
 1. The legal repercussions, <br>
    1.1 I am not of legal age to obtain a PMD, <br>
    1.2 The grey area of modifying a PMD, especially with regards to its speed, <br>
 2. and my inexpertise on this area (tampering with the electronics in a PMD, although I am willing to learn). <br><br>