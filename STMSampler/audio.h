#ifndef __AUDIO_H
#define __AUDIO_H

#include "STM32F4-Discovery/stm32f4_discovery_audio_codec.h"
#include <stdlib.h>

uint32_t retVal_Init;
uint32_t retVal_Play;
uint32_t retVal_PauseResume;

struct SampleNode {
	// TODO: Handler or something?
	uint32_t size;
	uint32_t pointer;
	struct SampleNode* prev;
	struct SampleNode* next;
};

struct SampleNode* samples;

// TODO: Configure SD Card
struct SampleNode* createSample(uint32_t size);

void runSample(struct SampleNode* newSample);

uint16_t processSamples(struct SampleNode** sample, uint16_t value);

void deleteSample(struct SampleNode** sample);

void configureAudio(void);

#endif /* __AUDIO_H */
