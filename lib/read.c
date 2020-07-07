 
#include "read.h"
#include "string.h"

int NAN;
int TYPE;

ReadClass read_build () {
    ReadClass read;

    read.string = GetString;
    read.password = GetPassword;
    read.integer = GetInt;
    read.floatn = GetFloat;
    read.doublen = GetDouble;
    read.character = GetChar;
    
    read.Warning.integer = WGetInt;
    read.Warning.floatn = WGetFloat;
    read.Warning.doublen = WGetDouble;
        
    return read;
}

/*
* @Description
* Reads a string from the terminal
* @Return
* It returns the string (which is a char*) that was read. 
* If user typed nothing it is returned a null-terminated 
* string with size 1;
* @Var
* temp: it stores the typed string (resizable)
* R: the string returned
* size: the size of the string read
* n: the string iterator
* character: each char of the string
*/

OString GetString(){

    int character, n = 0, size = 1;
    //at first, it is assumed that user will type nothing
    //so, it is allocated a string of size 1
    OString temp = (OString) calloc(size, sizeof(char));
    //null-terminates the string
    *(temp + 0) = END_STRING; 

	//as long as user types something
    while(TRUE){
		
        //clears the stdin buffer
        //setbuf(stdin, NULL);
        //gets the char typed from stdin
        character = getc(stdin);
        //if user pressed "Enter" then, terminate reading
        if (character == ENTER_KEY)
            return temp;
		
        //append the char read to "temp"
        *(temp + n) = character;

        n++; size++;
        //resize the string so that to house one more char
        temp = realloc(temp, size*sizeof(char));
        //null-terminaates "temp"
        *(temp + (size - 1)) = END_STRING;

    }

}

/*
* @Description
* Reads a string from the terminal but with echo disabled using shell script
* @Return
* It returns the string (which is a char*) that was read. 
* If user typed nothing it is returned a null-terminated 
* string with size 1;
* @Var
* temp: it stores the typed string (resizable)
* R: the string returned
* size: the size of the string read
* n: the string iterator
* character: each char of the string
*/

OString GetPassword(){

	system("stty -echo");
	OString pass = GetString();
	system("stty echo");
	return pass;

}


/*
* @Description
* Reads a char from the terminal
* @Return
* It returns the char read. If user typed too many chars,
* only the first one is considered thus, the others are ignored.
* @Var
* temp: the string contaning the char to be read
*/

char GetChar(){

	String temp = GetString();
	
	if (strlen(temp) == 2 && temp[0] == '\\')
		return *(temp + 1);	 
	
	return *(temp + 0);
}


/*
* @Description
* Reads an integer from the terminal
* @Return
* It returns the number that was read. 
* or 0 if used typed something other than a number
* @Var
* temp: the string to be converted to an int
* integer: the integer read
*/

int GetInt() {
	
	int integer;
	
	String temp = GetString();
	
	if (str_is_digit(temp)) {
		integer = atoi(temp);
		NAN     = FALSE;
	}

	else {
		integer = 0;
		NAN     = TRUE;
	}
	
	return integer;

}

int WGetInt (String text, String warning) {
    
    int temp;
    
    do {
        printf("%s ", text);
        temp = GetInt();
        if (IsNan()) {
            if (warning != nil)
                puts("");
            else
                puts(ERR_NAN);
        }
    } while (IsNan());
    
    return temp;
    
}

/*
* @Description
* Reads a float from the terminal
* @Return
* It returns the number that was read. 
* or 0 if used typed something other than a number
* @Var
* temp: the string to be converted to a float
* float_number: the float read
*/

float GetFloat() {
	
	float float_number;
	
	String temp = GetString();
	
	if (str_is_digit(temp)) {
		float_number = atof(temp);
		NAN          = FALSE;
	}

	else {
		float_number = 0;
		NAN          = TRUE;
	}
	
	return float_number;

}

float WGetFloat (String text, String warning) {
    
    float temp;
    
    do {
        printf("%s ", text);
        temp = GetFloat();
        if (IsNan()) {
            if (warning != nil)
                puts(warning);
            else
                puts(ERR_NAN);
        }
    } while (IsNan());
    
    return temp;
    
}

/*
* @Description
* Reads a double from the terminal
* @Return
* It returns the number that was read. 
* or 0 if used typed something other than a number
* @Var
* temp: the string to be converted to a double
* number: the double read
*/

double GetDouble() {
	
	double float_number;
	
	String temp = GetString();
	
	if (str_is_digit(temp)) {
		float_number = atof(temp);
		NAN          = FALSE;
	}

	else {
		float_number = 0;
		NAN          = TRUE;
	}
	
	return float_number;
}

double WGetDouble (String text, String warning) {
    
    double temp;
    
    do {
        printf("%s ", text);
        temp = GetDouble();
        if (IsNan()) {
            if (warning != nil)
                puts(warning);
            else
                puts(ERR_NAN);
        }
    } while (IsNan());
    
    return temp;
    
}

/*
* @Description
* Tells the user if it was typed an int or not
* @Return
* It returns NAN (which assumes TRUE or FALSE)
*/

int IsNan() {
	return NAN;
}


