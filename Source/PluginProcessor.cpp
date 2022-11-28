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
, apvts(*this, nullptr, juce::Identifier("STATESTORE"), myParameterLayout())
{
    linkParameterValues();
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
    return 1;
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
    return true;
}

juce::AudioProcessorEditor* DrawingSquaresAudioProcessor::createEditor()
{
    return new DrawingSquaresAudioProcessorEditor (*this);
}

//==============================================================================
void DrawingSquaresAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    auto state = apvts.copyState();
    std::unique_ptr<juce::XmlElement> xml (state.createXml());
//    std::cout << xml << "TEST";
}

void DrawingSquaresAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
}

void DrawingSquaresAudioProcessor::linkParameterValues() {
    scaleButtParam_1 = apvts.getRawParameterValue("ScaleButton_1");
}


//JXN Function to create APVTS params
juce::AudioProcessorValueTreeState::ParameterLayout
DrawingSquaresAudioProcessor::myParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout params;
    
    //Scale Buttons (I think the audio unit identifier has to start with 1)
    for (int i = 1; i < 8; ++i)
    {
        //params.add(std::make_unique<juce::AudioParameterBool>(juce::ParameterID {juce::String (i),i},juce::String (i), 1));
        juce::String paramName = "ScaleButton_" + juce::String(i);
        params.add(std::make_unique<juce::AudioParameterBool>(juce::ParameterID {paramName,i},paramName, 1));
    }

    return params;
    
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new DrawingSquaresAudioProcessor();
}
