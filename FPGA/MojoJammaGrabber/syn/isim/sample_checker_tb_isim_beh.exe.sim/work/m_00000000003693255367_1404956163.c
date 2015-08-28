/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "D:/githome/projects/AvrStuff/JammaTestBoard/Verilog/Mojo-SDRAM/sample_checker.v";
static int ng1[] = {0, 0};
static int ng2[] = {1, 0};
static unsigned int ng3[] = {0U, 0U};
static unsigned int ng4[] = {1U, 0U};
static unsigned int ng5[] = {8388607U, 0U};
static unsigned int ng6[] = {15U, 0U};



static void Cont_26_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 9128U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(26, ng0);
    t2 = (t0 + 5328);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 11112);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 7U;
    t11 = t10;
    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t5, 0, 2);
    t18 = (t0 + 10936);
    *((int *)t18) = 1;

LAB1:    return;
}

static void NetDecl_41_1(char *t0)
{
    char t3[8];
    char t6[8];
    char t35[8];
    char t44[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    char *t33;
    char *t34;
    char *t36;
    char *t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    char *t48;
    char *t49;
    char *t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t58;
    char *t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    int t68;
    int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    char *t76;
    char *t77;
    char *t78;
    char *t79;
    char *t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;
    unsigned int t84;
    unsigned int t85;
    char *t86;
    unsigned int t87;
    unsigned int t88;
    char *t89;

LAB0:    t1 = (t0 + 9376U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(41, ng0);
    t2 = (t0 + 6608);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t7 = (t6 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 0);
    t11 = (t10 & 1);
    *((unsigned int *)t6) = t11;
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 0);
    t14 = (t13 & 1);
    *((unsigned int *)t7) = t14;
    memset(t3, 0, 8);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t15);
    t17 = (~(t16));
    t18 = *((unsigned int *)t6);
    t19 = (t18 & t17);
    t20 = (t19 & 1U);
    if (t20 != 0)
        goto LAB7;

LAB5:    if (*((unsigned int *)t15) == 0)
        goto LAB4;

LAB6:    t21 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t21) = 1;

LAB7:    t22 = (t3 + 4);
    t23 = (t6 + 4);
    t24 = *((unsigned int *)t6);
    t25 = (~(t24));
    *((unsigned int *)t3) = t25;
    *((unsigned int *)t22) = 0;
    if (*((unsigned int *)t23) != 0)
        goto LAB9;

LAB8:    t30 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t30 & 1U);
    t31 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t31 & 1U);
    t32 = (t0 + 6608);
    t33 = (t32 + 56U);
    t34 = *((char **)t33);
    memset(t35, 0, 8);
    t36 = (t35 + 4);
    t37 = (t34 + 4);
    t38 = *((unsigned int *)t34);
    t39 = (t38 >> 1);
    t40 = (t39 & 1);
    *((unsigned int *)t35) = t40;
    t41 = *((unsigned int *)t37);
    t42 = (t41 >> 1);
    t43 = (t42 & 1);
    *((unsigned int *)t36) = t43;
    t45 = *((unsigned int *)t3);
    t46 = *((unsigned int *)t35);
    t47 = (t45 & t46);
    *((unsigned int *)t44) = t47;
    t48 = (t3 + 4);
    t49 = (t35 + 4);
    t50 = (t44 + 4);
    t51 = *((unsigned int *)t48);
    t52 = *((unsigned int *)t49);
    t53 = (t51 | t52);
    *((unsigned int *)t50) = t53;
    t54 = *((unsigned int *)t50);
    t55 = (t54 != 0);
    if (t55 == 1)
        goto LAB10;

LAB11:
LAB12:    t76 = (t0 + 11176);
    t77 = (t76 + 56U);
    t78 = *((char **)t77);
    t79 = (t78 + 56U);
    t80 = *((char **)t79);
    memset(t80, 0, 8);
    t81 = 1U;
    t82 = t81;
    t83 = (t44 + 4);
    t84 = *((unsigned int *)t44);
    t81 = (t81 & t84);
    t85 = *((unsigned int *)t83);
    t82 = (t82 & t85);
    t86 = (t80 + 4);
    t87 = *((unsigned int *)t80);
    *((unsigned int *)t80) = (t87 | t81);
    t88 = *((unsigned int *)t86);
    *((unsigned int *)t86) = (t88 | t82);
    xsi_driver_vfirst_trans(t76, 0, 0U);
    t89 = (t0 + 10952);
    *((int *)t89) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t3) = 1;
    goto LAB7;

