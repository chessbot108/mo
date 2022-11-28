
from manimlib import *

class naive_sort(Scene):
    def construct(self):

        input_file = "small_rng_3"
        with open(input_file + ".txt", "r") as INPUT: 
            R = INPUT.readlines()


        print(R)

        N = int(R[0].strip())
        arr = []

        for i in range(1, N+1):
            [x, y] = R[i].strip().split()
            arr.append(Dot([int(x) -1, int(y) -1, 0], color=RED, radius=0.12))

        numberplane = NumberPlane(x_range=(0, 10, 1), y_range=(0, 10, 1), faded_line_ratio=0).move_to(RIGHT*5 + UP*5);
        src = Dot(ORIGIN, color=RED, radius=0.12)
        trav = src.copy().set_color(YELLOW)
        self.play(self.camera.frame.animate.scale(2))
        self.play(self.camera.frame.animate.move_to([7, 3, 0]));

        self.add(numberplane);
        for e in arr:
            self.add(Arrow([e.get_x(), 0, 0], [e.get_x(), e.get_y(), 0], color=YELLOW));
            self.add(Arrow([0, 0, 0], [e.get_x(), 0, 0], color=YELLOW))

        for e in arr:
            self.add(e)
        


