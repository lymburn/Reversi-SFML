
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "texturemanager.hpp"
#include "piece.hpp"
#include "initialSetup.hpp"

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"


int main(int, char const**)
{
    
    int board[8][8] =
    { 0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,1,2,0,0,0,
        0,0,0,2,1,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
    };

    //Creates the pieces
    Piece whiteTiles[32];
    Piece blackTiles[32];
    for (int i=0; i<32; i++) {
        whiteTiles[i].setColor(1);
    }
    for (int i=0; i<32; i++) {
        blackTiles[i].setColor(2);
    }
    
    //Creates initial window
    sf::RenderWindow window(sf::VideoMode(1200, 1200), "Reversi");
    
    //Sets the icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    //Create the background board
    TextureManager textureLoader;
    textureLoader.loadBoardTexture();
    sf::Sprite background;
    createBackground(background,textureLoader.boardTexture);
    
    /*
    textureLoader.loadWhiteTile();
    sf::Sprite circle;
    circle.setTexture(textureLoader.whiteTile);
     */
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Clear screen
        window.clear();
        
        //Draw the board
        window.draw(background);
        //window.draw(circle);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
