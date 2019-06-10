#ifndef __MYTESTSUITE_H
#define __MYTESTSUITE_H

#include <cxxtest/TestSuite.h>
#include <Acid.h>
#include <OrangeShot.h>
#include "../server/Stage.h"
#include "BrickBlock.h"
#include "MetalBlock.h"
#include "DiagonalMetalBlock.h"
#include "configuration.h"

class BrickBlockTest : public CxxTest::TestSuite
{
    size_t width_stage = 500;
    size_t height_stage = 500;
    size_t x_pos = 10;
    size_t y_pos = 10;
    size_t side = 2;

public:
    void testBrickBlock() {
        std::cout << "Testing the brick block dimentions" << std::endl;

        Stage stage(width_stage, height_stage);
        stage.addBrickBlock(side, x_pos, y_pos);
        Coordinate* coordinates = new Coordinate(x_pos, y_pos);
        BrickBlock* block = stage.getBrickBlock(coordinates);

        TS_ASSERT_EQUALS(x_pos, block->getHorizontalPosition());
        TS_ASSERT_EQUALS(y_pos, block->getVerticalPosition());
    }
};

class MetalBlockTest : public CxxTest::TestSuite
{
    size_t width_stage = 500;
    size_t height_stage = 500;
    size_t x_pos = 10;
    size_t y_pos = 10;
    size_t side = 2;

public:
    void testMetalBlock() {
        std::cout << "Testing the metal block dimentions" << std::endl;

        Stage stage(width_stage, height_stage);
        stage.addMetalBlock(side, x_pos, y_pos);
        Coordinate* coordinates = new Coordinate(x_pos, y_pos);
        MetalBlock* block = stage.getMetalBlock(coordinates);

        TS_ASSERT_EQUALS(x_pos, block->getHorizontalPosition());
        TS_ASSERT_EQUALS(y_pos, block->getVerticalPosition());
    }
};


class DiagonalMetalBlockTest : public CxxTest::TestSuite
{
    size_t width_stage = 500;
    size_t height_stage = 500;
    size_t x_pos = 10;
    size_t y_pos = 10;
    size_t side = 2;

public:
    void testDiagonalMetalBlock() {
        std::cout << "Testing the diagonal metal block dimentions" << std::endl;

        Stage stage(width_stage, height_stage);
        stage.addDiagonalMetalBlock(side, x_pos, y_pos);
        Coordinate* coordinates = new Coordinate(x_pos, y_pos);
        DiagonalMetalBlock* block = stage.getDiagonalMetalBlock(coordinates);

        TS_ASSERT_EQUALS(x_pos, block->getHorizontalPosition());
        TS_ASSERT_EQUALS(y_pos, block->getVerticalPosition());
    }

};


class EnergyTransmitterTest : public CxxTest::TestSuite
{
    size_t width_stage = 500;
    size_t height_stage = 500;
    size_t x_pos = 10;
    size_t y_pos = 10;
    size_t side = 2;
    std::string id_et = "EnergyTransmitter1";

public:
    void testEnergyTransmitter() {
        std::cout << "Testing the energy transmitter dimentions" << std::endl;

        Stage stage(width_stage, height_stage);
        stage.addEnergyTransmitterRight(id_et, side, x_pos, y_pos);
        EnergyTransmitter* energy = stage.getEnergyTransmitter(id_et);

        TS_ASSERT_EQUALS(x_pos, energy->getHorizontalPosition());
        TS_ASSERT_EQUALS(y_pos, energy->getVerticalPosition());
    }
};


class RockTest : public CxxTest::TestSuite
{
    size_t width_stage = 500;
    size_t height_stage = 500;
    size_t x_pos = 10;
    size_t y_pos = 10;
    size_t side = 2;
    std::string id_rock = "Rock1";

public:
    void testRock() {
        std::cout << "Testing the rock dimentions" << std::endl;

        Stage stage(width_stage, height_stage);
        stage.addRock(id_rock, side, x_pos, y_pos);
        Rock* rock = stage.getRock(id_rock);

        TS_ASSERT_EQUALS(x_pos, rock->getHorizontalPosition());
        TS_ASSERT_EQUALS(y_pos, rock->getVerticalPosition());
    }
};

class EnergyBarTest : public CxxTest::TestSuite
{
    size_t width_stage = 500;
    size_t height_stage = 500;
    size_t x_pos = 10;
    size_t y_pos = 10;
    size_t v_side = 2;
    size_t h_side = 4;

public:
    void testEnergyBar() {
        std::cout << "Testing the energy bar dimentions" << std::endl;

        Stage stage(width_stage, height_stage);
        stage.addEnergyBar(v_side, h_side, x_pos, y_pos);
        Coordinate* coordinates = new Coordinate(x_pos, y_pos);
        EnergyBar* energy_bar = stage.getEnergyBar(coordinates);

        TS_ASSERT_EQUALS(x_pos, energy_bar->getHorizontalPosition());
        TS_ASSERT_EQUALS(y_pos, energy_bar->getVerticalPosition());
    }
};


class ButtonTest : public CxxTest::TestSuite
{
    size_t width_stage = 500;
    size_t height_stage = 500;
    size_t x_pos = 10;
    size_t y_pos = 10;
    size_t v_side = 2;
    size_t h_side = 4;

public:
    void testButton() {
        std::cout << "Testing the button dimentions" << std::endl;

        Stage stage(width_stage, height_stage);
        stage.addButton(v_side, h_side, x_pos, y_pos);
        Coordinate* coordinates = new Coordinate(x_pos, y_pos);
        Button* button = stage.getButton(coordinates);

        TS_ASSERT_EQUALS(x_pos, button->getHorizontalPosition());
        TS_ASSERT_EQUALS(y_pos, button->getVerticalPosition());
    }
};

