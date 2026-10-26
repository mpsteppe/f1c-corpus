void *__thiscall sub_59A81B(void *this, int a2)
{
  void *v2; // ecx
  void *v3; // esi
  _BYTE v5[28]; // [esp+0h] [ebp-1Ch] BYREF
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  sub_59A854(this);
  CxxThrowException8(v5, &_TI3_AVfailure_ios_base_std__);
  v3 = v2;
  DestructorWithSEHVTableReset((int)&savedregs);
  if ( (v5[4] & 1) != 0 )
    FreeWrapper_7bcf(v3);
  return v3;
}

