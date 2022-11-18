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
        
        # input_file = "input1"
        # alg_name = "hilbert1"
        input_file = input()
        alg_name = input()

        with open(input_file + ".txt", "r") as INPUT: 
            R = INPUT.readlines()
            

        print(R)
        
        N = int(R[0].strip())
        arr = []

        for i in range(1, N+1):
            [x, y] = R[i].strip().split()
            arr.append(Dot([int(x) -1, int(y) -1, 0], color=RED))
        
        with open(alg_name + ".txt", "r") as ANSWER:
            Q = ANSWER.readlines()

        print(Q)
        
        perm = []
        for e in Q[0].strip().split():
            perm.append(int(e))

        
        
        print(perm)

        numberplane = NumberPlane(x_range=(0, 10, 1), y_range=(0, 10, 1), faded_line_ratio=0).move_to(RIGHT*5 + UP*5);
        src = Dot(ORIGIN, color=RED)
        trav = src.copy().set_color(YELLOW)
        self.play(self.camera.frame.animate.scale(2))
        self.play(self.camera.frame.animate.move_to([7, 3, 0]));

        self.add(numberplane);
        self.add(src)

        for e in arr:
            self.add(e)

        self.add(trav)

        self.wait(duration=1.0)
        print("dense?")
        isd = input().strip()
        def arrow_tour():

            for idx, v in enumerate(perm):
                tmp = trav.copy();
                arr[v].set_color(GREEN)
                a = Arrow(start=tmp, end=arr[v], color=YELLOW)
                self.play(Write(a))
                everule(trav, arr[v])
                self.play(Uncreate(a))
                arr[v].set_color(YELLOW)
                print(trav.get_x(), trav.get_y())
            self.wait(duration=10)
        
        def dense_tour():
            for idx, v in enumerate(perm):
                tmp = trav.copy();
                arr[v].set_color(GREEN)
                l = Line(start=tmp, end=arr[v], color=YELLOW)
                self.play(Write(l))
                everule(trav, arr[v])
                arr[v].set_color(YELLOW)
                print(trav.get_x(), trav.get_y())
            self.wait(duration=10)
        if(isd[0] == 'Y'):
            dense_tour()
        else:
            arrow_tour()
    
