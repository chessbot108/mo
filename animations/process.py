from manimlib import * 


class fourLine(Scene):

    def construct(self):
        numberplane = NumberPlane()
        src = Dot(ORIGIN, color=BLUE)
        trav = src.copy().set_color(YELLOW)

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


        slide = lambda p, np: self.play(Transform(p, np))

        def everule(p, d):
            while p.get_x() != d.get_x() or p.get_y() != d.get_y():
                np = creep(p, d);
                slide(p, np)
                p = np

        self.add(numberplane, src)
        input_file = input()
        alg_name = input()

        with open(input_file + ".txt", "r") as INPUT: 
            R = INPUT.readlines()
            

        print(R)
        
        N = int(R[0].strip())
        arr = []

        for i in range(1, N+1):
            [x, y] = R[i].strip().split()
            arr.append(Dot([int(x), int(y), 0], color=BLUE))
        
        with open(alg_name + ".txt", "r") as ANSWER:
            Q = ANSWER.readlines()

        print(Q)
        
        perm = []
        for e in Q[0].strip().split():
            perm.append(int(e))

        
        
        print(perm)



        for e in arr:
            self.add(e)

        self.add(trav)
        for idx, v in enumerate(perm):
            everule(trav, arr[v])
            print(trav.get_x(), trav.get_y())



        
        self.wait()