LAB9:    t26 = *((unsigned int *)t3);
    t27 = *((unsigned int *)t23);
    *((unsigned int *)t3) = (t26 | t27);
    t28 = *((unsigned int *)t22);
    t29 = *((unsigned int *)t23);
    *((unsigned int *)t22) = (t28 | t29);
    goto LAB8;

LAB10:    t56 = *((unsigned int *)t44);
    t57 = *((unsigned int *)t50);
    *((unsigned int *)t44) = (t56 | t57);
    t58 = (t3 + 4);
    t59 = (t35 + 4);
    t60 = *((unsigned int *)t3);
    t61 = (~(t60));
    t62 = *((unsigned int *)t58);
    t63 = (~(t62));
    t64 = *((unsigned int *)t35);
    t65 = (~(t64));
    t66 = *((unsigned int *)t59);
    t67 = (~(t66));
    t68 = (t61 & t63);
    t69 = (t65 & t67);
    t70 = (~(t68));
    t71 = (~(t69));
    t72 = *((unsigned int *)t50);
    *((unsigned int *)t50) = (t72 & t70);
    t73 = *((unsigned int *)t50);
    *((unsigned int *)t50) = (t73 & t71);
    t74 = *((unsigned int *)t44);
    *((unsigned int *)t44) = (t74 & t70);
    t75 = *((unsigned int *)t44);
    *((unsigned int *)t44) = (t75 & t71);
    goto LAB12;

}

static void NetDecl_42_2(char *t0)
{
    char t7[8];
    char t24[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    char *t23;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    int t47;
    int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    char *t55;
    char *t56;
    char *t57;
    char *t58;
    char *t59;
    unsigned int t60;
    unsigned int t61;
    char *t62;
    unsigned int t63;
    unsigned int t64;
    char *t65;
    unsigned int t66;
    unsigned int t67;
    char *t68;

LAB0:    t1 = (t0 + 9624U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(42, ng0);
    t2 = (t0 + 5328);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 880);
    t6 = *((char **)t5);
    memset(t7, 0, 8);
    t5 = (t4 + 4);
    t8 = (t6 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t6);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t5);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t5);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB7;

LAB4:    if (t18 != 0)
        goto LAB6;

LAB5:    *((unsigned int *)t7) = 1;

LAB7:    t22 = (t0 + 3968U);
    t23 = *((char **)t22);
    t25 = *((unsigned int *)t7);
    t26 = *((unsigned int *)t23);
    t27 = (t25 & t26);
    *((unsigned int *)t24) = t27;
    t22 = (t7 + 4);
    t28 = (t23 + 4);
    t29 = (t24 + 4);
    t30 = *((unsigned int *)t22);
    t31 = *((unsigned int *)t28);
    t32 = (t30 | t31);
    *((unsigned int *)t29) = t32;
    t33 = *((unsigned int *)t29);
    t34 = (t33 != 0);
    if (t34 == 1)
        goto LAB8;

LAB9:
LAB10:    t55 = (t0 + 11240);
    t56 = (t55 + 56U);
    t57 = *((char **)t56);
    t58 = (t57 + 56U);
    t59 = *((char **)t58);
    memset(t59, 0, 8);
    t60 = 1U;
    t61 = t60;
    t62 = (t24 + 4);
    t63 = *((unsigned int *)t24);
    t60 = (t60 & t63);
    t64 = *((unsigned int *)t62);
    t61 = (t61 & t64);
    t65 = (t59 + 4);
    t66 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t66 | t60);
    t67 = *((unsigned int *)t65);
    *((unsigned int *)t65) = (t67 | t61);
    xsi_driver_vfirst_trans(t55, 0, 0U);
    t68 = (t0 + 10968);
    *((int *)t68) = 1;

LAB1:    return;
LAB6:    t21 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB7;

