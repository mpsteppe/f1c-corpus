int __thiscall sub_6BFDA7(int this)
{
  _DWORD *v1; // esi
  unsigned int v2; // ebx
  _DWORD *v3; // eax
  char *v4; // edi
  int v5; // eax
  _DWORD *v6; // eax
  char *v7; // ecx
  unsigned int v8; // eax
  unsigned int v9; // ebx
  unsigned int v10; // eax
  _DWORD *v11; // esi
  int result; // eax
  int v13; // edx
  unsigned int v14; // eax
  unsigned int v15; // eax
  int v16; // edi
  int v17; // ecx
  int v18; // ecx
  _DWORD *v19; // eax
  int v20; // eax
  unsigned int v21; // eax
  char *v22; // edi
  char *v23; // edi
  _DWORD *v24; // esi
  char v25; // cl
  _DWORD *v26; // eax
  int v27; // esi
  int *v28; // [esp-20h] [ebp-13Ch]
  char v29[64]; // [esp+Ch] [ebp-110h] BYREF
  _DWORD v30[4]; // [esp+4Ch] [ebp-D0h] BYREF
  _DWORD v31[4]; // [esp+5Ch] [ebp-C0h] BYREF
  _DWORD v32[4]; // [esp+6Ch] [ebp-B0h] BYREF
  _DWORD v33[28]; // [esp+7Ch] [ebp-A0h] BYREF
  _DWORD v34[4]; // [esp+ECh] [ebp-30h] BYREF
  int v35[4]; // [esp+FCh] [ebp-20h] BYREF
  _DWORD *v36; // [esp+10Ch] [ebp-10h]
  unsigned int v37; // [esp+110h] [ebp-Ch] BYREF
  unsigned int v38; // [esp+114h] [ebp-8h]
  int v39; // [esp+118h] [ebp-4h]

  v37 = 0;
  v35[0] = 0;
  v1 = (_DWORD *)this;
  v2 = **(_DWORD **)(this + 256) & 0xFFFFF;
  v28 = *(int **)(this + 256);
  v36 = (_DWORD *)this;
  v35[1] = 1;
  v35[2] = 2;
  v35[3] = 3;
  if ( !sub_6BB35B((_DWORD *)this, v28, dword_7462B0, v29, &v37, (int)v30, v35, v2, 1) )
  {
    v3 = (_DWORD *)sub_681186(116);
    if ( v3 )
    {
      v4 = (char *)sub_680CEC(v3);
      v38 = (unsigned int)v4;
    }
    else
    {
      v38 = 0;
      v4 = 0;
    }
    if ( v4 )
    {
      v5 = sub_6811D1(v4, v2 & 0xFFFFF | 0x73600000, 2 * v2, v2, 0);
LABEL_13:
      v39 = v5;
      v7 = v4;
      if ( v5 < 0 )
      {
LABEL_56:
        sub_66238F(v7, 1);
        return v39;
      }
      v39 = sub_680D22(v4, v1[64]);
      if ( v39 >= 0 )
      {
        v8 = v2;
        v9 = v38;
        v10 = 4 * v8;
        qmemcpy(*((void **)v4 + 4), *(const void **)(v1[64] + 16), v10);
        qmemcpy(*(void **)(v9 + 8), v30, v10);
        v11 = v31;
LABEL_58:
        v22 = (char *)(v10 + *(_DWORD *)(v9 + 8));
        qmemcpy(v22, v11, 4 * (v10 >> 2));
        v24 = &v11[v10 >> 2];
        v23 = &v22[4 * (v10 >> 2)];
        v25 = v10;
        v26 = v36;
        qmemcpy(v23, v24, v25 & 3);
        v27 = sub_681430((char *)v26[64], (_DWORD *)v9);
        sub_66238F((void *)v9, 1);
        return v27;
      }
LABEL_55:
      v7 = v4;
      goto LABEL_56;
    }
    return -2147024882;
  }
  if ( !sub_6BB35B(v1, (int *)v1[64], dword_746310, v29, &v37, (int)v30, v35, v2, 1) )
  {
    v6 = (_DWORD *)sub_681186(116);
    if ( v6 )
    {
      v4 = (char *)sub_680CEC(v6);
      v38 = (unsigned int)v4;
    }
    else
    {
      v38 = 0;
      v4 = 0;
    }
    if ( v4 )
    {
      v5 = sub_6811D1(v4, v2 & 0xFFFFF | 0x73500000, 2 * v2, v2, 0);
      goto LABEL_13;
    }
    return -2147024882;
  }
  result = sub_6BB35B(v1, (int *)v1[64], dword_746370, v29, &v37, (int)v30, v35, v2, 1);
  if ( result )
    return result;
  v13 = v1[5];
  if ( *(_DWORD *)(*(_DWORD *)(v13 + 4 * v32[0]) + 60) == 0x80000 )
  {
    v14 = 0;
    if ( v2 )
    {
      qmemcpy(v35, v33, 4 * v2);
      do
      {
        v34[v14] = *(_DWORD *)(*(_DWORD *)(v13 + 4 * v32[v14]) + 56);
        ++v14;
      }
      while ( v14 < v2 );
LABEL_26:
      v1 = v36;
      goto LABEL_27;
    }
    goto LABEL_27;
  }
  if ( *(_DWORD *)(*(_DWORD *)(v13 + 4 * v33[0]) + 60) == 0x80000 )
  {
    v15 = 0;
    if ( v2 )
    {
      qmemcpy(v35, v32, 4 * v2);
      do
      {
        v34[v15] = *(_DWORD *)(*(_DWORD *)(v13 + 4 * v33[v15]) + 56);
        ++v15;
      }
      while ( v15 < v2 );
      goto LABEL_26;
    }
LABEL_27:
    v38 = 0;
    v37 = 1;
    v39 = 1;
    if ( v2 )
    {
      v16 = v1[4];
      do
      {
        v17 = *(_DWORD *)(v13 + 4 * v30[v38]);
        if ( (*(_BYTE *)(*(_DWORD *)(v16 + 4 * *(_DWORD *)(v17 + 4)) + 5) & 1) == 0 )
        {
          v39 = 0;
          v37 = 0;
        }
        if ( *(double *)(v17 + 32) != 0.0 )
          v39 = 0;
        if ( *(double *)(v17 + 32) != 1.0 )
          v37 = 0;
        v18 = *(_DWORD *)(v13 + 4 * v31[v38]);
        if ( (*(_BYTE *)(*(_DWORD *)(v16 + 4 * *(_DWORD *)(v18 + 4)) + 5) & 1) == 0 )
        {
          v39 = 0;
          v37 = 0;
        }
        if ( *(double *)(v18 + 32) != 1.0 )
          v39 = 0;
        if ( *(double *)(v18 + 32) != 0.0 )
          v37 = 0;
        ++v38;
      }
      while ( v38 < v2 );
      if ( !v39 && !v37 )
        return 1;
    }
    v19 = (_DWORD *)sub_681186(116);
    if ( v19 )
    {
      v4 = (char *)sub_680CEC(v19);
      v38 = (unsigned int)v4;
    }
    else
    {
      v38 = 0;
      v4 = 0;
    }
    if ( v4 )
    {
      if ( v39 )
        v20 = v2 | 0x73600000;
      else
        v20 = v2 | 0x73500000;
      v39 = sub_6811D1(v4, v20, 2 * v2, v2, 0);
      v7 = v4;
      if ( v39 < 0 )
        goto LABEL_56;
      v39 = sub_680D22(v4, v1[64]);
      if ( v39 >= 0 )
      {
        v21 = v2;
        v9 = v38;
        v10 = 4 * v21;
        qmemcpy(*((void **)v4 + 4), *(const void **)(v1[64] + 16), v10);
        qmemcpy(*(void **)(v9 + 8), v35, v10);
        v11 = v34;
        goto LABEL_58;
      }
      goto LABEL_55;
    }
    return -2147024882;
  }
  return 1;
}
