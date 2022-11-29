
from manimlib import *


class minimum_spanning_tree(Scene):
    def construct(self):
        p1 = Dot([1, 1, 0], color=YELLOW, radius=.12)
        p2 = Dot([1, 4, 0], color=YELLOW, radius=.12)
        p3 = Dot([4, 1, 0], color=YELLOW, radius=.12)
        p4 = Dot([4, 4, 0], color=YELLOW, radius=.12)
        numberplane = NumberPlane(x_range=(0, 5, 1), y_range=(0, 5, 1), faded_line_ratio=0).move_to(RIGHT*2.5 + UP*2.5);
        self.add(numberplane)
        self.play(self.camera.frame.animate.scale(2))
        self.add(p1, p2, p3, p4)
        t1 = Tex('1', color=YELLOW).next_to(p1, DOWN*.5 + LEFT*.5)
        t2 = Tex('2', color=YELLOW).next_to(p2, UP*.5 + LEFT*.5)
        t3 = Tex('3', color=YELLOW).next_to(p3, DOWN*.5 + RIGHT*.5)
        t4 = Tex('4', color=YELLOW).next_to(p4, UP*.5 + RIGHT*.5)
        self.add(t1, t2, t3, t4)
        # valid 1
        # self.add(Line(p1, p2, color=YELLOW))
        # self.add(Line(p2, p4, color=YELLOW))
        # self.add(Line(p3, p4, color=YELLOW))
        # valid 2
        # self.add(Line(p1, p3, color=YELLOW))
        # self.add(Line(p2, p4, color=YELLOW))
        # self.add(Line(p3, p4, color=YELLOW))
        # invalid 1
        self.add(Line(p1, p2, color=YELLOW))
        self.add(Line(p2, p3, color=YELLOW))
        self.add(Line(p3, p4, color=YELLOW))
