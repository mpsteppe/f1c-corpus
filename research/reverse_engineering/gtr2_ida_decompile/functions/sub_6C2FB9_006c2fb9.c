int __thiscall sub_6C2FB9(int this, int a2, const void *a3, _DWORD *a4, const void *a5, int *a6, int a7, int a8)
{
  int v8; // esi
  unsigned int v10; // esi
  bool v11; // zf
  int v12; // edi
  int result; // eax
  _DWORD *v14; // eax
  int v15; // ebx
  int v16; // edi
  unsigned int v17; // ecx
  int v18; // eax
  _DWORD *v19; // edx
  int v20; // ebx
  int v21; // ecx
  int *v22; // eax
  int v23; // ecx
  int v24; // eax
  _DWORD *v25; // eax
  char *v26; // ebx
  int v27; // eax
  int v28; // esi
  _DWORD *v29; // ecx
  int v30; // edx
  int v31; // eax
  int v32; // ecx
  int v33; // edi
  _DWORD v34[4]; // [esp+Ch] [ebp-30h] BYREF
  _DWORD v35[4]; // [esp+1Ch] [ebp-20h] BYREF
  unsigned int v36; // [esp+2Ch] [ebp-10h]
  char *v37; // [esp+30h] [ebp-Ch]
  int v38; // [esp+34h] [ebp-8h]
  unsigned int v39; // [esp+38h] [ebp-4h]
  int v40; // [esp+4Ch] [ebp+10h]
  int v41; // [esp+4Ch] [ebp+10h]

  v8 = *a6;
  memset(v35, 0, sizeof(v35));
  v10 = v8 & 0xFFFFF;
  v11 = (*(_BYTE *)(this + 111) & 2) == 0;
  v38 = this;
  v36 = v10;
  if ( v11 )
  {
    v12 = 0;
    if ( v10 )
    {
      do
      {
        result = sub_6C2EA2((_DWORD *)this, *(_DWORD *)(a2 + 4 * v12), &v35[v12], &v34[v12]);
        if ( result )
          return result;
      }
      while ( ++v12 < v10 );
    }
    v39 = 0;
    if ( v10 )
    {
      v14 = a4;
      v15 = *(_DWORD *)(this + 20);
      v37 = (char *)((char *)v35 - (char *)a4);
      while ( *(_DWORD *)(*(_DWORD *)(v15 + 4 * *(_DWORD *)((char *)v14 + (char *)v34 - (char *)a4)) + 56) == *v14
           && (*(_BYTE *)(*(_DWORD *)(v15 + 4 * *v14) + 62) & 0x1F) == 0
           && *(_DWORD *)((char *)v14 + (_DWORD)v37) == v35[0] )
      {
        ++v39;
        ++v14;
        if ( v39 >= v10 )
          goto LABEL_11;
      }
      return 1;
    }
LABEL_11:
    v16 = 0;
    if ( *(_DWORD *)(v35[0] + 12) )
    {
      do
      {
        v17 = 0;
        v39 = 1;
        if ( !v10 )
          return 1;
        v18 = *(_DWORD *)(*(_DWORD *)(v35[0] + 16) + 4 * v16);
        do
        {
          if ( v18 == *(_DWORD *)(a2 + 4 * v17) )
            v39 = 0;
          ++v17;
        }
        while ( v17 < v10 );
        if ( v39 )
          return 1;
      }
      while ( (unsigned int)++v16 < *(_DWORD *)(v35[0] + 12) );
    }
  }
  else
  {
    v39 = 0;
    if ( v10 )
    {
      v19 = a4;
      v20 = *(_DWORD *)(this + 20);
      do
      {
        v21 = *(_DWORD *)(v20 + 4 * *(_DWORD *)((char *)v19 + a2 - (_DWORD)a4));
        if ( *(_DWORD *)(v21 + 56) != *v19 )
          return 1;
        if ( (*(_DWORD *)(v21 + 60) & 0x1F0000) != 0x10000 )
          return 1;
        v22 = *(int **)(v20 + 4 * *v19);
        v23 = v22[15];
        if ( (v23 & 0x1F0000) != 0 )
          return 1;
        if ( (v23 & 0x200) == 0 )
        {
          v24 = *v22;
          if ( (v24 & 4) == 0 || (v24 & 0x10) == 0 )
            return 1;
        }
        ++v39;
        ++v19;
      }
      while ( v39 < v10 );
    }
  }
  v25 = (_DWORD *)sub_681186(116);
  if ( v25 )
    v26 = (char *)sub_680CEC(v25);
  else
    v26 = 0;
  if ( !v26 )
    return -2147024882;
  result = sub_6811D1(v26, v10 & 0xFFFFF | 0x70100000, 3 * v10, v10, 0);
  if ( result >= 0 )
  {
    result = sub_680D22(v26, (int)a6);
    if ( result >= 0 )
    {
      qmemcpy(*((void **)v26 + 4), *(const void **)(a7 + 16), 4 * v10);
      qmemcpy(*((void **)v26 + 2), a4, 4 * v10);
      v40 = 2 * v36;
      qmemcpy((void *)(8 * v36 + *((_DWORD *)v26 + 2)), a3, 4 * v10);
      qmemcpy((void *)(4 * v10 + *((_DWORD *)v26 + 2)), a5, 4 * ((4 * v10) >> 2));
      v27 = *(_DWORD *)(v38 + 20);
      v28 = *(_DWORD *)(v27 + 4 * **((_DWORD **)v26 + 4));
      v29 = (_DWORD *)*((_DWORD *)v26 + 2);
      v30 = *(_DWORD *)(v27 + 4 * *v29);
      v31 = *(_DWORD *)(v27 + 4 * v29[v40]);
      v32 = *(_DWORD *)(v28 + 4);
      v41 = 0;
      if ( v32 == *(_DWORD *)(v30 + 4) && *(_DWORD *)(v28 + 12) == *(_DWORD *)(v30 + 12)
        || v32 == *(_DWORD *)(v31 + 4) && *(_DWORD *)(v28 + 12) == *(_DWORD *)(v31 + 12) )
      {
        v33 = v38;
      }
      else
      {
        v33 = v38;
        if ( v32 == *(_DWORD *)(v38 + 136) )
        {
LABEL_45:
          if ( !(*(int (__thiscall **)(int, char *, _DWORD))(*(_DWORD *)v33 + 32))(v33, v26, 0)
            && ((*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v33 + 16) + 4 * *(_DWORD *)(v28 + 4)) + 4) & 0x20) == 0 && !v41
             || (*(_BYTE *)(v33 + 111) & 2) != 0) )
          {
            result = sub_681430(*(char **)(*(_DWORD *)(v33 + 24) + 4 * a8), v26);
            if ( result >= 0 )
            {
              sub_66238F(v26, 1);
              *a6 = 0;
              if ( v35[0] )
                *(_DWORD *)v35[0] = 0;
              return 0;
            }
            return result;
          }
          sub_66238F(v26, 1);
          return 1;
        }
      }
      if ( (*(_BYTE *)(v33 + 111) & 2) == 0 )
        v41 = 1;
      goto LABEL_45;
    }
  }
  return result;
}
