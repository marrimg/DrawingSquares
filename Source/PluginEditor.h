/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "GuiElements.h"
#include "Components.h"

//==============================================================================
/**
*/
class DrawingSquaresAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    DrawingSquaresAudioProcessorEditor (DrawingSquaresAudioProcessor& p);
    ~DrawingSquaresAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    typedef juce::AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;
    
private:

    DrawingSquaresAudioProcessor& audioProcessor;
    std::unique_ptr<ButtonAttachment> buttonAttachment;
    juce::AudioProcessorParameterGroup scaleButt1Parameter;
    
    int border = 4;
    
    SceneComponent scene;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DrawingSquaresAudioProcessorEditor)
};
