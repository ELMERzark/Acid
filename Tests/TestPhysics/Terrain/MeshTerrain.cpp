#include "MeshTerrain.hpp"

namespace test
{
MeshTerrain::MeshTerrain(const std::vector<float> &heightmap, const float &sideLength, const float &squareSize, const uint32_t &vertexCount, const float &textureScale) :
	MeshSimple(sideLength, squareSize, vertexCount, textureScale),
	m_heightmap(heightmap)
{
	GenerateMesh();
}

VertexModel MeshTerrain::GetVertex(const uint32_t &col, const uint32_t &row)
{
	float x = ((row * m_squareSize) - m_sideLength) / 2.0f;
	float z = ((col * m_squareSize) - m_sideLength) / 2.0f;

	Vector3f position = GetPosition(x, z);
	Vector2f uv = Vector2f(static_cast<float>(col) * m_textureScale / static_cast<float>(m_vertexCount),
		static_cast<float>(row) * m_textureScale / static_cast<float>(m_vertexCount));
	Vector3f normal = GetNormal(x, z);
	//Colour colour = GetColour(normal);
	return VertexModel(position, uv, normal); // , colour
}

Vector3f MeshTerrain::GetPosition(const float &x, const float &z)
{
	int32_t row = static_cast<int32_t>(((x * 2.0f) + m_sideLength) / m_squareSize);
	int32_t col = static_cast<int32_t>(((z * 2.0f) + m_sideLength) / m_squareSize);

	if (row >= static_cast<int32_t>(m_vertexCount) || col >= static_cast<int32_t>(m_vertexCount))
	{
		return Vector3f(x, 0.0f, z);
	}

	return Vector3f(x, m_heightmap[col * m_vertexCount + row], z);
}

Vector3f MeshTerrain::GetNormal(const float &x, const float &z)
{
	Vector3f positionL = GetPosition(x - 1.0f, z);
	Vector3f positionR = GetPosition(x + 1.0f, z);
	Vector3f positionD = GetPosition(x, z - 1.0f);
	//Vector3 positionU = GetPosition(x, z + 1.0f);

	Vector3f normal = (positionL - positionR).Cross(positionR - positionD);
	return normal.Normalize();
}

Colour MeshTerrain::GetColour(const Vector3f &normal)
{
	return Colour(1.0f, 0.0f, 0.0f, 0.0f);
}
}
