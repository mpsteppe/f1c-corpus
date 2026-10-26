int __thiscall sub_4B5AA0(_DWORD *this, int a2)
{
  int result; // eax
  int *v3; // eax
  int v4; // esi
  int v5; // esi
  _DWORD *v6; // edx
  int v7; // esi
  int v8; // eax

  result = this[210];
  if ( result )
  {
    v3 = (int *)this[210];
    v4 = *v3;
    if ( a2 == 1 )
      v5 = this[214] + v4;
    else
      v5 = v4 - this[215];
    *v3 = v5;
    v6 = (_DWORD *)this[210];
    v7 = this[213];
    if ( *v6 < v7 || (v7 = this[212], *v6 > v7) )
      *v6 = v7;
    v8 = dword_B71DAC;
    dword_B71DA4 = 0;
    if ( dword_B71DAC > 0 || (v8 = dword_B71DB0, dword_B71DB0 < 0) )
      dword_B71DA4 = v8;
    return (*(int (__thiscall **)(_DWORD *))(*this + 184))(this);
  }
  return result;
}
