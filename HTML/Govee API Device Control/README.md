To be able to control your devices using you govee api you need a few things

1. Your govee api. You can get this by going to the govee app on your phone then going to your Setting then apply for API key
2. You need your devices ID to get this open your developer console by pressing CONTROL+SHIFT+I and most browsers. Once your there go to console the paste is the code below. It might not work in Github so open a new tab then open the console. Once you do that you should see something like this {data: {…}, message: 'Success', code: 200} after you see that click the arrow to the left of it then again on the data and devices. Now you should see you device IDs and Models 

```
const apiKey = 'REPLACE_WITH_YOUR_API_KEY';

fetch('https://developer-api.govee.com/v1/devices', {
    method: 'GET',
    headers: {
        'Content-Type': 'application/json',
        'Govee-API-Key': apiKey
    }
})
.then(response => response.json())
.then(data => {
    console.log(data);
})
.catch(error => {
    console.error('Error:', error);
});
