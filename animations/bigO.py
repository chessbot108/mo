from manimlib import *
import math


class n_square(Scene):
    def construct(self):
        numberplane = NumberPlane(x_range=(0, 10, 1), y_range=(0, 10, 1), faded_line_ratio=0).move_to(RIGHT*5 + UP*5)
        self.play(self.camera.frame.animate.scale(2))
        f1 = ParametricCurve(
                lambda x : np.array([x, x ** 2 /10, 0]),
                color=GREEN,
                t_range=[0, 10]
        )
        f2 = ParametricCurve(
                lambda x : np.array([x, (x ** 2 + x)/2 /10, 0]),
                color=RED,
                t_range=[0, 10]
        )
        f3 = ParametricCurve(
                lambda x : np.array([x, .5 * x ** 2 /10, 0]),
                color=YELLOW,
                t_range=[0, 10]
        )
        x_max = 10

        self.add(numberplane)
        self.add(f1, f2, f3)
        d1 = Dot(f1.get_point_from_function(x_max), color=f1.get_color())
        d2 = Dot(f2.get_point_from_function(x_max), color=f2.get_color())
        d3 = Dot(f3.get_point_from_function(x_max), color=f3.get_color())
        self.add(d1, d2, d3)


        t1 = Tex(r"2x^2", color=f1.get_color()).next_to(d1, RIGHT*.5)
        t2 = Tex(r"\frac{(x)(x + 1)}{2}", color=f2.get_color()).next_to(d2, UP*.5)
        t3 = Tex(r"\frac{1}{2} x^2", color=f3.get_color()).next_to(d3, RIGHT*.5 + DOWN*.5)
        self.add(t1, t2, t3)

        tf = Tex(r"f(x) = x^2, ")
        tg = Tex(r"g(x) = \frac{(x)(x+1)}{2}").next_to(tf, RIGHT)
        tfg = VGroup()
        tfg.add(tf, tg)
        tfg = tfg.next_to(numberplane, DOWN*.5)
        ineq = Tex(r"\text{as } x \text{ goes to infinity } \frac{1}{2}f(x) \leq g(x) \leq 2f(x)").next_to(numberplane, DOWN*4.5)
        self.add(tf, tg, ineq) 


class n_log_n(Scene):
    def construct(self):
        numberplane = NumberPlane(x_range=(0, 10, 1), y_range=(0, 10, 1), faded_line_ratio=0).move_to(RIGHT*5 + UP*5)
        self.play(self.camera.frame.animate.scale(2))
        x_max = 397
        y_scale = 400
        x_scale = x_max/10
        a = .5
        b = 1
        f1 = ParametricCurve(
                lambda x : np.array([x/x_scale, a * x * math.log(x)/math.log(2) /y_scale, 0]),
                color=GREEN,
                t_range=[1, x_max]
        )
        f2 = ParametricCurve(
                lambda x : np.array([x/x_scale, x * math.log(x) / y_scale, 0]),
                color=RED,
                t_range=[1, x_max]
        )
        f3 = ParametricCurve(
                lambda x : np.array([x/x_scale, b * x * math.log(x)/math.log(2) /y_scale, 0]),
                color=YELLOW,
                t_range=[1, x_max]
        )

        self.add(numberplane)
        self.add(f1, f2, f3)
        d1 = Dot(f1.get_point_from_function(x_max), color=f1.get_color())
        d2 = Dot(f2.get_point_from_function(x_max), color=f2.get_color())
        d3 = Dot(f3.get_point_from_function(x_max), color=f3.get_color())
        self.add(d1, d2, d3)


        t1 = Tex(r"\frac{1}{2}x \log_2(x)", color=f1.get_color()).next_to(d1, RIGHT*.5)
        t2 = Tex(r"x \ln(x)", color=f2.get_color()).next_to(d2, UP*.5)
        t3 = Tex(r"x \log_2(x)", color=f3.get_color()).next_to(d3, RIGHT*.5 + DOWN*.5)
        self.add(t1, t2, t3)

        tf = Tex(r"f(x) = x \log_2(x), ")
        tg = Tex(r"g(x) = x \ln(x)").next_to(tf, RIGHT)
        tfg = VGroup()
        tfg.add(tf, tg)
        tfg = tfg.next_to(numberplane, DOWN*.5)
        ineq = Tex(r"\text{as } x \text{ goes to infinity } \frac{1}{2}f(x) \leq g(x) \leq f(x)").next_to(numberplane, DOWN*4.5)
        self.add(tf, tg, ineq) 


 
