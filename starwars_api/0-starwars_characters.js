#!/usr/bin/node

/**
 *
 * Script that prints all characters of a Star Wars movie:
 * The first positional argument passed is the Movie ID -
 * example: 3 = "Return of the Jedi"
 * Display one character name per line in the same order as the "characters" list in the /films/ endpoint
 * You must use the Star wars API
 * you must use the request module
*/

const request = require('request');

const api = 'https://swapi-api.hbtn.io/api/';
const movieId = process.argv[2];

const getName = (url) => new Promise((resolve, reject) => {
  request(url, (error, response, body) => {
    if (error) {
      reject(error);
      return;
    }
    resolve(JSON.parse(body).name);
  });
});

request(
      `${api}films/${encodeURIComponent(movieId)}`,
      (error, response, body) => {
        if (error) { return; }
        const data = JSON.parse(body);
        Promise.all(data.characters.map(getName))
          .then((names) => names.forEach((n) => console.log(n)))
          .catch(console.error);
      }
);