LAB8:    t35 = *((unsigned int *)t24);
    t36 = *((unsigned int *)t29);
    *((unsigned int *)t24) = (t35 | t36);
    t37 = (t7 + 4);
    t38 = (t23 + 4);
    t39 = *((unsigned int *)t7);
    t40 = (~(t39));
    t41 = *((unsigned int *)t37);
    t42 = (~(t41));
    t43 = *((unsigned int *)t23);
    t44 = (~(t43));
    t45 = *((unsigned int *)t38);
    t46 = (~(t45));
    t47 = (t40 & t42);
    t48 = (t44 & t46);
    t49 = (~(t47));
    t50 = (~(t48));
    t51 = *((unsigned int *)t29);
    *((unsigned int *)t29) = (t51 & t49);
    t52 = *((unsigned int *)t29);
    *((unsigned int *)t29) = (t52 & t50);
    t53 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t53 & t49);
    t54 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t54 & t50);
    goto LAB10;

}

static void Cont_49_3(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 9872U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 8208);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 11304);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 15U;
    t11 = t10;
    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t5, 0, 3);
    t18 = (t0 + 10984);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Always_51_4(char *t0)
{
    char t18[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    char *t33;

LAB0:    t1 = (t0 + 10120U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(51, ng0);
    t2 = (t0 + 11000);
    *((int *)t2) = 1;
    t3 = (t0 + 10152);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(51, ng0);

LAB5:    xsi_set_current_line(52, ng0);
    t4 = (t0 + 5328);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 5168);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 3);
    xsi_set_current_line(54, ng0);
    t2 = (t0 + 5328);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);

LAB6:    t5 = (t0 + 472);
    t6 = *((char **)t5);
    t8 = xsi_vlog_unsigned_case_compare(t4, 3, t6, 32);
    if (t8 == 1)
        goto LAB7;

LAB8:    t2 = (t0 + 608);
    t3 = *((char **)t2);
    t8 = xsi_vlog_unsigned_case_compare(t4, 3, t3, 32);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = (t0 + 744);
    t3 = *((char **)t2);
    t8 = xsi_vlog_unsigned_case_compare(t4, 3, t3, 32);
    if (t8 == 1)
        goto LAB11;

LAB12:    t2 = (t0 + 880);
    t3 = *((char **)t2);
    t8 = xsi_vlog_unsigned_case_compare(t4, 3, t3, 32);
    if (t8 == 1)
        goto LAB13;

LAB14:    t2 = (t0 + 1016);
    t3 = *((char **)t2);
    t8 = xsi_vlog_unsigned_case_compare(t4, 3, t3, 32);
    if (t8 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB2;

LAB7:    xsi_set_current_line(55, ng0);

LAB18:    xsi_set_current_line(56, ng0);
    t5 = (t0 + 5648);
    t7 = (t5 + 56U);
    t9 = *((char **)t7);
    t10 = (t9 + 4);
    t11 = *((unsigned int *)t10);
    t12 = (~(t11));
    t13 = *((unsigned int *)t9);
    t14 = (t13 & t12);
    t15 = (t14 != 0);
    if (t15 > 0)
        goto LAB19;

LAB20:
LAB21:    goto LAB17;

LAB9:    xsi_set_current_line(60, ng0);

LAB23:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 5968);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 4);
    t11 = *((unsigned int *)t7);
    t12 = (~(t11));
    t13 = *((unsigned int *)t6);
    t14 = (t13 & t12);
    t15 = (t14 != 0);
    if (t15 > 0)
        goto LAB24;

LAB25:
LAB26:    goto LAB17;

LAB11:    xsi_set_current_line(65, ng0);

LAB28:    xsi_set_current_line(66, ng0);
    t2 = (t0 + 5968);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    memset(t18, 0, 8);
    t7 = (t6 + 4);
    t11 = *((unsigned int *)t7);
    t12 = (~(t11));
    t13 = *((unsigned int *)t6);
    t14 = (t13 & t12);
    t15 = (t14 & 1U);
    if (t15 != 0)
        goto LAB32;

LAB30:    if (*((unsigned int *)t7) == 0)
        goto LAB29;

LAB31:    t9 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t9) = 1;

LAB32:    t10 = (t18 + 4);
    t16 = (t6 + 4);
    t19 = *((unsigned int *)t6);
    t20 = (~(t19));
    *((unsigned int *)t18) = t20;
    *((unsigned int *)t10) = 0;
    if (*((unsigned int *)t16) != 0)
        goto LAB34;

