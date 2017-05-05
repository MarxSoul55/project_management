(Incomplete)

The plan with this assignment is to make it AS MODULAR AS POSSIBLE.
Each of you will create your own completely separate .cc files.

ALL CODE MUST BE DOCUMENTED AS PER GRADING POINT #2 IN THE README FILE.
(I have no idea what he means by "pre/post conditions"???)

Your .cc file will implement one and only one of the following points:

1. The Hash Table.
* It needs to take a single letter `char` as a key and map it to an integer.
* The STL looks like it might have you covered: http://www.cplusplus.com/reference/unordered_map/unordered_map/
* Excellent example of it: http://stackoverflow.com/questions/2179946/i-would-like-to-see-a-hash-map-example-in-c
* Global hash table.

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

4. Someone is going to have to take all of the code specified in the above parts and combine it into the complete program.
* TODO explain this
