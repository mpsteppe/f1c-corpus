int __usercall sub_5906BB@<eax>(double a1@<st1>, double a2, double a3)
{
  double v3; // st7
  int v4; // edx
  __int16 v5; // fps
  int savedregs; // [esp+2D4h] [ebp+0h] BYREF

  CRTFload(a2);
  v3 = CRTFload(a3);
  sub_58DAD7(v4, (int)&savedregs, v5, a1, v3);
  return sub_590703((int)&savedregs);
}
