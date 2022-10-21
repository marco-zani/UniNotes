# Strings
This function showcases Rust Strings and how to use them  
See  https://doc.rust-lang.org/std/string/struct.String.html  

`str_string` has type &str, i.e., pointer to a `str`.  This is also called a String literal. It is hardcoded  into the text of our program.    // It must have known fixed length at compile time
```rust
pub fn strings(){  
    let str_string : &str = "hello";  
    let mut str_string2 = "wht";  
    str_string2 = "mehs";  
    
    println!("Strings {} and {}", str_string , str_string2);  
```
note that we don't have methods to add to a `&str`, we can only replace it with something of fixed size  

A String is stored as a vector of bytes (`Vec<u8>`), guaranteed to always be a valid UTF-8 sequence.  

A string is heap-allocated, growable, and not null-terminated. Each `String` is allocated on the heap and your a variable of type `String` consists of three parts:    
- a **pointer** to the memory that holds the contents of the string.
- The **length** is how much memory, in bytes, the contents of the String is currently using.
- The **capacity** is the total amount of memory, in bytes, that the String has received from the allocator.    
- /* Visually:            strptr_string                 str_string                 heap stuff          | name  | value |         | name     | value |        | index | value |          | ptr   | ----------------> ptr      | ---------------> 0     | h     |                                    | length   | 5     |        | 1     | e     |                                    | capacity | 5     |        | 2     | l     |                                                                | 3     | l     |                                                                | 4     | o     |    */    

(1) - Below is the reference of a *String*,  it allows us to refer to the string without taking ownership of it.    
(2) - this does not show a pointer!  when we see traits, we'll see the details of why this is printing this way
(3) - when we see structs, we will discuss displaying with Debug and Display  
```rust
	let str_string = String::from(str_string);  
    // (1)
    let strptr_string : &String = &str_string;  
    let str_slice : &str = &str_string[..2];  
    println!("This is a slice {}", str_slice);  
    println!("This is (not) a pointer: {}", strptr_string);  
    // (2)
    println!("This is a pointer: {:p}", strptr_string);  
    // (3)
``` 

(1) - Using Strings in Rust is different than in other languages, this is **NOT** a String, it's a &str  
(2) - this is a String, but it is not mutable, as we are used to
(3) - Another way of manipulating strings is with `format!
(4) - Strings cannot be indexed directly, even though they are arrays, because you can end in the middle of a character    
```rust
    // (1)  
    let _s = "hell";  
    // (2)
    let s0 = "hell".to_string();    
    // s.push("o world") // this does not typecheck  
    let mut s = "hell".to_string();  
    let t = String::from("o world");  
    s.push_str(&t);  

    // (3)
    let r = format!("{} is real t{}lings", s0, t);  
    println!("{}",r);  
  
    // (4)
    for c in s0.chars() {  
        println!("Char: {:?}", c)  
    }  
}  
```
# Vectors
/// This function showcases Rust Vec  
/// See  https://doc.rust-lang.org/std/vec/struct.Vec.html  
```rust
pub fn vec(){  
    // Like `array`, vector `Vec` can store a single type of values next to each other.  
    // Unlike `array`, `Vec` is allocated in the heap and doesn't need to have a fixed length at compile time.    // Find the list of methods for `Vec` from their doc:    //      https://doc.rust-lang.org/std/vec/struct.Vec.html#method.from_raw_parts  
    // This is a Vector of i32. There are 2 types here: Vec and i32. i32 here is a type parameter.    // Rust defines Vec<T> for any type T (T here is a type variable)    // Rust has Parametric Polymorphism (like in System F) and this is an example    
    let mut v: Vec<i32> = Vec::new();  
    // one can push and pop values in a Vec  
    v.push(5);  
    v.push(5);  
    v.push(6);  
    v.push(5);  
    v.pop();  
    // or just get them values (for now, as immutable! )  
    let n = v.get(0).unwrap();  
    let nn = v.get(2).unwrap();  
    // first we need to deal with the options that `get` returns  
    // then observe the types of `n` and of `nn`:    // QUIZ: can i do this:    // nn = nn + n;    // no, i need to deref `nn` first, it's a pointer!    // while n gets dereferenced automatically to i32    
    let nn = *nn;       //shadowing!  
    println!("Adding stuff {}", nn + n);  
  
    // Vec tors can be iterated with for loops, taking immutable references  
    for i in &v {  
        println!("{}", i);  
    }  
    // or taking mutable ones  
    for i in &mut v {  
        *i += 50;  
    }  
    // For complex data structures that implement the Debug trait,  
    // we can use {:?} to print them in a standard way -- more info on this later    
    println!("Vector v {:?}", v);  
}  
```

# Hashmap
/// This function showcases Rust HashMap  
/// See  
///     https://doc.rust-lang.org/std/collections/struct.HashMap.html  
```rust
pub fn hashmap(){  
    // A Hashmap is a collection that stores a key-value mapping  
    // The type is HashMap<K,V>, which is Polymorphic in the types of keys `K` and of values `V`    use std::collections::HashMap;  
    // this import can be per-function (as here), or per module (move to beginning of code)  
  
    let mut scores = HashMap::new();  
    // insert values  
    scores.insert(String::from("Blue"), 10);  
    scores.insert(String::from("Yellow"), 50);  
    // get values  
    for (key, value) in &scores {  
        println!("Hashmap content: {}: {}", key, value);  
    }  
  
    //overwrite  
    scores.insert(String::from("Blue"), 25);  
    //get or insert in two different ways  
    // with `get` and the related handling of options    let blue_scores = scores.get("Blue").unwrap();  
    println!("blue: {}", blue_scores);  
}  

