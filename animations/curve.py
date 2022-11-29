
from manimlib import * 

class hilbert(Scene):
    def construct(self):
    
        numberplane = NumberPlane(x_range=(0, 10, 1), y_range=(0, 10, 1), faded_line_ratio=0).move_to(RIGHT*5 + UP*5);
        self.play(self.camera.frame.animate.scale(2))
        self.add(numberplane)
        with open("16x16hilbert.txt", "r") as ANSWER:
            Q = ANSWER.readlines()

        print(Q)
        
        perm = []
        for e in Q[0].strip().split():
            perm.append(int(e))

        pts = []
        for i in range(256):
            pts.append([int(i/16), int(i%16), 0])

        for i in range(255):
            if pts[perm[i]][0] <= 10 and pts[perm[i]][1] <= 10 and pts[perm[i+1]][0] <= 10 and pts[perm[i+1]][1] <= 10:
                self.add(Line(pts[perm[i]], pts[perm[i+1]], color=YELLOW, stroke_width=4))



        input_file = "small_rng_3"
        with open(input_file + ".txt", "r") as INPUT: 
            R = INPUT.readlines()


        print(R)

        N = int(R[0].strip())
        arr = []

        for i in range(1, N+1):
            [x, y] = R[i].strip().split()
            arr.append(Dot([int(x) -1, int(y) -1, 0], color=RED, radius=0.12))
        
        for e in arr:
            self.add(e)


        with open("hilbert.txt", "r") as ANSWER:
            Q = ANSWER.readlines()

        print(Q)
        
        order = []
        for e in Q[0].strip().split():
            order.append(int(e))
        
        for i,p in enumerate(order):
            self.add(Tex(str(i+1), color=RED).next_to(arr[p], LEFT*.5 + UP*.5))


class sierpinski(Scene):
    def construct(self):
    
        numberplane = NumberPlane(x_range=(0, 10, 1), y_range=(0, 10, 1), faded_line_ratio=0).move_to(RIGHT*5 + UP*5);
        self.play(self.camera.frame.animate.scale(2.4))
        self.add(numberplane)
        with open("16x16sierpinski.txt", "r") as ANSWER:
            Q = ANSWER.readlines()

        print(Q)
        
        perm = []
        for e in Q[0].strip().split():
            perm.append(int(e))

        pts = []
        for i in range(256):
            pts.append([int(i/16), int(i%16), 0])

        for i in range(255):
            if pts[perm[i]][0] <= 10 and pts[perm[i]][1] <= 10 and pts[perm[i+1]][0] <= 10 and pts[perm[i+1]][1] <= 10:
                self.add(Line(pts[perm[i]], pts[perm[i+1]], color=YELLOW, stroke_width=4))



        input_file = "small_rng_3"
        with open(input_file + ".txt", "r") as INPUT: 
            R = INPUT.readlines()


        print(R)

        N = int(R[0].strip())
        arr = []

        for i in range(1, N+1):
            [x, y] = R[i].strip().split()
            arr.append(Dot([int(x) -1, int(y) -1, 0], color=RED, radius=0.12))
       
        # self.add(DashedLine([0, -.5, 0], [15.5, 15, 0], color=RED, dash_length=.5))
        # self.add(DashedLine([8.25, 7.25, 0], [8.25 + 8, 7.25 - 8, 0], color=RED, dash_length=.5))
        # self.add(DashedLine([11+.5, 3.75, 0], [11+.5 - 4, 3.75 - 4, 0], color=RED, dash_length=.5))
        for e in arr:
            self.add(e)


        with open("sierpinski.txt", "r") as ANSWER:
            Q = ANSWER.readlines()

        print(Q)
        
        order = []
        for e in Q[0].strip().split():
            order.append(int(e))
        
        for i,p in enumerate(order):
            self.add(Tex(str(i+1), color=RED).next_to(arr[p], LEFT*.5 + UP*.5 if i + 1 != 3 else RIGHT*.5 + UP*.5))



