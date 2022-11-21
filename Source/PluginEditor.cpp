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
    addAndMakeVisible (scene);

    /*
     setLookAndFeel (&mainLookAndFeel);
    addAndMakeVisible (button1);
    button1.setButtonText("D#");

    addAndMakeVisible (button2);
    button2.setButtonText("C#");

    addAndMakeVisible (button3);
    button3.setButtonText("B");
*/
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
    scene.setBounds (0, 0, getWidth(), getHeight());
    /*
    auto area = getLocalBounds();
    button1.setBounds (area.removeFromLeft(buttonWidth).removeFromTop(buttonHeight).reduced(border));
    button2.setBounds (area.removeFromLeft(buttonWidth).removeFromTop(buttonHeight).reduced(border));
    button3.setBounds (area.removeFromLeft(buttonWidth).removeFromTop(buttonHeight).reduced(border));
*/
}