class AcidTest : public CxxTest::TestSuite
{
    size_t width_stage = 500;
    size_t height_stage = 500;
    size_t x_pos = 10;
    size_t y_pos = 10;
    size_t v_side = 2;
    size_t h_side = 4;
    std::string id_acid = "Acid1";

public:
    void testAcid() {
        std::cout << "Testing the acid dimentions" << std::endl;

        Stage stage(width_stage, height_stage);
        stage.addAcid(id_acid, v_side, h_side, x_pos, y_pos);
        Acid* button = stage.getAcid(id_acid);

        TS_ASSERT_EQUALS(x_pos, button->getHorizontalPosition());
        TS_ASSERT_EQUALS(y_pos, button->getVerticalPosition());
    }
};

class OutOfRangeTest : public CxxTest::TestSuite
{
    size_t width_stage = 500;
    size_t height_stage = 500;
    size_t x_pos_bad = 600;
    size_t x_pos_ok = 1;
    size_t y_pos_bad = 600;
    size_t y_pos_ok = 1;

public:
    void testOutOfRange() {
        std::cout << "Testing the out of range excepcion" << std::endl;

        Stage stage(width_stage, height_stage);
        try {
            stage.addBrickBlock(5, x_pos_bad, y_pos_ok);
        }
        catch (...) {
            std::cout << "Catching the excepcion correctly 1" << std::endl;
        }
        try {
            stage.addBrickBlock(5, x_pos_ok, y_pos_bad);
        }
        catch (...) {
            std::cout << "Catching the excepcion correctly 2" << std::endl;
        }
        try {
            stage.addBrickBlock(5, x_pos_bad, y_pos_bad);
        }
        catch (...) {
            std::cout << "Catching the excepcion correctly 3" << std::endl;
            return;
        }
        TS_ASSERT_EQUALS(1, 0);
    }
};

class ChellTest : public CxxTest::TestSuite {

    size_t width_stage = 1000;
    size_t height_stage = 1000;
    size_t initial_position_x = 500;
    size_t initial_position_y = 100;
    size_t v_side = 10;
    size_t h_side = 10;
    size_t mass = v_side * h_side;
    std::string id_chell = "Chell1";

public:
    void testChellInit() {
        std::cout << "Testing the creation of Chell" << std::endl;

        Stage stage(width_stage, height_stage);
        stage.addChell(id_chell, v_side, h_side, initial_position_x, initial_position_y);
        Chell* chell = stage.getChell(id_chell);

        TS_ASSERT_EQUALS(initial_position_x, chell->getHorizontalPosition());
        TS_ASSERT_EQUALS(initial_position_y, chell->getVerticalPosition());
        TS_ASSERT_EQUALS(0, chell->getHorizontalVelocity());
        TS_ASSERT_EQUALS(0, chell->getVerticalVelocity());
    }

    void testChellFalls() {
        std::cout << "Testing chell falling" << std::endl;

        Stage stage(width_stage, height_stage);
        stage.addChell(id_chell, h_side, v_side, initial_position_x, initial_position_y);
        Chell* chell = stage.getChell(id_chell);

        float dt = 1.0f/60.0f;
        float gravity = gameConfiguration.gravity;
        float velocity_y = 0;
        float position = initial_position_y;

        for (size_t i = 0; i < 120; i++) {
            stage.step();
            velocity_y += gravity * dt;
            position += velocity_y * dt;
            TS_ASSERT_DELTA(position, chell->getVerticalPosition(), 0.1f);
            TS_ASSERT_DELTA(velocity_y, chell->getVerticalVelocity(), 0.1f);
        }
    }

    void testChellMovesRight() {
        std::cout << "Testing chell moving right" << std::endl;

        Stage stage(width_stage, height_stage);
        stage.addChell(id_chell, h_side, v_side, initial_position_x, initial_position_y);
        Chell* chell = stage.getChell(id_chell);

        chell->moveRight();

        float dt = 1.0f/60.0f;
        float velocity_x = 0;
        float position = initial_position_x;
        float force = gameConfiguration.chellForce;
        float acceleration = force / mass;

        for (size_t i = 0; i < 120; i++) {
            stage.step();
            if (velocity_x <= 0.5) velocity_x += acceleration * dt;
            position += velocity_x * dt;
            TS_ASSERT_DELTA(position, chell->getHorizontalPosition(), 0.1f);
            TS_ASSERT_DELTA(velocity_x, chell->getHorizontalVelocity(), 0.1f);
        }
    }

    void testChellMovesLeft() {
        std::cout << "Testing chell moving left" << std::endl;

        Stage stage(width_stage, height_stage);
        stage.addChell(id_chell, h_side, v_side, initial_position_x, initial_position_y);
        Chell* chell = stage.getChell(id_chell);

        chell->moveLeft();

        float dt = 1.0f/60.0f;
        float velocity_x = 0;
        float position = initial_position_x;
        float force = -gameConfiguration.chellForce;
        float acceleration = force / mass;

        for (size_t i = 0; i < 120; i++) {
            stage.step();
            if(velocity_x >= -0.5) velocity_x += acceleration * dt;
            position += velocity_x * dt;
            TS_ASSERT_DELTA(position, chell->getHorizontalPosition(), 0.1f);
            TS_ASSERT_DELTA(velocity_x, chell->getHorizontalVelocity(), 0.1f);
        }
    }

