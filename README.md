# Library System 
 Authors: 
  
 [Puloma Katiyar](https://github.com/puloma-k)
 
 [Joseph Prince](https://github.com/josephdprince)
  
 [Raymond Yang](https://github.com/raymyun)
 
## Project Description
This project is important to us because it allows us to incorporate design patterns learned in class
to a useful program that can be applied in the real world. It will help us understand the methods of
collaboration via GitHub and give us an insight into how software development is completed at the industry level. The project idea is
interesting to us because of the variety of features in the design. Creating a login system and providing recommendations to users based on
past activity are features that we have not implemented before, so it will provide an interesting challenge. In addition, this project can be 
expanded to many levels of complexity and we can continue to build on it even after completing this course.

This project will be composed entirely in C++ and use the following tools/technologies:
* Valgrind - used to facilitate memory managemnt
* CMake - used to simplify the compilation process
* Kanban Board - to help keep everything organized while giving each group member a task to complete

Project Specifications:
* input/output - A user may input their username and password to log into the library system. Afterwards, various inputs will allow them to perform different operations within the system. An output may be a list of favorite books or the title of books that were rented out. 
 
Design Patterns:  
* Strategy - This pattern will be useful because it lets us take take advantage of subclasses and virtual functions. We want to be able to call the same algorithm on two different subclasses and have it do two separate things. For example, we want to use this pattern to help facilitate book recommendations. This would be done in combination with a composite pattern to allow a user to select what they like and what they don't like. We would have subclasses that all have their own implementation of the algorithm that would let us get a list of books we would like while removing books we wouldn't like. We could use AND and NOT subclasses that facilitate this. 
* Composite - This pattern will let us use a tree-like structure where a part can contain a whole while still treating each part similarly. Essentially, we would have a structure of AND and NOT nodes that give us a way to select which books we like and don't like. The AND, NOT, and each individual book would all derive from the same class so they can be treated similarly. The AND and NOT objects can either hold books or another AND/NOT objects.


## Class Diagram
 ![alt text](https://github.com/cs100/final-project-jprin012-pkati001-ryang038/blob/master/Library%20Book%20System.png)
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
