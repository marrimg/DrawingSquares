/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "LookAndFeel.h"

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

    DrawingSquaresAudioProcessor& audioProcessor;
    
    void drawButtonBackground (juce::Graphics& g, juce::Button& button, const juce::Colour& backgroundColour,
                               bool, bool isButtonDown);
    AntimatterLookAndFeel mainLookAndFeel;
    juce::TextButton button1;
    juce::TextButton button2;
    juce::TextButton button3;
    
    // colors
//    juce::Colour darkGrey1 = juce::Colour::fromFloatRGBA (0.14f, 0.14f, 0.14f, 1.0f);
//    juce::Colour midGrey = juce::Colour::fromFloatRGBA (0.25f, 0.25f, 0.25f, 1.0f);
//    juce::Colour lightGrey = juce::Colour::fromFloatRGBA (0.34f, 0.34f, 0.34f, 1.0f);
//    juce::Colour darkGrey2 = juce::Colour::fromFloatRGBA (0.45f, 0.45f, 0.45f, 1.0f);
//    juce::Colour white = juce::Colour::fromFloatRGBA (1.0f, 1.0f, 1.0f, 1.0f);
//    juce::Colour orange = juce::Colour::fromFloatRGBA (0.91f, 0.38f, 0.19f, 1.0f);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DrawingSquaresAudioProcessorEditor)
};
