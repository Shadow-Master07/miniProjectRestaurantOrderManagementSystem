# Name: Hotel Order Management System
- Using linked list (nothing specific like queue or stack)
- Linked list only because we have to take care of all the adding and removing without using any specific type of algorithm
- Adding head of dishes to order so we can check all the dishes associated to a specific order number
- Basically Linked list inside a Linked list

<b>Use this struct as a basis of other data inputting &darr;</b>
```c
// Struct for orders and making a linked list of that
typedef struct dish
{
    char *name;
    struct dish *next;
} dishName;

// Struct to maintain orders and making a linked list of them
typedef struct order
{
    int ID;
    int tableNumber;
    dishName *head; // Taking head of dish linked list and check accordingly
    struct order *next;
} orders;
```


## <u>Necessary:</u>
- User Input orders
- Create a Menu to get inputs from
- Take dish number, or harder can be to take dish name
- Have a chef count
- Assign tasks to those chefs
- Assigning status (Added, In-Progress, Completed, Cancelled)
- Work according to status

## <u>More features:</u>
- Adding and maintaining time taken for food to cook
- Updating status of dish to maintain status check easily
- Taking user details and adding them to our data when taking orders


### Idea Dump:
1. Creating custom header files and decluttering the code
2. Using database to adding data to
3. Reading/Initializing  by adding data to variable using database


## Extra:
1. Created a header file to separate some functions and remove errors/distinguish location of errors
2. To compile the source code, we need to follow a certain format
    - gcc -o $\lt$final file name$\gt$ $\lt$all c source files to compile and attach$\gt$
    - example: gcc -o main main.c ./include/src/showMainMenu.c

    NOTE: not compiling header file because that is already included in showMainMenu.c and it gets compiled, also similar thing will be followed later on to set things up

3. To arrange all the files and source in a specific format, put everything in include folder, open include and add 2 folders (lib, src). Put header files in lib and C files of same name as in header in src, remaining main file in project (starting location) folder


```
Update few other functionalities if want to
 - Time of order
 - Price of orders
```


