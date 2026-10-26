_DWORD *__thiscall sub_69C457(char *this, int a2, _DWORD *a3, _DWORD *a4, int a5)
{
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  unsigned int v9; // edi
  _DWORD *v10; // esi
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int *v15; // eax
  int *v16; // ebx
  int v17; // edx
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  _DWORD *v23; // edx
  _DWORD *v24; // eax
  _DWORD *v25; // edx
  _DWORD *v26; // eax
  _DWORD *v27; // eax
  int v28; // [esp-8h] [ebp-24h]
  int *v29; // [esp+8h] [ebp-14h] BYREF
  int v30; // [esp+Ch] [ebp-10h]
  int *v31; // [esp+10h] [ebp-Ch] BYREF
  int v32; // [esp+14h] [ebp-8h]
  int v33; // [esp+18h] [ebp-4h]
  const void *v34; // [esp+28h] [ebp+Ch]

  v33 = (int)this;
  v30 = 0;
  v29 = 0;
  v32 = 0;
  v31 = 0;
  if ( a3 && a3[1] != 13 )
    return 0;
  if ( a4 )
  {
    if ( a4[1] != 13 )
      return 0;
    v7 = a4 + 12;
    goto LABEL_7;
  }
  if ( a3 )
  {
    v7 = a3 + 12;
LABEL_7:
    v34 = v7;
    goto LABEL_11;
  }
  v34 = this + 32;
LABEL_11:
  v8 = (_DWORD *)sub_65B229(80);
  v9 = a2;
  if ( v8 )
    v10 = sub_67F5FE(v8, 0, a2, 0, 0, a5, v34);
  else
    v10 = 0;
  if ( !v10 )
    return 0;
  if ( a3 )
  {
    v11 = (*(int (__thiscall **)(_DWORD *))(*a3 + 4))(a3);
    v10[8] = v11;
    if ( !v11 )
      return 0;
  }
  if ( a2 != 28 && a2 != 29 && a2 != 30 && a2 != 31 && a2 != 32 && a2 != 33 && a2 != 34 )
  {
    if ( a4 )
    {
      v12 = (*(int (__thiscall **)(_DWORD *))(*a4 + 4))(a4);
      v10[9] = v12;
      if ( !v12 )
        return 0;
    }
LABEL_44:
    v14 = v10[8];
    if ( v14 )
    {
      v15 = *(int **)(v14 + 16);
      v30 = (int)v15;
      v29 = v15;
    }
    else
    {
      v15 = (int *)v30;
    }
    if ( v9 >= 2
      && v9 != 20
      && v9 != 21
      && v9 != 16
      && v9 != 17
      && (!v15 || *(_DWORD *)(v30 + 4) != 9 || !sub_695154((_DWORD *)v33, (_DWORD *)v30)) )
    {
      sub_694B97(v33, (int)v34, 3022, "scalar, vector, or matrix expected");
      return 0;
    }
    if ( v9 == 2 || v9 == 3 || v9 == 20 || v9 == 21 )
    {
      v16 = (int *)v30;
      if ( sub_6950BD((_DWORD *)v33, (_DWORD *)v30) || sub_695A44((_DWORD *)v10[8]) )
      {
        sub_694B97(v33, (int)v34, 3025, "l-value specifies const object");
        return 0;
      }
      v18 = *(_DWORD *)(*(_DWORD *)(v17 + 16) + 16);
      if ( (v18 == 3 || v18 == 4) && !sub_695154((_DWORD *)v33, (_DWORD *)v30) )
      {
        sub_694B97(v33, (int)v34, 3065, "object assignments are not allowed inside functions");
        return 0;
      }
    }
    else
    {
      v16 = (int *)v30;
    }
    v19 = v10[9];
    if ( v19 )
    {
      v32 = *(_DWORD *)(v19 + 16);
      v31 = (int *)v32;
    }
    if ( v9 == 20 || v9 == 21 )
    {
      if ( !sub_696CB7((void *)v33, v16, (int *)v32, 0) )
      {
        sub_696FEF((void *)v33, (int)v34, 0, v16, (int *)v32, 0);
        return 0;
      }
      if ( v16 )
      {
        v22 = (*(int (__thiscall **)(int *))(*v16 + 4))(v16);
        v10[4] = v22;
        if ( !v22 )
          return 0;
      }
      v31 = v16;
    }
    else if ( v9 )
    {
      if ( v9 != 4 && v9 != 5 && v9 != 6 && v9 != 2 && v9 != 3 && v9 != 1 )
      {
        if ( v9 == 12 || v9 == 13 || v9 == 14 || v9 == 15 || v9 == 16 || v9 == 17 || v9 == 18 || v9 == 19 )
        {
          if ( sub_697320((_DWORD *)v33, v16, (int *)v32, &v29, &v31, v10 + 4) >= 0 )
          {
            *(_DWORD *)(v10[4] + 20) = 0;
            goto LABEL_102;
          }
        }
        else if ( sub_697320((_DWORD *)v33, v16, (int *)v32, &v29, &v31, v10 + 4) >= 0 )
        {
          goto LABEL_102;
        }
        sub_694B97(v33, (int)v34, 3020, "type mismatch");
        return 0;
      }
      if ( v16 )
      {
        v21 = (*(int (__thiscall **)(int *))(*v16 + 4))(v16);
        v10[4] = v21;
        if ( !v21 )
          return 0;
      }
      sub_694F9B((_DWORD *)v33, v10[4], 1);
    }
    else if ( v16 )
    {
      v20 = (*(int (__thiscall **)(int *))(*v16 + 4))(v16);
      v10[4] = v20;
      if ( !v20 )
        return 0;
    }
LABEL_102:
    if ( v10[8] && v16 != v29 && !sub_695259(v16, v29) )
    {
      v24 = sub_699F10((int *)v33, (int)v29, v23, 0, 0);
      if ( !v24 )
        return 0;
      v10[8] = v24;
    }
    if ( v10[9] && (int *)v32 != v31 && !sub_695259((_DWORD *)v32, v31) )
    {
      v26 = sub_699F10((int *)v33, (int)v31, v25, 0, 0);
      if ( !v26 )
        return 0;
      v10[9] = v26;
    }
    if ( !v10[4] )
      v10[4] = 0;
    sub_695BDE((_DWORD *)v33, v10);
    if ( sub_695AC0(v10) )
    {
      v27 = sub_69BD09((_DWORD *)v33, v10);
      if ( v27 )
        return v27;
    }
    return v10;
  }
  switch ( a2 )
  {
    case 28:
      v28 = 7;
      goto LABEL_41;
    case 29:
      v28 = 8;
      goto LABEL_41;
    case 30:
      v28 = 9;
      goto LABEL_41;
    case 31:
      v28 = 10;
      goto LABEL_41;
    case 32:
      v28 = 11;
LABEL_41:
      v9 = 21;
      goto LABEL_42;
  }
  v9 = 1;
  if ( a2 == 33 )
    v28 = 2;
  else
    v28 = 3;
LABEL_42:
  v13 = sub_69C457(v28, a3, a4, 0);
  v10[9] = v13;
  if ( v13 )
  {
    v10[7] = v9;
    goto LABEL_44;
  }
  return 0;
}
