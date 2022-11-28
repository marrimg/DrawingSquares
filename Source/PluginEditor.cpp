/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DrawingSquaresAudioProcessorEditor::DrawingSquaresAudioProcessorEditor (DrawingSquaresAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), scene(p)
{

    auto parameters = p.getParameterTree().getParameters (true);

    addAndMakeVisible (scene);

    setSize (600, 600);
}

DrawingSquaresAudioProcessorEditor::~DrawingSquaresAudioProcessorEditor()
{
    setLookAndFeel (nullptr);
}

//==============================================================================
void DrawingSquaresAudioProcessorEditor::paint (juce::Graphics& g)
{
    /*
    bool scaleButton_0 = scene.scaleButtons.at(0)->getToggleState();
    bool button1 = scene.scaleButtons.at(1)->getToggleState();
    bool button2 = scene.scaleButtons.at(2)->getToggleState();
    bool button3 = scene.scaleButtons.at(3)->getToggleState();
    bool button4 = scene.scaleButtons.at(4)->getToggleState();
    bool button5 = scene.scaleButtons.at(5)->getToggleState();
    bool button6 = scene.scaleButtons.at(6)->getToggleState();
    
    std::cout << "scaleButton_1" << scaleButton_1 << std::endl;
    std::cout << "Button1: " << button1 << std::endl;
    std::cout << "Button2: " << button2 << std::endl;
    std::cout << "Button3: " << button3 << std::endl;
    std::cout << "Button4: " << button4 << std::endl;
    std::cout << "Button5: " << button5 << std::endl;
    std::cout << "Button6: " << button6 << std::endl;
     */
}


void DrawingSquaresAudioProcessorEditor::resized()
{
    scene.setBounds (0, 0, getWidth(), getHeight());
}