LAB33:    t25 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t25 & 1U);
    t26 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t26 & 1U);
    t17 = (t18 + 4);
    t27 = *((unsigned int *)t17);
    t28 = (~(t27));
    t29 = *((unsigned int *)t18);
    t30 = (t29 & t28);
    t31 = (t30 != 0);
    if (t31 > 0)
        goto LAB35;

LAB36:
LAB37:    goto LAB17;

LAB13:    xsi_set_current_line(70, ng0);

LAB39:    xsi_set_current_line(71, ng0);
    t2 = (t0 + 5968);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 4);
    t11 = *((unsigned int *)t7);
    t12 = (~(t11));
    t13 = *((unsigned int *)t6);
    t14 = (t13 & t12);
    t15 = (t14 != 0);
    if (t15 > 0)
        goto LAB40;

LAB41:
LAB42:    goto LAB17;

LAB15:    xsi_set_current_line(75, ng0);

LAB44:    goto LAB17;

LAB19:    xsi_set_current_line(56, ng0);

LAB22:    xsi_set_current_line(57, ng0);
    t16 = (t0 + 608);
    t17 = *((char **)t16);
    t16 = (t0 + 5168);
    xsi_vlogvar_assign_value(t16, t17, 0, 0, 3);
    goto LAB21;

LAB24:    xsi_set_current_line(61, ng0);

LAB27:    xsi_set_current_line(62, ng0);
    t9 = (t0 + 744);
    t10 = *((char **)t9);
    t9 = (t0 + 5168);
    xsi_vlogvar_assign_value(t9, t10, 0, 0, 3);
    goto LAB26;

LAB29:    *((unsigned int *)t18) = 1;
    goto LAB32;

LAB34:    t21 = *((unsigned int *)t18);
    t22 = *((unsigned int *)t16);
    *((unsigned int *)t18) = (t21 | t22);
    t23 = *((unsigned int *)t10);
    t24 = *((unsigned int *)t16);
    *((unsigned int *)t10) = (t23 | t24);
    goto LAB33;

LAB35:    xsi_set_current_line(66, ng0);

LAB38:    xsi_set_current_line(67, ng0);
    t32 = (t0 + 880);
    t33 = *((char **)t32);
    t32 = (t0 + 5168);
    xsi_vlogvar_assign_value(t32, t33, 0, 0, 3);
    goto LAB37;

LAB40:    xsi_set_current_line(71, ng0);

LAB43:    xsi_set_current_line(72, ng0);
    t9 = (t0 + 1016);
    t10 = *((char **)t9);
    t9 = (t0 + 5168);
    xsi_vlogvar_assign_value(t9, t10, 0, 0, 3);
    goto LAB42;

}

static void Always_81_5(char *t0)
{
    char t6[8];
    char t17[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;

LAB0:    t1 = (t0 + 10368U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(81, ng0);
    t2 = (t0 + 11016);
    *((int *)t2) = 1;
    t3 = (t0 + 10400);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(81, ng0);

LAB5:    xsi_set_current_line(82, ng0);
    t4 = (t0 + 2528U);
    t5 = *((char **)t4);
    t4 = (t0 + 5488);
    xsi_vlogvar_assign_value(t4, t5, 0, 0, 1);
    xsi_set_current_line(83, ng0);
    t2 = (t0 + 2208U);
    t3 = *((char **)t2);
    t2 = (t0 + 5808);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 1);
    xsi_set_current_line(84, ng0);
    t2 = (t0 + 2368U);
    t3 = *((char **)t2);
    t2 = (t0 + 6128);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 1);
    xsi_set_current_line(85, ng0);
    t2 = (t0 + 2048U);
    t3 = *((char **)t2);
    t2 = (t0 + 6448);
    t4 = (t0 + 6448);
    t5 = (t4 + 72U);
    t7 = *((char **)t5);
    t8 = ((char*)((ng1)));
    xsi_vlog_generic_convert_bit_index(t6, t7, 2, t8, 32, 1);
    t9 = (t6 + 4);
    t10 = *((unsigned int *)t9);
    t11 = (!(t10));
    if (t11 == 1)
        goto LAB6;

LAB7:    xsi_set_current_line(86, ng0);
    t2 = (t0 + 6608);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t6 + 4);
    t7 = (t4 + 4);
    t10 = *((unsigned int *)t4);
    t12 = (t10 >> 0);
    t13 = (t12 & 1);
    *((unsigned int *)t6) = t13;
    t14 = *((unsigned int *)t7);
    t15 = (t14 >> 0);
    t16 = (t15 & 1);
    *((unsigned int *)t5) = t16;
    t8 = (t0 + 6448);
    t9 = (t0 + 6448);
    t18 = (t9 + 72U);
    t19 = *((char **)t18);
    t20 = ((char*)((ng2)));
    xsi_vlog_generic_convert_bit_index(t17, t19, 2, t20, 32, 1);
    t21 = (t17 + 4);
    t22 = *((unsigned int *)t21);
    t11 = (!(t22));
    if (t11 == 1)
        goto LAB8;

