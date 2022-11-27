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
//    scaleButt1Parameter = p.stateStore.getRawParameterValue("scaleButt");
//    std::cout << "POOPPARAM :" << *scaleButt1Parameter << std::endl;
//    scaleButt1Parameter = p.getParameterTree();
    auto parameters = p.getParameterTree().getParameters (true);
//    std::unique_ptr<juce::XmlElement> xml (parameters.createXml());
//    std::cout << xml;
    addAndMakeVisible (scene);
//    parameterChanged("poopParameterId");

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
    //bool out = scene.button1.getToggleState();
    //std::cout << out << std::endl;
    //scene.scaleButtons.at(1)->lastToggleState
    bool button0 = scene.scaleButtons.at(0)->getToggleState();
    bool button1 = scene.scaleButtons.at(1)->getToggleState();
    bool button2 = scene.scaleButtons.at(2)->getToggleState();
    bool button3 = scene.scaleButtons.at(3)->getToggleState();
    bool button4 = scene.scaleButtons.at(4)->getToggleState();
    bool button5 = scene.scaleButtons.at(5)->getToggleState();
    bool button6 = scene.scaleButtons.at(6)->getToggleState();
    std::cout << "Button0: " << button0 << std::endl;
    std::cout << "Button1: " << button1 << std::endl;
    std::cout << "Button2: " << button2 << std::endl;
    std::cout << "Button3: " << button3 << std::endl;
    std::cout << "Button4: " << button4 << std::endl;
    std::cout << "Button5: " << button5 << std::endl;
    std::cout << "Button6: " << button6 << std::endl;
}

//void parameterChanged (const juce::String& parameterID, float newValue) {
//    std::cout << newValue;
//}
//struct PoopListener : public juce::AudioProcessorValueTreeState::Listener
//{
//
////    PoopListener(SynthWaveform& wf) : juce::AudioProcessorValueTreeState::Listener(), waveform(wf) {}
//    void parameterChanged(const juce::String&, float newValue) override
//    {
//        std::cout << newValue;
//    }
//};


void DrawingSquaresAudioProcessorEditor::resized()
{
    scene.setBounds (0, 0, getWidth(), getHeight());
//    scene.button1;
//    scaleButt1Parameter = p.stateStore.getRawParameterValue("scaleButt");
//    std::cout << "POOPPARAM :" << *scaleButt1Parameter << std::endl;
    /*
    auto area = getLocalBounds();
    button1.setBounds (area.removeFromLeft(buttonWidth).removeFromTop(buttonHeight).reduced(border));
    button2.setBounds (area.removeFromLeft(buttonWidth).removeFromTop(buttonHeight).reduced(border));
    button3.setBounds (area.removeFromLeft(buttonWidth).removeFromTop(buttonHeight).reduced(border));
*/
}
