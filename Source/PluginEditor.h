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
    DrawingSquaresAudioProcessorEditor (DrawingSquaresAudioProcessor&);
    ~DrawingSquaresAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:

    int border = 4;
    
    int buttonHeight = 100;
    int buttonWidth = 60;
    
    DrawingSquaresAudioProcessor& audioProcessor;
    
    void drawButtonBackground (juce::Graphics& g, juce::Button& button, const juce::Colour& backgroundColour,
                               bool, bool isButtonDown);
    
    SceneComponent scene;
    
    /*
    ScaleButton mainLookAndFeel;
   juce::TextButton button1;
    juce::TextButton button2;
    juce::TextButton button3;
*/
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DrawingSquaresAudioProcessorEditor)
};
