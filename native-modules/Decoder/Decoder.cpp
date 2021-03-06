extern "C" {
    #include "Decoder.h"
}

#include "ffmpegReader.hpp"

class Decoder {
public:
    FFmpegFile * pFFmpegFile;

    int64_t frames;
    int64_t samplesPerFrame;
    int64_t bitsPerSample;
    
    int channels;
    int sampleRate;

    Decoder() 
    : pFFmpegFile(NULL)
    , frames(0)
    , samplesPerFrame(0)
    , bitsPerSample(0)
    , channels(0)
    , sampleRate(0)
    {}    
};

int CreateDecoder(const char * szFilename, DecoderHandle * phDecoder)
{
    if (phDecoder == NULL) return -1;

    Decoder * pDecoder = new Decoder();

    av_register_all();

    pDecoder->pFFmpegFile = new FFmpegFile(szFilename);
    pDecoder->pFFmpegFile->info(
        pDecoder->frames,
        pDecoder->samplesPerFrame,
        pDecoder->bitsPerSample,
        pDecoder->channels, 
        pDecoder->sampleRate);

    *phDecoder = pDecoder;
    return 0;
}

void FreeDecoder(DecoderHandle hDecoder)
{
    if (hDecoder == NULL) return;
    Decoder * pDecoder = (Decoder *) hDecoder;

    delete pDecoder;
}

int DecodeSamples(DecoderHandle hDecoder, int64_t firstSample, int64_t sampleCount, int8_t * pBuffer, int64_t bufferSize, int64_t * pBytesWritten)
{
    if (hDecoder == NULL) return -1;
    Decoder * pDecoder = (Decoder *) hDecoder;

    int64_t bytesWritten = 0;

    bytesWritten = pDecoder->pFFmpegFile->decodeSamples(firstSample, sampleCount, pBuffer, bufferSize);
    if (bytesWritten < 0) return bytesWritten;

    if (pBytesWritten) *pBytesWritten = bytesWritten;

    return 0;
}

const char * GetError(DecoderHandle hDecoder)
{
    if (hDecoder == NULL) return NULL;

    Decoder * pDecoder = (Decoder *) hDecoder;

    return pDecoder->pFFmpegFile->error();
}