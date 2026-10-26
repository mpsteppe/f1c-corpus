int __thiscall sub_6BFAB9(int this)
{
  int v2; // eax
  unsigned int v3; // ecx
  int v4; // ecx
  _DWORD *v5; // eax
  int v6; // edx
  _DWORD *v8; // esi
  _DWORD *v9; // ebx
  _DWORD *v10; // edx
  unsigned int v11; // edx
  _DWORD *v12; // eax
  char *v13; // ebx
  _DWORD *v14; // eax
  int v15; // edi
  int v16; // ecx
  char *v17; // esi
  char *v18; // edi
  char v19; // al
  unsigned int v20; // ecx
  char *v21; // edi
  char *v22; // esi
  _DWORD *v23; // eax
  unsigned int v24; // ecx
  int v25; // ecx
  int v26; // edx
  int v27; // edi
  int v28; // edx
  int v29; // ecx
  int *v30; // esi
  int v31; // edx
  void *v32; // ecx
  int v33; // [esp+4h] [ebp-1Ch]
  int v34; // [esp+8h] [ebp-18h]
  _DWORD *v35; // [esp+Ch] [ebp-14h]
  _DWORD *v36; // [esp+10h] [ebp-10h]
  int v37; // [esp+14h] [ebp-Ch]
  unsigned int v38; // [esp+14h] [ebp-Ch]
  unsigned int v39; // [esp+18h] [ebp-8h]
  unsigned int v40; // [esp+18h] [ebp-8h]
  int v41; // [esp+1Ch] [ebp-4h]
  unsigned int v42; // [esp+1Ch] [ebp-4h]

  v2 = *(_DWORD *)(this + 256);
  v3 = *(_DWORD *)v2 & 0xFFF00000;
  v36 = (_DWORD *)this;
  if ( v3 != 1342177280 && v3 != 273678336 && v3 != 274726912 && v3 != 271581184 && v3 != 275775488 )
    return 1;
  if ( *(_DWORD *)(v2 + 12) != 1 )
    return 1;
  v4 = *(_DWORD *)(this + 20);
  v41 = 0;
  v34 = **(_DWORD **)(v2 + 16);
  v5 = *(_DWORD **)(v4 + 4 * v34);
  v6 = v5[21];
  if ( v6 == -1 )
    return 1;
  v39 = 0;
  v8 = *(_DWORD **)(*(_DWORD *)(this + 24) + 4 * v6);
  v35 = v8;
  if ( v8[3] )
  {
    v9 = (_DWORD *)v8[4];
    v37 = v8[3];
    do
    {
      if ( *(_DWORD *)(*(_DWORD *)(v4 + 4 * *v9) + 76) > v39 )
        v39 = *(_DWORD *)(*(_DWORD *)(v4 + 4 * *v9) + 76);
      ++v9;
      --v37;
    }
    while ( v37 );
  }
  v10 = *(_DWORD **)(v4 + 4 * *(_DWORD *)v8[4]);
  if ( v10[1] == v5[1] && v10[3] == v5[3] && v10[2] == v5[2] && v5[21] != v5[22] )
    v41 = 1;
  if ( v39 > *(_DWORD *)(this + 252)
    || !v41 && v5[21] != v5[22]
    || (*(_BYTE *)(this + 108) & 1) != 0
    && (!v8[3] || *(_DWORD *)(*(_DWORD *)(v4 + 4 * *(_DWORD *)v8[4]) + 4) == *(_DWORD *)(this + 132))
    || (*v8 & 0xFFF00000) != 0x10000000
    || (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * v10[1]) + 4) & 4) != 0 )
  {
    return 1;
  }
  v11 = 0;
  if ( v8[1] )
  {
    v12 = (_DWORD *)v8[2];
    while ( *v12 == v34 )
    {
      ++v11;
      ++v12;
      if ( v11 >= v8[1] )
        goto LABEL_31;
    }
    return 1;
  }
LABEL_31:
  v13 = 0;
  if ( *(_DWORD *)(*(_DWORD *)(v4 + 4 * *(_DWORD *)v8[2]) + 60) )
    return 1;
  v14 = (_DWORD *)sub_681186(116);
  if ( v14 )
    v13 = (char *)sub_680CEC(v14);
  if ( !v13 )
    return -2147024882;
  v15 = sub_6811D1(v13, **(_DWORD **)(this + 256), *(_DWORD *)(*(_DWORD *)(this + 256) + 4), v8[3] + (v41 != 0), 1);
  if ( v15 >= 0 )
  {
    v16 = v8[3];
    v17 = (char *)v8[4];
    v18 = (char *)*((_DWORD *)v13 + 4);
    v19 = 4 * v16;
    v20 = (unsigned int)(4 * v16) >> 2;
    qmemcpy(v18, v17, 4 * v20);
    v22 = &v17[4 * v20];
    v21 = &v18[4 * v20];
    LOBYTE(v20) = v19;
    v23 = v36;
    qmemcpy(v21, v22, v20 & 3);
    if ( v41 )
      *(_DWORD *)(*((_DWORD *)v13 + 4) + 4 * v35[3]) = **(_DWORD **)(v36[64] + 16);
    v24 = *((_DWORD *)v13 + 3);
    v42 = 0;
    if ( v24 )
    {
      v38 = 1;
      while ( 1 )
      {
        v40 = v38;
        if ( v38 < v24 )
          break;
LABEL_48:
        ++v42;
        v24 = *((_DWORD *)v13 + 3);
        ++v38;
        if ( v42 >= v24 )
          goto LABEL_49;
      }
      while ( 1 )
      {
        v25 = *((_DWORD *)v13 + 4);
        v26 = v36[5];
        v27 = *(_DWORD *)(v26 + 4 * *(_DWORD *)(v25 + 4 * v42));
        v28 = *(_DWORD *)(v26 + 4 * *(_DWORD *)(4 * v40 + v25));
        v33 = v28;
        if ( *(_DWORD *)(v27 + 16) > *(_DWORD *)(v28 + 16) )
        {
          v29 = *((_DWORD *)v13 + 4);
          v30 = (int *)(v29 + 4 * v40);
          v31 = *v30;
          *v30 = *(_DWORD *)(v29 + 4 * v42);
          *(_DWORD *)(*((_DWORD *)v13 + 4) + 4 * v42) = v31;
          v28 = v33;
        }
        if ( *(_DWORD *)(v27 + 16) == *(_DWORD *)(v28 + 16) )
          break;
        if ( ++v40 >= *((_DWORD *)v13 + 3) )
          goto LABEL_48;
      }
      sub_686791((int)v36, *(_DWORD *)(v36[64] + 60), 4822, "internal error: multiple write to same output");
      sub_66238F(v35, 1);
      return -2147467259;
    }
    else
    {
LABEL_49:
      qmemcpy(*((void **)v13 + 2), *(const void **)(v36[64] + 8), 4 * *(_DWORD *)(v36[64] + 4));
      v32 = *(void **)(v36[6] + 4 * v36[63]);
      if ( v32 )
      {
        sub_66238F(v32, 1);
        v23 = v36;
      }
      *(_DWORD *)(v23[6] + 4 * v23[63]) = v13;
      *v35 = 0;
      return 0;
    }
  }
  else
  {
    sub_66238F(v13, 1);
    return v15;
  }
}
