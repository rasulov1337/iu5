class Fetch {
    post(url, callback) {
        fetch(url)
        .then(response => response.json())
        .then(result => callback(result))
        .catch((reason) => console.log("Error! Couldn't fetch the data", reason))
    }
}

export const fetch_ = new Fetch();