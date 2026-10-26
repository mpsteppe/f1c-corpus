_DWORD *__thiscall sub_699E09(int *this, int a2, int a3)
{
  int v3; // edi
  const char **v4; // esi
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  int v9; // eax
  _DWORD *v10; // eax
  _DWORD *v11; // eax
  int v14; // [esp+8h] [ebp-4h] BYREF
  const void *v15; // [esp+14h] [ebp+8h]

  v14 = 0;
  if ( a2 && *(_DWORD *)(a2 + 4) == 3 )
  {
    v3 = a3;
    v4 = (const char **)(a2 + 16);
    v15 = (const void *)(a2 + 16);
    if ( !a3 )
    {
      if ( sub_69974C(this, 1, v4, 0, 0, this[4], 1, &v14, 0) )
        return 0;
      v3 = v14;
    }
    v5 = (_DWORD *)sub_65B229(80);
    if ( v5 )
      v6 = sub_67F5FE(v5, 0, 0, 0, 0, 1, v4);
    else
      v6 = 0;
    if ( v6 )
    {
      if ( *(_DWORD *)(v3 + 36) )
      {
        v7 = (_DWORD *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v3 + 36) + 4))(*(_DWORD *)(v3 + 36));
      }
      else
      {
        v8 = (_DWORD *)sub_65B229(64);
        v7 = v8 ? sub_67F7B5(v8, 6, *(_DWORD *)(v3 + 16), *(_DWORD *)(v3 + 20), v15) : 0;
      }
      v6[8] = v7;
      if ( v7 )
      {
        v9 = sub_67ECC3(*(_DWORD *)(v3 + 32));
        v6[4] = v9;
        if ( a3 )
          sub_694F9B(this, v9, 0);
        v10 = (_DWORD *)sub_65B229(20);
        v11 = v10 ? sub_67ED1B(v10, v6[8], 0, (int)"Value") : 0;
        if ( v11 )
        {
          v6[8] = v11;
          sub_695BDE(this, v6);
          return v6;
        }
      }
    }
    return 0;
  }
  return 0;
}