```
# Ownership
https://doc.rust-lang.org/book/ch04-01-what-is-ownership.html  

Central to the reason why Rust has ownership is the role of Stack and Heap. Existing languages have many a problem with the management of the heap, e.g., buffer overflows, data races, dangling pointers etc...  

 **Rust's Ownership Rules**
 - Each value in Rust has one **owner**        
 - There can only be **one owner** at a time for each value        
 - When the owner goes out of scope (when the *lifetime* is over), the value will be dropped (deallocated, freed).  
  Why?
  - Each piece of memory has its owner. No data race!        
  - When the owner gets dropped, the piece of memory will be freed. No dangling pointers!      
  - 
(1) - moves s1 into s2 and when s1 is used, it does not own the value anymore. This is called **move semantics**. The Rust type system statically keeps track of ownership of values and of how that ownership moves around were programs to execute  
(2) - When the scope is over, rust calls `drop()` function automatically to drop `s1` and `s2`.  
(3) -  If we really want to keep `s1` and `s2` at the same time, we can `clone` it explicitly
(4) - Ownership rules only affects HEAP values, not STACK ones (such as i32)  
```rust
pub fn ownership(){  
	{
		// (1)
        let s1 = String::from("hello");  
        let _s2 = s1;    
    } // (2)
  
    {  
        let s1 = String::from("hello");  
        // (3)
        let s2 = s1.clone();  
  
        println!("s1 = {}, s2 = {}", s1, s2);  
    }  
  
    // (4)
    let x: i32 = 5;  
    let y = x;  
    println!("x = {}, y = {}", x, y); //works  
    //This is OK because x has a primitive type, `i32`, whose length is known at compile-time and is stored on the stack.    // So, the Rust compiler will *copy* the value of  `x` to `y`, so both `x` and `y` have the same value of type `5i32`    // but are stored in a different place on the stack.        
    ownership_for_functions();  
}  
```

(4) is ok because `i32` has the `Copy` trait. If a type implements the `Copy` trait, the value of the type will be copied after the assignment. This also matters with Implicit Deref Coercion  
2 Words on Rust Traits: A Trait is a way of saying that a type has a particular property (e.g., Copy, Move, Debug, Display, PartialEq ...)  

(1) - s's value moves into the function `takes_ownership`  
(2) - x would move into the function,  but i32 is Copy, so it's okay to still  use x afterward    
(3) - Here, x goes out of scope, then s. But because s's value was moved, nothing happens:  it does not get deallocated because of this 'drop'  
(4) - Here, some_string goes out of scope and `drop` is called. The backing memory is freed.  
(5) - Here, some_integer goes out of scope. Nothing special happens.  
```rust
fn ownership_for_functions() {  
     
    let s = String::from("hello");  
    // (1)
    takes_ownership(s);  
    
    let x = 5;  
    // (2)
    makes_copy(x);  
} // (3)
  
fn takes_ownership(some_string: String) { 
    println!("{}", some_string);  
} // (4)
  
fn makes_copy(some_integer: i32) { 
    println!("{}", some_integer);  
} // (5)
```

# References and Borrowing
(1) - Borrowing avoids transferring ownership. If we don't want a function to take ownership of our data, we can pass a reference to the function, creating an explicit, non-owning pointer. By making a reference is called **borrowing** in rust.  References are done with `&` ampersand operator. The opposite of referencing by using `&` is dereferencing, which is accomplished with `*`.  
(2) -  `&` alone doesn't give us the permission to modify the data. To make a mutable reference, we need to specify `&mut` when making a reference. 
(3) - Mutable references have one big restriction: you can have only **one** mutable reference to a particular piece of data in a particular scope.    
(4) - We can have either 1 RW references or multiple R only references. The benefit of having this restriction is that Rust can prevent data races statically (i.e., at compile-time) and it enforces Temporal Memory Safety statically    

``` rust
pub fn refs_and_borrowing(){  
    // (1)
    let s1 = String::from("hello");  
    
    let len = calculate_length(&s1);  

    println!("The length of '{}' is {}.", s1, len);  

  
    //(2)
    let mut s = String::from("hello");  
    change(&mut s);  
  
	let mut s = String::from("hello");  

	// (3)
    let r1 = &mut s;  
    let r2 = "asd";  
    // let r2 = &mut s; -> DNC cannot borrow `s` as mutable more than once at a time  
    println!("r1 and r2: {} and {}", r1, r2);  
  
    //(4)
    // Data Races Prevention Example    
    let r1 = &s;  
    let r2 = &s;  
    let r3 = "asd";  
    // let r3 = &mut s; -> DNC: cannot borrow `s` as mutable because it is also borrowed as immutable  
    println!("r1 and r2 and r3: {} and {} and {}", r1, r2, r3);  
}
  