LAB9:    xsi_set_current_line(87, ng0);
    t2 = (t0 + 2688U);
    t3 = *((char **)t2);
    t2 = (t0 + 6768);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 8);
    xsi_set_current_line(88, ng0);
    t2 = (t0 + 2848U);
    t3 = *((char **)t2);
    t2 = (t0 + 7088);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 8);
    xsi_set_current_line(89, ng0);
    t2 = (t0 + 3008U);
    t3 = *((char **)t2);
    t2 = (t0 + 7408);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 8);
    xsi_set_current_line(91, ng0);
    t2 = (t0 + 8208);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 8048);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 4);
    xsi_set_current_line(92, ng0);
    t2 = (t0 + 7888);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7728);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 23);
    xsi_set_current_line(93, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 4528);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 23);
    xsi_set_current_line(94, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 4688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(95, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 4848);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(96, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 5008);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(98, ng0);
    t2 = (t0 + 4128U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t10 = *((unsigned int *)t2);
    t12 = (~(t10));
    t13 = *((unsigned int *)t3);
    t14 = (t13 & t12);
    t15 = (t14 != 0);
    if (t15 > 0)
        goto LAB10;

LAB11:
LAB12:    goto LAB2;

LAB6:    xsi_vlogvar_assign_value(t2, t3, 0, *((unsigned int *)t6), 1);
    goto LAB7;

LAB8:    xsi_vlogvar_assign_value(t8, t6, 0, *((unsigned int *)t17), 1);
    goto LAB9;

LAB10:    xsi_set_current_line(98, ng0);

LAB13:    xsi_set_current_line(99, ng0);
    t4 = (t0 + 3488U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t5 + 4);
    t16 = *((unsigned int *)t4);
    t22 = (~(t16));
    t23 = *((unsigned int *)t5);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB17;

LAB15:    if (*((unsigned int *)t4) == 0)
        goto LAB14;

LAB16:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;

LAB17:    t8 = (t6 + 4);
    t26 = *((unsigned int *)t8);
    t27 = (~(t26));
    t28 = *((unsigned int *)t6);
    t29 = (t28 & t27);
    t30 = (t29 != 0);
    if (t30 > 0)
        goto LAB18;

LAB19:    xsi_set_current_line(108, ng0);

LAB30:    xsi_set_current_line(109, ng0);
    t2 = (t0 + 8208);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 4, t4, 4, t5, 4);
    t7 = (t0 + 8048);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 4);

LAB20:    goto LAB12;

LAB14:    *((unsigned int *)t6) = 1;
    goto LAB17;

LAB18:    xsi_set_current_line(99, ng0);

LAB21:    xsi_set_current_line(100, ng0);
    t9 = (t0 + 7888);
    t18 = (t9 + 56U);
    t19 = *((char **)t18);
    t20 = ((char*)((ng4)));
    memset(t17, 0, 8);
    xsi_vlog_unsigned_add(t17, 23, t19, 23, t20, 23);
    t21 = (t0 + 7728);
    xsi_vlogvar_assign_value(t21, t17, 0, 0, 23);
    xsi_set_current_line(101, ng0);
    t2 = (t0 + 7888);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4528);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 23);
    xsi_set_current_line(102, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 4688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(103, ng0);
    t2 = (t0 + 6288);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    t7 = (t0 + 7568);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t18 = (t0 + 7248);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    t21 = (t0 + 6928);
    t31 = (t21 + 56U);
    t32 = *((char **)t31);
    xsi_vlogtype_concat(t6, 32, 32, 5U, t32, 8, t20, 8, t9, 8, t5, 7, t4, 1);
    t33 = (t0 + 4848);
    xsi_vlogvar_assign_value(t33, t6, 0, 0, 32);
    xsi_set_current_line(104, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 5008);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(105, ng0);
    t2 = (t0 + 7888);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng5)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t10 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t13 = (t10 ^ t12);
    t14 = *((unsigned int *)t7);
    t15 = *((unsigned int *)t8);
    t16 = (t14 ^ t15);
    t22 = (t13 | t16);
    t23 = *((unsigned int *)t7);
    t24 = *((unsigned int *)t8);
    t25 = (t23 | t24);
    t26 = (~(t25));
    t27 = (t22 & t26);
    if (t27 != 0)
        goto LAB25;

