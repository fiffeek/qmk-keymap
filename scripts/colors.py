#!/usr/bin/python3

from dataclasses import dataclass
from enum import Enum
from typing import List
from itertools import chain


flatten = lambda x: list(chain.from_iterable(x))

COLORS_FILE = "keyboards/zsa/voyager/keymaps/colemak/keymap.c"
COLORS_LINE = "PROGMEM ledmap"


@dataclass
class LedColor:
    red: int
    green: int
    blue: int


EMPTY_LED = LedColor(0, 0, 0)
WHITE_LED = LedColor(43, 85, 255)
BLUE_LED = LedColor(118, 235, 221)
LIGHT_BLUE_LED = LedColor(128, 222, 183)
WHITE_RED_LED = LedColor(5, 56, 255)
PINK_LED = LedColor(245, 195, 249)
LIGHT_PINK_LED = LedColor(5, 105, 255)
YELLOW_LED = LedColor(21, 204, 255)
BRIGHT_PINK_LED = LedColor(245, 255, 255)


class Hand(Enum):
    LEFT = 0
    RIGHT = 1


class LedLayer:
    left: List[List[LedColor]]
    right: List[List[LedColor]]
    REGULAR_ROW_COUNT = 4
    REGULAR_ROW_LED_COUNT = 6
    THUMB_ROW_LED_COUNT = 2

    def __init__(self) -> None:
        self.left = []
        self.right = []

    def add_row(self, hand: Hand, leds: List[List[LedColor]]):
        led_list = flatten(leds)
        piece = self.left if hand == Hand.LEFT else self.right
        expected_length = (
            self.REGULAR_ROW_LED_COUNT
            if len(piece) < self.REGULAR_ROW_COUNT
            else self.THUMB_ROW_LED_COUNT
        )
        assert (
            len(led_list) == expected_length
        ), f"len is {len(led_list)} but expected is {expected_length}"
        piece.append(led_list)

    def to_list(self):
        return flatten(flatten([self.left, self.right]))


def find_ledmap_start(filepath: str):
    with open(filepath, "r") as f:
        data = f.readlines()
        ledmap_start_index = None
        for i in range(len(data)):
            line = data[i]
            if COLORS_LINE in line:
                ledmap_start_index = i
        assert ledmap_start_index is not None
    return ledmap_start_index + 1


def override_leds(filepath: str, index: int, layout: List[LedLayer]):
    lines = None
    with open(filepath, "r") as f:
        lines = f.readlines()
        for layer_index, layer in enumerate([layer.to_list() for layer in layout]):
            line = f"    [{layer_index}] = " + "{"
            for idx, led in enumerate(layer):
                line += "{" + f"{led.red}, {led.green}, {led.blue}" + "}"
                line += ", " if idx != (len(layer) - 1) else ""
            line += "},\n"
            lines[index + layer_index] = line
    with open(filepath, "w") as f:
        assert lines is not None
        f.writelines(lines)


