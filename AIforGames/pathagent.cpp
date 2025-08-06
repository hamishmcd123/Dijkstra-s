#include "pathagent.hpp"
#include "nodemap.hpp"

void PathAgent::update(float dtime)
{
}

void PathAgent::goToNode(Node* node)
{
	m_path = NodeMap::DijkstrasSearch(m_currentNode, node);
	m_currentIndex = 0;
}

void PathAgent::draw()
{
}
