
from manimlib import *

class classic(Scene):
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


        alg_name = "classic"        
        with open(alg_name + ".txt", "r") as ANSWER:
            Q = ANSWER.readlines()

        print(Q)
        
        perm = []
        for e in Q[0].strip().split():
            perm.append(int(e))

        numberplane = NumberPlane(x_range=(0, 10, 1), y_range=(0, 10, 1), faded_line_ratio=0).move_to(RIGHT*5 + UP*5);
        textB = Tex(r"B = 3").next_to(numberplane, DOWN);
        self.add(textB);
        src = Dot(ORIGIN, color=RED, radius=0.12)
        trav = src.copy().set_color(YELLOW)
        self.play(self.camera.frame.animate.scale(2))
        self.play(self.camera.frame.animate.move_to([7, 3, 0]));

        self.add(numberplane);
        for x in range(0, 10, 3):
            self.add(DashedLine([x, 0, 0], [x, 10, 0], color=YELLOW, dash_length = .5));
        
        for e in arr:
            self.add(e)

        for i in range(0, N-1):
            self.add(Arrow(arr[perm[i]], arr[perm[i+1]], color=YELLOW))
        

class classic_with_parity(Scene):
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


        alg_name = "classic_with_parity"        
        with open(alg_name + ".txt", "r") as ANSWER:
            Q = ANSWER.readlines()

        print(Q)
        
        perm = []
        for e in Q[0].strip().split():
            perm.append(int(e))

        numberplane = NumberPlane(x_range=(0, 10, 1), y_range=(0, 10, 1), faded_line_ratio=0).move_to(RIGHT*5 + UP*5);
        textB = Tex(r"B = 3").next_to(numberplane, DOWN);
        self.add(textB);
        src = Dot(ORIGIN, color=RED, radius=0.12)
        trav = src.copy().set_color(YELLOW)
        self.play(self.camera.frame.animate.scale(2))
        self.play(self.camera.frame.animate.move_to([7, 3, 0]));

        self.add(numberplane);
        for x in range(0, 10, 3):
            self.add(DashedLine([x, 0, 0], [x, 10, 0], color=YELLOW, dash_length = .5));
        
        for e in arr:
            self.add(e)

        for i in range(0, N-1):
            self.add(Arrow(arr[perm[i]], arr[perm[i+1]], color=YELLOW))
        
