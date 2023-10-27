# Library System 
 Authors: 

 [Joseph Prince](https://github.com/josephdprince)
  
 [Puloma Katiyar](https://github.com/puloma-k)
  
 [Raymond Yang](https://github.com/raymyun)
 
## Project Description
This project is composed entirely in C++ and use the following tools/technologies:
* Valgrind - used to facilitate memory managemnt
* CMake - used to simplify the compilation process
* Kanban Board - to help keep everything organized while giving each group member a task to complete

Project Specifications:
* input/output - A user may input their username and password to log into the library system. Afterwards, various inputs will allow them to perform different operations within the system. An output may be a list of favorite books or the title of books that were rented out. 
 
Design Patterns:  
* Strategy - This pattern will be useful because it lets us take take advantage of subclasses and virtual functions. We want to be able to call the same algorithm on two different subclasses and have it do two separate things. For example, we want to use this pattern to help facilitate book recommendations. These two separate book recommendation algorithms will recommend based off of books the user like and off of popular books in the library. 
* Composite - This pattern will let us use a tree-like structure where a part can contain a whole while still treating each part similarly. A user will be able create a book list containing multiple books. Additionally, a book list can contain another book list and it is treated exactly the same as if we were dealing with just an individual book. Therefore, a books list is a composite of books and book lists.


## Class Diagram
 ![alt text](https://github.com/cs100/final-project-jprin012-pkati001-ryang038/blob/master/images/SystemUML.png)

The library system is in charge of holding all of the books and will only have the file of one user open at a time (whoever is logged in). There are 2 types of users, a     standard user and an admin. An admin should be able to do everything a standard user can do plus the ability to add and remove books from the library. The Strategy class will be used to facilitate user book recommendations so it would be an aggregation.
 
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

 ### Dependencies
This project uses the mongo c++ driver library and the nlohmann json library. Both projects should be cloned in a directory called thirdparty that sits in the top level of the project

* Mongo drivers
  - Although not mentioned, the C++ driver depends on the C driver. So follow the instructions to download and install (in the thirdparty directory) both here https://www.mongodb.com/docs/drivers/
  - I personally had issues installing the drivers into my system, so make sure everything gets installed into thirdparty beause cmake will expect to find the mongocxx and bsoncxx package in the thirdparty directory (see CMakeLists.txt).
* Nlohmann Json
  - Clone the repository and build the package. By default, everything will be installed into your system, and cmake will look there for the package.
 ## Testing
 Our project was tested using googletest. There are files for every class that contain the unit tests for each class's specific functions.  