    void testChellJumps() {
        std::cout << "Testing chell jumping" << std::endl;

        Stage stage(width_stage, height_stage);
        float position = 5;
        stage.addChell(id_chell, h_side, v_side, initial_position_x, position);
        Chell* chell = stage.getChell(id_chell);

        chell->jump();

        float velocity_y = chell->getVerticalVelocity();
        float dt = 1.0f/60.f;
        float gravity = gameConfiguration.gravityJump;

        for (size_t i = 0; i < 130; i++) {
            stage.step();
            velocity_y += gravity * dt;
            position += velocity_y * dt;
            if (position <= 5) continue; //it has reached the floor
            TS_ASSERT_DELTA(position, chell->getVerticalPosition(), 0.1f);
        }
    }
};

class EnergyBallTest : public CxxTest::TestSuite {
    size_t width_stage = 1000;
    size_t height_stage = 1000;
    size_t initial_position_x = 500;
    size_t initial_position_y = 500;
    size_t side = 10;
    size_t mass = side * side;
    std::string id_eb = "EnergyBall1";

public:
    void testEnergyBallInit() {
        std::cout << "Testing the creation of EnergyBall" << std::endl;

        Stage stage(width_stage, height_stage);
        stage.addEnergyBallHorizontal(id_eb, side, initial_position_x, initial_position_y);
        EnergyBall* energy_ball = stage.getEnergyBall(id_eb);

        TS_ASSERT_EQUALS(initial_position_x, energy_ball->getHorizontalPosition());
        TS_ASSERT_EQUALS(initial_position_y, energy_ball->getVerticalPosition());
        TS_ASSERT_EQUALS(0, energy_ball->getHorizontalVelocity());
        TS_ASSERT_EQUALS(0, energy_ball->getVerticalVelocity());
    }

    void testEnergyBallDoesntFall() {
        std::cout << "Testing that the energy ball doesn't fall" << std::endl;

        Stage stage(width_stage, height_stage);
        stage.addEnergyBallHorizontal(id_eb, side, initial_position_x, initial_position_y);
        EnergyBall* energy_ball = stage.getEnergyBall(id_eb);

        for (size_t i = 0; i < 120; i++) {
            stage.step();
            TS_ASSERT_EQUALS(initial_position_y, energy_ball->getVerticalPosition());
            TS_ASSERT_EQUALS(0, energy_ball->getVerticalVelocity());
        }
    }

    void testEnergyBallHorizontalCollidesAndInvertsDirection() {
        std::cout << "Testing that the horizontal energy ball collides against a wall and inverts direction" << std::endl;

        Stage stage(width_stage, height_stage);
        stage.addEnergyBallHorizontal(id_eb, side, width_stage - 50, initial_position_y);
        EnergyBall* energy_ball = stage.getEnergyBall(id_eb);

        energy_ball->fly();

        float position = energy_ball->getHorizontalPosition();
        float velocity;
        float dt = 1.0f/60.f;

        bool test = false;

        for (size_t i = 0; i < 120000; i++) {
            stage.step();
            velocity = energy_ball->getHorizontalVelocity();
            position += velocity * dt;
            if (energy_ball->isDead()) continue;
            TS_ASSERT_DELTA(position, energy_ball->getHorizontalPosition(), 1.0f);
            if (position < width_stage - 50) test = true;
        }
        TS_ASSERT_EQUALS(test, true);
    }

    void testEnergyBallVerticalCollidesAndInvertsDirection() {
        std::cout << "Testing that the vertical energy ball collides against a wall and inverts direction" << std::endl;

        Stage stage(width_stage, height_stage);
        stage.addEnergyBallVertical(id_eb, side, initial_position_x, height_stage - 50);
        EnergyBall* energy_ball = stage.getEnergyBall(id_eb);

        energy_ball->fly();

        float position = energy_ball->getVerticalPosition();
        float velocity;
        float dt = 1.0f/60.f;

        bool test = false;

        for (size_t i = 0; i < 1100; i++) {
            stage.step();
            velocity = energy_ball->getVerticalVelocity();
            position += velocity * dt;
            TS_ASSERT_DELTA(position, energy_ball->getVerticalPosition(), 1.0f);
            if (position < height_stage - 50) test = true;
        }
        TS_ASSERT_EQUALS(test, true);
    }

    void testEnergyBallVerticalCollidesAgainstMetalBlockAndInvertsDirection() {
        std::cout << "Testing that the vertical energy ball collides against a metal block and inverts direction" << std::endl;

        Stage stage(width_stage, height_stage);
        stage.addEnergyBallVertical(id_eb, side, initial_position_x, initial_position_y);
        stage.addMetalBlock(side, initial_position_x, initial_position_y + 10);
        EnergyBall* energy_ball = stage.getEnergyBall(id_eb);

        energy_ball->fly();

        float position = energy_ball->getVerticalPosition();
        float velocity;
        float dt = 1.0f/60.f;

        bool test = false;

        for (size_t i = 0; i < 120; i++) { //2s
            stage.step();
            velocity = energy_ball->getVerticalVelocity();
            position += velocity * dt;
            TS_ASSERT_DELTA(position, energy_ball->getVerticalPosition(), 1.0f);
            if (position < (initial_position_y + 10)) {
                test = true;
            }
        }
        TS_ASSERT_EQUALS(test, true);
    }

