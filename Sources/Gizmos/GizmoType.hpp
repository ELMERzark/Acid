#pragma once

#include "Maths/Colour.hpp"
#include "Maths/Matrix4.hpp"
#include "Models/Model.hpp"
#include "Renderer/Buffers/InstanceBuffer.hpp"
#include "Renderer/Descriptors/DescriptorsHandler.hpp"
#include "Renderer/Pipelines/PipelineGraphics.hpp"
#include "Resources/Resource.hpp"
#include "Serialized/Metadata.hpp"

namespace acid
{
class Gizmo;

/**
 * @brief Resource that represents a gizmo type.
 */
class ACID_EXPORT GizmoType :
	public Resource
{
public:
	/**
	 * Creates a new gizmo type, or finds one with the same values.
	 * @param metadata The metadata to decode values from.
	 * @return The gizmo type with the requested values.
	 */
	static std::shared_ptr<GizmoType> Create(const Metadata &metadata);

	/**
	 * Creates a new gizmo type, or finds one with the same values.
	 * @param model The model that the gizmo will render.
	 * @param lineThickness The thickness that the model will be rendered at.
	 * @param colour The default colour for gizmos.
	 * @return The gizmo type with the requested values.
	 */
	static std::shared_ptr<GizmoType> Create(const std::shared_ptr<Model> &model = nullptr, const float &lineThickness = 1.0f, const Colour &colour = Colour::White);

	/**
	 * Creates a new gizmo type.
	 * @param model The model that the gizmo will render.
	 * @param lineThickness The thickness that the model will be rendered at.
	 * @param colour The default colour for gizmos.
	 */
	explicit GizmoType(std::shared_ptr<Model> model, const float &lineThickness = 1.0f, const Colour &colour = Colour::White);

	void Update(const std::vector<std::unique_ptr<Gizmo>> &gizmos);

	bool CmdRender(const CommandBuffer &commandBuffer, const PipelineGraphics &pipeline, UniformHandler &uniformScene);

	void Decode(const Metadata &metadata) override;

	void Encode(Metadata &metadata) const override;

	static Shader::VertexInput GetVertexInput(const uint32_t &baseBinding = 0);

	const std::shared_ptr<Model> &GetModel() const { return m_model; }

	void SetModel(const std::shared_ptr<Model> &model) { m_model = model; }

	const float &GetLineThickness() const { return m_lineThickness; }

	void SetLineThickness(const float &lineThickness) { m_lineThickness = lineThickness; }

	const Colour &GetColour() const { return m_colour; }

	void SetColour(const Colour &colour) { m_colour = colour; }

private:
	struct GizmoTypeData // TODO: Convert into a IVertex!
	{
		Matrix4 m_modelMatrix;
		Colour m_colour;
	};

	std::shared_ptr<Model> m_model;
	float m_lineThickness;
	Colour m_colour;

	uint32_t m_maxInstances;
	uint32_t m_instances;

	DescriptorsHandler m_descriptorSet;
	InstanceBuffer m_instanceBuffer;
};
}
