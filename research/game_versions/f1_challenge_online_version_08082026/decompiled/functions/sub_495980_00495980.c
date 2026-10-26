_DWORD *__thiscall sub_495980(_DWORD *this)
{
  int v1; // ebp
  int v2; // eax
  int v3; // edx
  int v4; // edi
  _DWORD *v5; // ebx
  _DWORD *i; // esi
  _DWORD *j; // esi
  int v9; // [esp+10h] [ebp-4h]

  v1 = this[23];
  v9 = this[24];
  v2 = sub_495970(this);
  v4 = v2;
  if ( !v2 )
    return (_DWORD *)v3;
  v5 = 0;
  for ( i = (_DWORD *)sub_498F60(v2); i; i = (_DWORD *)sub_486320(i) )
  {
    if ( (*(int (__thiscall **)(_DWORD *, int, int))(*i + 48))(i, v1, v9) )
      v5 = i;
  }
  if ( sub_498E40(v4) )
  {
    if ( !v5 )
    {
      for ( j = *(_DWORD **)(sub_498E40(v4) + 68); j; j = (_DWORD *)sub_486320(j) )
      {
        if ( (*(int (__thiscall **)(_DWORD *, int, int))(*j + 48))(j, v1, v9) )
          v5 = j;
      }
    }
  }
  return v5;
}
