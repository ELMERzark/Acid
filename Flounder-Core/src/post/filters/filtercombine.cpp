#include "filtercombine.h"

namespace flounder
{
	filtercombine::filtercombine() :
		ipostfilter("filterCombine", "res/shaders/filters/combineFragment.glsl")
	{
		m_slideSpaceValue = new vector4(0.0f, 1.0f, 0.0f, 1.0f);
	}

	filtercombine::~filtercombine()
	{
		delete m_slideSpaceValue;
	}

	void filtercombine::storeValues()
	{
		m_shader->loadUniform("slideSpace", *m_slideSpaceValue);
	}
}