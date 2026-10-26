int __thiscall sub_4C1830(float *this, int a2)
{
  float v3; // edx
  int result; // eax
  float v5[3]; // [esp+4h] [ebp-18h] BYREF
  _BYTE v6[12]; // [esp+10h] [ebp-Ch] BYREF

  v3 = *this;
  *((_DWORD *)this + 207) = *(char *)(a2 + 8);
  this[208] = *(float *)(a2 + 4);
  result = *(_DWORD *)(LODWORD(v3) + 16584);
  if ( result == 2 || result == 3 )
  {
    result = *((_DWORD *)this + 207);
    if ( result )
    {
      if ( result == 2 )
        result = sub_4C19D0(this);
    }
    else
    {
      result = sub_4C1BA0(this);
    }
  }
  if ( dword_75CBB0 == 7 )
  {
    result = sub_4EED40(*(_DWORD *)this);
    if ( (_BYTE)result )
    {
      if ( *((_DWORD *)this + 207) == 2 && dword_75CBB4 != 8 )
      {
        sub_4F8F10(*(_DWORD *)this, v5, v6);
        sub_404ED0(&flt_628F60, *(_DWORD *)(dword_75AACC + 25264), v5, 0);
        return sub_4BEA40(dword_766238, v5, (int)v6);
      }
    }
  }
  return result;
}
