_DWORD *__thiscall sub_6976A0(_DWORD *this, _DWORD *a2, int a3)
{
  _DWORD *v4; // eax
  _DWORD *v5; // ebx
  int v6; // eax
  int v7; // eax
  _DWORD *v8; // esi
  int v10; // ebx
  _DWORD *v11; // eax
  _DWORD *v12; // eax
  int v13; // esi
  _DWORD *v15; // [esp+10h] [ebp-4h]
  int v16; // [esp+1Ch] [ebp+8h]

  while ( a2[1] != 3 )
    a2 = (_DWORD *)a2[2];
  v4 = (_DWORD *)sub_65B229(80);
  if ( v4 )
  {
    v5 = sub_67F5FE(v4, 0, 0, 0, 0, 1, a2 + 4);
    v15 = v5;
  }
  else
  {
    v15 = 0;
    v5 = 0;
  }
  if ( !v5 )
    return 0;
  if ( a3 )
  {
    v6 = (*(int (__thiscall **)(int))(*(_DWORD *)a3 + 4))(a3);
    v5[8] = v6;
    if ( !v6 )
      return 0;
  }
  v7 = v5[8];
  v8 = v5 + 4;
  v16 = v7;
  if ( v7 )
  {
    while ( 1 )
    {
      v10 = *(_DWORD *)(v7 + 8);
      if ( v10 && *(_DWORD *)(v10 + 4) == 13 && *(_DWORD *)(v10 + 16) )
      {
        v11 = (_DWORD *)sub_65B229(20);
        if ( v11 )
          v12 = sub_67ED1B(v11, 0, 0, (int)"Types");
        else
          v12 = 0;
        *v8 = v12;
        if ( !v12 )
          return 0;
        *(_DWORD *)(*v8 + 8) = sub_67ECC3(*(_DWORD *)(v10 + 16));
        v13 = *v8;
        if ( !*(_DWORD *)(v13 + 8) )
          return 0;
        v7 = v16;
        v8 = (_DWORD *)(v13 + 12);
      }
      v16 = *(_DWORD *)(v7 + 12);
      if ( !v16 )
        break;
      v7 = *(_DWORD *)(v7 + 12);
    }
    v5 = v15;
  }
  sub_695BDE(this, v5);
  return v5;
}
