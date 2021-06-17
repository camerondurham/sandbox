use reqwest::{Response, header::{ACCEPT_ENCODING}};
use serde_json;

const API_V2_2_BASE_URL : &str = "https://api.stackexchange.com/2.2";

fn auth() {
    // TODO: implement auth flow specified in https://api.stackexchange.com/docs/authentication
}

fn log_http_response(resp: &Response) {
    println!("Status: {}", resp.status());
    println!("{:#?}", resp);
}

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

    log_http_response(&resp);

    let parsed: serde_json::Value = serde_json::from_str(&resp.text().await?)?;
    println!("Parsed json: {:#?}", parsed);


    // https://api.stackexchange.com/docs/answers-on-users#pagesize=100&order=desc&sort=activity&ids=4676641&filter=default&site=stackoverflow&run=true
    // path: /2.2/users/4676641/answers?pagesize=100&order=desc&sort=activity&site=stackoverflow

    let user_id = "4676641";
    let resp = client
    .get(format!("{}/{}/{}/{}", API_V2_2_BASE_URL, "users",user_id, "answers"))
    .header(ACCEPT_ENCODING,"gzip")
    .query(&[("order", "desc"), ("sort","activity"),("site","stackoverflow")])
    .send()
    .await?;

    log_http_response(&resp);

    let parsed: serde_json::Value = serde_json::from_str(&resp.text().await?)?;
    println!("Parsed json: {:#?}", parsed);

    Ok(())
}