fn calculate_length(s: &String) -> usize {  
    s.len()  
}  
 
fn change(some_string: &mut String) {  
    some_string.push_str(", world");  
}  
```
Recall that Rust also enforces (almost) spatial memory safety (by keeping sizes of arrays around and by dealing with Option types    


Temporal memory safety includes: no dangling references (dangling pointers) and no use-after free  

Dangling References: In languages with pointers, it's easy to erroneously create a *dangling pointer*, a pointer that references a location in memory that may have been given to someone else, by freeing some memory while preserving a pointer to that memory.  In rust, the dangling pointer will never happen, because Rust compiler will make sure that if you have a reference to some data, the data will not go out of scope before the reference to the data does.  

(1)- This function cannot return because the variable s is dropped at the end of the function.  
(2)- This function can return and it returns an actual string, so because as `s` is returned,  it is not freed when `drop` is called at the end of the function scope   
(3)- equivalent to  `return s;`

```rust
{
    // let reference_to_nothing = dangle();  
    // take a look at `no_dangle`    
    let string = no_dangle();  
    println!("String {}",string);  
}  
 
// fn dangle() -> &String {  
       // (1)
//     let s = String::from("hello");  
//     &s  //-> DNC :  missing lifetime specifier  

// } 

fn no_dangle() -> String {  
    //(2) 
    let s = String::from("hello");  
    //(3)
    s   
}  
```

Let's study in details how to deal with ownership and compound data types  
(1) - move occurs because value has type `String`, which does not implement the `Copy` trait. Consider borrowing here: `&v[0]`    
(2) -  Can I get another mutable reference to a different entry in the vector?  two elements do not overlap, their ownership is disjoint, the issue is that ownership goes through v 
(3) -  Use concat to merge them back, applied to an array since arrays can concat() slices to a vector  

```rust
pub fn ownership_and_compound(){  
    
    let mut v = vec![String::from("something");10];  

	//(1)
    // let first_nonmut = v[0];    
    // let sec_nonmut = v[1]; -> DNC: error[E0507]: cannot move out of index of `Vec<String>`    
    
    let first_nonnmut = &v[0];  
    // note that this now is a &String  
    let mut first_mut = v.get_mut(0).unwrap();  
    first_mut.push_str(" else");  
    println!("First Element: {}",first_mut);  
  
    let second_nonnmut = v.get(1).unwrap();  
    
    // println!("First Element: {}",first_mut);  -> DNC: cannot borrow `v` as immutable because it is also borrowed as mutable    
	let third_nonmut = v.get(2).unwrap();  
    
    println!("Nonmut: second and third {}, {}", second_nonnmut, third_nonmut);  
    
   // println!(" First nonmut ? no {}",first_nonnmut); -> DNC:  cannot borrow `v` as mutable because it is also borrowed as immutable  
   
    //(2)  
    let (v05, v6plus) = v.split_at_mut(6);  
    let mut one_mut = v05.get_mut(5).unwrap();  
    let mut two_mut = v6plus.get_mut(0).unwrap();  

    println!("5: {}, 6: {}",one_mut, two_mut);  
  
    //(3)  
    let vv = [v05,v6plus].concat();  
    println!("{:?} == {:?}",v,vv);  
}  
```

# Slicing

```rust
pub fn slices(){  
    // Another type that does not have ownership is the slice.  
    // Slices let you reference a contiguous sequence of elements in a collection rather than the whole collection.  
    // slicing is done by taking the desired range with square brackets [..],    // the first interval is inclusive, the second is not  
    let s : String = String::from("hello world");  
    let _hello : &str = &s[0..5];  
    let _world : &str = &s[6..11];  
    // `s` owns the string.  
    // `world` is a reference pointing to the second word of the string.  
    /* Visually:                s                        heap stuff          | name     | value  |       | index | value |          | ptr      | ---------------> 0     | h     |          | length   | 11     |       | 1     | e     |          | capacity | 11     |       | 2     | l     |                                      | 3     | l     |                                      | 4     | o     |                world                 | 5     |       |          | ptr      | ---------------> 6     | w     |          | length   | 5      |       | 7     | o     |          | capacity | 5      |       | 8     | r     |                                      | 9     | l     |                                      | 10    | d     |    */    // these are equal    let _slice = &s[0..2];  
    let _slice = &s[..2];  
    // these are equal too  
    let len = s.len();  
    let _slice = &s[3..len];  
    let _slice = &s[3..];  
  
    // slicing is not limited to Strings, but it works on Array s and on Vec s too  
    let a = [1, 2, 3, 4, 5];  
    let slice = &a[1..3];  
    assert_eq!(slice, &[2, 3]);  
  
    let v = vec![1, 2, 3, 4, 5];  
    let third: &i32 = &v[2];  
    println!("The third element is {}", third);  
    match v.get(2) {  
        Some(third) => println!("The third element is {}", third),  
        None => println!("There is no third element."),  
    }  
}  

```