    void testEnergyBallHorizontalCollidesAgainstMetalBlockAndInvertsDirection() {
        std::cout << "Testing that the horizontal energy ball collides against a metal block and inverts direction" << std::endl;

        Stage stage(width_stage, height_stage);
        stage.addEnergyBallHorizontal(id_eb, side, initial_position_x, initial_position_y);
        stage.addMetalBlock(side, initial_position_x + 10, initial_position_y);
        EnergyBall* energy_ball = stage.getEnergyBall(id_eb);

        energy_ball->fly();

        float position = energy_ball->getHorizontalPosition();
        float velocity;
        float dt = 1.0f/60.f;

        bool test = false;

        for (size_t i = 0; i < 120; i++) { //2s
            stage.step();
            velocity = energy_ball->getHorizontalVelocity();
            position += velocity * dt;
            TS_ASSERT_DELTA(position, energy_ball->getHorizontalPosition(), 1.0f);
            if (position < initial_position_x + 10) {
                test = true;
            }
        }
        TS_ASSERT_EQUALS(test, true);
    }

    void testEnergyBallVerticalCollidesAgainstBrickBlockAndDies() {
        std::cout << "Testing that the vertical energy ball collides against brick block and dies" << std::endl;

        float initial_position_x_brick_block = initial_position_x;
        float initial_position_y_brick_block = initial_position_y + 10; //colliding
        Stage stage(width_stage, height_stage);
        stage.addEnergyBallVertical(id_eb, side, initial_position_x, initial_position_y);
        stage.addBrickBlock(side, initial_position_x_brick_block, initial_position_y_brick_block);
        EnergyBall* energy_ball = stage.getEnergyBall(id_eb);

        energy_ball->fly();

        bool test = false;
        for (size_t i = 0; i < 300; i++) {
            if (energy_ball->isDead()) {
                test = true;
                break;
            }
            stage.step();
        }
        TS_ASSERT_EQUALS(test, true);
    }

    void testEnergyBallHorizontalCollidesAgainstBrickBlockAndDies() {
        std::cout << "Testing that the horizontal energy ball collides against brick block and dies" << std::endl;

        float initial_position_x_brick_block = initial_position_x + 10;
        float initial_position_y_brick_block = initial_position_y; //colliding
        Stage stage(width_stage, height_stage);
        stage.addEnergyBallHorizontal(id_eb, side, initial_position_x, initial_position_y);
        stage.addBrickBlock(side, initial_position_x_brick_block, initial_position_y_brick_block);
        EnergyBall* energy_ball = stage.getEnergyBall(id_eb);

        energy_ball->fly();
        bool test = false;
        for (size_t i = 0; i < 300; i++) {
            if (energy_ball->isDead()) {
                test = true;
                break;
            }
            stage.step();
        }
        TS_ASSERT_EQUALS(test, true);
    }

    void testEnergyBallHorizontalCollidesAgainstDiagonalMetalBlockAndChangesDirection() {
        std::cout << "Testing that the horizontal energy ball collides against diagonal metal block and changes direction" << std::endl;

        float initial_position_x_diagonal_block = initial_position_x + 100;
        float initial_position_y_diagonal_block = initial_position_y; //colliding
        Stage stage(width_stage, height_stage);
        stage.addEnergyBallHorizontal(id_eb, side, initial_position_x, initial_position_y);
        stage.addDiagonalMetalBlock(side, initial_position_x_diagonal_block, initial_position_y_diagonal_block);
        EnergyBall* energy_ball = stage.getEnergyBall(id_eb);

        energy_ball->fly();

        bool test = false;
        for (size_t i = 0; i < 3000; i++) {
            if (energy_ball->isVertical()) {
                test = true;
                break;
            }
            stage.step();
        }
        TS_ASSERT_EQUALS(test, true);
    }

    void testEnergyBallVerticalCollidesAgainstDiagonalMetalBlockAndChangesDirection() {
        std::cout << "Testing that the vertical energy ball collides against diagonal metal block and changes direction" << std::endl;

        float initial_position_x_diagonal_block = initial_position_x;
        float initial_position_y_diagonal_block = initial_position_y + 100; //colliding
        Stage stage(width_stage, height_stage);
        stage.addEnergyBallVertical(id_eb, side, initial_position_x, initial_position_y);
        stage.addDiagonalMetalBlock(side, initial_position_x_diagonal_block, initial_position_y_diagonal_block);
        EnergyBall* energy_ball = stage.getEnergyBall(id_eb);

        energy_ball->fly();

        bool test = false;
        for (size_t i = 0; i < 3000; i++) {
            if (! energy_ball->isVertical()) {
                test = true;
                break;
            }
            stage.step();
        }
        TS_ASSERT_EQUALS(test, true);
    }
};

class MovingRockTest :  public CxxTest::TestSuite {
    size_t width_stage = 1000;
    size_t height_stage = 1000;
    size_t initial_pos_x_chell = 500;
    size_t initial_pos_y = 500;
    size_t initial_pos_x_rock = 520;
    size_t side_rock = 10;
    size_t mass_rock = side_rock * side_rock;
    size_t side_chell = 2;
    size_t mass_chell = side_chell * side_chell;
    std::string id_rock = "Rock1";
    std::string id_chell = "Chell1";

public:
    void testRockBlockHasGravity() {
        std::cout << "Testing that the rock has gravity" << std::endl;

        Stage stage(width_stage, height_stage);
        stage.addRock(id_rock, side_rock, initial_pos_x_rock, initial_pos_y);
        Rock* rock = stage.getRock(id_rock);
        float dt = 1.0f/60.0f;
        float gravity = gameConfiguration.gravity;
        float velocity_y = 0;
        float position = initial_pos_y;
        for (size_t i = 0; i < 120; i++) {
            stage.step();
            velocity_y += gravity * dt;
            position += velocity_y * dt;
            TS_ASSERT_DELTA(position, rock->getVerticalPosition(), 0.1f);
            TS_ASSERT_DELTA(velocity_y, rock->getVerticalVelocity(), 0.1f);
        }
    }

