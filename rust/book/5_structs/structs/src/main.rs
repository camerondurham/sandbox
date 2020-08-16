struct User {
    username: String,
    email: String,
    sign_in_count: u64,
    active: bool,
}

fn build_user(email: String, username: String) -> User {
    User {
        email: email,
        username: username,
        active: true,
        sign_in_count: 1,
    }
}

fn main() {
    // entire struct must be mutable to change one field
    let mut user1 = User {
        email: String::from("someone@example.com"),
        username: String::from("someone123"),
        active: true,
        sign_in_count: 3,
    };

    user1.email = String::from("anotherexample@example.com");

    let user2 = build_user(
        String::from("drop@bobbytables.com"),
        String::from("bobby tables"),
    );

    // create instance from other instances with update syntax
    let user3 = User {
        email: String::from("another@example.com"),
        username: String::from("anotherusername345"),
        ..user1
    };
}
