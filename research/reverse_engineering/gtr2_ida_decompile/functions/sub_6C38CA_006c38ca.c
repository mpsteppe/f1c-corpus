int __thiscall sub_6C38CA(int this, int a2, int a3, int a4, int *a5)
{
  _DWORD *v5; // ebx
  int v7; // edi
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  int v12; // edi
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  unsigned int v17; // eax
  int v18; // edi
  int v19; // eax
  int v20; // eax
  _DWORD *v21; // ecx
  int v22; // eax
  _DWORD *v23; // eax
  _DWORD *j; // edx
  int v25; // eax
  int v26; // ebx
  _DWORD *v27; // ecx
  int v29; // [esp+14h] [ebp-14h]
  _DWORD *v30; // [esp+18h] [ebp-10h]
  int v31; // [esp+1Ch] [ebp-Ch]
  int v32; // [esp+1Ch] [ebp-Ch]
  int v33; // [esp+20h] [ebp-8h]
  unsigned int i; // [esp+20h] [ebp-8h]
  unsigned int v35; // [esp+24h] [ebp-4h]
  unsigned int v36; // [esp+30h] [ebp+8h]
  int v37; // [esp+30h] [ebp+8h]
  int v38; // [esp+34h] [ebp+Ch]
  int v39; // [esp+34h] [ebp+Ch]

  v5 = (_DWORD *)a4;
  if ( *(_DWORD *)(a4 + 48) != -1 )
    goto LABEL_43;
  v7 = *(_DWORD *)(*(_DWORD *)(this + 16) + 4 * *(_DWORD *)(a4 + 4));
  v8 = *(_DWORD *)(v7 + 4);
  if ( (v8 & 0x800) != 0 )
    v9 = *(_DWORD *)v7;
  else
    v9 = a2;
  v10 = sub_681A51((void *)this, v9, a3 | v8 | 0x40, -1, 4);
  v31 = v10;
  if ( v10 == -1 )
    return -2147024882;
  if ( (*(_BYTE *)(v7 + 5) & 1) == 0 )
  {
    v33 = 0;
    v36 = 0;
    v35 = *(_DWORD *)(this + 8);
    if ( v35 )
    {
      do
      {
        v12 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v36);
        if ( *(_DWORD *)(v12 + 4) == *(_DWORD *)(a4 + 4)
          && (v13 = *(_DWORD *)(v12 + 96), v13 == *(_DWORD *)(a4 + 96))
          && v13
          && *(_DWORD *)(v12 + 8) == -1
          || a4 == v12 )
        {
          v14 = sub_681AAA((void *)this, v31, *(_DWORD *)(v12 + 100), 0, *(double *)(v12 + 32));
          *(_DWORD *)(v12 + 48) = v14;
          if ( v14 == -1 )
            return -2147024882;
          v30 = *(_DWORD **)(*(_DWORD *)(this + 20) + 4 * v14);
          sub_681692(v30, (_DWORD *)v12);
          v30[28] = 4 * v30[25];
          if ( *(_DWORD *)(v12 + 68) != -1 )
            v33 = 1;
        }
        ++v36;
      }
      while ( v36 < v35 );
    }
    v15 = *(_DWORD *)(this + 224);
    if ( v15 && v33 )
    {
      if ( (a3 & 0x2000) != 0 )
        v16 = *(_DWORD *)(v15 + 180);
      else
        v16 = *(_DWORD *)(v15 + 184);
      v37 = v16;
      if ( v16 == -1 )
        return -2147024882;
      v17 = 0;
      for ( i = 0; i < v35; v17 = ++i )
      {
        v18 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v17);
        if ( *(_DWORD *)(v18 + 4) == v5[1]
          && (v19 = *(_DWORD *)(v18 + 96), v19 == v5[24])
          && v19
          && *(_DWORD *)(v18 + 8) == -1
          || v5 == (_DWORD *)v18 )
        {
          v29 = sub_681AAA(*(void **)(this + 224), v37, *(_DWORD *)(v18 + 100), 0, *(double *)(v18 + 32));
          if ( v29 == -1 )
            return -2147024882;
          v20 = *(_DWORD *)(v18 + 68);
          if ( v20 != -1 )
          {
            v21 = *(_DWORD **)(this + 224);
            v22 = *(_DWORD *)(*(_DWORD *)(v21[5] + 4 * v20) + 72);
            if ( v22 != -1 )
            {
              v23 = *(_DWORD **)(v21[6] + 4 * v22);
              v32 = (int)v23;
              if ( (*v23 & 0xFFF00000) == 0x10000000 )
              {
                v38 = 0;
                if ( v23[3] )
                {
                  for ( j = (_DWORD *)v23[4]; *j != *(_DWORD *)(v18 + 68); ++j )
                  {
                    if ( (unsigned int)++v38 >= v23[3] )
                      break;
                  }
                }
                v39 = *(_DWORD *)(v23[2] + 4 * v38);
                v25 = sub_681B0A(v21, 268435457, 1, 1);
                if ( v25 == -1 )
                  return -2147024882;
                v26 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 224) + 24) + 4 * v25);
                sub_680D22((_DWORD *)v26, v32);
                **(_DWORD **)(v26 + 16) = v29;
                v27 = *(_DWORD **)(v26 + 8);
                v5 = (_DWORD *)a4;
                *v27 = v39;
                *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *(_DWORD *)(v18 + 48)) + 68) = v29;
              }
            }
          }
        }
      }
    }
LABEL_43:
    *a5 = v5[12];
    return 0;
  }
  v11 = sub_681AAA((void *)this, v10, *(_DWORD *)(a4 + 100), 0, *(double *)(a4 + 32));
  *(_DWORD *)(a4 + 48) = v11;
  if ( v11 != -1 )
  {
    *a5 = v11;
    sub_681692(*(_DWORD **)(*(_DWORD *)(this + 20) + 4 * *(_DWORD *)(a4 + 48)), (_DWORD *)a4);
    return 0;
  }
  return -2147024882;
}
