int __thiscall sub_42D500(int *this)
{
  int result; // eax
  int v3[3]; // [esp+8h] [ebp-18h] BYREF
  _DWORD v4[3]; // [esp+14h] [ebp-Ch] BYREF

  memset(this + 5858, 0, 0x50u);
  result = *(_DWORD *)(this[20] + 25264);
  if ( result < 0 || this[18] < 0 )
  {
    this[5903] = 1;
    this[5902] = 0;
  }
  else
  {
    sub_4045E0(&flt_628F60, result, v3, v4);
    result = sub_4040B0(&flt_628F60, (float *)v3, 0, this[18], 0.0, 0);
    this[5902] = result;
    if ( result )
      this[5903] = *(_DWORD *)(result + 100);
  }
  return result;
}
