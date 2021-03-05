// src\main.rs
use bindings::{
    windows::foundation::Uri,
    windows::web::syndication::SyndicationClient,
    windows::Result,
};

fn main() -> Result<()> {
    let uri = Uri::create_uri("https://blogs.windows.com/feed")?;
    let client = SyndicationClient::new()?;
    let feed = client.retrieve_feed_async(uri)?.get()?;

    for item in feed.items()? {
        println!("{}", item.title()?.text()?);
    }

    Ok(())
}