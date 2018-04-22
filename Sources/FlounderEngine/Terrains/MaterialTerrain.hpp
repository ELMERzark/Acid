#pragma once

#include "Materials/IMaterial.hpp"

namespace Flounder
{
	/// <summary>
	/// Class that represents a terrain material shader.
	/// </summary>
	class F_EXPORT MaterialTerrain :
		public IMaterial
	{
	private:
		PipelineMaterial *m_material;
	public:
		MaterialTerrain();

		~MaterialTerrain();

		void Update() override;

		void Load(LoadedValue *value) override;

		void Write(LoadedValue *destination) override;

		void PushUniforms(UniformHandler *uniformObject) override;

		void PushDescriptors(DescriptorsHandler *descriptorSet) override;

		std::string GetName() const override { return "MaterialTerrain"; };

		PipelineMaterial *GetMaterial() const override { return m_material; }
	};
}