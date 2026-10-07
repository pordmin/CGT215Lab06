#include <iostream>
#include <SFML/Graphics.hpp>
//Allows use to the SFML library that needs to be installed via NuGet
using namespace sf;
using namespace std;
int main() {
	//These are basically path references (not absolute) to image file locations
	string background = "images1/backgrounds/winter.png";
	string foreground = "images1/characters/yoda.png";
	//These 2 upcoming textures are used to determine if the image is at the relative location listed above.
	//If they are not, it prints "COULDN"T LOAD IMAGE" and kills the program fully.
	Texture backgroundTex;
	if (!backgroundTex.loadFromFile(background)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Texture foregroundTex;
	if (!foregroundTex.loadFromFile(foreground)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	//Textures translated into Images in order to better mess with it and do all sorts of transformation with it.
	Image backgroundImage;
	backgroundImage = backgroundTex.copyToImage();
	Image foregroundImage;
	foregroundImage = foregroundTex.copyToImage();
	//Used to get how large something is, like a Vector2f(32, 32) image (pixelated).
	Vector2u sz = backgroundImage.getSize();
	//Used to compare if the pixel at x,y location is of the color green.
	Color comparisonColor(32, 214, 23);
	for (int y = 0; y < sz.y; y++) {
		for (int x = 0; x < sz.x; x++) {
			//Gets the foreground and background color for comparison sakes
			Color currfColor = foregroundImage.getPixel(x, y);
			Color currbColor = backgroundImage.getPixel(x, y);
			//Final color output
			Color mixediColor(currfColor);
			//This checks if the current pixels color of the foreground is indeed green and if so set the 
			//Color to the backgrounds color.
			if (((currfColor.g == comparisonColor.g) )) {
				mixediColor.r = currbColor.r;
				mixediColor.g = currbColor.g;
				mixediColor.b = currbColor.b;
			}
			//This sets the color of an existing image
			foregroundImage.setPixel(x, y, mixediColor);
		}
	}
	// By default, just show the foreground image
	RenderWindow window(VideoMode(1024, 768), "Here's the output");
	Sprite sprite1;
	Texture tex1;
	tex1.loadFromImage(foregroundImage);
	sprite1.setTexture(tex1);
	window.clear();
	window.draw(sprite1);
	window.display();
	while (true);
}