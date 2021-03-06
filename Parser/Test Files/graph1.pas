{ program 4.9 from Jensen & Wirth       -- file pastst.pas }


(*
(program graph1 (progn output)
                (progn (:= i 0)
                       (label 1)
                       (if (<= i 32)
                           (progn (:= x (* 6.250000e-02
                                           (float i)))
                                  (:= y (* (funcall exp (- x))
                                           (funcall sin (* 6.283180e+00
                                                           x))))
                                  (:= n (fix (+ (funcall round (* 3.200000e+01
                                                                  y))
                                                3.400000e+01)))
                                  (progn (label 0)
                                         (funcall write ' ')
                                         (:= n (- n 1))
                                         (if (= n 0)
                                             (progn)
                                             (goto 0)))
                                  (funcall writeln '*')
                                  (:= i (+ i 1))
                                  (goto 1))))) 
*)

program graph1(output);
const d = 0.0625; {1/16, 16 lines for interval [x,x+1]}
      s = 32; {32 character widths for interval [y,y+1]}
      h = 34; {character position of x-axis}
      c = 6.28318; {2*pi}  lim = 32;
var x,y : real;  i,n : integer;
begin
   for i := 0 to lim do
      begin x := d*i;
	  y := exp(-x)*sin(c*x);
      n := round(s*y) + h;
      repeat write(' ');  n := n-1
      until n=0;
      writeln('*')
   end
end.
