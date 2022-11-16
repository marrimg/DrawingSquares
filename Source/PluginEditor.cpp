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
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    auto border = 4;

    auto area = getLocalBounds();

    auto buttonHeight = 75;
    auto buttonWidth = 55;
    
    setLookAndFeel (&mainLookAndFeel);

    button1.setButtonText ("1");
    addAndMakeVisible (button1);

    button2.setButtonText ("2");
    addAndMakeVisible (button2);
    
    button3.setButtonText ("3");
    addAndMakeVisible (button3);

    button1.setBounds (area.removeFromLeft(buttonWidth).removeFromTop(buttonHeight).reduced(border));
    button2.setBounds (area.removeFromLeft(buttonWidth).removeFromTop(buttonHeight).reduced(border));
    button3.setBounds (area.removeFromLeft(buttonWidth).removeFromTop(buttonHeight).reduced(border));
    
    
    
    setSize (600, 600);
}

DrawingSquaresAudioProcessorEditor::~DrawingSquaresAudioProcessorEditor()
{
    setLookAndFeel (nullptr);
}

//void DrawingSquaresAudioProcessorEditor::drawButtonBackground (juce::Graphics& g, juce::Button& button, const juce::Colour& backgroundColour,
//                           bool, bool isButtonDown)
//{
//    setLookAndFeel (&mainLookAndFeel);
//
//    button1.setButtonText ("1");
//    addAndMakeVisible (button1);
//
//    button2.setButtonText ("2");
//    addAndMakeVisible (button2);
//
//    button3.setButtonText ("3");
//    addAndMakeVisible (button3);
//
//    setSize (600, 600);
//
//}

//==============================================================================
void DrawingSquaresAudioProcessorEditor::paint (juce::Graphics& g)
{

}


void DrawingSquaresAudioProcessorEditor::resized()
{

    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
