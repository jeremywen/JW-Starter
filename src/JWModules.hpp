#pragma once
#include "rack.hpp"
#define RIGHT_ARROW "▸"

using namespace rack;
extern Plugin *pluginInstance;

struct TinyPJ301MPort : SvgPort {
	TinyPJ301MPort() {
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/TinyPJ301M.svg")));
	}
};


struct Screw_J : SVGScrew {
	Screw_J() {
		sw->setSVG(APP->window->loadSvg(asset::plugin(pluginInstance, "res/Screw_J.svg")));
		box.size = sw->box.size;
	}
};

struct Screw_W : SVGScrew {
	Screw_W() {
		sw->setSVG(APP->window->loadSvg(asset::plugin(pluginInstance, "res/Screw_W.svg")));
		box.size = sw->box.size;
	}
};

////////////////////////////////////////////// WIDGETS //////////////////////////////////////////////

extern Model *modelAdd5;

inline int clampijw(int x, int minimum, int maximum) {
	return clamp(x, minimum, maximum);
}
inline float clampfjw(float x, float minimum, float maximum) {
	return fminf(fmaxf(x, minimum), maximum);
}
inline float rescalefjw(float x, float xMin, float xMax, float yMin, float yMax) {
	return yMin + (x - xMin) / (xMax - xMin) * (yMax - yMin);
}

