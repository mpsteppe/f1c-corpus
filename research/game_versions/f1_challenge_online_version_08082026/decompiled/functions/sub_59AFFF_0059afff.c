void *__thiscall sub_59AFFF(void *this, int a2)
{
  void *v2; // ecx
  void *v3; // esi
  _BYTE v5[28]; // [esp+0h] [ebp-1Ch] BYREF
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  sub_59B038(this);
  sub_59BFC3(v5, &_TI3_AVout_of_range_std__);
  v3 = v2;
  sub_59AFC2((int)&savedregs);
  if ( (v5[4] & 1) != 0 )
    sub_587BCF(v3);
  return v3;
}