LAB22:    if (t25 != 0)
        goto LAB24;

LAB23:    *((unsigned int *)t6) = 1;

LAB25:    t18 = (t6 + 4);
    t28 = *((unsigned int *)t18);
    t29 = (~(t28));
    t30 = *((unsigned int *)t6);
    t34 = (t30 & t29);
    t35 = (t34 != 0);
    if (t35 > 0)
        goto LAB26;

LAB27:
LAB28:    goto LAB20;

LAB24:    t9 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB25;

LAB26:    xsi_set_current_line(105, ng0);

LAB29:    xsi_set_current_line(106, ng0);
    t19 = ((char*)((ng6)));
    t20 = (t0 + 8048);
    xsi_vlogvar_assign_value(t20, t19, 0, 0, 4);
    goto LAB28;

}

static void Always_114_6(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;

LAB0:    t1 = (t0 + 10616U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(114, ng0);
    t2 = (t0 + 11032);
    *((int *)t2) = 1;
    t3 = (t0 + 10648);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(114, ng0);

LAB5:    xsi_set_current_line(115, ng0);
    t4 = (t0 + 1728U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(126, ng0);

LAB10:    xsi_set_current_line(127, ng0);
    t2 = (t0 + 5168);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5328);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 3, 0LL);
    xsi_set_current_line(128, ng0);
    t2 = (t0 + 5488);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5648);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(129, ng0);
    t2 = (t0 + 5808);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5968);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(130, ng0);
    t2 = (t0 + 6128);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6288);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(131, ng0);
    t2 = (t0 + 6448);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6608);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 2, 0LL);
    xsi_set_current_line(132, ng0);
    t2 = (t0 + 8048);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 8208);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);
    xsi_set_current_line(133, ng0);
    t2 = (t0 + 7728);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7888);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 23, 0LL);
    xsi_set_current_line(134, ng0);
    t2 = (t0 + 6768);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6928);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 8, 0LL);
    xsi_set_current_line(135, ng0);
    t2 = (t0 + 7088);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7248);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 8, 0LL);
    xsi_set_current_line(136, ng0);
    t2 = (t0 + 7408);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7568);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 8, 0LL);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(115, ng0);

LAB9:    xsi_set_current_line(116, ng0);
    t11 = (t0 + 472);
    t12 = *((char **)t11);
    t11 = (t0 + 5328);
    xsi_vlogvar_wait_assign_value(t11, t12, 0, 0, 3, 0LL);
    xsi_set_current_line(117, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 5648);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(118, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 5968);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(119, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 6288);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(120, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 6608);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 2, 0LL);
    xsi_set_current_line(121, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 8208);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 4, 0LL);
    xsi_set_current_line(122, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 7888);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 23, 0LL);
    xsi_set_current_line(123, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 6928);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 8, 0LL);
    xsi_set_current_line(124, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 7248);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 8, 0LL);
    xsi_set_current_line(125, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 7568);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 8, 0LL);
    goto LAB8;

}


extern void work_m_00000000003693255367_1404956163_init()
{
	static char *pe[] = {(void *)Cont_26_0,(void *)NetDecl_41_1,(void *)NetDecl_42_2,(void *)Cont_49_3,(void *)Always_51_4,(void *)Always_81_5,(void *)Always_114_6};
	xsi_register_didat("work_m_00000000003693255367_1404956163", "isim/sample_checker_tb_isim_beh.exe.sim/work/m_00000000003693255367_1404956163.didat");
	xsi_register_executes(pe);
}
