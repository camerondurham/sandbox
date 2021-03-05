// bindings\build.rs
fn main() {
  // The windows::build! macro takes care of resolving any dependencies in the
  // form of .winmd files, and generating bindings for selected types directly
  // from metadata.
    windows::build!(windows::web::syndication::SyndicationClient);
}