    void testRockBlockMovesRight() {
        std::cout << "Testing that the rock block moves right" << std::endl;

        Stage stage(width_stage, height_stage);
        stage.addChell(id_chell, side_chell, side_chell, initial_pos_x_chell, initial_pos_y);
        Chell* chell = stage.getChell(id_chell);
        stage.addRock(id_rock, side_rock, initial_pos_x_rock, initial_pos_y);
        Rock* rock = stage.getRock(id_rock);

        chell->grabRock(rock);
        chell->moveRight();

        float dt = 1.0f/60.0f;

        float old_pos = rock->getHorizontalPosition();

        float velocity_x_chell = 0;
        float position_chell = initial_pos_x_chell;
        float force_chell = gameConfiguration.chellForce;
        float acceleration_chell = force_chell / mass_chell;

        for (size_t i = 0; i < 120; i++) {
            stage.step();

            float pos_actual = rock->getHorizontalPosition();
            TS_ASSERT_EQUALS(old_pos <= pos_actual, true)
            TS_ASSERT_EQUALS(rock->getHorizontalVelocity() > 0, true);
            old_pos = rock->getHorizontalPosition();

            if (velocity_x_chell <= 0.5) velocity_x_chell += acceleration_chell * dt;
            position_chell += velocity_x_chell * dt;
            TS_ASSERT_DELTA(position_chell, chell->getHorizontalPosition(), 0.2f);
            TS_ASSERT_DELTA(velocity_x_chell, chell->getHorizontalVelocity(), 0.1f);
        }
    }

    void testRockBlockMovesLeft() {
        std::cout << "Testing that the rock block moves left" << std::endl;

        Stage stage(width_stage, height_stage);
        stage.addChell(id_chell, side_chell, side_chell, initial_pos_x_chell, initial_pos_y);
        Chell* chell = stage.getChell(id_chell);
        stage.addRock(id_rock, side_rock, initial_pos_x_rock, initial_pos_y);
        Rock* rock = stage.getRock(id_rock);

        chell->grabRock(rock);
        chell->moveLeft();

        float dt = 1.0f/60.0f;

        float old_pos = rock->getHorizontalPosition();

        float velocity_x_chell = 0;
        float position_chell = initial_pos_x_chell;
        float force_chell = -gameConfiguration.chellForce;
        float acceleration_chell = force_chell / mass_chell;

        for (size_t i = 0; i < 120; i++) {
            stage.step();

            float pos_actual = rock->getHorizontalPosition();
            TS_ASSERT_EQUALS(old_pos >= pos_actual, true)
            TS_ASSERT_EQUALS(rock->getHorizontalVelocity() < 0, true);
            old_pos = rock->getHorizontalPosition();

            if (velocity_x_chell >= -0.5) velocity_x_chell += acceleration_chell * dt;
            position_chell += velocity_x_chell * dt;
            TS_ASSERT_DELTA(position_chell, chell->getHorizontalPosition(), 0.2f);
            TS_ASSERT_DELTA(velocity_x_chell, chell->getHorizontalVelocity(), 0.1f);
        }
    }

};

class ChellDiesTest :  public CxxTest::TestSuite {
    size_t width_stage = 500;
    size_t height_stage = 500;
    size_t x_pos_chell = 1;
    size_t y_pos = 1;
    size_t x_pos_acid = 4;
    size_t side_chell = 2;
    size_t side_acid = 1;
    std::string id_chell = "Chell1";
    std::string id_acid = "Acid1";
    std::string id_eb = "EnergyBall1";

public:
    void testChellDiesAgainstAcid() {
        std::cout << "Testing that Chell dies against acid" << std::endl;

        Stage stage(width_stage, height_stage);
        stage.addChell(id_chell, side_chell, side_chell, x_pos_chell, y_pos);
        stage.addAcid(id_acid, side_acid, side_acid, x_pos_acid, y_pos);

        Chell* chell_right = stage.getChell(id_chell);

        bool test_right = false;
        chell_right->moveRight();

        TS_ASSERT_EQUALS(chell_right->isDead(), false);

        for (size_t i = 0; i < 120000; i++) {
            if (chell_right->isDead()) {
                test_right = true;
            }
            stage.step();
        }
        TS_ASSERT_EQUALS(test_right, true);
    }
};

