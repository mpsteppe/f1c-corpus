// f1c  0x0052a5d7  size=277
int __cdecl sub_52A5D7(_DWORD *a1, _DWORD *a2, int a3)
{
  char *v4; // edx
  unsigned int v5; // edi
  unsigned int v6; // eax
  unsigned int v7; // edi
  int (__cdecl *v8)(_DWORD, char *, unsigned int); // eax
  int v9; // eax
  char v10; // al
  unsigned int v11; // ecx
  char *v12; // edi
  char *v13; // eax
  char *v14; // edx
  unsigned int v15; // eax
  unsigned int v16; // edi
  int (__cdecl *v17)(_DWORD, char *, unsigned int); // eax
  int v18; // eax
  char v19; // al
  unsigned int v20; // ecx
  char *v21; // edi
  char *v23; // [esp+Ch] [ebp-8h]
  char *v24; // [esp+Ch] [ebp-8h]
  unsigned int v25; // [esp+10h] [ebp-4h]
  unsigned int v26; // [esp+10h] [ebp-4h]
  char *v27; // [esp+1Ch] [ebp+8h]
  char *v28; // [esp+1Ch] [ebp+8h]
  char *v29; // [esp+1Ch] [ebp+8h]

  v4 = (char *)a1[12];
  v5 = a1[13];
  v23 = (char *)a2[3];
  v27 = v4;
  if ( (unsigned int)v4 > v5 )
    v5 = a1[11];
  v6 = a2[4];
  v7 = v5 - (_DWORD)v4;
  v25 = v7;
  if ( v7 > v6 )
  {
    v25 = a2[4];
    v7 = v25;
  }
  if ( v7 && a3 == -5 )
    a3 = 0;
  a2[5] += v7;
  a2[4] = v6 - v7;
  v8 = (int (__cdecl *)(_DWORD, char *, unsigned int))a1[14];
  if ( v8 )
  {
    v9 = v8(a1[15], v4, v7);
    v4 = v27;
    a1[15] = v9;
    a2[12] = v9;
  }
  v10 = v7;
  v11 = v7 >> 2;
  qmemcpy(v23, v4, 4 * (v7 >> 2));
  v12 = &v23[4 * (v7 >> 2)];
  v24 = &v23[v25];
  v28 = &v27[v25];
  qmemcpy(v12, &v4[4 * v11], v10 & 3);
  v13 = (char *)a1[11];
  if ( v28 == v13 )
  {
    v14 = (char *)a1[10];
    v29 = v14;
    if ( (char *)a1[13] == v13 )
      a1[13] = v14;
    v15 = a2[4];
    v16 = a1[13] - (_DWORD)v14;
    v26 = v16;
    if ( v16 > v15 )
    {
      v26 = a2[4];
      v16 = v26;
    }
    if ( v16 && a3 == -5 )
      a3 = 0;
    a2[5] += v16;
    a2[4] = v15 - v16;
    v17 = (int (__cdecl *)(_DWORD, char *, unsigned int))a1[14];
    if ( v17 )
    {
      v18 = v17(a1[15], v14, v16);
      v14 = v29;
      a1[15] = v18;
      a2[12] = v18;
    }
    v19 = v16;
    v20 = v16 >> 2;
    qmemcpy(v24, v14, 4 * (v16 >> 2));
    v21 = &v24[4 * (v16 >> 2)];
    v24 += v26;
    v28 = &v29[v26];
    qmemcpy(v21, &v14[4 * v20], v19 & 3);
  }
  a2[3] = v24;
  a1[12] = v28;
  return a3;
}
