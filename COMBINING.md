### Pseudocode for weaving it all together in `main.cc`

This is a general idea of how we're going to weave it all together. I may have missed some details
but I'm pretty sure I got everything covered.

So by this point we have all our separate code in our separate .cc files. The complete program will
be inside of a file called `main.cc` for simplicity.

We can treat each source file as just a collection of code. We should take that code from each
source file and put it into a function inside of `main.cc`. *We will likely have to make some
modifications to make it work.*

See below for my pseudocode; descriptions of what I'm thinking after `#`

    func die()
        # terminates program

    class SpecialInt
        private
            int data
        public
            set_data
                # stuff
                # throw error if data out of bounds
            get_data
                # stuff
                # throw error if data out of bounds
            increment_data
                data++
                # throw error if data is now out of bounds
    
    # Hash should be a global variable; this way, multiple functions can access it easily
    hash_table<SpecialInt> hash
        
    func read_input ()
        # Reads the input
        # If it contains "quit" or "QUIT", or is just the end of an input file, program terminates.
        # If setting a variable, returns a vector with 2 elements; var's name (a single letter) and number
        # ^ IN THAT ORDER i.e. (varname, integer)
        # Else, vector with 1 element; return the whole expression
    
    func calc (statement)
        # statement is a vector gotten from read_input
        # This is an expression that we need to evaluate.
        if statement.size == 1:
            # from the statement, see what variables we need
            # From those variables' names, get the corresponding SpecialInt's data from the hash table
            # Now you can use the data to evaluate the expression
            # Now increment the data via SpecialInts member function
            # Now return the actual result (a 32 bit int) from the expression.
        # This is an expression that's setting a variable.
        else if statement.size == 2:
            # create a SpecialInt with the numerical value
            # do something like hash['x'] = SpecialInt_VarName
            # Basically just store the SpecialInt into the global hash table
    
    func main()
        # Now in main, of course we should print out the license stuff (as specified in PLAN.md point 5)
        # Then in a while True loop...
            # call read_input and save result into variable
            # put that variable into calc function
            # I think that's it! (maybe not, check README to make sure)
