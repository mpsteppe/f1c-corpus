void *__thiscall sub_59AF17(void *this, int a2)
{
  void *v2; // ecx
  void *v3; // esi
  _BYTE v5[28]; // [esp+0h] [ebp-1Ch] BYREF
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  VTableConstructor(this);
  CxxThrowException8(v5, &_TI3_AVlength_error_std__);
  v3 = v2;
  ExceptionDestructor((int)&savedregs);
  if ( (v5[4] & 1) != 0 )
    FreeWrapper_7bcf(v3);
  return v3;
}

