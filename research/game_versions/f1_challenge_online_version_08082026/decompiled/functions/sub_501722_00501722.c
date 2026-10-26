int __thiscall sub_501722(_DWORD *this, int a2, int a3)
{
  int v3; // esi
  _DWORD *v4; // eax
  unsigned int v5; // eax
  _DWORD *v6; // esi
  unsigned int v7; // ecx
  bool v8; // zf
  unsigned int v9; // eax
  int v10; // eax
  char *i; // ebx
  int *v12; // esi
  _BYTE *v13; // eax
  int *v14; // ecx
  unsigned __int16 v15; // dx
  int v17; // [esp-4h] [ebp-284h]
  int v18; // [esp-4h] [ebp-284h]
  char (__cdecl *v19[2])(_DWORD *); // [esp+Ch] [ebp-274h] BYREF
  int (*v20)(); // [esp+14h] [ebp-26Ch]
  char v21[64]; // [esp+90h] [ebp-1F0h] BYREF
  int v22; // [esp+D0h] [ebp-1B0h] BYREF
  int v23; // [esp+D4h] [ebp-1ACh]
  _DWORD *v24; // [esp+E4h] [ebp-19Ch]
  int v25; // [esp+114h] [ebp-16Ch]
  unsigned int v26; // [esp+12Ch] [ebp-154h]
  unsigned int v27; // [esp+130h] [ebp-150h]
  int v28; // [esp+138h] [ebp-148h]
  unsigned int v29; // [esp+148h] [ebp-138h]
  _DWORD *v30; // [esp+278h] [ebp-8h]
  const void **v31; // [esp+27Ch] [ebp-4h]

  v30 = this;
  v22 = sub_51177C(v19);
  v19[0] = sub_5016E0;
  v20 = nullsub_4;
  if ( sub_58A7EC(v21, 0, v17) )
    goto LABEL_2;
  sub_50F632(&v22, 61, 424);
  v4 = (_DWORD *)(*(int (__cdecl **)(int *, _DWORD, int))v23)(&v22, 0, 36);
  v24 = v4;
  v4[8] = a3;
  v4[2] = nullsub_4;
  v4[3] = &loc_5016FC;
  v4[4] = sub_501711;
  v4[5] = sub_5114D5;
  v4[6] = nullsub_4;
  v4[1] = 0;
  *v4 = 0;
  v4[7] = a2;
  sub_50F9AB(&v22, 1);
  if ( !sub_50FC7D() )
    v25 = 1;
  v20 = (int (*)())sub_511686;
  sub_50FB3B(&v22);
  if ( v28 == 1 )
  {
    v6 = v30;
    v5 = v26;
    *v30 = 50;
    v6[12] = v5;
LABEL_9:
    v6[13] = 0;
    v8 = v6[16] == 0;
    v6[3] = v5;
    v9 = v27;
    v6[4] = v27;
    v6[5] = 1;
    if ( !v8 )
    {
      v18 = v9 * v6[12];
      v6[14] = 1;
      v10 = sub_587C03(v18);
      v6[1] = v10;
      if ( !v10
        || (v31 = (const void **)(*(int (__cdecl **)(int *, int, unsigned int, int))(v23 + 8))(&v22, 1, v28 * v26, 1)) == 0 )
      {
        v3 = -2147024882;
        goto LABEL_25;
      }
      if ( *v6 == 50 )
      {
        for ( i = (char *)v6[1]; v29 < v27; i += v26 )
        {
          sub_50FAB7(&v22, v31, 1);
          qmemcpy(i, *v31, v26);
        }
      }
      else if ( *v6 == 22 )
      {
        v12 = (int *)v6[1];
        while ( v29 < v27 )
        {
          sub_50FAB7(&v22, v31, 1);
          v13 = *v31;
          v14 = &v12[v26];
          while ( v12 < v14 )
          {
            HIBYTE(v15) = *v13;
            LOBYTE(v15) = v13[1];
            *v12++ = (unsigned __int8)v13[2] | (v15 << 8);
            v13 += 3;
          }
        }
      }
      sub_50F904(&v22);
    }
    v3 = 0;
    goto LABEL_25;
  }
  if ( v28 == 3 )
  {
    v5 = v26;
    v6 = v30;
    v7 = 4 * v26;
    *v30 = 22;
    v6[12] = v7;
    goto LABEL_9;
  }
LABEL_2:
  v3 = -2147467259;
LABEL_25:
  sub_50F6F2(&v22);
  return v3;
}
