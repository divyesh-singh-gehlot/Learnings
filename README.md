# Music Player using Doubly Linked List

A simple music player application that allows users to manage a playlist of songs using a doubly linked list. The player supports adding songs, playing the next or previous song, switching to a specific song, and retrieving the currently playing song.

## Features

- **Add Song**: Add a new song to the end of the playlist.
- **Play Next**: Move to the next song in the playlist.
- **Play Previous**: Move to the previous song in the playlist.
- **Switch Song**: Jump to a specific song in the playlist.
- **Current Song**: Get the ID of the song currently playing.

## Assumptions

- The `playNext` function will not be called from the last song.
- The `playPrev` function will not be called from the first song.
- The `switchSong` function will always receive a song ID present in the list.
- The `addSong` function will not be called for a song ID already in the list.
- The `current` function will not be called when the list is empty.

## Getting Started

### Prerequisites

- C++ compiler (e.g., g++, clang)
- Basic understanding of C++ programming and data structures

### How to Use

1. Clone this repository to your local machine:
   ```bash
   git clone https://github.com/your-username/music-player.git
