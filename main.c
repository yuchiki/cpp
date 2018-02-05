
#define rec_0(f, v) f(v)
#define rec_1(f, v) rec_0(f, rec_0(f, v))
#define rec_2(f, v) rec_1(f, rec_1(f, v))
#define rec_3(f, v) rec_2(f, rec_2(f, v))
#define rec_4(f, v) rec_3(f, rec_3(f, v))
#define rec_5(f, v) rec_4(f, rec_4(f, v))
#define rec_6(f, v) rec_5(f, rec_5(f, v))
#define rec_7(f, v) rec_6(f, rec_6(f, v))
#define rec_8(f, v) rec_7(f, rec_7(f, v))
#define rec_9(f, v) rec_8(f, rec_8(f, v))
#define rec(f, v) rec_3(f, v)

#define pif(b) if_inner(b)
#define if_inner(b) if_##b
#define if_1(x, y) x
#define if_0(x, y) y

#define fst(x) fst_inner x
#define fst_inner(x, y, z) x
#define third(x) third_inner x
#define third_inner(x, y, z) z

#define while_filter(p, f, v) (p, f, pif(p(v))(f(v), v))
#define while_filter_compressed(tpl) while_filter tpl
#define while(p, f, v) third(rec(while_filter_compressed, (p, f, v)))

#include "incdec.c"
#define inc(i) inc_inner(i)
#define inc_inner(i) inc_##i
#define dec(i) dec_inner(i)
#define dec_inner(i) dec_##i
#define is_pos(i) is_pos_inner(i)
#define is_pos_inner(i) is_pos_##i

#define rep_filter(i, f, v) (dec i, f, pif(is_pos(i))(f(v), v))
#define rep_filter_compressed(tpl) rep_filter tpl
#define rep(i, f, v) third(rec(rep_filter_compressed, (i, f, v)))


#define ctrue(x) 1 
while (ctrue, inc, 10)

pif(is_pos(dec(10)))(10,20)