int __thiscall sub_6C2620(int this)
{
  int *v2; // eax
  int v3; // esi
  int v4; // edi
  unsigned int v5; // esi
  int result; // eax
  int *v7; // eax
  int v8; // ecx
  _DWORD *v9; // edx
  _DWORD *v10; // eax
  bool v11; // zf
  unsigned int v12; // eax
  _DWORD *v13; // edi
  _DWORD *v14; // eax
  int v15; // eax
  unsigned int v16; // ecx
  int v17; // ecx
  int *v18; // esi
  int *v19; // eax
  int v20; // ecx
  int v21; // ecx
  int v22; // eax
  int v23; // eax
  unsigned int v24; // edx
  int v25; // eax
  int v26; // [esp-8h] [ebp-120h]
  int v27; // [esp-4h] [ebp-11Ch]
  char v28[64]; // [esp+14h] [ebp-104h] BYREF
  _DWORD v29[4]; // [esp+54h] [ebp-C4h] BYREF
  int v30; // [esp+64h] [ebp-B4h]
  unsigned int v31; // [esp+68h] [ebp-B0h]
  int v32; // [esp+74h] [ebp-A4h]
  int v33[4]; // [esp+F4h] [ebp-24h] BYREF
  int v34; // [esp+104h] [ebp-14h]
  int v35; // [esp+108h] [ebp-10h]
  int v36; // [esp+10Ch] [ebp-Ch]
  int v37; // [esp+110h] [ebp-8h] BYREF
  unsigned int v38; // [esp+114h] [ebp-4h]

  v2 = *(int **)(this + 256);
  v3 = *v2;
  v37 = 0;
  v33[0] = 0;
  v36 = 0;
  v4 = 1;
  v5 = v3 & 0xFFFFF;
  v33[1] = 1;
  v33[2] = 2;
  v33[3] = 3;
  if ( sub_6BB35B((_DWORD *)this, v2, dword_747090, v28, (unsigned int *)&v37, (int)v29, v33, v5, 1) )
  {
    result = sub_6BB35B(
               (_DWORD *)this,
               *(int **)(this + 256),
               dword_7470F0,
               v28,
               (unsigned int *)&v37,
               (int)v29,
               v33,
               v5,
               1);
    if ( result )
      return result;
    v36 = 1;
  }
  if ( **(_DWORD **)v28 == 1342177282 )
  {
    v38 = 1;
    if ( v5 > 1 )
    {
      v7 = *(int **)(*(_DWORD *)(this + 256) + 8);
      v35 = *v7;
      v8 = 4 * v5 + 4;
      v9 = v7 + 1;
      while ( *v9 == v35 )
      {
        if ( *(_DWORD *)(v8 + *(_DWORD *)(*(_DWORD *)(this + 256) + 8)) != *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 256)
                                                                                                 + 8)
                                                                                     + 4 * v5) )
          return 1;
        ++v38;
        ++v9;
        v8 += 4;
        if ( v38 >= v5 )
          goto LABEL_11;
        v4 = 1;
      }
      return v4;
    }
LABEL_11:
    v10 = (_DWORD *)sub_681186(116);
    if ( v10 )
      v38 = (unsigned int)sub_680CEC(v10);
    else
      v38 = 0;
    v4 = sub_6811D1((char *)v38, 1887436802, 6, v5, 0);
    if ( v4 < 0 )
      goto LABEL_30;
    v4 = sub_680D22((_DWORD *)v38, *(_DWORD *)(this + 256));
    if ( v4 < 0 )
      goto LABEL_30;
    v11 = v36 == 0;
    v12 = v38;
    qmemcpy(*(void **)(v38 + 16), *(const void **)(*(_DWORD *)(this + 256) + 16), 4 * v5);
    v13 = (_DWORD *)v12;
    v14 = *(_DWORD **)(v12 + 8);
    *v14 = v29[0];
    v14[1] = v29[1];
    if ( v11 )
    {
      v15 = v13[2];
      *(_DWORD *)(v15 + 8) = v30;
      v16 = v31;
    }
    else
    {
      v17 = *(_DWORD *)(this + 20);
      v18 = *(int **)(v17 + 4 * v31);
      v34 = v30;
      v19 = *(int **)(v17 + 4 * v30);
      v20 = v19[14];
      v36 = v31;
      if ( v20 != -1 )
      {
        v19 = *(int **)(*(_DWORD *)(this + 20) + 4 * v20);
        v34 = v20;
      }
      v21 = v18[14];
      if ( v21 != -1 )
      {
        v18 = *(int **)(*(_DWORD *)(this + 20) + 4 * v21);
        v36 = v21;
      }
      v22 = sub_681AAA((void *)this, v19[1], v19[3], v19[4], 0.0);
      v27 = v18[4];
      v26 = v18[3];
      v35 = v22;
      v37 = sub_681AAA((void *)this, v18[1], v26, v27, 0.0);
      if ( v35 == -1 || v37 == -1 )
      {
        v4 = -2147024882;
LABEL_30:
        if ( v38 )
          sub_66238F((void *)v38, 1);
        return v4;
      }
      v23 = 4 * v35;
      *(_DWORD *)(*(_DWORD *)(v23 + *(_DWORD *)(this + 20)) + 60) = v34 ^ 0x80000;
      v24 = 4 * v37;
      *(_DWORD *)(*(_DWORD *)(4 * v37 + *(_DWORD *)(this + 20)) + 60) = v36 ^ 0x80000;
      *(_DWORD *)(*(_DWORD *)(v23 + *(_DWORD *)(this + 20)) + 56) = v34;
      *(_DWORD *)(*(_DWORD *)(v24 + *(_DWORD *)(this + 20)) + 56) = v36;
      *(_DWORD *)(v13[2] + 8) = v35;
      v15 = v13[2];
      v16 = v37;
    }
    *(_DWORD *)(v15 + 12) = v16;
    v25 = v32;
    *(_DWORD *)(v13[2] + 16) = v32;
    *(_DWORD *)(v13[2] + 20) = v25;
    if ( (*(int (__thiscall **)(int, _DWORD *))(*(_DWORD *)this + 48))(this, v13) )
      v4 = 1;
    else
      v4 = sub_681430(*(char **)(this + 256), v13);
    goto LABEL_30;
  }
  return v4;
}