class ShootingTest :  public CxxTest::TestSuite {
    size_t width_stage = 500;
    size_t height_stage = 500;
    size_t x_pos_chell = 1;
    size_t y_pos = 1;
    size_t side_chell = 2;
    float h_side_shot = 1;
    float v_side_shot = 2;
    std::string id_blue_shot = "BlueShot1";
    std::string id_orange_shot = "OrangeShot1";
    std::string id_chell = "Chell1";

public:
    void testBlueTrayectoryShooting() {
        std::cout << "Testing the blue trayectory of the shooting" << std::endl;

        Stage stage(width_stage, height_stage);
        stage.addChell(id_chell, side_chell, side_chell, x_pos_chell, y_pos);

        Chell* chell = stage.getChell(id_chell);

        Coordinate* origin = new Coordinate(x_pos_chell + 2 + h_side_shot/2, y_pos + 1);
        Coordinate* target = new Coordinate(8, 1);
        stage.addBlueShot(id_blue_shot, v_side_shot, h_side_shot, chell, target);

        BlueShot* blueShot = stage.getBlueShot(id_blue_shot);

        for (size_t i = 0; i < 120; i++) {
            if (blueShot->isDead()) break;
            stage.step();
        }
        TS_ASSERT_DELTA(blueShot->getHorizontalPosition(), 8, 0.5);
        TS_ASSERT_DELTA(blueShot->getVerticalPosition(), 1, 0.5);
        TS_ASSERT_EQUALS(blueShot->isDead(), true);
    }

    void testOrangeTrayectoryShooting() {
        std::cout << "Testing the orange trayectory of the shooting" << std::endl;

        Stage stage(width_stage, height_stage);
        stage.addChell(id_chell, side_chell, side_chell, x_pos_chell, y_pos);

        Chell* chell = stage.getChell(id_chell);

        Coordinate* origin = new Coordinate(x_pos_chell + 2 + h_side_shot/2, y_pos + 1);
        Coordinate* target = new Coordinate(8, 1);
        stage.addOrangeShot(id_orange_shot, v_side_shot, h_side_shot, chell, target);

        OrangeShot* orangeShot = stage.getOrangeShot(id_orange_shot);

        for (size_t i = 0; i < 120; i++) {
            if (orangeShot->isDead()) break;
            stage.step();
        }
        TS_ASSERT_DELTA(orangeShot->getHorizontalPosition(), 8, 0.5);
        TS_ASSERT_DELTA(orangeShot->getVerticalPosition(), 1, 0.5);
        TS_ASSERT_EQUALS(orangeShot->isDead(), true);
    }

    void testTrayectoryBlueShootingBackwards() {
        std::cout << "Testing the trayectory of the blue shooting backwards" << std::endl;

        Stage stage(width_stage, height_stage);
        x_pos_chell = 8;
        y_pos = 1;
        stage.addChell(id_chell, side_chell, side_chell, x_pos_chell, y_pos);

        Chell* chell = stage.getChell(id_chell);

        Coordinate* origin = new Coordinate(x_pos_chell - 2 - h_side_shot/2, y_pos + 1);
        Coordinate* target = new Coordinate(3, 1);
        stage.addBlueShot(id_blue_shot, v_side_shot, h_side_shot, chell, target);

        BlueShot* blueShot = stage.getBlueShot(id_blue_shot);

        for (size_t i = 0; i < 120; i++) {
            if (blueShot->isDead()) break;
            stage.step();
        }
        TS_ASSERT_DELTA(blueShot->getHorizontalPosition(), 4, 0.5);
        TS_ASSERT_DELTA(blueShot->getVerticalPosition(), 1, 0.5);
        TS_ASSERT_EQUALS(blueShot->isDead(), true);
    }

    void testTrayectoryOrangeShootingBackwards() {
        std::cout << "Testing the trayectory of the orange shooting backwards" << std::endl;

        Stage stage(width_stage, height_stage);
        x_pos_chell = 8;
        y_pos = 1;
        stage.addChell(id_chell, side_chell, side_chell, x_pos_chell, y_pos);

        Chell* chell = stage.getChell(id_chell);

        Coordinate* origin = new Coordinate(x_pos_chell - 2 - h_side_shot/2, y_pos + 1);
        Coordinate* target = new Coordinate(4, 4);
        stage.addOrangeShot(id_orange_shot, v_side_shot, h_side_shot, chell, target);

        OrangeShot* orangeShot = stage.getOrangeShot(id_orange_shot);

        for (size_t i = 0; i < 120; i++) {
            if (orangeShot->isDead()) break;
            stage.step();
        }
        TS_ASSERT_DELTA(orangeShot->getHorizontalPosition(), 4, 0.5);
        TS_ASSERT_DELTA(orangeShot->getVerticalPosition(), 4, 0.5);
        TS_ASSERT_EQUALS(orangeShot->isDead(), true);
    }

    void testOrangeShotCollidesWithMetalBlock() {
        std::cout << "Testing that the orange shot collides with the metal block" << std::endl;

        Stage stage(20, 20);
        x_pos_chell = 10;
        y_pos = 1;
        stage.addChell(id_chell, side_chell, side_chell, x_pos_chell, y_pos);

        Chell* chell = stage.getChell(id_chell);

        Coordinate* origin = new Coordinate(x_pos_chell + 2 + h_side_shot/2, y_pos + 1);
        Coordinate* target = new Coordinate(14, 14);
        stage.addOrangeShot(id_orange_shot, v_side_shot, h_side_shot, chell, target);
        stage.addMetalBlock(2, 14, 14);
        MetalBlock* metalBlock = stage.getMetalBlock(new Coordinate(14, 14));

        OrangeShot* orangeShot = stage.getOrangeShot(id_orange_shot);

        for (size_t i = 0; i < 120; i++) {
            orangeShot = stage.getOrangeShot(id_orange_shot);

            if (orangeShot->isDead()) return;

            if (orangeShot != nullptr) {
                float x = orangeShot->getHorizontalPosition();
                float y = orangeShot->getVerticalPosition();
            }
            stage.step();
        }
        TS_ASSERT_EQUALS(orangeShot, nullptr);
        TS_ASSERT_EQUALS(metalBlock->hasPortal(), true);
    }

