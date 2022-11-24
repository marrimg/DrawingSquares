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

//==============================================================================
class SceneComponent: public juce::Component
{
    
public:

    std::unique_ptr<ScaleButton> c_scale_button = std::make_unique<ScaleButton>();
    std::vector<std::unique_ptr<juce::TextButton>> scaleButtons;
         
    SceneComponent()
    {
        setLookAndFeel(&mainLookAndFeel);
        addAndMakeVisible(button1);
        button1.setButtonText("PooP");
        std::vector<std::string> scaleButtonLabels = {"A", "B", "C", "D", "E", "F", "G"};
        
        for (int i = 0; i <= scaleButtonLabels.size(); i++)
        {
          auto scaleButt = std::make_unique<juce::TextButton>(scaleButtonLabels[i]);
          scaleButt->setBounds(i * 100, 100, 100, 100);
          addAndMakeVisible(*scaleButt);
          scaleButtons.push_back(std::move(scaleButt));
        }
        
       // buttonAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.apvts, "apvtsButtVar", scene.chordButton2);
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
    
    
private:
    //==============================================================================
    ScaleButton mainLookAndFeel;
    juce::TextButton button1;
    int border = 4;
    int buttonHeight = 100;
    int buttonWidth = 60;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SceneComponent)
};
