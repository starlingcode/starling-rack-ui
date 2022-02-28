#pragma once

#include "rack.hpp"

using namespace rack;

// Square light used in the TRS meter module
template <typename TBase>
struct MeterLight : TBase {
	MeterLight() {
		this->box.size = window::mm2px(math::Vec(2.45, 2.45));

	}
};

struct RGBTriangle : ModuleLightWidget {
    RGBTriangle() {
        addBaseColor(nvgRGBAf(1.0, 0.0, 0.0, 1.0));
        addBaseColor(nvgRGBAf(0.0, 1.0, 0.0, 1.0));
        addBaseColor(nvgRGBAf(0.0, 0.0, 1.0, 1.0));
    }
    
    void drawBackground(const DrawArgs &args) override {}

    void drawLight(const DrawArgs &args) override {
        
        nvgBeginPath(args.vg);
        nvgMoveTo(args.vg, .5,-17.8);
        nvgLineTo(args.vg, -12,9.6);
        nvgLineTo(args.vg, 12.7,9.6);
        nvgClosePath(args.vg);
        
        // Solid color
        
        nvgFillColor(args.vg, color);
        //nvgTransRGBAf(color, 1.0);
        nvgFill(args.vg);
        
        // Border
        nvgStrokeWidth(args.vg, 0.5);
        nvgStrokeColor(args.vg, borderColor);
        nvgStroke(args.vg);
        nvgRotate(args.vg, (30.0/120.0)*NVG_PI*2);
    }
    
    void drawHalo(const DrawArgs &args) override {
        float radius = 14;
        float oradius = radius + 13;
        
        nvgBeginPath(args.vg);
        nvgRect(args.vg, -25, -25, 50, 50);
        
        NVGpaint paint;
        NVGcolor icol = color::mult(color, 0.10);
        NVGcolor ocol = nvgRGB(0, 0, 0);
        paint = nvgRadialGradient(args.vg, 0, 0, radius, oradius, icol, ocol);
        nvgFillPaint(args.vg, paint);
        nvgGlobalCompositeOperation(args.vg, NVG_LIGHTER);
        nvgFill(args.vg);
    }
};


struct SifamBlack : RoundKnob {
    SifamBlack() {
        setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/starling-rack-gfx/knob-sifam-blkcap.svg")));
    }
};

struct SifamGrey : RoundKnob {
    SifamGrey() {
        setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/starling-rack-gfx/knob-sifam-grycap.svg")));
    }
};

struct HexJack : SvgPort {
    HexJack() {
        setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/starling-rack-gfx/jack-nogradients.svg")));
    }
};

// Button skins for the manual trigger and touch sensors


struct TransparentButton : SvgSwitch {

    TransparentButton() {
        momentary = true;
        shadow->opacity = 0.0;
        addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/starling-rack-gfx/transparent_button.svg")));
    }
};

struct ViaPushButton : SvgSwitch {
    ViaPushButton() {
        momentary = true;
        addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/starling-rack-gfx/manual-trig.svg")));
        addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/starling-rack-gfx/manual-trig-down.svg")));
    }
};

struct ButtonLight : YellowLight {
    ButtonLight() {
        box.size = Vec(28 - 6, 28 - 6);
        bgColor = color::BLACK_TRANSPARENT;
    }
};

struct NKK_2 : app::SvgSwitch {
	NKK_2() {
		addFrame(Svg::load(asset::system("res/ComponentLibrary/NKK_0.svg")));
		addFrame(Svg::load(asset::system("res/ComponentLibrary/NKK_2.svg")));
	}
};


