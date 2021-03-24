# PSS_HomeWork2
A program that implements a system of university access using the OOP

## Program description
### Access levels:
 Guest: blue
 Student: green  
 Professor: red  
 Lab Employee: yellow + cabinet  
 Admin : red  
 Director: black  
 
 ----------  
 Conference room : blue  
 Class room: green  
 Lecture room: yellow  
 Cabinet: red  
 DirectorCabinet: black  

### How the program structure is organized:
 There is a class university that contains all the rooms and people inside.
#### How the people are stored:
![image](https://user-images.githubusercontent.com/48117438/112392992-ec737880-8d2c-11eb-9046-afac6f0620fe.png)  
 - people store information related only to the person;
 - University people store information common to all people in the university.

#### How the rooms are stored:
 ![room_diagram](https://user-images.githubusercontent.com/48117438/110330102-f4a29700-804f-11eb-9a40-25e1ad8e18cd.png)
 - Room store information common to all room.
 - University room store information common to all room in the university.

#### What it looks like together:
 ![full_diagram](https://user-images.githubusercontent.com/48117438/110330629-90cc9e00-8050-11eb-84da-1613b0c93a9f.png)
  
## Program features
### first version
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
### second version
- Started working towards the modularity of the program. To do this, I took out of the main the filling of the University of the initial information and communication with the user.
- Started working on a graphical interface for communicating with the user, so far made only the initial background. You can switch to another version instantly, just by commenting out one line in the main, the modularity of the system came in handy.
- Up to the impossible, I simplified the interface with the user from a programmatic point of view. Now it is almost completely independent of the University, and takes data from it. (This is what I did mostly)
- I added standalone logger of information and user actions in the terminal.
- I finally added gitignore and removed all unnecessary files.
- Introduced an emergency system, anyone can turn it on, but only someone with red or higher access level can turn it off.
- I added guests to the university, and a system for registering a new guest. (If a guest is under 14 years old, I do not ask for his passport :) )
### What I plan to do next (Globally)
- Introduce random emergencies in campuses to make life more fun for students :)
- Introduce a system of achieves, so that the person who checks my work is not bored, and so that he knows what else can be tested
- Allow students to mine innopoints (would be especially interesting with a graphical interface, make something like a clicker)
- During emergencies I will turn on the alarm sound so it won't be boring :)
- In the first place, I want to make a normal graphical interface, but I can't find the time to design it.

## How to run the code
 For this project the qmake build system was used.  
 The ".pro" files are located in the directory:
 > PSS_HomwWork2

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
 All in all the code (.cpp and .h files) weighs about 82 661 bytes.
 A huge amount of time was taken up with the user interaction part, I hope it turned out cool and that you will like it.
 
 
