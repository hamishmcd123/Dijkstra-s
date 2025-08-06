#pragma once
#include "pathfinding.hpp"

class PathAgent {
private:
	int m_currentIndex;
	Node* m_currentNode;
	float m_speed;
public:
	std::vector<Node*> m_path;
	glm::vec2 m_position;
	void update(float dtime);
	void goToNode(Node* node);
	void draw();
	void setNode(Node* node);
	void setSpeed(int speed);

};