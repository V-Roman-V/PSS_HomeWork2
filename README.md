# PSS_HomeWork2
A program that implements a system of university access using the OOP

## Program description
### Access levels:
 Student: green  
 Professor: red  
 Lab Employee: yellow + cabinet  
 Admin : red  
 Director: black  
 
 ----------  
 Class room: green  
 Cabinet: red  
 Lecture room: yellow  
 Conference room : red  
 DirectorCabinet: black  

### How the program structure is organized:
 There is a class university that contains all the rooms and people inside.
#### How the people are stored:
 ![people_diagram](https://user-images.githubusercontent.com/48117438/110329998-d9378c00-804f-11eb-909e-2a1712abf0dc.png)
 - people store information related only to the person;
 - University people store information common to all people in the university.

#### How the rooms are stored:
 ![room_diagram](https://user-images.githubusercontent.com/48117438/110330102-f4a29700-804f-11eb-9a40-25e1ad8e18cd.png)
 - Room store information common to all room.
 - University room store information common to all room in the university.

#### What it looks like together:
 ![full_diagram](https://user-images.githubusercontent.com/48117438/110330629-90cc9e00-8050-11eb-84da-1613b0c93a9f.png)
  
## Program features
- In the program almost all users are created automatically  and randomly.
- A person's age is automatically calculated from today's date using their date of birth.
- People have passports, phone numbers, nationality and more. 
- People at the university have their own unique card that gives them access to rooms and also keeps a history of their movements.
- Each student is enrolled in one of the living rooms.
- Implemented a convenient and fully controlled system of communication between the user and the program.(It was very hard)
- Admins have passwords (they are set by software) .
- A HUGE state machine has been implemented to interact with the user. 
- In the console you can enter the whole word or a simplified version in brackets.
- You can go back at any time during the interaction with the system.
- Implemented a beautiful input using ">" this symbol :)
- The text in the console is automatically erased, for convenience, so you don't need a lot of scrolling.
- If you enter a lot of text incorrectly, it will not fill the entire console, it is also erased.
- You can log in as any user in the system, but for the administrator you must enter a password.
- The list of objects in the beginning is made in two columns, which is not so easy to implement.
- There are still a lot of different additional things that I implemented, but it's hard to remember all of them.
        
## How to run the code
 Qt Creator was used as the IDE for this project. If you have it, you will be able to open this project through it.

### Where the source code is located
  main.cpp and other classes are located in the directory:
 > PSS_HomwWork2 
 
### How to execute the code
  Compiled and ready to run .exe file is located in the directory:
 > build-PSS_HomwWork2-Desktop_Qt_5_12_5_MinGW_64_bit-Debug\debug
  
  The runnability test was done under Windows x64 without Qt, the .exe file ran successfully.
  

## How to test the code
Testing my program can be done entirely through communicating with my system in the console.
![image](https://user-images.githubusercontent.com/48117438/110340330-b7440680-805b-11eb-9b46-236677e51cb6.png)  
Your options are written in curly brackets. You can enter either the whole word or a short character in brackets to the left.  
Watch carefully what the system asks you to enter, or you might get a little confused.  
To log in as administrator, you must enter a password, the first has the password "password", the second "12345". Don't forget to try to check if the password is incorrect.  
Please try to view all the features in my system, it's not for nothing that I tried so hard.
Below I provide a small map to facilitate testing. But the system is easy to understand.  
![class diagram](https://user-images.githubusercontent.com/48117438/110346991-b4004900-8062-11eb-9449-1f209ed585fd.png)

## Postscript
 The task was very fuzzy, so in many cases I showed my vision of university architecture.  
 In my opinion, a complete and programmatically correct solution to this problem is not designed for 2 weeks.  
 I started working on the program back on February 22, but still, I spent the last three days working on the program for 10 hours.  
 All in all the code (.cpp and .h files) weighs exactly 70 813 bytes, which means that I typed out about 70,000 characters. (Неплохо так получилсь)  
 A huge amount of time was taken up with the user interaction part, I hope it turned out cool and that you will like it.
 
 
