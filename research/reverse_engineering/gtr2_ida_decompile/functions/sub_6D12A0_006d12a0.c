int __stdcall sub_6D12A0(int a1, int a2, char **a3, int *a4)
{
  int v4; // ebx
  int result; // eax
  int i; // esi
  char *v7; // edx
  _BYTE *v8; // eax
  _BYTE *j; // edi
  char v10; // cl
  _BYTE *v11; // eax

  v4 = *a4;
  result = *(_DWORD *)(a1 + 316);
  for ( i = 0; i < result; ++a3 )
  {
    v7 = *a3;
    v8 = *(_BYTE **)(v4 + 4 * i);
    for ( j = &v8[*(_DWORD *)(a1 + 112)]; v8 < j; v8 = v11 + 1 )
    {
      v10 = *v7++;
      *v8 = v10;
      v11 = v8 + 1;
      *v11 = v10;
    }
    sub_6B5FF0(v4, i, v4, i + 1, 1, *(_DWORD *)(a1 + 112));
    result = *(_DWORD *)(a1 + 316);
    i += 2;
  }
  return result;
}
