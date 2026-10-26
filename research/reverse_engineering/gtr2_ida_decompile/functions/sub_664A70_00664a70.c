int __thiscall sub_664A70(
        _DWORD *this,
        _DWORD *a2,
        unsigned int *a3,
        unsigned int a4,
        int a5,
        int a6,
        int a7,
        int *a8,
        int a9,
        int a10,
        _DWORD *a11)
{
  const char *v11; // edi
  int v12; // esi
  int result; // eax
  _DWORD *v14; // eax
  bool v15; // zf
  int v16; // ecx
  int v17; // eax
  const char *v18; // ebx
  int v19; // eax
  int v20; // ebx
  _DWORD *v21; // esi
  int v22; // ecx
  int v23; // eax
  unsigned int v24; // eax
  int v25; // ecx
  int v26; // eax
  int v27; // eax
  int v28; // eax
  unsigned int v29; // esi
  int v30; // eax
  char *v31; // edx
  int v32; // [esp+Ch] [ebp-1Ch] BYREF
  int v33; // [esp+10h] [ebp-18h]
  int v34; // [esp+18h] [ebp-10h] BYREF
  int v35; // [esp+1Ch] [ebp-Ch] BYREF
  const char *v36; // [esp+20h] [ebp-8h]
  _DWORD *v37; // [esp+24h] [ebp-4h]
  unsigned int v38; // [esp+40h] [ebp+18h]
  const char *v39; // [esp+4Ch] [ebp+24h]
  int v40; // [esp+50h] [ebp+28h]

  v11 = 0;
  v37 = this;
  v35 = 0;
  v34 = 0;
  if ( !a2 )
    goto LABEL_9;
  if ( !a5 && a9 )
  {
    a7 = a9;
    a8 = &v34;
    a5 = 1;
  }
  if ( !a6 )
  {
    v12 = a10;
    if ( a10 )
    {
      if ( !this[33] )
      {
        while ( 1 )
        {
          v14 = *(_DWORD **)(v12 + 8);
          v15 = v14[1] == 17;
          v39 = 0;
          v36 = 0;
          if ( v15 )
          {
            v16 = v14[5];
            v17 = v14[4];
            v18 = *(const char **)(v16 + 24);
            if ( v17 )
            {
              if ( sub_6460B4(*(const char **)(v17 + 24), 0, &v32) >= 0 )
              {
                v19 = v37[4];
                if ( v19 == v33 )
                {
                  v39 = v18;
                }
                else if ( (v19 & 0xFFFF0000) == v33 )
                {
                  v11 = v18;
                }
              }
            }
            else
            {
              v36 = *(const char **)(v16 + 24);
            }
          }
          v20 = 0;
          v40 = *(_DWORD *)(v12 + 12);
          if ( v39 || (!v11 ? (v39 = v36) : (v39 = v11), v39) )
          {
            v21 = v37;
            v22 = v37[2];
            if ( a4 >= *(_DWORD *)(v22 + 4) )
              v23 = 0;
            else
              v23 = *(_DWORD *)(*(_DWORD *)(v22 + 16) + 4 * a4);
            if ( !v23 )
              return -2147467259;
            v24 = sub_681B61(v23);
            v25 = v21[2];
            a4 = v24;
            if ( v24 < *(_DWORD *)(v25 + 4) )
              v20 = *(_DWORD *)(*(_DWORD *)(v25 + 16) + 4 * v24);
            if ( !v20 )
              return -2147024882;
            v26 = *(_DWORD *)(v20 + 4);
            if ( (v26 & 0x800) != 0 )
            {
              v29 = strlen(*(const char **)v20);
              v36 = (const char *)v29;
              v38 = strlen(v39);
              v30 = sub_67EB7E(v38 + v29 + 3, 4u);
              if ( !v30 )
                return -2147024882;
              qmemcpy((void *)v30, *(const void **)v20, v29);
              v31 = (char *)&v36[v30];
              *v31 = 59;
              v31[1] = 32;
              qmemcpy(v31 + 2, v39, v38);
              v36[v30 + 2 + v38] = 0;
              *(_DWORD *)v20 = v30;
            }
            else
            {
              v27 = v26 | 0x840;
              *(_DWORD *)v20 = v39;
              *(_DWORD *)(v20 + 4) = v27;
              if ( (v27 & 0x10) != 0 && (v27 & 0x80u) == 0 )
              {
                if ( (v27 & 0x200) != 0 && (*(_DWORD *)(v37[2] + 112) & 0x200) != 0 )
                  *(_DWORD *)(v20 + 4) = v27 | 0x400;
                v28 = *(_DWORD *)(v20 + 4);
                if ( (v28 & 0x200) == 0 && (*(_BYTE *)(v37[2] + 113) & 4) != 0 )
                  *(_DWORD *)(v20 + 4) = v28 | 0x100400;
              }
            }
            a6 = 1;
          }
          v11 = 0;
          if ( !v40 )
            break;
          v12 = v40;
        }
      }
    }
  }
  result = sub_663EC6(v37, a2, a3, a4, a5, a6, a7, a8, &v35);
  if ( result >= 0 )
  {
LABEL_9:
    if ( a11 )
      *a11 = v35;
    return 0;
  }
  return result;
}
