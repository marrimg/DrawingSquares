/*
  ==============================================================================

    Components.h
    Created: 21 Nov 2022 9:50:26am
    Author:  jeph

  ==============================================================================
*/

#pragma once

#include "GuiElements.h"
#include "PluginEditor.h"
#include "PluginProcessor.h"
const std::vector<std::string> noteNames = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

//==============================================================================
class SceneComponent: public juce::Component
{
    
public:

    std::unique_ptr<ScaleButton> c_scale_button = std::make_unique<ScaleButton>();
    std::vector<std::unique_ptr<juce::TextButton>> scaleButtons;
          
    SceneComponent(DrawingSquaresAudioProcessor& p)
    {
        setLookAndFeel(&mainLookAndFeel);
       
        
        for (int i = 0; i <= noteNames.size(); i++)
        {
          auto scaleButt = std::make_unique<juce::TextButton>(noteNames[i]);
          scaleButt->setBounds(i * buttonWidth + 10, 100, buttonWidth, buttonHeight);
          addAndMakeVisible(*scaleButt);
          p.addParameter (new juce::AudioParameterBool (juce::ParameterID {i, 1}, "scaleButt", false));
            //buttonAttachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment(p.getVTS(), "poopParameterId", button1));
          scaleButtons.push_back(std::move(scaleButt));
        }
        
    }
    
    void paint (juce::Graphics& g) override
    {
        g.fillAll (juce::Colours::black);
    }
    
    void resized() override
    {
        auto area = getLocalBounds();
        button1.setBounds(area.removeFromLeft(buttonWidth).removeFromTop(buttonHeight).reduced(border));
    }
    
    ~SceneComponent(){
        setLookAndFeel(nullptr);
    }
    ScaleButton mainLookAndFeel;
    juce::TextButton button1;
    
private:
    //==============================================================================

    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> buttonAttachment;
    int border = 4;
    int buttonHeight = 100;
    int buttonWidth = 60;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SceneComponent)
};
