/**
 * WEB222 – Assignment 04
 *
 * I declare that this assignment is my own work in accordance with
 * Seneca Academic Policy. No part of this assignment has been
 * copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Please update the following with your information:
 *
 *      Name:       Ankush Gauro
 *      Student ID: 108593237
 *      Date:       March 22, 2024
 */

// All of our data is available on the global `window` object.
// Create local variables to work with it in this file.
const { artists, songs } = window;

// For debugging, display all of our data in the console. You can remove this later.
console.log({ artists, songs }, "App Data");

document.addEventListener("DOMContentLoaded", function () {
  // Get elements from the DOM
  const menu = document.querySelector("#menu");
  const selectedArtist = document.querySelector("#selected-artist");
  const songsContainer = document.querySelector("#songs"); // Declare songsContainer

  //const menu = document.getElementById("menu");
  //const selectedArtist = document.getElementById("selected-artist");
  //const songsTableBody = document.getElementById("songs");

  // Function to create buttons for each artist
  function createArtistButtons() {
    // Iterate through the array of artists
    artists.forEach((artist) => {
      // Create a new button element
      const button = document.createElement("button");

      // Set the button text content to the artist's name
      button.textContent = artist.name;

      // Add a click event listener to the button. When clicked, call the function to show songs
      button.addEventListener("click", function () {
        showSongsForArtist(artist);
      });
      // Append the button to the menu
      menu.appendChild(button);
    });
  }

  // Function to show a list of songs for a chosen artist
  function showSongsForArtist(artist) {
    // Update the text of the Selected Artist above your table
    selectedArtist.innerHTML = ""; // Clear previous content

    // Artist name with clickable links in brackets
    const artistInfo = document.createElement("span");

    // Update the selected artist title and links
    artistInfo.innerHTML = `${artist.name} (${artist.urls
      .map((url) => createClickableLink(url.url, url.name))
      .join(", ")})`;

    // Append the artist information
    selectedArtist.appendChild(artistInfo);

    // Clear current song cards
    songsContainer.innerHTML = "";

    // Filter songs for the chosen artist and non-flagged, non-explicit songs
    const artistSongs = songs.filter(
      (song) => song.artistId === artist.artistId && !song.flagged && !song.explicit
    );

    // Loop over the filtered songs and add them to the table
    artistSongs.forEach((song) => {
      const card = createSongCard(song);
      songsContainer.appendChild(card);
    });
  }

  // Function to create song cards dynamically
  function createSongCard(song) {
    // Create a <div> to hold the card
    const card = document.createElement("div");
    // Add the .song-card class to the <div>
    card.classList.add("song-card");

    // Create a song Image, use the .card-image class
    const songImage = document.createElement("img");
    songImage.src = song.imageUrl; // Set the image source from the song object
    songImage.alt = song.title; // Set the alt attribute to the song title
    songImage.classList.add("card-image"); // Add the .card-image class
    songImage.addEventListener("click", function () {
      window.open(song.url, "_blank"); // Open the link in a new tab
    });

    // h2 element for song name
    const songName = document.createElement("h2");
    songName.textContent = song.title; // Set the text content to the song title

    // Time element for the year
    const year = document.createElement("time");
    year.textContent = song.year;

    // span element for duration
    const duration = document.createElement("span");
    duration.textContent = formatDuration(song.duration);

    // Append elements to the card
    card.appendChild(songImage);
    card.appendChild(songName);

    card.appendChild(document.createElement("br")); // line break
    card.appendChild(document.createTextNode(`Year: ${year.textContent}`)); // Display year
    card.appendChild(document.createElement("br")); // line break
    card.appendChild(document.createTextNode(`Duration: ${duration.textContent}`)); // Display duration

    return card;
  }

  // Function to format duration from seconds to mm:ss
  function formatDuration(seconds) {
    // Rounding down to the nearest whole number using Math.floor().
    const minutes = Math.floor(seconds / 60);
    // The remaining seconds after removing the minutes.
    const remainingSeconds = seconds % 60;
    // The seconds part is displayed with two digits, adding a leading zero if necessary.
    return `${minutes}:${remainingSeconds < 10 ? "0" : ""}${remainingSeconds}`;
  }
  // Function to create clickable link
  function createClickableLink(url, text) {
    return `<a href="${url}" target="_blank">${text}</a>`;
  }

  // Call the function to create artist buttons on page load
  createArtistButtons();

  // Show default songs for the first artist
  if (artists.length > 0) {
    showSongsForArtist(artists[0]);
  }
});
