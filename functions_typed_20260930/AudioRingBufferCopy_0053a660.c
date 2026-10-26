int __fastcall sub_53A660(_DWORD *a1, _DWORD *a2, int a3)
{
  char *v5; // edi
  unsigned int v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // esi
  unsigned int v9; // edx
  int (__fastcall *v10)(_DWORD, char *, unsigned int); // eax
  int v11; // eax
  char *v12; // eax
  char *v13; // ecx
  char *v14; // esi
  unsigned int v15; // eax
  unsigned int v16; // edi
  unsigned int v17; // edx
  int (__fastcall *v18)(_DWORD, char *, unsigned int); // eax
  int v19; // eax
  unsigned int v21; // [esp+10h] [ebp-Ch]
  unsigned int v22; // [esp+10h] [ebp-Ch]
  char *v23; // [esp+14h] [ebp-8h]
  char *v24; // [esp+14h] [ebp-8h]

  v5 = (char *)a1[12];
  v6 = a1[13];
  v23 = (char *)a2[3];
  if ( (unsigned int)v5 > v6 )
    v6 = a1[11];
  v7 = a2[4];
  v8 = v6 - (_DWORD)v5;
  v21 = v8;
  if ( v8 > v7 )
  {
    v21 = a2[4];
    v8 = v21;
  }
  if ( v8 && a3 == -5 )
    a3 = 0;
  v9 = v8 + a2[5];
  a2[4] = v7 - v8;
  a2[5] = v9;
  v10 = (int (__fastcall *)(_DWORD, char *, unsigned int))a1[14];
  if ( v10 )
  {
    v11 = v10(a1[15], v5, v8);
    a1[15] = v11;
    a2[12] = v11;
  }
  qmemcpy(v23, v5, v8);
  v12 = &v5[v21];
  v13 = (char *)a1[11];
  v24 = &v23[v21];
  if ( &v5[v21] == v13 )
  {
    v14 = (char *)a1[10];
    if ( (char *)a1[13] == v13 )
      a1[13] = v14;
    v15 = a2[4];
    v16 = a1[13] - (_DWORD)v14;
    v22 = v16;
    if ( v16 > v15 )
    {
      v22 = a2[4];
      v16 = v22;
    }
    if ( v16 && a3 == -5 )
      a3 = 0;
    v17 = v16 + a2[5];
    a2[4] = v15 - v16;
    a2[5] = v17;
    v18 = (int (__fastcall *)(_DWORD, char *, unsigned int))a1[14];
    if ( v18 )
    {
      v19 = v18(a1[15], v14, v16);
      a1[15] = v19;
      a2[12] = v19;
    }
    qmemcpy(v24, v14, v16);
    v24 += v22;
    v12 = &v14[v22];
  }
  a2[3] = v24;
  a1[12] = v12;
  return a3;
}

