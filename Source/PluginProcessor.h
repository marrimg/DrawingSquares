/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class DrawingSquaresAudioProcessor  : public juce::AudioProcessor
                            #if JucePlugin_Enable_ARA
                             , public juce::AudioProcessorARAExtension
                            #endif
{
public:
    //==============================================================================
    DrawingSquaresAudioProcessor();
    ~DrawingSquaresAudioProcessor() override;
    
    juce::AudioProcessorValueTreeState& getVTS() { return apvts;
    };
    

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    //juce::Value poopParameter;
    //std::atomic<float>* poopParam = nullptr;
    
private:
    juce::AudioProcessorValueTreeState apvts;
    static juce::AudioProcessorValueTreeState::ParameterLayout myParameterLayout();
    void linkParameterValues();
    
    
    bool scaleButtParam_1 = 0;
    bool scaleButtParam_2 = 0;
    bool scaleButtParam_3 = 0;
    bool scaleButtParam_4 = 0;
    bool scaleButtParam_5 = 0;
    bool scaleButtParam_6 = 0;
    bool scaleButtParam_7 = 0;
    bool scaleButtParam_8 = 0;
    bool scaleButtParam_9 = 0;
    bool scaleButtParam_10 = 0;
    bool scaleButtParam_11 = 0;
    bool scaleButtParam_12 = 0;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DrawingSquaresAudioProcessor)
};
