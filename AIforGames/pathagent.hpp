#pragma once
#include "pathfinding.hpp"

class PathAgent {
private:
	glm::vec2 m_position;

	std::vector<Node*> m_path;
	int m_currentIndex;
	Node* m_currentNode;

	float m_speed;
public:
	void update(float dtime);
	void goToNode(Node* node);
	void draw();

};