#pragma once

#include "ofMain.h"

/*
// based KTween library.
// http://kawanet.googlecode.com/svn/lang/as3/KTween/trunk/src/net/kawa/tween/easing/
 
// example
void testApp::draw()
{
	float t = ofClamp(ofGetElapsedTimef() / 10., 0, 1);
	
	// all functions take input 0. ~ 1., and outputs 0. ~ 1.
	float v = ofxEasingFunc::Cubic::easeInOut(t);
	
	ofCircle(t * ofGetWidth(), v * ofGetHeight(), 10);
}
*/

namespace ofxEasingFunc
{

struct Back
{
	inline static float easeIn(const float t)
	{
		return 3 * t * t * t - 2 * t * t;
	}

	inline static float easeOut(const float t)
	{
		return 1. - easeIn(1. - t);
	}

	inline static float easeInOut(const float t)
	{
		return (t < 0.5) ? easeIn(t * 2.0) * 0.5 : 1 - easeIn(2.0 - t * 2.0) * 0.5;
	}
};

struct Bounce
{
	inline static float easeIn(const float t)
	{
		float s;
		if (t < D1)
		{
			s = t - DH;
			s = DH - s * s * IH;
		}
		else if (t < D3)
		{
			s = t - D2;
			s = D1 - s * s * I1;
		}
		else if (t < D7)
		{
			s = t - D5;
			s = D2 - s * s * I2;
		}
		else
		{
			s = t - 1;
			s = 1 - s * s * I4D;
		}
		return s;
	}

	inline static float easeOut(const float t)
	{
		return 1. - easeIn(1. - t);
	}

	inline static float easeInOut(const float t)
	{
		return (t < 0.5) ? easeIn(t * 2.0) * 0.5 : 1 - easeIn(2.0 - t * 2.0) * 0.5;
	}

private:

	static const float DH;
	static const float D1;
	static const float D2;
	static const float D3;
	static const float D4;
	static const float D5;
	static const float D7;
	static const float IH;
	static const float I1;
	static const float I2;
	static const float I4D;
};

struct Circ
{
	inline static float easeIn(const float t)
	{
		return 1.0 - sqrtf(1.0 - t * t);
	}

	inline static float easeOut(const float t)
	{
		return 1. - easeIn(1. - t);
	}

	inline static float easeInOut(const float t)
	{
		return (t < 0.5) ? easeIn(t * 2.0) * 0.5 : 1 - easeIn(2.0 - t * 2.0) * 0.5;
	}
};

struct Cubic
{
	inline static float easeIn(const float t)
	{
		return t * t * t;
	}

	inline static float easeOut(const float t)
	{
		return 1. - easeIn(1. - t);
	}

	inline static float easeInOut(const float t)
	{
		return (t < 0.5) ? easeIn(t * 2.0) * 0.5 : 1 - easeIn(2.0 - t * 2.0) * 0.5;
	}
};

struct Elastic
{
	inline static float easeIn(const float t)
	{
		return 1.0 - easeOut(1.0 - t);
	}

	inline static float easeOut(const float t)
	{
		float s = 1 - t;
		return 1 - powf(s, 8) + sinf(t * t * 6 * PI) * s * s;
	}

	inline static float easeInOut(const float t)
	{
		return (t < 0.5) ? easeIn(t * 2.0) * 0.5 : 1 - easeIn(2.0 - t * 2.0) * 0.5;
	}
};

struct Expo
{
	inline static float easeIn(const float t)
	{
		return powf(2, 10 * (t - 1));
	}

	inline static float easeOut(const float t)
	{
		return 1.0 - powf(2, -10 * t);
	}

	inline static float easeInOut(const float t)
	{
		return (t < 0.5) ? easeIn(t * 2.0) * 0.5 : 1 - easeIn(2.0 - t * 2.0) * 0.5;
	}
};

struct Linear
{
	inline static float easeIn(const float t)
	{
		return t;
	}

	inline static float easeOut(const float t)
	{
		return t;
	}

	inline static float easeInOut(const float t)
	{
		return t;
	}
};

struct Quad
{
	inline static float easeIn(const float t)
	{
		return t * t;
	}

	inline static float easeOut(const float t)
	{
		return 1. - easeIn(1. - t);
	}

	inline static float easeInOut(const float t)
	{
		return (t < 0.5) ? easeIn(t * 2.0) * 0.5 : 1 - easeIn(2.0 - t * 2.0) * 0.5;
	}
};

struct Quart
{
	inline static float easeIn(const float t)
	{
		return t * t * t * t;
	}

	inline static float easeOut(const float t)
	{
		return 1. - easeIn(1. - t);
	}

	inline static float easeInOut(const float t)
	{
		return (t < 0.5) ? easeIn(t * 2.0) * 0.5 : 1 - easeIn(2.0 - t * 2.0) * 0.5;
	}
};

struct Quint
{
	inline static float easeIn(const float t)
	{
		return t * t * t * t * t;
	}

	inline static float easeOut(const float t)
	{
		return 1. - easeIn(1. - t);
	}

	inline static float easeInOut(const float t)
	{
		return (t < 0.5) ? easeIn(t * 2.0) * 0.5 : 1 - easeIn(2.0 - t * 2.0) * 0.5;
	}
};

struct Sine
{
	inline static float easeIn(const float t)
	{
		return 1.0 - cosf(t * HALF_PI);
	}

	inline static float easeOut(const float t)
	{
		return 1. - easeIn(1. - t);
	}

	inline static float easeInOut(const float t)
	{
		return (t < 0.5) ? easeIn(t * 2.0) * 0.5 : 1 - easeIn(2.0 - t * 2.0) * 0.5;
	}
};

}
