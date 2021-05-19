use reqwest::header::{ACCEPT_ENCODING};
use serde_json;


#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
    
    
    let client = reqwest::Client::builder()
    .gzip(true)
    .build()?;
    let resp = client
    .get("https://api.stackexchange.com/2.2/questions/featured/")
    .header(ACCEPT_ENCODING, "gzip")
    .query(&[("order", "desc"), ("sort", "creation"), ("site", "stackoverflow")])
    .send()
    .await?;

    // let resp = reqwest::get("https://httpbin.org/ip")

    println!("Status: {}", resp.status());
    println!("{:#?}", resp);
    let parsed: serde_json::Value = serde_json::from_str(&resp.text().await?)?;
    println!("Parsed json: {:#?}", parsed);
    Ok(())
}
