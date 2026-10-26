unsigned int __stdcall sub_6CE250(_DWORD *a1, int a2, unsigned int *a3, unsigned int a4)
{
  _DWORD *v4; // esi
  unsigned int result; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  bool v9; // cf
  int v10; // ecx
  bool v11; // zf
  int v12; // edi

  v4 = (_DWORD *)a1[107];
  if ( !v4[12] )
  {
    result = (*(int (__stdcall **)(_DWORD *, _DWORD))(a1[108] + 12))(a1, v4[v4[16] + 14]);
    if ( !result )
      return result;
    v6 = v4[19] + 1;
    v4[12] = 1;
    v4[19] = v6;
  }
  v7 = v4[17];
  if ( !v7 )
  {
LABEL_9:
    v10 = v4[19];
    v4[18] = a1[80] - 1;
    v11 = v10 == a1[81];
    v4[13] = 0;
    if ( v11 )
      sub_6CE120(a1);
    v4[17] = 1;
    goto LABEL_12;
  }
  v8 = v7 - 1;
  if ( v8 )
  {
    result = v8 - 1;
    if ( result )
      return result;
    (*(void (__stdcall **)(_DWORD *, _DWORD, _DWORD *, _DWORD, int, unsigned int *, unsigned int))(a1[109] + 4))(
      a1,
      v4[v4[16] + 14],
      v4 + 13,
      v4[18],
      a2,
      a3,
      a4);
    result = v4[13];
    if ( result < v4[18] )
      return result;
    v9 = *a3 < a4;
    v4[17] = 0;
    if ( !v9 )
      return result;
    goto LABEL_9;
  }
LABEL_12:
  result = (*(int (__stdcall **)(_DWORD *, _DWORD, _DWORD *, _DWORD, int, unsigned int *, unsigned int))(a1[109] + 4))(
             a1,
             v4[v4[16] + 14],
             v4 + 13,
             v4[18],
             a2,
             a3,
             a4);
  if ( v4[13] >= v4[18] )
  {
    if ( v4[19] == 1 )
      sub_6CE040(a1);
    v12 = a1[80];
    v4[16] ^= 1u;
    result = v12 + 1;
    v4[12] = 0;
    v4[13] = v12 + 1;
    v4[18] = v12 + 2;
    v4[17] = 2;
  }
  return result;
}
