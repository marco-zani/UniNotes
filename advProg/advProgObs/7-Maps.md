https://www.newline.co/@kkostov/the-rust-map-function-a-gateway-to-iterators--f991b22b  

Map is a function that works on iterators and returns an iterator, used to apply a function on each element of a sequence. The fact that returns an iterator allowes us to apply map functions in chain

```rust
pub fn twomaps(){
    let numbers = vec![3, 6, 9, 12];
    let result: Vec<i32> = numbers
        .iter()
        .map(|n| n * 10)
        .map(|n| n / 3)
        .collect();
    println!("{:?}",result);
}

```

Map is a lazy function, because it operates with [[12-Functional programming#Iterators|iterators]] 

```rust
pub fn lazymap_nocollect(){
    let numbers = vec![3, 6, 9, 12];
    let mut number_of_times = 0;
    // notice the change in type here
    let result = numbers
        .iter()
        .map(|n| {
            number_of_times += 1;
            return n * 10
        });
    println!("{:?}",result);
    println!("{}",number_of_times);
}
```

