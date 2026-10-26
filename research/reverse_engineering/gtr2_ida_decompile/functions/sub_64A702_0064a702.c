int __thiscall sub_64A702(int *this, LPCWCH lpWideCharStr, int a3, unsigned int a4)
{
  int *v4; // esi
  int *v5; // edi
  _DWORD *v6; // eax
  int v7; // eax
  int v8; // edi
  char *v9; // eax
  int *v10; // ebx
  int v11; // esi
  int v12; // eax
  char *v13; // eax
  char *v14; // eax
  int v15; // edx
  int v16; // edi
  unsigned int v17; // ebx
  const void *v18; // esi
  _DWORD v20[4]; // [esp+Ch] [ebp-ECh] BYREF
  _BYTE v21[24]; // [esp+1Ch] [ebp-DCh] BYREF
  _BYTE v22[24]; // [esp+34h] [ebp-C4h] BYREF
  int v23; // [esp+4Ch] [ebp-ACh]
  int v24; // [esp+58h] [ebp-A0h]
  int v25; // [esp+5Ch] [ebp-9Ch]
  _DWORD v26[2]; // [esp+60h] [ebp-98h] BYREF
  int v27; // [esp+68h] [ebp-90h]
  int v28; // [esp+6Ch] [ebp-8Ch]
  _DWORD v29[6]; // [esp+70h] [ebp-88h] BYREF
  _BYTE v30[24]; // [esp+88h] [ebp-70h] BYREF
  int v31; // [esp+A0h] [ebp-58h]
  int v32; // [esp+ACh] [ebp-4Ch]
  int v33; // [esp+B0h] [ebp-48h]
  _BYTE v34[12]; // [esp+B4h] [ebp-44h] BYREF
  int v35[5]; // [esp+C0h] [ebp-38h] BYREF
  int v36; // [esp+D4h] [ebp-24h]
  unsigned int v37; // [esp+E0h] [ebp-18h]
  int v38; // [esp+E4h] [ebp-14h]
  int *v39; // [esp+E8h] [ebp-10h]
  void *Block; // [esp+ECh] [ebp-Ch]
  int *v41; // [esp+F0h] [ebp-8h]
  char *Locale; // [esp+F4h] [ebp-4h]
  int v43; // [esp+104h] [ebp+Ch]

  v4 = this;
  v39 = this;
  sub_646222(v35);
  switch ( a3 )
  {
    case 0:
    case 6:
      v5 = (int *)&unk_913B10;
      goto LABEL_8;
    case 1:
      v5 = (int *)&unk_913B6C;
      goto LABEL_8;
    case 2:
      v5 = (int *)&unk_913B60;
      goto LABEL_8;
    case 3:
      v5 = (int *)&unk_913B74;
      goto LABEL_8;
    case 4:
      v5 = (int *)&unk_913B90;
      goto LABEL_8;
    case 7:
    case 8:
      v5 = (int *)&unk_913B84;
LABEL_8:
      v6 = sub_644568(*v4);
      v7 = sub_64460A(v5, v4[2], (int)v6);
      v8 = v7;
      v38 = v7;
      if ( !v7 )
        goto LABEL_45;
      if ( v7 == *v4 )
        goto LABEL_21;
      sub_64AADB(v34);
      v9 = (char *)(sub_644568(v8)[2] >> 3);
      Locale = v9;
      v41 = v4;
      break;
    default:
LABEL_45:
      v11 = -2005530516;
      goto LABEL_46;
  }
  do
  {
    v10 = v41;
    if ( v41 )
    {
      while ( 1 )
      {
        Block = operator new((_DWORD)v9 * v10[3] * v10[5] * v10[4]);
        if ( !Block )
        {
          sub_64AAE5(v34);
          v11 = -2147024882;
          goto LABEL_46;
        }
        v20[0] = v10[1];
        v20[1] = *v10;
        v20[2] = v10[12];
        v20[3] = v10[13];
        qmemcpy(v21, v10 + 6, sizeof(v21));
        qmemcpy(v22, v10 + 6, sizeof(v22));
        v24 = 0;
        v23 = 1;
        v25 = v10[2];
        v26[0] = Block;
        v26[1] = v38;
        v27 = (_DWORD)Locale * v10[3];
        v28 = (_DWORD)Locale * v10[3] * v10[4];
        v29[0] = 0;
        v29[1] = 0;
        v29[2] = v10[3];
        v29[3] = v10[4];
        v29[4] = 0;
        v29[5] = v10[5];
        qmemcpy(v30, v29, sizeof(v30));
        v32 = 0;
        v31 = 1;
        v33 = v10[2];
        v11 = sub_64E329(v26, v20, 524289);
        if ( v11 < 0 )
          break;
        if ( v10[1] && v10[14] )
        {
          j__free((void *)v10[1]);
          v10[1] = 0;
        }
        *v10 = v38;
        v10[1] = (int)Block;
        qmemcpy(v10 + 6, v30, 0x18u);
        v10[12] = v27;
        v10[13] = v28;
        v9 = Locale;
        v10[14] = 1;
        v10 = (int *)v10[19];
        if ( !v10 )
        {
          v4 = v39;
          goto LABEL_19;
        }
      }
      j__free(Block);
      sub_64AAE5(v34);
      goto LABEL_46;
    }
LABEL_19:
    v41 = (int *)v41[20];
  }
  while ( v41 );
  sub_64AAE5(v34);
LABEL_21:
  v12 = sub_646241(v35, lpWideCharStr, a4);
  if ( v12 < 0 )
    goto LABEL_22;
  v13 = setlocale(4, 0);
  v14 = _strdup(v13);
  Locale = v14;
  if ( !v14 || (v4 = v39, strcmp(v14, "C")) )
    setlocale(4, "C");
  switch ( a3 )
  {
    case 0:
    case 6:
      sub_64719B(v4, v15, (int)v35, 1u);
      break;
    case 1:
      sub_647AE9(v4, (int)v35);
      break;
    case 2:
      sub_6481DD(v4, (int)v35);
      break;
    case 3:
      sub_648585(v4, (int)v35);
      break;
    case 4:
      sub_649048(v4, (int)v35);
      break;
    case 5:
      break;
    case 7:
      sub_649862(v4, (int)v35);
      break;
    case 8:
      sub_64970E(v4, (int)v35);
      break;
    default:
      goto LABEL_45;
  }
  v43 = sub_64645D((int)v35);
  if ( Locale )
  {
    if ( strcmp(Locale, "C") )
      setlocale(4, Locale);
    free(Locale);
  }
  v11 = v43;
  if ( v43 >= 0 )
  {
    if ( a4 == 2 )
    {
      v12 = sub_677265(v37, lpWideCharStr);
      if ( v12 < 0 )
      {
LABEL_22:
        v11 = v12;
        goto LABEL_46;
      }
      v16 = *(_DWORD *)lpWideCharStr;
      v17 = v37;
      v18 = (const void *)(*(int (__stdcall **)(int))(*(_DWORD *)v36 + 12))(v36);
      qmemcpy((void *)(*(int (__stdcall **)(int))(*(_DWORD *)v16 + 12))(v16), v18, v17);
    }
    v11 = 0;
  }
LABEL_46:
  sub_6493C0((int)v35);
  return v11;
}
