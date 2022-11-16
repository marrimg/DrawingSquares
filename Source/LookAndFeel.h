/*
  ==============================================================================

    LookAndFeel.h
    Created: 16 Nov 2022 12:42:06pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once

class AntimatterLookAndFeel : public juce::LookAndFeel_V4
{
public:
    int borderWidth = 4;
    void drawButtonBackground (juce::Graphics& g, juce::Button& button, const juce::Colour& backgroundColour,
                               bool, bool isButtonDown) override
    {
        // colors
        juce::Colour darkGrey1 = juce::Colour::fromFloatRGBA (0.14f, 0.14f, 0.14f, 1.0f);
        juce::Colour midGrey = juce::Colour::fromFloatRGBA (0.25f, 0.25f, 0.25f, 1.0f);
        juce::Colour lightGrey = juce::Colour::fromFloatRGBA (0.34f, 0.34f, 0.34f, 1.0f);
        juce::Colour darkGrey2 = juce::Colour::fromFloatRGBA (0.45f, 0.45f, 0.45f, 1.0f);
        juce::Colour white = juce::Colour::fromFloatRGBA (1.0f, 1.0f, 1.0f, 1.0f);
        juce::Colour orange = juce::Colour::fromFloatRGBA (0.91f, 0.38f, 0.19f, 1.0f);
        
        
        auto buttonArea = button.getLocalBounds();
        
        buttonArea.removeFromLeft (borderWidth);
        buttonArea.removeFromTop (borderWidth);
        buttonArea.removeFromRight (borderWidth);
        buttonArea.removeFromBottom (borderWidth);


        g.setColour (darkGrey1);
        g.drawRoundedRectangle(borderWidth, borderWidth, buttonArea.getWidth(), buttonArea.getHeight(),12, borderWidth);
        g.setColour (midGrey);
        g.fillRoundedRectangle (borderWidth + 2, borderWidth + 2, buttonArea.getWidth() - borderWidth, buttonArea.getHeight() - borderWidth, 9);

    }

};
