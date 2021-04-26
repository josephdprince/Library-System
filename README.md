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
* Strategy - This pattern will be useful because it lets us take take advantage of subclasses and virtual functions. We want to be able to call the same algorithm on two different subclasses and have it do two separate things. For example, calling the run() function on an admin should put them in an administrator view while on a standard user it should not do that. We anticipate that using this strategy will help us encapusulate the structure of the system.
Since the user will run a command the same way regardless of their status, they are unaware of the mechanisms of the
system and only need to concern themselves with which command they want to run.
* Factory Method - This pattern lets us defer all instantiation to a subclass. We want our User class to be pure virtual so that we can create different kinds of users in the system similarly. Using factory method will help us reduce the amount of repeated code when making each type of user. This helps because each subclass will have the same functions and private data, but with different implementations.

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
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
 
