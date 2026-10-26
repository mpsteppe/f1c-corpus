int __thiscall sub_6B16E1(_DWORD *this)
{
  int v1; // edi
  unsigned int v2; // esi
  int v3; // ebx
  int v4; // edx
  int v5; // eax
  _DWORD *v6; // ecx
  _DWORD *v7; // eax
  int v8; // esi
  char *v9; // edi
  int v10; // ecx
  char *v11; // edi
  char *v12; // esi
  char v13; // al
  unsigned int v14; // ecx
  char *v15; // edi
  char *v16; // esi
  char *v17; // eax
  _DWORD *v18; // esi
  void *v19; // ecx
  int result; // eax
  int v21; // eax
  bool v22; // zf
  _DWORD *v23; // esi
  int v24; // ebx
  _DWORD *v25; // edi
  int v26; // eax
  int v27; // edx
  int v28; // esi
  int v29; // ecx
  _DWORD *v30; // eax
  void **v31; // edi
  char *v32; // eax
  _DWORD *v33; // esi
  void *v34; // ecx
  int v35; // [esp-4h] [ebp-30h]
  _DWORD *v36; // [esp+10h] [ebp-1Ch]
  int v37; // [esp+14h] [ebp-18h]
  unsigned int v38; // [esp+14h] [ebp-18h]
  int v39; // [esp+18h] [ebp-14h]
  int v40; // [esp+18h] [ebp-14h]
  int v41; // [esp+1Ch] [ebp-10h] BYREF
  int v42; // [esp+20h] [ebp-Ch]
  char *v43; // [esp+24h] [ebp-8h]
  _DWORD *v44; // [esp+28h] [ebp-4h]

  v1 = this[64];
  v2 = *(_DWORD *)v1 & 0xFFFFF;
  v44 = this;
  v42 = v1;
  if ( v2 < 3 )
    return 0;
  v3 = sub_6C5028(268435458, v1, 0, 2, 1);
  if ( v3 || (v3 = sub_6C5028(268435459, v1, 0, 2, 1)) != 0 || (v3 = sub_6C5028(268435460, v1, 0, 2, 1)) != 0 )
  {
    v4 = **(_DWORD **)(v3 + 16);
    v43 = (char *)v44[5];
    if ( *(_DWORD *)(*(_DWORD *)&v43[4 * v4] + 4) == v44[33] )
    {
      v5 = *(_DWORD *)v3 & 0xFFFFF;
      v39 = 1;
      if ( !v5 )
        goto LABEL_13;
      v41 = **(_DWORD **)(v1 + 16);
      v6 = *(_DWORD **)(v3 + 8);
      v37 = v5;
      do
      {
        if ( *v6 != v41 || (*(_DWORD *)(*(_DWORD *)&v43[4 * *v6] + 52) & 0x1FFE00) != 0 )
          v39 = 0;
        ++v6;
        --v37;
      }
      while ( v37 );
      if ( v39 )
      {
LABEL_13:
        v7 = (_DWORD *)sub_681186(116);
        if ( v7 )
          v43 = (char *)sub_680CEC(v7);
        else
          v43 = 0;
        if ( v43 )
        {
          v8 = sub_6811D1(v43, v2 & 0xFFFFF | 0x50000000, *(_DWORD *)(v1 + 4), *(_DWORD *)(v3 + 12), 0);
          if ( v8 < 0 )
          {
            v9 = v43;
          }
          else
          {
            v35 = v1;
            v9 = v43;
            v8 = sub_680D22(v43, v35);
            if ( v8 >= 0 )
            {
              v10 = *((_DWORD *)v43 + 3);
              v11 = (char *)*((_DWORD *)v43 + 4);
              v12 = *(char **)(v3 + 16);
              v13 = 4 * v10;
              v14 = (unsigned int)(4 * v10) >> 2;
              qmemcpy(v11, v12, 4 * v14);
              v16 = &v12[4 * v14];
              v15 = &v11[4 * v14];
              LOBYTE(v14) = v13;
              v17 = v43;
              qmemcpy(v15, v16, v14 & 3);
              qmemcpy(*((void **)v43 + 2), *(const void **)(v42 + 8), 4 * *((_DWORD *)v43 + 1));
              *(_DWORD *)v3 = 0;
              v18 = v44;
              v19 = (void *)v44[64];
              if ( v19 )
              {
                sub_66238F(v19, 1);
                v17 = v43;
              }
              *(_DWORD *)(v44[6] + 4 * v44[63]) = v17;
              v18[64] = v17;
              return 0;
            }
          }
          sub_66238F(v9, 1);
          return v8;
        }
        return -2147024882;
      }
    }
  }
  if ( v2 != 3 )
    return 0;
  if ( (unsigned __int16)v44[50] < 0x200u )
    return 0;
  v21 = v44[64];
  v22 = memcmp(*(const void **)(v21 + 8), (const void *)(*(_DWORD *)(v21 + 8) + 12), 0xCu) == 0;
  v42 = v21;
  if ( !v22 )
    return 0;
  v23 = (_DWORD *)sub_6C5028(275775489, v21, 0, 2, 1);
  v36 = v23;
  if ( !v23 )
    return 0;
  v24 = sub_6C5028(542113795, v23, &v41, 2, 1);
  if ( !v24 )
  {
    v24 = sub_6C5028(542113796, v23, &v41, 2, 1);
    if ( !v24 )
      return 0;
  }
  v25 = *(_DWORD **)(v42 + 8);
  v26 = v44[5];
  v27 = *(_DWORD *)(v26 + 4 * *v25);
  v28 = *(_DWORD *)(v24 + 8);
  v29 = *(_DWORD *)v24 & 0xFFFFF;
  v43 = *(char **)(v26 + 4 * **(_DWORD **)(v24 + 16));
  v40 = v29;
  v38 = 4 * v29;
  if ( memcmp((const void *)(4 * v29 + v28), v25, 0xCu)
    || *(_DWORD *)(v27 + 4) == *((_DWORD *)v43 + 1) && *(_DWORD *)(v27 + 12) == *((_DWORD *)v43 + 3) )
  {
    return 0;
  }
  v30 = (_DWORD *)sub_681186(116);
  if ( v30 )
  {
    v31 = (void **)sub_680CEC(v30);
    v43 = (char *)v31;
  }
  else
  {
    v43 = 0;
    v31 = 0;
  }
  if ( !v31 )
    return -2147024882;
  result = sub_6811D1((char *)v31, v40 & 0xFFFFF | 0x70200000, v40, v40, 0);
  if ( result >= 0 )
  {
    result = sub_680D22(v31, v24);
    if ( result >= 0 )
    {
      qmemcpy(v31[4], *(const void **)(v24 + 16), v38);
      v32 = v43;
      qmemcpy(*((void **)v43 + 2), (const void *)(v38 + *(_DWORD *)(v24 + 8)), v38);
      v33 = v44;
      if ( !(*(int (__thiscall **)(_DWORD *, char *, _DWORD))(*v44 + 32))(v44, v32, 0) )
      {
        *(_DWORD *)v42 = 0;
        *v36 = 0;
        *(_DWORD *)v24 = 0;
        if ( !(*(int (__thiscall **)(_DWORD *, char *, int))(*v33 + 52))(v33, v43, v41) )
        {
          v34 = *(void **)(v33[6] + 4 * v41);
          if ( v34 )
            sub_66238F(v34, 1);
          *(_DWORD *)(v33[6] + 4 * v41) = v43;
          return 0;
        }
        *(_DWORD *)v42 = 1342177283;
        *v36 = 275775489;
        *(_DWORD *)v24 = v40 | 0x20500000;
      }
      sub_66238F(v43, 1);
      return 0;
    }
  }
  return result;
}
