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
* Strategy - This pattern will be useful because it lets us take take advantage of subclasses and virtual functions. We want to be able to call the same algorithm on two different subclasses and have it do two separate things. For example, we want to use this pattern to help facilitate book recommendations. These two separate book recommendation algorithms will recommend based off of books the user like and off of popular books in the library. 
* Composite - This pattern will let us use a tree-like structure where a part can contain a whole while still treating each part similarly. A user will be able create a book list containing multiple books. Additionally, a book list can contain another book list and it is treated exactly the same as if we were dealing with just an individual book. Therefore, a books list is a composite of books and book lists.


## Class Diagram
 ![alt text](https://github.com/cs100/final-project-jprin012-pkati001-ryang038/blob/master/Library%20Book%20System.png)

The library system is in charge of holding all of the books and will only have the file of one user open at a time (whoever is logged in). There are 2 types of users, a     standard user and an admin. An admin should be able to do everything a standard user can do plus the ability to add and remove books from the library. The Strategy class will be used to facilitate user book recommendations so it would be an aggregation.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 Logging in:
 
 ![alt text](https://github.com/cs100/final-project-jprin012-pkati001-ryang038/blob/master/images/login.png)
 
 Output library:
 ![alt text](https://github.com/cs100/final-project-jprin012-pkati001-ryang038/blob/master/images/OutputLibrary.png)
 
 Checked out books:
 ![alt text](https://github.com/cs100/final-project-jprin012-pkati001-ryang038/blob/master/images/CheckedOut.png)
 
 Return book:
 
 ![alt text](https://github.com/cs100/final-project-jprin012-pkati001-ryang038/blob/master/images/Return.png)
 
 Recommendations:
 ![alt text](https://github.com/cs100/final-project-jprin012-pkati001-ryang038/blob/master/images/recommend.png)
 
 Create list:
 
 ![alt text](https://github.com/cs100/final-project-jprin012-pkati001-ryang038/blob/master/images/CreateList.png)
 
 View lists:
 
 ![alt text](https://github.com/cs100/final-project-jprin012-pkati001-ryang038/blob/master/images/ViewLists.png)
 
 Add book (admin only):
 
 ![alt text](https://github.com/cs100/final-project-jprin012-pkati001-ryang038/blob/master/images/AddBook.png)
 
 Remove book (admin only):
 ![alt text](https://github.com/cs100/final-project-jprin012-pkati001-ryang038/blob/master/images/RemoveBook.png)
 ## Installation/Usage
 * Click on the Green "Code" Box at the top corner 
 * Copy link under "HTTPS"
 * In your own terminal, run "git clone --recursive [link]"
 * Make sure that CMake is installed on your system
 ## Testing
 Our project was tested through the use of googletest. We made test files for every class that contain the unit tests for each class's specific functions.  
