/*
  ==============================================================================

    Components.h
    Created: 21 Nov 2022 9:50:26am
    Author:  jeph

  ==============================================================================
*/

#pragma once

#include "GuiElements.h"

/*
class ScaleButtonComponent   : public juce::Component
{
public:
    ScaleButtonComponent() {}
    
    void paint (juce::Graphics& g) override
    {
        //setLookAndFeel (&mainLookAndFeel);
        ScaleButton mainLookAndFeel;
        juce::TextButton button1;
        addAndMakeVisible (button1);
        button1.setButtonText("D#");
    }
    
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScaleButtonComponent)
};
*/


//==============================================================================
class SceneComponent: public juce::Component
{
    
public:

    std::unique_ptr<ScaleButton> c_scale_button = std::make_unique<ScaleButton>();
    
    SceneComponent()
    {
        setLookAndFeel(&mainLookAndFeel);
        addAndMakeVisible(button1);
        button1.setButtonText("PooP");
    }
    
    void paint (juce::Graphics& g) override
    {
        g.fillAll (juce::Colours::black);
    }
    
    void resized() override
    {
        auto area = getLocalBounds();
        button1.setBounds(area.removeFromLeft(buttonWidth).removeFromTop(buttonHeight).reduced(border));
        auto separation = juce::jlimit (2, 10, getHeight() / 20);
       // c_scale_button.setBounds (0, (int) (getHeight() * 0.20) + separation / 2, getWidth(), (int) (getHeight() * 0.80) - separation);
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
