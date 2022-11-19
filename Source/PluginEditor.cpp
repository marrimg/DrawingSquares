/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DrawingSquaresAudioProcessorEditor::DrawingSquaresAudioProcessorEditor (DrawingSquaresAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setLookAndFeel (&mainLookAndFeel);

    addAndMakeVisible (button1);

    addAndMakeVisible (button2);

    addAndMakeVisible (button3);

    setSize (600, 600);
}

DrawingSquaresAudioProcessorEditor::~DrawingSquaresAudioProcessorEditor()
{
    setLookAndFeel (nullptr);
}

//==============================================================================
void DrawingSquaresAudioProcessorEditor::paint (juce::Graphics& g)
{

}


void DrawingSquaresAudioProcessorEditor::resized()
{
    
    auto area = getLocalBounds();
    button1.setBounds (area.removeFromLeft(buttonWidth).removeFromTop(buttonHeight).reduced(border));
    button2.setBounds (area.removeFromLeft(buttonWidth).removeFromTop(buttonHeight).reduced(border));
    button3.setBounds (area.removeFromLeft(buttonWidth).removeFromTop(buttonHeight).reduced(border));

}
