#include "wav_parser.h"

/*
Reads bytes from a file ptr
inputs: file - file ptr
        buffer - memory to store result
*/
int ReadBytes(FILE* file, char* buffer, int bytes)
{
    int bytes_read = fread(buffer, sizeof(int8_t), bytes, file);
    if (bytes_read == 0)
    {
        if (!feof(file))
        {
            perror("fread");
        }
    }
    return bytes_read;
}

FILE* open_wav(char* filename, WavHeader* wav_header)
{
    // open file
    FILE* wav_file = fopen(filename, "rb");
    if (wav_file == NULL)
    {
        perror("fopen");
        return wav_file;
    }

    // TODO - if can figure out how to ensure WavHeader is contiguous can just load directly in
    // parse header
    ReadBytes(wav_file, wav_header->riff, 4);
    ReadBytes(wav_file, wav_header->file_size, 4);
    ReadBytes(wav_file, wav_header->file_type, 4);
    ReadBytes(wav_file, wav_header->format, 4);
    ReadBytes(wav_file, wav_header->format_length, 4);
    ReadBytes(wav_file, wav_header->format_type, 2);
    ReadBytes(wav_file, wav_header->num_channels, 2);
    ReadBytes(wav_file, wav_header->sample_rate, 4);
    ReadBytes(wav_file, wav_header->bytes_per_second, 4);
    ReadBytes(wav_file, wav_header->bytes_per_sample, 2);
    ReadBytes(wav_file, wav_header->bits_per_sample_per_channel, 2);
    ReadBytes(wav_file, wav_header->data, 4);
    ReadBytes(wav_file, wav_header->data_length, 4);

    // check they are correct
    char temp[5] = { '\0' };
    for (int i = 0; i < 4; i++)
        temp[i] = wav_header->riff[i];
    printf("%s", temp);

    return wav_file;
}

int main()
{
    WavHeader wav_header;
    open_wav("GuitarHack JJ BBAE 0.wav", &wav_header);
}