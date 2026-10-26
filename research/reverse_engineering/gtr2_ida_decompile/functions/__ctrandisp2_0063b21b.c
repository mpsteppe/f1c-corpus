int __usercall _ctrandisp2@<eax>(double a1@<st1>, double a2@<st0>, double a3, double a4)
{
  int v4; // edx
  __int16 v5; // fps
  int savedregs; // [esp+2D4h] [ebp+0h] BYREF

  _fload(a3);
  _fload(a4);
  _trandisp2(v4, (int)&savedregs, v5, a1, a2);
  return ctranexit();
}
