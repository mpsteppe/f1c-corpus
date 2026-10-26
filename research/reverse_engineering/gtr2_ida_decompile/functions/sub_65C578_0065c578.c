int __thiscall sub_65C578(int this, void **a2)
{
  _DWORD *v3; // eax
  int v4; // edi
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  int v7; // eax
  const char **v8; // ecx
  _DWORD *v9; // eax
  int v10; // eax
  void **v11; // esi
  char *v12; // edi
  void *v14; // edx
  unsigned int v15; // eax
  _BYTE v16[56]; // [esp+Ch] [ebp-64h] BYREF
  _DWORD v17[8]; // [esp+44h] [ebp-2Ch] BYREF
  int v18; // [esp+64h] [ebp-Ch]
  char *v19; // [esp+68h] [ebp-8h]
  void *Block; // [esp+6Ch] [ebp-4h]

  v18 = *(_DWORD *)(this + 620);
  v19 = (char *)this;
  memset(v17, 0, sizeof(v17));
  v3 = operator new(0x14u);
  if ( v3 )
  {
    *v3 = "DIRECT3D";
    v3[1] = 0;
    v3[2] = 0;
    v3[3] = 0;
    v3[4] = 0;
    Block = v3;
  }
  else
  {
    Block = 0;
  }
  if ( !Block )
    goto LABEL_28;
  v4 = sub_65B478((char *)this, (const char **)Block);
  if ( v4 < 0 )
    goto LABEL_34;
  v5 = operator new(0x14u);
  if ( v5 )
  {
    *v5 = "D3DX";
    v5[1] = 0;
    v5[2] = 0;
    v5[3] = 0;
    v5[4] = 0;
    Block = v5;
  }
  else
  {
    Block = 0;
  }
  if ( !Block )
    goto LABEL_28;
  v4 = sub_65B478((char *)this, (const char **)Block);
  if ( v4 < 0 )
    goto LABEL_34;
  v17[0] = 2;
  v17[2] = 2304;
  v6 = operator new(0x14u);
  if ( v6 )
  {
    *v6 = "DIRECT3D_VERSION";
    v6[1] = 0;
    v6[2] = 0;
    v6[3] = 0;
    v6[4] = 0;
    Block = v6;
  }
  else
  {
    Block = 0;
  }
  if ( !Block )
    goto LABEL_28;
  v7 = sub_65B229(48) ? sub_67EF22(v17) : 0;
  v8 = (const char **)Block;
  *((_DWORD *)Block + 2) = v7;
  if ( !v7 )
    goto LABEL_28;
  v4 = sub_65B478(v19, v8);
  if ( v4 < 0 )
    goto LABEL_34;
  v17[0] = 2;
  v17[2] = 2306;
  v9 = operator new(0x14u);
  if ( v9 )
  {
    *v9 = "D3DX_VERSION";
    v9[1] = 0;
    v9[2] = 0;
    v9[3] = 0;
    v9[4] = 0;
    Block = v9;
  }
  else
  {
    Block = 0;
  }
  if ( !Block || (!sub_65B229(48) ? (v10 = 0) : (v10 = sub_67EF22(v17)), (*((_DWORD *)Block + 2) = v10) == 0) )
  {
LABEL_28:
    v4 = -2147024882;
    goto LABEL_34;
  }
  v4 = sub_65B478(v19, (const char **)Block);
  if ( v4 >= 0 )
  {
    v11 = a2;
    Block = 0;
    if ( !a2 )
    {
LABEL_33:
      v4 = 0;
      goto LABEL_34;
    }
    sub_65D7E5(v16);
    v12 = v19;
    *((_DWORD *)v19 + 155) = v16;
    if ( !*a2 )
    {
LABEL_32:
      nullsub_9(v16);
      goto LABEL_33;
    }
    while ( 1 )
    {
      v14 = v11[1];
      v15 = v14 ? strlen((const char *)v11[1]) : 0;
      v4 = sub_65D800(v14, v15, 0, 0, v12, v12 + 24);
      if ( v4 < 0 )
        break;
      v4 = sub_65C2D3((int)v19, *v11, 0);
      if ( v4 < 0 )
        break;
      v11 += 2;
      if ( !*v11 )
        goto LABEL_32;
      v12 = v19;
    }
    nullsub_9(v16);
  }
LABEL_34:
  *((_DWORD *)v19 + 155) = v18;
  if ( Block )
    sub_65B2FE(Block, 1);
  return v4;
}
