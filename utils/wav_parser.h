#ifndef WAV_PARSER_H
#define WAV_PARSER_H

#include <stdio.h>
#include <stdint.h>

typedef struct {
    char riff[4];
    int32_t file_size;
    char file_type[4];
    char format[4];
    int32_t format_length;
    int16_t format_type;
    int16_t num_channels;
    int32_t sample_rate;
    int32_t bytes_per_second; // (Sample Rate * BitsPerSample * Channels) / 8
    int16_t bytes_per_sample; // (BitsPerSample * Channels) / 8
    int16_t bits_per_sample_per_channel; 
    char data[4];
    int32_t data_length;
} WavHeader;

FILE* open_wav(char* filename, WavHeader* wav_header);
int ReadBytes(FILE* file, char* buffer, int bytes);

#endif