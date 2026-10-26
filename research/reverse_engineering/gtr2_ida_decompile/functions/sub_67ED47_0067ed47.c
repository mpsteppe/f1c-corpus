BOOL __thiscall sub_67ED47(_DWORD *this, int a2)
{
  _DWORD *v2; // esi
  BOOL result; // eax
  int v4; // ecx
  int v5; // edi

  v2 = (_DWORD *)a2;
  result = sub_67EC87(this, a2);
  if ( result )
  {
    v5 = v4;
    if ( v4 )
    {
      while ( *(_DWORD *)(v5 + 4) == 1 )
      {
        if ( !v2 || v2[1] != 1 || !sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(v5 + 8), v2[2]) )
          return 0;
        v5 = *(_DWORD *)(v5 + 12);
        v2 = (_DWORD *)v2[3];
        if ( !v5 )
          return 1;
      }
      if ( !sub_67ECA2((int (__thiscall ***)(_DWORD, int))v5, (int)v2) )
        return 0;
    }
    return 1;
  }
  return result;
}
