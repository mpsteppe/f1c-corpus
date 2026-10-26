int __stdcall sub_500BC8(int a1, const void *a2, unsigned int a3, int a4)
{
  int v4; // esi
  int v6; // eax
  unsigned int v7; // eax
  int v8; // esi
  int v9; // eax
  int *v10; // edx
  unsigned int v11; // edi
  int v12; // eax
  int *v13; // edx
  int v14; // eax
  char v15[20]; // [esp+8h] [ebp-64h] BYREF
  int v16; // [esp+1Ch] [ebp-50h]
  int v17; // [esp+20h] [ebp-4Ch]
  int v18; // [esp+24h] [ebp-48h]
  _BYTE v19[24]; // [esp+28h] [ebp-44h] BYREF
  int v20; // [esp+40h] [ebp-2Ch]
  int v21; // [esp+44h] [ebp-28h]
  unsigned int v22; // [esp+48h] [ebp-24h]
  unsigned int v23; // [esp+4Ch] [ebp-20h]
  int v24; // [esp+50h] [ebp-1Ch]
  int v25; // [esp+54h] [ebp-18h]
  unsigned int v26; // [esp+58h] [ebp-14h]
  int v27; // [esp+5Ch] [ebp-10h]
  int v28; // [esp+60h] [ebp-Ch] BYREF
  int v29; // [esp+64h] [ebp-8h] BYREF
  int v30; // [esp+68h] [ebp-4h] BYREF

  v4 = a1;
  if ( !a1 )
    return -2005530516;
  v27 = (*(int (__stdcall **)(int))(*(_DWORD *)a1 + 40))(a1);
  if ( v27 != 3 && (unsigned int)(v27 - 4) >= 2 )
    return -2005530516;
  v25 = v4;
  if ( a4 != -1 )
    goto LABEL_16;
  if ( v27 == 3 )
  {
    (*(void (__stdcall **)(int, _DWORD, _BYTE *))(*(_DWORD *)v25 + 56))(v25, 0, v19);
    if ( ((v20 - 1) & v20) == 0 && ((v21 - 1) & v21) == 0 )
      goto LABEL_26;
    a4 = 0;
    goto LABEL_25;
  }
  if ( v27 == 4 )
  {
    (*(void (__stdcall **)(int, _DWORD, char *))(*(_DWORD *)v25 + 56))(v25, 0, v15);
    if ( ((v16 - 1) & v16) != 0 || ((v17 - 1) & v17) != 0 )
      goto LABEL_15;
    v6 = v18;
LABEL_14:
    if ( ((v6 - 1) & v6) != 0 )
      goto LABEL_15;
LABEL_26:
    a4 = 5;
    goto LABEL_16;
  }
  if ( v27 != 5 )
  {
LABEL_25:
    if ( !a4 )
      goto LABEL_15;
    goto LABEL_26;
  }
  (*(void (__stdcall **)(int, _DWORD, _BYTE *))(*(_DWORD *)v25 + 56))(v25, 0, v19);
  if ( ((v20 - 1) & v20) == 0 )
  {
    v6 = v21;
    goto LABEL_14;
  }
LABEL_15:
  a4 = 524292;
LABEL_16:
  if ( v27 == 5 )
    BYTE2(a4) |= 7u;
  v7 = (*(int (__stdcall **)(int))(*(_DWORD *)v4 + 52))(v4);
  v23 = v7;
  if ( a3 == -1 )
    a3 = 0;
  if ( a3 >= v7 )
    return -2005530516;
  a1 = 0;
  v29 = 0;
  v30 = 0;
  v28 = 0;
  v22 = v27 != 5 ? 1 : 6;
  if ( (unsigned __int8)a4 == 2 || (v24 = 0, (unsigned __int8)a4 == 5) )
    v24 = 1;
  v26 = 0;
  v8 = a4;
  do
  {
    switch ( v27 )
    {
      case 3:
        v10 = &a1;
        goto LABEL_37;
      case 4:
        v10 = &v29;
LABEL_37:
        v9 = (*(int (__stdcall **)(int, unsigned int, int *))(*(_DWORD *)v25 + 60))(v25, a3, v10);
        goto LABEL_38;
      case 5:
        v9 = (*(int (__stdcall **)(int, unsigned int, unsigned int, int *))(*(_DWORD *)v25 + 60))(v25, v26, a3, &a1);
LABEL_38:
        v8 = v9;
        break;
    }
    if ( v8 < 0 )
      goto LABEL_75;
    v11 = a3;
    while ( ++v11 < v23 )
    {
      if ( v27 == 3 )
      {
        v13 = &v30;
        goto LABEL_47;
      }
      if ( v27 == 4 )
      {
        v13 = &v28;
LABEL_47:
        v12 = (*(int (__stdcall **)(int, unsigned int, int *))(*(_DWORD *)v25 + 60))(v25, v11, v13);
        goto LABEL_48;
      }
      if ( v27 != 5 )
        goto LABEL_49;
      v12 = (*(int (__stdcall **)(int, unsigned int, unsigned int, int *))(*(_DWORD *)v25 + 60))(v25, v26, v11, &v30);
LABEL_48:
      v8 = v12;
LABEL_49:
      if ( v8 < 0 )
        goto LABEL_75;
      switch ( v27 )
      {
        case 3:
LABEL_53:
          v14 = sub_50099C(v30, a2, 0, a1, a2, 0, a4, 0);
LABEL_54:
          v8 = v14;
          break;
        case 4:
          v14 = sub_500B42(v28, (int)a2, 0, v29, (int)a2, 0, a4, 0);
          goto LABEL_54;
        case 5:
          goto LABEL_53;
      }
      if ( v8 < 0 )
        goto LABEL_75;
      if ( v24 )
      {
        if ( a1 )
        {
          (*(void (__stdcall **)(int))(*(_DWORD *)a1 + 8))(a1);
          a1 = 0;
        }
        if ( v29 )
          (*(void (__stdcall **)(int))(*(_DWORD *)v29 + 8))(v29);
        a1 = v30;
        v30 = 0;
        v29 = v28;
LABEL_67:
        v28 = 0;
      }
      else
      {
        if ( v30 )
        {
          (*(void (__stdcall **)(int))(*(_DWORD *)v30 + 8))(v30);
          v30 = 0;
        }
        if ( v28 )
        {
          (*(void (__stdcall **)(int))(*(_DWORD *)v28 + 8))(v28);
          goto LABEL_67;
        }
      }
    }
    if ( a1 )
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)a1 + 8))(a1);
      a1 = 0;
    }
    if ( v29 )
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)v29 + 8))(v29);
      v29 = 0;
    }
    ++v26;
  }
  while ( v26 < v22 );
  v8 = 0;
LABEL_75:
  if ( a1 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)a1 + 8))(a1);
    a1 = 0;
  }
  if ( v29 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)v29 + 8))(v29);
    v29 = 0;
  }
  if ( v30 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)v30 + 8))(v30);
    v30 = 0;
  }
  if ( v28 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v28 + 8))(v28);
  return v8;
}
