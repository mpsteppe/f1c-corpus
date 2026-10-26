void __usercall Cintrindisp1(int a1@<edx>, __int16 a2@<cx>, __int16 a3@<fpstat>, double a4@<st0>)
{
  int savedregs; // [esp+2D4h] [ebp+0h] BYREF

  Trandisp1(a1, a2, (int)&savedregs, a3, a4);
  sub_59070A((double *)&savedregs, a4);
}
