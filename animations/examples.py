
from manimlib import * 
from random import * 

class small_example(Scene):

    def construct(self):
        numberplane = NumberPlane(x_range=(0, 5, 1), y_range=(0, 5, 1), faded_line_ratio=0).move_to(RIGHT*2.5 + UP*2.5);
        src = Dot(ORIGIN, color=RED, radius=0.12)
        trav = src.copy().set_color(YELLOW)
        self.play(self.camera.frame.animate.scale(2))
        self.add(numberplane);
        p1 = Dot([1, 2, 0], color=RED, radius=0.12);
        p2 = Dot([4, 0, 0], color=RED, radius=0.12);
        self.add(trav, p1, p2);


class small_example_with_solution(Scene):

    def construct(self):
        numberplane = NumberPlane(x_range=(0, 5, 1), y_range=(0, 5, 1), faded_line_ratio=0).move_to(RIGHT*2.5 + UP*2.5);
        src = Dot(ORIGIN, color=RED, radius=0.12)
        trav = src.copy().set_color(YELLOW)
        self.play(self.camera.frame.animate.scale(2))
        self.add(numberplane);
        p1 = Dot([1, 2, 0], color=RED, radius=0.12);
        p2 = Dot([4, 0, 0], color=RED, radius=0.12);
        self.add(trav, p1, p2);
        t1 = Text('1', color=RED).next_to(p1, UP*.5 + RIGHT*.5);
        t2 = Text('2', color=RED).next_to(p2, UP*.5 + RIGHT*.5);
        self.add(t1, t2);
        a1 = Arrow(trav, [0, 2, 0], color=YELLOW);
        a2 = Arrow([0, 2, 0], p1, color=YELLOW);
        a3 = Arrow(p1, [1, 0, 0], color=YELLOW);
        a4 = Arrow([1, 0, 0], p2, color=YELLOW);
        self.add(a1, a2, a3, a4);

        ta1 = Text('+2', color=YELLOW).next_to(a1, LEFT*.5);
        ta2 = Text('+1', color=YELLOW).next_to(a2, UP*.5);
        ta3 = Text('+2', color=YELLOW).next_to(a3, RIGHT*.5);
        ta4 = Text('+3', color=YELLOW).next_to(a4, UP*.5);
        self.add(ta1, ta2, ta3, ta4);

class large_example(Scene):
    def construct(self):
        
        input_file = "small_rng_3"

        with open(input_file + ".txt", "r") as INPUT: 
            R = INPUT.readlines()

        numberplane = NumberPlane(x_range=(0, 10, 1), y_range=(0, 10, 1), faded_line_ratio=0).move_to(RIGHT*5 + UP*5);
        print(R)

        N = int(R[0].strip())
        arr = []

        for i in range(1, N+1):
            [x, y] = R[i].strip().split()
            arr.append(Dot([int(x) -1, int(y) -1, 0], color=RED, radius=0.12))

        self.play(self.camera.frame.animate.scale(2))

        self.add(numberplane) 
        self.add(Dot(ORIGIN, color=YELLOW, radius=0.12))

        for e in arr:
            self.add(e)

class very_large_example(Scene):
    def construct(self):

        numberplane = NumberPlane(x_range=(0, 100, 5), y_range=(0, 100, 5), faded_line_ratio=0).move_to(RIGHT*50 + UP*50);

        self.play(self.camera.frame.animate.scale(20))

        self.add(numberplane) 
        self.add(Dot(ORIGIN, color=YELLOW, radius=.5))
        
        trial = 20000
        random.seed(a=3366)
        for i in range(trial):
            x = random() * 100
            y = random() * 100
            self.add(Dot([x, y, 0], color=RED, radius=.2))


class manhattan_distance_diagram(Scene):
    def construct(self):
        numberplane = NumberPlane(x_range=(0, 5, 1), y_range=(0, 5, 1), faded_line_ratio=0).move_to(RIGHT*2.5 + UP*2.5);
        self.play(self.camera.frame.animate.scale(2))
        self.add(numberplane) 
        a = Dot([1, 4, 0], color=RED, radius=.12);
        b = Dot([4, 2, 0], color=RED, radius=.12);
        self.add(a, b);
        ly = Line(a, [1, 2, 0], color=YELLOW);
        lx = Line([1, 2, 0], b, color=YELLOW);
        self.add(lx, ly);
        ty = Tex(r"|4 - 2| = 2").next_to(ly, LEFT);
        tx = Tex(r"|1 - 4| = 3").next_to(lx, DOWN*.5);
        self.add(tx, ty)