    void testBlueShotCollidesAgainstMetalBlock() {
        std::cout << "Testing that the blue shot collides with the metal block" << std::endl;

        Stage stage(20, 20);
        x_pos_chell = 10;
        y_pos = 1;
        stage.addChell(id_chell, side_chell, side_chell, x_pos_chell, y_pos);

        Chell* chell = stage.getChell(id_chell);

        Coordinate* origin = new Coordinate(x_pos_chell + 2 + h_side_shot/2, y_pos + 1);
        Coordinate* target = new Coordinate(14, 1);
        stage.addBlueShot(id_blue_shot, v_side_shot, h_side_shot, chell, target);
        stage.addMetalBlock(2, 18, 1);
        MetalBlock* metalBlock = stage.getMetalBlock(new Coordinate(18, 1));

        BlueShot* blueShot = stage.getBlueShot(id_blue_shot);

        for (size_t i = 0; i < 120; i++) {
            blueShot = stage.getBlueShot(id_blue_shot);

            if (blueShot->isDead()) return;

            if (blueShot != nullptr) {
                float x = blueShot->getHorizontalPosition();
                float y = blueShot->getVerticalPosition();
            }
            stage.step();
        }
        TS_ASSERT_EQUALS(blueShot, nullptr);
    }

    void testBlueShotCollidesAndDies() {
        std::cout << "Testing that the blue shot collides and dies in the middle of the way" << std::endl;

        Stage stage(20, 20);
        x_pos_chell = 10;
        y_pos = 1;
        stage.addChell(id_chell, side_chell, side_chell, x_pos_chell, y_pos);

        Chell* chell = stage.getChell(id_chell);

        Coordinate* origin = new Coordinate(x_pos_chell + 2 + h_side_shot/2, y_pos + 1);
        Coordinate* target = new Coordinate(18, 1);
        stage.addBlueShot(id_blue_shot, v_side_shot, h_side_shot, chell, target);
        stage.addChell(id_chell, side_chell, side_chell, 14, 1);

        BlueShot* blueShot = stage.getBlueShot(id_blue_shot);

        for (size_t i = 0; i < 120; i++) {
            blueShot = stage.getBlueShot(id_blue_shot);

            if (blueShot != nullptr) {
                float x = blueShot->getHorizontalPosition();
                float y = blueShot->getVerticalPosition();
            }
            stage.step();
        }
        TS_ASSERT_EQUALS(blueShot, nullptr);
    }
};


class PortalTest :  public CxxTest::TestSuite {
    size_t width_stage = 500;
    size_t height_stage = 500;
    size_t x_pos_chell = 1;
    size_t y_pos = 1;
    size_t side_chell = 2;
    size_t side_portal = 2;
    std::string id_chell = "Chell1";
    std::string id_blue_shot = "BlueShot1";
    std::string id_orange_shot = "OrangeShot1";

public:

    void testMetalBlocksInInitDoesntHavePortal() {
        std::cout << "Testing that metal blocks in init don't have portals" << std::endl;

        x_pos_chell = 10;
        y_pos = 1;
        float width_shot = 1;
        float height_shot = 2;
        float x_pos_right_metal_block = x_pos_chell + 10;
        float x_pos_left_metal_block = x_pos_chell - 10;

        Stage stage(width_stage, height_stage);
        stage.addChell(id_chell, side_chell, side_chell, x_pos_chell, y_pos);
        stage.addMetalBlock(2, x_pos_right_metal_block, y_pos);
        stage.addMetalBlock(2, x_pos_left_metal_block, y_pos);

        MetalBlock* left_metal_block = stage.getMetalBlock(new Coordinate(x_pos_left_metal_block, y_pos));
        MetalBlock* right_metal_block = stage.getMetalBlock(new Coordinate(x_pos_right_metal_block, y_pos));
        TS_ASSERT_EQUALS(left_metal_block->hasPortal(), false);
        TS_ASSERT_EQUALS(right_metal_block->hasPortal(), false);
    }

    void testChellCreatesTwoPortals() {
        std::cout << "Testing that Chell creates portals correctly" << std::endl;

        x_pos_chell = 20;
        y_pos = 1;
        float width_shot = 1;
        float height_shot = 2;
        float x_pos_right_metal_block = x_pos_chell + 10;
        float x_pos_left_metal_block = x_pos_chell - 10;
        Coordinate* right_target = new Coordinate(x_pos_right_metal_block, y_pos);
        Coordinate* left_target = new Coordinate(x_pos_left_metal_block, y_pos);

        Stage stage(width_stage, height_stage);
        stage.addChell(id_chell, side_chell, side_chell, x_pos_chell, y_pos);
        stage.addMetalBlock(2, x_pos_right_metal_block, y_pos);
        stage.addMetalBlock(2, x_pos_left_metal_block, y_pos);

        MetalBlock* left_metal_block = stage.getMetalBlock(new Coordinate(x_pos_left_metal_block, y_pos));
        MetalBlock* right_metal_block = stage.getMetalBlock(new Coordinate(x_pos_right_metal_block, y_pos));

        Chell* chell = stage.getChell(id_chell);
        stage.addBlueShot(id_blue_shot, height_shot, width_shot, chell, right_target);
        stage.addOrangeShot(id_orange_shot, height_shot, width_shot, chell, left_target);

        BlueShot* blueShot = stage.getBlueShot(id_blue_shot);
        OrangeShot* orangeShot = stage.getOrangeShot(id_orange_shot);

        for (size_t i = 0; i < 2500; i++) {
            stage.step();
        }

        TS_ASSERT_EQUALS(left_metal_block->hasPortal(), true);
        TS_ASSERT_EQUALS(right_metal_block->hasPortal(), true);
        TS_ASSERT_EQUALS(orangeShot->isDead(), true);
        TS_ASSERT_EQUALS(blueShot->isDead(), true);
    }

