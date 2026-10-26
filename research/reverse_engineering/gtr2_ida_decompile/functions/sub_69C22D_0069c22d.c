_DWORD *__thiscall sub_69C22D(_DWORD *this, _DWORD *a2, int a3)
{
  _DWORD *v3; // edi
  _DWORD *v4; // eax
  _DWORD *v5; // edi
  _DWORD *v6; // esi
  int v7; // eax
  int v8; // eax
  unsigned int v9; // esi
  _DWORD *v10; // eax
  _DWORD *v11; // eax
  _DWORD *v12; // eax
  _DWORD *v13; // eax
  int v14; // eax
  int v15; // esi
  _DWORD *v16; // eax
  _DWORD *v17; // eax
  int v18; // eax
  int v20; // [esp+Ch] [ebp-Ch]
  _DWORD *v22; // [esp+14h] [ebp-4h]

  if ( !a2 || a2[1] != 13 || !a3 || *(_DWORD *)(a3 + 4) != 13 )
    return 0;
  v3 = (_DWORD *)(a3 + 48);
  v22 = (_DWORD *)(a3 + 48);
  v4 = (_DWORD *)sub_65B229(80);
  v5 = v4 ? sub_67F5FE(v4, 0, 22, 0, 0, 1, v3) : 0;
  if ( !v5 )
    return 0;
  v6 = (_DWORD *)a2[4];
  v20 = *(_DWORD *)(a3 + 16);
  if ( !v6 )
    goto LABEL_41;
  v7 = v6[1];
  if ( v7 != 8 )
  {
    if ( v7 == 9 )
    {
      if ( v6[4] == 1 )
      {
        v10 = (_DWORD *)sub_65B229(36);
        if ( v10 )
          v11 = sub_67F2D4(v10, 0, v6[5], 1, 1, v6[8] & 0x200);
        else
          v11 = 0;
        v5[4] = v11;
        if ( !v11 )
          return 0;
        v9 = v6[7];
        goto LABEL_27;
      }
      if ( v6[4] == 2 )
      {
        v12 = (_DWORD *)sub_65B229(36);
        if ( v12 )
          v13 = sub_67F2D4(v12, 1, v6[5], 1, v6[7], v6[8] & 0x200);
        else
          v13 = 0;
        v5[4] = v13;
        if ( !v13 )
          return 0;
        v9 = v6[6];
        goto LABEL_27;
      }
    }
LABEL_41:
    sub_694B97((int)this, (int)v22, 3021, "array expected");
    return 0;
  }
  if ( v6[4] )
  {
    v8 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v6[4] + 4))(v6[4]);
    v5[4] = v8;
    if ( !v8 )
      return 0;
  }
  v9 = v6[5];
LABEL_27:
  if ( sub_695130(v20) )
  {
    v14 = (*(int (__thiscall **)(_DWORD *))(*a2 + 4))(a2);
    v5[8] = v14;
    if ( v14 )
    {
      if ( sub_695AC0((_DWORD *)a3) )
      {
        if ( sub_69BE34(this, (_DWORD *)a3, &a3) < 0 )
          return 0;
        if ( a3 >= v9 )
        {
          sub_694B97((int)this, (int)v22, 3030, "array index out of bounds");
          a3 = 0;
        }
        v15 = sub_6951CB(this, (_DWORD *)v5[4]);
        v16 = (_DWORD *)sub_65B229(64);
        v17 = v16 ? sub_67F780(v16, 2, a3 * v15, v22) : 0;
        v5[9] = v17;
        if ( !v17 )
          return 0;
        v5[7] = 23;
      }
      else
      {
        v18 = sub_67ECC3(a3);
        v5[9] = v18;
        if ( !v18 )
          return 0;
      }
      sub_695BDE(this, v5);
      return v5;
    }
  }
  else
  {
    sub_694B97((int)this, (int)v22, 3051, "scalar expected");
  }
  return 0;
}
