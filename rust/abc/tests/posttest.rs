use abc::post::Post;
use chrono::Local;

use abc::tlog;
use abc::tlog::{telog, tlog};

#[test]
fn post_test01() {
    let mut post = Post::new();

    post.add_content("post.add_content is called with this string");

    let post = post.request_review();

    let post = post.approve();

    assert_eq!(
        "post.add_content is called with this string",
        post.content()
    );
}
