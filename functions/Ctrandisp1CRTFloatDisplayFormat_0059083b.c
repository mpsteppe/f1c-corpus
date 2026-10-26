int __cdecl Ctrandisp1CRTFloatDisplayFormat(double a1)
{
  double v1; // st7
  int v2; // edx
  __int16 v3; // cx
  __int16 v4; // fps
  int savedregs; // [esp+2D4h] [ebp+0h] BYREF

  v1 = CRTFload(a1);
  Trandisp1(v2, v3, (int)&savedregs, v4, v1);
  return sub_590703((int)&savedregs);
}
