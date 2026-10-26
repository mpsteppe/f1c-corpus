int *__thiscall sub_46FB70(_DWORD *this, int a2)
{
  int *result; // eax
  int v3; // esi
  int v4; // esi
  _DWORD *v5; // eax
  int v6; // esi

  result = (int *)this[210];
  if ( result )
  {
    v3 = *result;
    if ( a2 == 1 )
      v4 = this[213] + v3;
    else
      v4 = v3 - this[214];
    *result = v4;
    v5 = (_DWORD *)this[210];
    v6 = this[211];
    if ( *v5 <= v6 )
    {
      if ( *v5 < this[212] )
        *v5 = v6;
      return (int *)(*(int (__thiscall **)(_DWORD *))(*this + 180))(this);
    }
    else
    {
      *v5 = this[212];
      return (int *)(*(int (__thiscall **)(_DWORD *))(*this + 180))(this);
    }
  }
  return result;
}
