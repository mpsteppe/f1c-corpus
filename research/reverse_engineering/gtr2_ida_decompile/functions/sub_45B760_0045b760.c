int __thiscall sub_45B760(int this, _DWORD *a2)
{
  _DWORD *v2; // esi
  int result; // eax
  __int16 v5; // ax
  bool v6; // cc
  int v7; // ebx
  int v8; // ebp
  unsigned __int8 v9; // al
  unsigned __int8 v10; // [esp+21h] [ebp-5h] BYREF
  int v11; // [esp+22h] [ebp-4h]

  v2 = a2;
  if ( (*(int (__thiscall **)(_DWORD *, int, int))(*a2 + 28))(a2, this, 4) != 4
    || (*(int (__thiscall **)(_DWORD *, int, int))(*v2 + 28))(v2, this + 4, 4) != 4
    || (*(int (__thiscall **)(_DWORD *, _DWORD **, int))(*v2 + 28))(v2, &a2, 1) != 1 )
  {
    return -1;
  }
  v5 = (char)a2;
  v6 = (char)a2 <= -3;
  *(_WORD *)(this + 8) = (char)a2;
  if ( v6 )
    return -1;
  v7 = 2;
  if ( v5 >= 2 )
    return -1;
  v8 = 0;
  if ( v5 >= 0 )
  {
    if ( (*(int (__thiscall **)(_DWORD *, unsigned __int8 *, int))(*v2 + 28))(v2, &v10, 1) != 1 )
      return -1;
    v9 = v10;
    *(_BYTE *)(this + 10) = v10 & 0xF;
    *(_BYTE *)(this + 11) = v9 >> 4;
    *(_DWORD *)(this + 12) = v2[28] + 16 * v2[26];
    v2[26] += 2;
    if ( sub_45B760(v2) || sub_45B760(v2) )
      return -1;
  }
  else
  {
    if ( v5 == -1 )
    {
      v7 = 1;
    }
    else if ( v5 != -2 )
    {
      v7 = (int)a2;
    }
    *(_DWORD *)(this + 12) = v2[25] + 96 * v2[23];
    v2[23] += v7;
    if ( v7 > 0 )
    {
      v11 = 0;
      while ( 1 )
      {
        result = sub_45AC60(v2);
        if ( result )
          break;
        ++v8;
        v11 += 96;
        if ( v8 >= v7 )
          return result;
      }
      return -1;
    }
  }
  return 0;
}
