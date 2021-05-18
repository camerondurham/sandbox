use reqwest::header::{CONTENT_ENCODING, CONTENT_TYPE};


#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
    
    
    let resp = reqwest::Client::new()
    .get("https://api.stackexchange.com/2.2/questions/featured")
    .header(CONTENT_TYPE, "application/json")
    .header(CONTENT_ENCODING, "utf-8")
    .query(&[("order", "desc"), ("sort", "creation"), ("site", "stackoverflow")])
    .send()
    .await?;

    // let resp = reqwest::Client::new()
    // .get("https://api.stackexchange.com/2.2/questions/unanswered/my-tags")
    // .query(&[("fromdate", "1621123200"), ("order", "desc"), ("sort", "creation"), ("site", "stackoverflow")])
    // .header("access_token", "VEZu*G7zmmbsewpD7g8Nqg))")
    // .send()
    // .await?
    //     .json::<HashMap<String, HashMap<String,String>>>()
    // .await?;


    // let resp = reqwest::get("https://httpbin.org/ip")
    println!("Status: {}", resp.status());
    println!("{:#?}", resp.json().await?);
    Ok(())
}
