fun f filename =
	let
		val instream=TextIO.openIn(filename);
		fun supp (a::b::c::d::r) = (implode[c,d])::supp(r)
		| supp (a::b) = []
		| supp (a::b::c) = implode(c)::nil
		| supp (a) = []
		val text = explode(TextIO.inputAll(instream));
	in
		supp(text)
	end;


f "/home/marco/Documents/uni/linguaggi/in"

 
fun f (a::b::r)= a - b + f(r) 
| f (a::nil) = a
| f (nil) = 0
	

fun f n (a::b::r) =  b + f n r
| f n a = n 

fun f (a::b::r) = if(a>b) then false else f (b::r)
| f (a::nil) = true
| f nil = true

FOR = For of int*(int->int);

fun rad n = n * 2;

fun eval (For(n,f)) x = if(n>0) then eval (For(n-1, f)) (f x) else x;

eval (For(3,rad)) 2


fun count (a::r) = if (List.exists (fn eq => a = eq) r) then count r else (count r) +1
| count nil = 0;

count ["pera", "para", "pirla", "pera"];



fun f (a::r) = if(a>=0) then (a*a-1)::(f r) else (a*a+1)::(f r)
| f nil = [] ;

f [~1,2,3,0,~5,6];

