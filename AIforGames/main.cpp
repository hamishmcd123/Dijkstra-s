#include <string>
#include "pathfinding.hpp"
#include "nodemap.hpp"
#include "raylib.hpp"

int main() {
    int cellSize = 80;

    std::vector<std::string> asciiMap;
    asciiMap.push_back("000000000000");
    asciiMap.push_back("010111011100");
    asciiMap.push_back("010101110110");
    asciiMap.push_back("010100010000");
    asciiMap.push_back("010111111110");
    asciiMap.push_back("010000010000");
    asciiMap.push_back("011111111110");
    asciiMap.push_back("000000000000");
    
    NodeMap map;
    map.initialise(asciiMap, cellSize);
    
    Node* start = nullptr;
    Node* end = nullptr;

    std::vector<Node*> path = NodeMap::DijkstrasSearch(start, end);

    InitWindow(cellSize * map.m_width, cellSize * map.m_height, "NodeGraph");
   
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        map.draw();
        NodeMap::drawPath(path);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();
            start = map.getClosestNode(glm::vec2(mousePos.x, mousePos.y));
            path = NodeMap::DijkstrasSearch(start, end);
        }
        else if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();
            end = map.getClosestNode(glm::vec2(mousePos.x, mousePos.y));
            path = NodeMap::DijkstrasSearch(start, end);
        }
        EndDrawing();
    }

    CloseWindow();
    
}

