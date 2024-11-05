import pytest
from bd_main import fade_color_increments, motor_control_increments

def test_fade_color_increments():
    assert fade_color_increments([0,255,0], [0,0,255])
    assert fade_color_increments([255,0,0], [0,0,255])
    assert fade_color_increments([0,0,255], [0,0,255])

    assert fade_color_increments([0,255,0], [0,255,0])
    assert fade_color_increments([255,0,0], [0,255,0])
    assert fade_color_increments([0,0,255], [255,0,0])

def test_motor_control_increments():
    assert motor_control_increments(0,90)
    assert motor_control_increments(180,90)
    assert motor_control_increments(90,90)
    assert motor_control_increments(90,45)
    assert motor_control_increments(90,135)

pytest.main(["-v", "--tb=line", "-rN", __file__])
