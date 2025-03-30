#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

struct song {
    char *title;
    char *artist;
    char *audioFilePath;
    struct song *link;
};

void enqueue();
void dequeue();
void displayPlaylist();
void playAudio(const char *audioFilePath);

struct song *front = NULL;
struct song *rear = NULL;

int main(void) {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        fprintf(stderr, "SDL initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    int ch;

    do {
        printf("\n\n\n1. Enqueue (Add song to playlist)\n2. Dequeue (Play next song)\n3. Display Playlist\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayPlaylist();
                break;
            case 4:
                printf("Exiting the music player.\n");
                SDL_Quit();
                exit(0);
            default:
                printf("\n\nInvalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}

void enqueue() {
    struct song *new_song = (struct song *)malloc(sizeof(struct song));

    if (new_song == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        exit(1);
    }

    printf("\n\nEnter song title: ");
    new_song->title = (char *)malloc(100 * sizeof(char));  // Assuming a maximum title length of 100 characters
    scanf(" %[^\n]", new_song->title);

    printf("Enter artist: ");
    new_song->artist = (char *)malloc(50 * sizeof(char));  // Assuming a maximum artist name length of 50 characters
    scanf(" %[^\n]", new_song->artist);

    printf("Enter audio file path: ");
    new_song->audioFilePath = (char *)malloc(256 * sizeof(char));  // Assuming a maximum file path length of 256 characters
    scanf(" %[^\n]", new_song->audioFilePath);

    new_song->link = NULL;

    if (front == NULL) {
        // If the playlist is empty, make the new song the first song
        front = rear = new_song;
    } else {
        // Add the new song to the end of the playlist
        rear->link = new_song;
        rear = new_song;
    }

    printf("Song '%s' by %s added to the playlist.\n", new_song->title, new_song->artist);
}

void dequeue() {
    struct song *current;

    if (front == NULL) {
        printf("\n\nPlaylist is empty.\n");
    } else {
        current = front;
        front = front->link;

        playAudio(current->audioFilePath);

        free(current->title);
        free(current->artist);
        free(current->audioFilePath);
        free(current);
    }
}

void displayPlaylist() {
    struct song *current;

    if (front == NULL) {
        printf("\n\nPlaylist is empty.\n");
    } else {
        printf("\n\nPlaylist: \n");
        current = front;
        while (current != NULL) {
            printf("Title: %s, Artist: %s, Audio: %s\n", current->title, current->artist, current->audioFilePath);
            current = current->link;
        }
    }
}

void playAudio(const char *audioFilePath) {
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8 *wavBuffer;

    if (SDL_LoadWAV(audioFilePath, &wavSpec, &wavBuffer, &wavLength) == NULL) {
        fprintf(stderr, "Failed to load audio: %s\n", SDL_GetError());
        return;
    }

    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    if (deviceId == 0) {
        fprintf(stderr, "Failed to open audio device: %s\n", SDL_GetError());
        SDL_FreeWAV(wavBuffer);
        return;
    }

    SDL_PauseAudioDevice(deviceId, 0);
    SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_Delay((wavLength / (wavSpec.freq * wavSpec.channels)) * 1000);

    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);
}
