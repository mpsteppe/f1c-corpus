int __thiscall sub_680557(_DWORD *this, const void *a2, int ArgList, int *a4)
{
  _WORD *v5; // edi
  int result; // eax
  _DWORD *v7; // edx
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  int v10; // [esp-10h] [ebp-3Ch]
  _DWORD v11[8]; // [esp+Ch] [ebp-20h] BYREF

  qmemcpy(v11, a2, sizeof(v11));
  v5 = (_WORD *)ArgList;
  v11[2] = ArgList + 2;
  v10 = this[1];
  v11[0] = 10;
  if ( sub_69974C(1, v11, 0, 0, v10, 2, &ArgList, 0) )
  {
    *a4 = 0;
    return 0;
  }
  result = sub_680494(*(_DWORD **)(ArgList + 32), a4, 0);
  if ( result >= 0 )
  {
    if ( *v5 == *(_WORD *)"b_" )
    {
      if ( *v7 == 1 )
      {
        v8 = *(_DWORD **)(ArgList + 32);
        if ( v8[1] == 9 && !v8[4] && !v8[5] )
          return 0;
      }
      sub_65DD1F(
        (_DWORD *)(*(_DWORD *)(*this + 4) + 24),
        (int)a2,
        2900,
        "boolean constant register '%s' must be defined as a variable of type bool only",
        v5);
    }
    else
    {
      if ( *v5 != *(_WORD *)"i_" )
        return 0;
      if ( *v7 == 1 )
      {
        v9 = *(_DWORD **)(ArgList + 32);
        if ( v9[1] == 9 && v9[4] == 1 && v9[5] == 4 && v9[7] >= 3u )
          return 0;
      }
      sub_65DD1F(
        (_DWORD *)(*(_DWORD *)(*this + 4) + 24),
        (int)a2,
        2901,
        "integer constant register '%s' must be defined as a variable of type int3 or int4 only",
        v5);
    }
    return -2147467259;
  }
  return result;
}
