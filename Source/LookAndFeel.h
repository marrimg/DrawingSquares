/*
  ==============================================================================

    LookAndFeel.h
    Created: 16 Nov 2022 12:42:06pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once

// Global colors
const juce::Colour black = juce::Colour::fromFloatRGBA (0.0f, 0.0f, 0.0f, 1.0f);
const juce::Colour darkGrey1 = juce::Colour::fromFloatRGBA (0.14f, 0.14f, 0.14f, 1.0f);
const juce::Colour midGrey = juce::Colour::fromFloatRGBA (0.25f, 0.25f, 0.25f, 1.0f);
const juce::Colour lightGrey = juce::Colour::fromFloatRGBA (0.34f, 0.34f, 0.34f, 1.0f);
const juce::Colour darkGrey2 = juce::Colour::fromFloatRGBA (0.45f, 0.45f, 0.45f, 1.0f);
const juce::Colour white = juce::Colour::fromFloatRGBA (1.0f, 1.0f, 1.0f, 1.0f);
const juce::Colour orange = juce::Colour::fromFloatRGBA (0.91f, 0.38f, 0.19f, 1.0f);

//Embed font
static const juce::Font getCustomFont()
{
    static auto typeface = juce::Typeface::createSystemTypefaceFor (BinaryData::HelveticaNeue_ttc, BinaryData::HelveticaNeue_ttcSize);
    return juce::Font (typeface);
}


class ScaleButton : public juce::LookAndFeel_V4
{
public:
    int borderThick = 4;
    int borderThin = 2;

    void drawButtonBackground (juce::Graphics& g, juce::Button& button, const juce::Colour& backgroundColour,
                               bool, bool isButtonDown) override
    {
        
        //Main area and border
        auto buttonArea = button.getLocalBounds();
        
        buttonArea.removeFromLeft (borderThick);
        buttonArea.removeFromTop (borderThick);
        buttonArea.removeFromRight (borderThick);
        buttonArea.removeFromBottom (borderThick);
        button.setClickingTogglesState(1);
        
        g.setColour (darkGrey1);
        g.drawRoundedRectangle(borderThick, borderThick, buttonArea.getWidth(), buttonArea.getHeight(),12, borderThick);
        g.setColour (midGrey);
        g.fillRoundedRectangle (borderThick + 2, borderThick + 2, buttonArea.getWidth() - borderThick, buttonArea.getHeight() - borderThick, 9);
        
        
        //Label text
        g.setColour (white);
        g.setFont(getCustomFont());
        g.setFont(30);
        
        float labelX = buttonArea.getCentreX() - (buttonArea.getWidth() * .4);
        float labelY = buttonArea.getHeight() - (buttonArea.getHeight() * .9);
        
        g.drawText("D#", labelX, labelY, buttonArea.getCentreY(), buttonArea.getWidth() ,4);

        //Make LED
        float ledCenterX = buttonArea.getCentreX() - (buttonArea.getWidth() * .4);
        float ledCenterY = buttonArea.getBottom() - (buttonArea.getHeight() * .4);
        
//        g.setColour (darkGrey1);
//        g.drawRect(ledCenterX, ledCenterY, buttonArea.getWidth() * .8,  buttonArea.getHeight() * .2);
//        g.fillRect(ledCenterX, ledCenterY, buttonArea.getWidth() * .8,  buttonArea.getHeight() * .2);
        
        // From Marri
        juce::Rectangle<int> ledRect (ledCenterX, ledCenterY, buttonArea.getWidth() * .8, buttonArea.getHeight() * .25);
        
        g.setColour (darkGrey1);
        g.drawRect (ledRect, borderThin) ;
        
        //
    
        if(button.getToggleState() == 0) g.setColour (lightGrey);
        
        if(button.getToggleState() == 1) g.setColour (orange);
        
        ledRect.removeFromLeft (borderThin);
        ledRect.removeFromTop (borderThin);
        ledRect.removeFromRight (borderThin);
        ledRect.removeFromBottom (borderThin);
        
        g.fillRect(ledRect);

//        g.fillRect(ledCenterX, ledCenterY, (buttonArea.getWidth() * .8) -borderWidth,  (buttonArea.getHeight() * .2) -borderWidth);
        
//        g.drawRect(ledCenterX -1, ledCenterY -1, (buttonArea.getWidth() * .8) -2,  (buttonArea.getHeight() * .2) -2) ;
//        g.fillRect(ledCenterX, ledCenterY, (buttonArea.getWidth() * .8) -2,  (buttonArea.getHeight() * .2) -2);

    }

};
