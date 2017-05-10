The plan with this assignment is to make it AS MODULAR AS POSSIBLE.
Each of you will create your own completely separate .cc files.

ALL CODE MUST BE DOCUMENTED AS PER GRADING POINT #2 IN THE README FILE.
(I have no idea what he means by "pre/post conditions"???)

Your .cc file will implement one and only one of the following points, and AFTER THAT, you must email the source file to me so I can put it on Github:

1. The Hash Table.
* It needs to take a single letter `char` as a key and map it to an integer.
* The STL looks like it might have you covered: http://www.cplusplus.com/reference/unordered_map/unordered_map/
* Excellent example of it: http://stackoverflow.com/questions/2179946/i-would-like-to-see-a-hash-map-example-in-c
* The hash table variable in your code must be a GLOBAL variable. That is, it shouldn't be in a function or class or anything.
It should be on the top-level.

2. Reading input.
* It should follow what is specified in README.
* The user will enter in a string as in README's example.
* Based on that string, you need to extract two values.
* First, you need the variable name, a single character.
* TIP: Since it MUST always be a single character, the
equals-sign must always be at the same index in the string! So you can
use that fact to check for one of the error-cases
(which is that the variable name must be a single character).
* Second, you need the actual integer value. It should just be
simply one index past the equals sign onwards to the end.
* Now simply add both those substrings into a vector of strings and return it.
* You're not done yet! You have to consider that sometimes the user isn't setting a variable...
* But instead just entering an expression, per the README.
* In that case, there would be no equals sign, so you can parse the string for it...
* And if it's not there, then return a vector with the expression only.
* NOTE for person doing number 5: Anyone using this function would be able to tell whether an expression or variable-set was inputed BASED OFF OF THE SIZE OF THE VECTOR! So if it's of size 1, you know it's an expression, and so on.

3. The stupid, unnecessary class that just complicates this assignment.
* This one is detailed in grading point #3 in the README.
* This one sucks, but I don't think it'll be super-hard to implement.
* You're gonna have to create a class. Name it `SpecialInt`.
* It needs to have a private integer called `data`.
* It needs to have public methods for setting it and getting it.
* When you set the integer, it needs to print "BAD INPUT" to the
screen and exit the entire program IF the value you're trying to set
it to is > 255.
* It also needs to have a public method for incrementing it by 1.
The same rules apply for the get-function: if `data` ends up being
\> 255 after the increment, prints "BAD INPUT" and exits the entire program.

4. The logic.
* This one is basically just the logic of the calculator.
* You'll be given a string of an expression. There will be variables, like `x` or `y` for example.
* You need to communicate with the person who implemented the hash table to see how you *would* recover
the values for those variables and replace them in the expression.
* Now you'll have a string of the expression without variables, just numbers.
* You need to parse the string and extract the values and operations.
* So you'll need to figure out how to convert a string to an integer (good luck).
* You also need to handle the operations.
* At the end of it all, you'll return an integer, NOT A FLOAT.
* This of course means that if you do something like division it won't be the actual answer if there's a remainder.
* But that's what Kerney wants :P

5. Someone is going to have to take all the code specified in the above parts and combine it into one main.cc file.
* I'VE WENT MORE INTO DETAIL IN "COMBINING.md" about this part!
* Make sure that at the VERY BEGINNING of the program (in main()), the following is couted to the screen:
* `This software is licensed with the GNU Affero GPL v3.0. This means it respects your freedom! To learn more about GNU and their amazing licenses, see the following link: https://www.gnu.org/philosophy/free-sw.html`
* `endl`
* `The source code for this program can be viewed/downloaded here: https://github.com/MarxSoul55/project_management/releases`
* `endl`
* `endl`

6. After the program is completely done, we should further edit the program to get Extra Credit (i.e. the `loop` command)
* See details in README.txt

### How to send source files to me.

* If you have your .cc files on the server, you need to be able to download those files onto your local computer, where you will then
put them into a .zip file and send them to me via email.
* To do this, you need a FTP Client (a file-transfer-protocol client).
* You should use FileZilla. It's a beautiful and free FTP client that respects your freedom (licensed with GNU).
* Download it from this link: https://filezilla-project.org/
* You want the CLIENT, NOT THE SERVER!
* Go ahead and install it.
* Now open it. Ignore everything except the top left-hand corner.
* You should see 4 boxes.
* In `host`, type `www.csci4x.com`.
* In username, type your username for the server; same for password.
* In port, type 22.
* Now click on `Quickconnect`. You are now connected to the server.
* From here, you can navigate through the server's folders and drag-and-drop files from
the server to your PC.
* Now that you have the files on your PC, zip them up into a .zip file, and send them to me via email.
* I will handle the Github stuff.
