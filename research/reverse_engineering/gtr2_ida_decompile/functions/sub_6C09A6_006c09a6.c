int __thiscall sub_6C09A6(_DWORD *this)
{
  unsigned int v2; // esi
  _DWORD *v3; // eax
  void **v4; // edi
  int v5; // eax
  _DWORD *v6; // eax
  void **v7; // ecx
  unsigned int v8; // eax
  _DWORD *v9; // esi
  int result; // eax
  int v11; // edx
  int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  int v15; // eax
  int v16; // eax
  void *v17; // eax
  int v18; // ecx
  int v19; // edx
  int v20; // ecx
  _DWORD *v21; // eax
  int v22; // eax
  int v23; // eax
  void **v24; // edx
  int v25; // esi
  int *v26; // [esp-20h] [ebp-13Ch]
  char v27[64]; // [esp+Ch] [ebp-110h] BYREF
  _DWORD v28[4]; // [esp+4Ch] [ebp-D0h] BYREF
  _DWORD v29[4]; // [esp+5Ch] [ebp-C0h] BYREF
  _DWORD v30[4]; // [esp+6Ch] [ebp-B0h] BYREF
  _DWORD v31[28]; // [esp+7Ch] [ebp-A0h] BYREF
  _DWORD v32[4]; // [esp+ECh] [ebp-30h] BYREF
  void *v33; // [esp+FCh] [ebp-20h]
  int v34[4]; // [esp+100h] [ebp-1Ch] BYREF
  unsigned int v35; // [esp+110h] [ebp-Ch]
  int v36; // [esp+114h] [ebp-8h] BYREF
  void **v37; // [esp+118h] [ebp-4h]

  v36 = 0;
  v34[0] = 0;
  v2 = *(_DWORD *)this[64] & 0xFFFFF;
  v26 = (int *)this[64];
  v34[1] = 1;
  v34[2] = 2;
  v34[3] = 3;
  v35 = v2;
  if ( !sub_6BB35B(this, v26, dword_746790, v27, (unsigned int *)&v36, (int)v28, v34, v2, 1) )
  {
    v3 = (_DWORD *)sub_681186(116);
    if ( v3 )
    {
      v4 = (void **)sub_680CEC(v3);
      v37 = v4;
    }
    else
    {
      v37 = 0;
      v4 = 0;
    }
    if ( v4 )
    {
      v5 = sub_6811D1((char *)v4, v2 & 0xFFFFF | 0x74600000, 2 * v2, v2, 0);
LABEL_13:
      v36 = v5;
      v7 = v4;
      if ( v5 < 0 )
      {
LABEL_66:
        sub_66238F(v7, 1);
        return v36;
      }
      v36 = sub_680D22(v4, this[64]);
      if ( v36 >= 0 )
      {
        v8 = 4 * v2;
        qmemcpy(v4[4], *(const void **)(this[64] + 16), 4 * v2);
        qmemcpy(v37[2], v28, 4 * v2);
        v9 = v29;
LABEL_68:
        v24 = v37;
        qmemcpy((char *)v37[2] + v8, v9, v8);
        v25 = sub_681430((char *)this[64], v24);
        sub_66238F(v37, 1);
        return v25;
      }
LABEL_65:
      v7 = v4;
      goto LABEL_66;
    }
    return -2147024882;
  }
  if ( !sub_6BB35B(this, (int *)this[64], dword_746730, v27, (unsigned int *)&v36, (int)v28, v34, v2, 1) )
  {
    v6 = (_DWORD *)sub_681186(116);
    if ( v6 )
    {
      v4 = (void **)sub_680CEC(v6);
      v37 = v4;
    }
    else
    {
      v37 = 0;
      v4 = 0;
    }
    if ( v4 )
    {
      v5 = sub_6811D1((char *)v4, v2 & 0xFFFFF | 0x74700000, 2 * v2, v2, 0);
      goto LABEL_13;
    }
    return -2147024882;
  }
  result = sub_6BB35B(this, (int *)this[64], dword_7467F0, v27, (unsigned int *)&v36, (int)v28, v34, v2, 1);
  if ( result )
    return result;
  v11 = this[5];
  v12 = *(_DWORD *)(v11 + 4 * v30[0]);
  v36 = *(_DWORD *)(v12 + 60);
  if ( v36 == 0x80000 )
  {
    v13 = 0;
    if ( v2 )
    {
      qmemcpy(v34, v31, 4 * v2);
      do
      {
        v32[v13] = *(_DWORD *)(*(_DWORD *)(v11 + 4 * v30[v13]) + 56);
        ++v13;
      }
      while ( v13 < v35 );
LABEL_26:
      v2 = v35;
    }
  }
  else
  {
    v37 = *(void ***)(v11 + 4 * v31[0]);
    v33 = v37[15];
    if ( v33 == (void *)0x80000 )
    {
      v14 = 0;
      if ( v2 )
      {
        qmemcpy(v34, v30, 4 * v2);
        do
        {
          v32[v14] = *(_DWORD *)(*(_DWORD *)(v11 + 4 * v31[v14]) + 56);
          ++v14;
        }
        while ( v14 < v35 );
        goto LABEL_26;
      }
    }
    else
    {
      if ( v2 != 1 )
        return 1;
      v15 = *(_DWORD *)(v12 + 72);
      if ( v15 == -1
        || (v35 = *(_DWORD *)(this[6] + 4 * v15), (*(_DWORD *)v35 & 0xFFF00000) != 0x10100000)
        || (*(_DWORD *)v35 & 0xFFFFF) != 1
        || v36 )
      {
        v17 = v37[18];
        if ( v17 == (void *)-1 )
          return 1;
        v35 = *(_DWORD *)(this[6] + 4 * (_DWORD)v17);
        if ( (*(_DWORD *)v35 & 0xFFF00000) != 0x10100000 || (*(_DWORD *)v35 & 0xFFFFF) != 1 || v33 )
          return 1;
        v32[0] = **(_DWORD **)(v35 + 8);
        v16 = v30[0];
      }
      else
      {
        v32[0] = **(_DWORD **)(v35 + 8);
        v16 = v31[0];
      }
      v34[0] = v16;
    }
  }
  v37 = 0;
  v35 = 1;
  v36 = 1;
  if ( !v2 )
    goto LABEL_55;
  do
  {
    v18 = this[5];
    v19 = *(_DWORD *)(v18 + 4 * v28[(_DWORD)v37]);
    if ( (*(_DWORD *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v19 + 4)) + 4) & 0x100) == 0 )
    {
      v36 = 0;
      v35 = 0;
    }
    if ( *(double *)(v19 + 32) != 1.0 )
      v36 = 0;
    if ( *(double *)(v19 + 32) != 0.0 )
      v35 = 0;
    v20 = *(_DWORD *)(v18 + 4 * v29[(_DWORD)v37]);
    if ( (*(_DWORD *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v20 + 4)) + 4) & 0x100) == 0 )
    {
      v36 = 0;
      v35 = 0;
    }
    if ( *(double *)(v20 + 32) != 0.0 )
      v36 = 0;
    if ( *(double *)(v20 + 32) != 1.0 )
      v35 = 0;
    v37 = (void **)((char *)v37 + 1);
  }
  while ( (unsigned int)v37 < v2 );
  if ( v36 || v35 )
  {
LABEL_55:
    v21 = (_DWORD *)sub_681186(116);
    if ( v21 )
    {
      v4 = (void **)sub_680CEC(v21);
      v37 = v4;
    }
    else
    {
      v37 = 0;
      v4 = 0;
    }
    if ( v4 )
    {
      v22 = v2 & 0xFFFFF;
      if ( v36 )
        v23 = v22 | 0x74600000;
      else
        v23 = v22 | 0x74700000;
      v36 = sub_6811D1((char *)v4, v23, 2 * v2, v2, 0);
      v7 = v4;
      if ( v36 < 0 )
        goto LABEL_66;
      v36 = sub_680D22(v4, this[64]);
      if ( v36 >= 0 )
      {
        v8 = 4 * v2;
        qmemcpy(v4[4], *(const void **)(this[64] + 16), 4 * v2);
        qmemcpy(v37[2], v34, 4 * v2);
        v9 = v32;
        goto LABEL_68;
      }
      goto LABEL_65;
    }
    return -2147024882;
  }
  return 1;
}
