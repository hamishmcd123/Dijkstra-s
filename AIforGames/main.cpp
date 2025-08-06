#include <string>
#include "pathfinding.hpp"
#include "nodemap.hpp"
#include "raylib.hpp"
#include "pathagent.hpp"

int main() {
    int cellSize = 32;

    std::vector<std::string> asciiMap;
    asciiMap.push_back("000000000000000000000000000000");
    asciiMap.push_back("011111111111111111111111111110");
    asciiMap.push_back("011000000000001111000000000110");
    asciiMap.push_back("011011111110001001111111110110");
    asciiMap.push_back("011010000010001001000000010110");
    asciiMap.push_back("011011110011111001111110010110");
    asciiMap.push_back("011000010000001001000010010110");
    asciiMap.push_back("011111011111101111011110010110");
    asciiMap.push_back("010000010001000001000010010110");
    asciiMap.push_back("011111110111111111111110010110");
    asciiMap.push_back("011000000100000000000000010110");
    asciiMap.push_back("011011111101111111111111110110");
    asciiMap.push_back("011010000001000000000000000110");
    asciiMap.push_back("011011111101011111111111110110");
    asciiMap.push_back("011000000101000000000010000110");
    asciiMap.push_back("011111111101011111111111110110");
    asciiMap.push_back("011000000000000000000000000110");
    asciiMap.push_back("011111111111111111111111111110");
    asciiMap.push_back("000000000000000000000000000000");


    
    NodeMap map;
    map.initialise(asciiMap, cellSize);
    
    Node* start = map.getNode(2,2);
    Node* end = nullptr;


    PathAgent agent;
    agent.setNode(start);
    agent.m_position = start->position;
    agent.setSpeed(1024);
    agent.setRadius(8);

    std::vector<Node*> path = NodeMap::DijkstrasSearch(start, end);

    InitWindow(cellSize * map.m_width, cellSize * map.m_height, "NodeGraph");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        map.draw();
        NodeMap::drawPath(agent.m_path);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            map.resetNodes();
            Vector2 mousePos = GetMousePosition();
            start = map.getClosestNode(glm::vec2(mousePos.x, mousePos.y));
            path = NodeMap::DijkstrasSearch(start, end);
            if (start != nullptr) {
				agent.setNode(start);
                agent.m_position = start->position;
				agent.goToNode(end);
            }
	   }

        else if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
            map.resetNodes();
            Vector2 mousePos = GetMousePosition();
            end = map.getClosestNode(glm::vec2(mousePos.x, mousePos.y));
            agent.goToNode(end);
        }

        agent.update(GetFrameTime());
        agent.draw();
        EndDrawing();
    }

    CloseWindow();
    
}