    void testChellTeleportsWhenHittingAPortal() {
        std::cout << "Testing that Chell teleports while hitting a portal" << std::endl;

        x_pos_chell = 20;
        y_pos = 1;
        float width_shot = 1;
        float height_shot = 2;
        float x_pos_right_metal_block = x_pos_chell + 10;
        float x_pos_left_metal_block = x_pos_chell - 10;
        Coordinate* right_target = new Coordinate(x_pos_right_metal_block, y_pos);
        Coordinate* left_target = new Coordinate(x_pos_left_metal_block, y_pos);

        Stage stage(width_stage, height_stage);
        stage.addChell(id_chell, side_chell, side_chell, x_pos_chell, y_pos);
        stage.addMetalBlock(2, x_pos_right_metal_block, y_pos);
        stage.addMetalBlock(2, x_pos_left_metal_block, y_pos);

        MetalBlock* left_metal_block = stage.getMetalBlock(new Coordinate(x_pos_left_metal_block, y_pos));
        MetalBlock* right_metal_block = stage.getMetalBlock(new Coordinate(x_pos_right_metal_block, y_pos));

        Chell* chell = stage.getChell(id_chell);
        stage.addBlueShot(id_blue_shot, height_shot, width_shot, chell, right_target);
        stage.addOrangeShot(id_orange_shot, height_shot, width_shot, chell, left_target);
        //blue = 30
        //orange = 10

        BlueShot* blueShot = stage.getBlueShot(id_blue_shot);
        OrangeShot* orangeShot = stage.getOrangeShot(id_orange_shot);

        chell->moveRight();

        for (size_t i = 0; i < 2500; i++) {
            float x = chell->getHorizontalPosition();
            float y = chell->getVerticalPosition();
            if (x < 20) {
                TS_ASSERT_DELTA(x, 10, 0.1);
                TS_ASSERT_DELTA(y, 1, 0.1);
                return;
            }
            stage.step();
        }
        TS_ASSERT_EQUALS(1, 0);
    }


    void testChellCreatesOtherPortalWhenHitting() {
        std::cout << "Testing that Chell creates other portal while hitting" << std::endl;

        x_pos_chell = 20;
        y_pos = 1;
        float width_shot = 1;
        float height_shot = 2;
        float x_pos_right_metal_block = x_pos_chell + 10;
        float x_pos_left_metal_block = x_pos_chell - 10;
        Coordinate* right_target = new Coordinate(x_pos_right_metal_block, y_pos);
        Coordinate* left_target = new Coordinate(x_pos_left_metal_block, y_pos);

        Stage stage(width_stage, height_stage);
        stage.addChell(id_chell, side_chell, side_chell, x_pos_chell, y_pos);
        stage.addMetalBlock(2, x_pos_right_metal_block, y_pos);
        stage.addMetalBlock(2, x_pos_left_metal_block, y_pos);

        MetalBlock* left_metal_block = stage.getMetalBlock(new Coordinate(x_pos_left_metal_block, y_pos));
        MetalBlock* right_metal_block = stage.getMetalBlock(new Coordinate(x_pos_right_metal_block, y_pos));

        Chell* chell = stage.getChell(id_chell);
        stage.addBlueShot(id_blue_shot, height_shot, width_shot, chell, right_target); //blue = right
        stage.addOrangeShot(id_orange_shot, height_shot, width_shot, chell, left_target); //orange = left

        BlueShot* blueShot = stage.getBlueShot(id_blue_shot);
        OrangeShot* orangeShot = stage.getOrangeShot(id_orange_shot);

        chell->moveRight();

        for (size_t i = 0; i < 2500; i++) {
            if (left_metal_block->hasPortal() && right_metal_block->hasPortal()) break;
            stage.step();
        }
        TS_ASSERT_EQUALS(right_metal_block->hasPortal(), true);
        TS_ASSERT_EQUALS(left_metal_block->hasPortal(), true);

        float x = chell->getHorizontalPosition();
        float y = chell->getVerticalPosition();

        stage.addMetalBlock(2, x, y + 5);
        Coordinate* new_target = new Coordinate(x, y + 5);
        std::string id_orange_shot_2 = "OrangeShot2";
        stage.addOrangeShot(id_orange_shot_2, height_shot, width_shot, chell, new_target); //orange = new

        MetalBlock* metal_block_new = stage.getMetalBlock(new_target);

        TS_ASSERT_EQUALS(right_metal_block->hasPortal(), true);
        TS_ASSERT_EQUALS(left_metal_block->hasPortal(), false);
        TS_ASSERT_EQUALS(metal_block_new->hasPortal(), false);

        for (size_t i = 0; i < 2500; i++) {
            if (metal_block_new->hasPortal() && right_metal_block->hasPortal()) break;
            stage.step();
        }

        TS_ASSERT_EQUALS(metal_block_new->hasPortal(), true);
    }
};

#endif