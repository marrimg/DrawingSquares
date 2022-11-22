/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DrawingSquaresAudioProcessor::DrawingSquaresAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

DrawingSquaresAudioProcessor::~DrawingSquaresAudioProcessor()
{
}

//==============================================================================
const juce::String DrawingSquaresAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool DrawingSquaresAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool DrawingSquaresAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool DrawingSquaresAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double DrawingSquaresAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int DrawingSquaresAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int DrawingSquaresAudioProcessor::getCurrentProgram()
{
    return 0;
}

void DrawingSquaresAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String DrawingSquaresAudioProcessor::getProgramName (int index)
{
    return {};
}

void DrawingSquaresAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void DrawingSquaresAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{

}

void DrawingSquaresAudioProcessor::releaseResources()
{

}

#ifndef JucePlugin_PreferredChannelConfigurations
bool DrawingSquaresAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else

    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void DrawingSquaresAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {

    }
}

//==============================================================================
bool DrawingSquaresAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* DrawingSquaresAudioProcessor::createEditor()
{
    return new DrawingSquaresAudioProcessorEditor (*this);
}

//==============================================================================
void DrawingSquaresAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
}

void DrawingSquaresAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
}

//JXN Function to create APVTS params
juce::AudioProcessorValueTreeState::ParameterLayout
DrawingSquaresAudioProcessor::createParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout params;
    
    for (int i = 1; i < 9; ++i) {
        params.add(std::make_unique<juce::AudioParameterFloat>(juce::ParameterID {juce::String (i),i}, juce::String (i), juce::NormalisableRange<float>(0.001, 0.5, 0.001), 0.002));
    }
    return params;
}


//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new DrawingSquaresAudioProcessor();
}
