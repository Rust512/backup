
fn main() {
  let mut s: String = String::from("hello");
  let s2: &String = &s;
  let s3: &mut String = &mut s;
  s3.push_str(" world");
  println!("{s2}");
}