#include "Engine2D.h"

int main(int argc, char *args[])
{
    int width=800;
    int height=800;
    Engine2D engine(width, height);
    int gridSize = 50;
    int radius = gridSize * 0.5;


    // players
    const auto player1 = engine.world.create();
    engine.world.emplace<TransformComponent>(player1, Vec2D(425,425));
    engine.world.emplace<GridMovementComponent>(player1, gridSize);
    engine.world.emplace<NameGroupComponent>(player1, "player1", "players");

    const auto player2 = engine.world.create();
    engine.world.emplace<TransformComponent>(player2, Vec2D(225,425));
    engine.world.emplace<GridMovementComponent>(player2, gridSize);
    engine.world.emplace<NameGroupComponent>(player2, "player2", "players");

    while (engine.nextFrame())
    {
        engine.update();

        Graphics::drawGrid(gridSize);

        const auto player1TransformComp =  engine.world.get<TransformComponent>(player1);
        const auto player2TransformComp =  engine.world.get<TransformComponent>(player2);


        // draw players
        Graphics::drawFillCircle(
            player1TransformComp.position.x, 
            player1TransformComp.position.y, 
            radius, 
            Color::blue()
        );

        Graphics::drawFillCircle(
            player2TransformComp.position.x, 
            player2TransformComp.position.y, 
            radius, 
            Color::green()
        );

        engine.render();
    }

    return 0;
}