def main(filepath: str):
    index = find_ledmap_start(filepath)
    top = LedLayer()
    top.add_row(Hand.LEFT, [[EMPTY_LED] * 6])
    top.add_row(Hand.LEFT, [[PINK_LED] * 6])
    top.add_row(Hand.LEFT, [[PINK_LED], [LIGHT_PINK_LED] * 4, [PINK_LED]])
    top.add_row(Hand.LEFT, [[EMPTY_LED], [PINK_LED] * 5])
    top.add_row(Hand.LEFT, [[LIGHT_PINK_LED] * 2])
    top.add_row(Hand.RIGHT, [[EMPTY_LED] * 6])
    top.add_row(Hand.RIGHT, [[PINK_LED] * 6])
    top.add_row(Hand.RIGHT, [[PINK_LED], [LIGHT_PINK_LED] * 4, [PINK_LED]])
    top.add_row(Hand.RIGHT, [[PINK_LED] * 5, [EMPTY_LED]])
    top.add_row(Hand.RIGHT, [[LIGHT_PINK_LED] * 2])

    sym = LedLayer()
    sym.add_row(Hand.LEFT, [[EMPTY_LED] * 6])
    sym.add_row(Hand.LEFT, [[EMPTY_LED], [WHITE_LED] * 5])
    sym.add_row(Hand.LEFT, [[EMPTY_LED], [WHITE_LED] * 5])
    sym.add_row(Hand.LEFT, [[EMPTY_LED], [WHITE_LED] * 5])
    sym.add_row(Hand.LEFT, [[WHITE_LED] * 2])
    sym.add_row(Hand.RIGHT, [[EMPTY_LED] * 6])
    sym.add_row(Hand.RIGHT, [[WHITE_LED] * 5, [EMPTY_LED]])
    sym.add_row(Hand.RIGHT, [[WHITE_LED] * 5, [EMPTY_LED]])
    sym.add_row(Hand.RIGHT, [[WHITE_LED] * 5, [EMPTY_LED]])
    sym.add_row(Hand.RIGHT, [[WHITE_LED] * 2])

    num = LedLayer()
    num.add_row(Hand.LEFT, [[EMPTY_LED] * 6])
    num.add_row(Hand.LEFT, [[BLUE_LED] * 6])
    num.add_row(Hand.LEFT, [[BLUE_LED] * 6])
    num.add_row(Hand.LEFT, [[EMPTY_LED] * 6])
    num.add_row(Hand.LEFT, [[EMPTY_LED] * 2])
    num.add_row(Hand.RIGHT, [[EMPTY_LED] * 6])
    num.add_row(Hand.RIGHT, [[BLUE_LED] * 6])
    num.add_row(Hand.RIGHT, [[BLUE_LED] * 6])
    num.add_row(Hand.RIGHT, [[EMPTY_LED] * 6])
    num.add_row(Hand.RIGHT, [[EMPTY_LED] * 2])

    navi = LedLayer()
    navi.add_row(Hand.LEFT, [[EMPTY_LED] * 6])
    navi.add_row(Hand.LEFT, [[EMPTY_LED], [BLUE_LED] * 5])
    navi.add_row(Hand.LEFT, [[EMPTY_LED], [WHITE_RED_LED] * 4, [EMPTY_LED]])
    navi.add_row(Hand.LEFT, [[EMPTY_LED], [BLUE_LED] * 5])
    navi.add_row(Hand.LEFT, [[BLUE_LED] * 2])
    navi.add_row(Hand.RIGHT, [[EMPTY_LED] * 6])
    navi.add_row(Hand.RIGHT, [[WHITE_RED_LED] * 5, [EMPTY_LED]])
    navi.add_row(Hand.RIGHT, [[WHITE_RED_LED] * 5, [EMPTY_LED]])
    navi.add_row(Hand.RIGHT, [[BLUE_LED] * 5, [EMPTY_LED]])
    navi.add_row(Hand.RIGHT, [[BLUE_LED] * 2])

    media = LedLayer()
    media.add_row(Hand.LEFT, [[EMPTY_LED] * 6])
    media.add_row(Hand.LEFT, [[EMPTY_LED] * 6])
    media.add_row(Hand.LEFT, [[EMPTY_LED] * 6])
    media.add_row(Hand.LEFT, [[EMPTY_LED] * 6])
    media.add_row(Hand.LEFT, [[YELLOW_LED] * 2])
    media.add_row(Hand.RIGHT, [[EMPTY_LED] * 5, [BRIGHT_PINK_LED]])
    media.add_row(
        Hand.RIGHT,
        [[EMPTY_LED], [YELLOW_LED], [EMPTY_LED] * 2, [YELLOW_LED], [EMPTY_LED]],
    )
    media.add_row(Hand.RIGHT, [[EMPTY_LED], [YELLOW_LED] * 4, [EMPTY_LED]])
    media.add_row(Hand.RIGHT, [[EMPTY_LED], [YELLOW_LED] * 4, [EMPTY_LED]])
    media.add_row(Hand.RIGHT, [[YELLOW_LED] * 2])

    qwerty = LedLayer()
    qwerty.add_row(Hand.LEFT, [[PINK_LED], [EMPTY_LED] * 5])
    qwerty.add_row(Hand.LEFT, [[PINK_LED] * 6])
    qwerty.add_row(Hand.LEFT, [[PINK_LED] * 6])
    qwerty.add_row(Hand.LEFT, [[PINK_LED] * 6])
    qwerty.add_row(Hand.LEFT, [[PINK_LED] * 2])
    qwerty.add_row(Hand.RIGHT, [[EMPTY_LED] * 6])
    qwerty.add_row(Hand.RIGHT, [[PINK_LED] * 6])
    qwerty.add_row(Hand.RIGHT, [[PINK_LED] * 6])
    qwerty.add_row(Hand.RIGHT, [[PINK_LED] * 6])
    qwerty.add_row(Hand.RIGHT, [[PINK_LED] * 2])

    override_leds(filepath, index, [top, sym, num, navi, media, qwerty])


if __name__ == "__main__":
    main(COLORS_FILE)
