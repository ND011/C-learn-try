#include <iostream>
#include <vector>
#include <string>

// Basic structure to represent a song
struct Song {
    std::string title;
    std::string artist;
    std::string audioFilePath;
};

// Basic class representing a simple playlist
class SimplePlaylist {
public:
    void enqueueSong(const Song& song) {
        playlist.push_back(song);
        std::cout << "Song enqueued: " << song.title << " by " << song.artist << std::endl;
    }

    void dequeueSong() {
        if (!playlist.empty()) {
            Song currentSong = playlist.front();
            playlist.erase(playlist.begin());
            std::cout << "Now playing: " << currentSong.title << " by " << currentSong.artist << std::endl;
        } else {
            std::cout << "Playlist is empty." << std::endl;
        }
    }

    void displayPlaylist() const {
        std::cout << "Playlist:" << std::endl;
        for (const Song& song : playlist) {
            std::cout << "- " << song.title << " by " << song.artist << std::endl;
        }
    }

private:
    std::vector<Song> playlist;
};

int main() {
    SimplePlaylist playlistManager;

    // Example songs
    Song song1 = {"Song1", "Artist1", "/path/to/audio1"};
    Song song2 = {"Song2", "Artist2", "/path/to/audio2"};

    // Enqueue songs
    playlistManager.enqueueSong(song1);
    playlistManager.enqueueSong(song2);

    // Display playlist
    playlistManager.displayPlaylist();

    // Dequeue a song
    playlistManager.dequeueSong();

    return 0;
}
