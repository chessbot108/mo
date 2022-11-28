
from manimlib import * 


class tspAnimation(Scene):

    def construct(self):

        def creep(p, d):
            if p.get_x() < d.get_x():
                return p.set_x(p.get_x() + 1)
            if p.get_x() > d.get_x():
                return p.set_x(p.get_x() - 1)
            if p.get_y() < d.get_y():
                return p.set_y(p.get_y() + 1)
            if p.get_y() > d.get_y():
                return p.set_y(p.get_y() - 1)
            return p


        slide = lambda p, np: self.play(Transform(p, np, run_time=.35))

        def everule(p, d):
            while p.get_x() != d.get_x() or p.get_y() != d.get_y():
                np = creep(p, d);
                slide(p, np)
                p = np
        
        input_file = "small_rng_3"
        alg_name = "classic_with_parity"
        underlying = "empty"
        # input_file = input()
        # alg_name = input()
        # underlying = input()

        with open(input_file + ".txt", "r") as INPUT: 
            R = INPUT.readlines()
            

        print(R)
        
        N = int(R[0].strip())
        arr = []

        for i in range(1, N+1):
            [x, y] = R[i].strip().split()
            arr.append(Dot([int(x) -1, int(y) -1, 0], color=RED, radius=0.12))
        
        with open(alg_name + ".txt", "r") as ANSWER:
            Q = ANSWER.readlines()

        print(Q)
        
        perm = []
        for e in Q[0].strip().split():
            perm.append(int(e))

        
        
        print(perm)

        with open(underlying + ".txt", "r") as UNDERLYING:
            U = UNDERLYING.readlines()


        numberplane = NumberPlane(x_range=(0, 10, 1), y_range=(0, 10, 1), faded_line_ratio=0).move_to(RIGHT*5 + UP*5);
        src = Dot(ORIGIN, color=RED, radius=0.12)
        trav = src.copy().set_color(YELLOW)
        self.play(self.camera.frame.animate.scale(2))
        self.play(self.camera.frame.animate.move_to([7, 3, 0]));

        self.add(numberplane);


        if len(U) != 0:
            M = int(U[0].strip())
            for i in range(1, M+1):
                [x1, y1, x2, y2] = U[i].strip().split()
                self.add(DashedLine([int(x1)-1, int(y1)-1, 0], [int(x2)-1, int(y2)-1, 0], color=WHITE, dash_length=0.3))

        for e in arr:
            self.add(e)

        self.add(trav)

        self.wait(duration=1.0)
        print("dense?")
        # isd = input().strip()
        isd = "N"
        def arrow_tour():

            for idx, v in enumerate(perm):
                tmp = trav.copy();
                a = Arrow(start=tmp, end=arr[v], color=YELLOW)
                arr[v].set_color(GREEN)
                self.play(Write(a))
                self.wait(duration=1)
                everule(trav, arr[v])
                self.play(Uncreate(a))
                arr[v].set_color(YELLOW)
                # print(trav.get_x(), trav.get_y())
            self.wait(duration=10)
        
        def dense_tour():
            trav.set_color(ORANGE)
            for idx, v in enumerate(perm):
                tmp = trav.copy();
                arr[v].set_color(GREEN)
                l = Line(start=tmp, end=arr[v], color=YELLOW)
                self.play(Write(l))
                everule(trav, arr[v])
                arr[v].set_color(YELLOW)
                # print(trav.get_x(), trav.get_y())
            self.wait(duration=10)
        if(isd[0] == 'Y'):
            dense_tour()
        else:
            arrow_tour()
    
