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
const juce::Colour lightGrey = juce::Colour::fromFloatRGBA (0.45f, 0.45f, 0.45f, 1.0f);
const juce::Colour darkGrey2 = juce::Colour::fromFloatRGBA (0.45f, 0.45f, 0.45f, 1.0f);
const juce::Colour white = juce::Colour::fromFloatRGBA (1.0f, 1.0f, 1.0f, 1.0f);
const juce::Colour whiteGrey = juce::Colour::fromFloatRGBA (.6f, .6f, 0.6f, 1.0f);
const juce::Colour orange = juce::Colour::fromFloatRGBA (0.91f, 0.38f, 0.19f, 1.0f);
const juce::Colour lightOrange = juce::Colour::fromFloatRGBA (0.93f, 0.67f, 0.114f, 1.0f);

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
        g.setColour (lightGrey);
        g.fillRoundedRectangle (borderThick + 2, borderThick + 2, buttonArea.getWidth() - borderThick, buttonArea.getHeight() - borderThick, 9);

        //Make LED
        
        float leftIndent = 12;
        float rightIndent = 12;
        float ledWidth = button.getWidth() - leftIndent - rightIndent;
        float ledHeight = buttonArea.getHeight() * .2;
        
        juce::Path ledRect;
        
        ledRect.addRoundedRectangle(leftIndent, button.getHeight() * .6, ledWidth, ledHeight, 2);
        
        float ledCenterX = ledRect.getBounds().getCentreX();
        float ledCenterY = ledRect.getBounds().getCentreY();
        
        if(button.getToggleState() == 0)
        {
            juce::ColourGradient ledGradient = juce::ColourGradient(whiteGrey, ledCenterX, ledCenterY, lightGrey, ledRect.getBounds().getX() + 3,  ledRect.getBounds().getY() + 3, true);
            g.setFillType(ledGradient);
        }

        if(button.getToggleState() == 1)
        {
            juce::ColourGradient ledGradient = juce::ColourGradient(lightOrange, ledCenterX, ledCenterY, orange, ledRect.getBounds().getX() +3,  ledRect.getBounds().getY() +3, true);
            g.setFillType(ledGradient);
        }
        
        g.fillPath(ledRect);
        
        g.setColour (darkGrey1);
        g.strokePath (ledRect, juce::PathStrokeType (2.0f));
    }
    
    void drawButtonText (juce::Graphics& g, juce::TextButton& button, bool, bool isButtonDown) override
    {
        auto font = getTextButtonFont (button, button.getHeight());
        g.setFont (font);
        g.setColour (white);
        
        //Label text

        g.setFont(getCustomFont());
        g.setFont(20);

        auto yIndent = button.proportionOfHeight (0.25);
        auto cornerSize = juce::jmin (button.getHeight(), button.getWidth()) / 2;

        auto fontHeight = juce::roundToInt (font.getHeight() * 0.6f);
        auto leftIndent  = juce::jmin (fontHeight, 2 + cornerSize / (button.isConnectedOnLeft()  ? 4 : 2));
        auto rightIndent = juce::jmin (fontHeight, 2 + cornerSize / (button.isConnectedOnRight() ? 4 : 2));
        auto textWidth = button.getWidth() - leftIndent - rightIndent;

        if (textWidth > 0)
            g.drawFittedText (button.getButtonText(),
                              leftIndent, yIndent, textWidth, button.getHeight() - yIndent,
                              juce::Justification::centredTop, 2);
    }

};
