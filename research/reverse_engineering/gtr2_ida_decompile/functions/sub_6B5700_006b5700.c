_DWORD *__stdcall sub_6B5700(int *a1, unsigned int a2, int a3, int a4, int a5, int a6)
{
  int v6; // edi
  int v7; // eax
  _DWORD *result; // eax
  int v9; // ecx

  v6 = a1[1];
  if ( a2 != 1 )
  {
    v7 = *a1;
    *(_DWORD *)(v7 + 20) = 14;
    *(_DWORD *)(v7 + 24) = a2;
    (*(void (__stdcall **)(int *))v7)(a1);
  }
  result = (_DWORD *)sub_6B5340(a1, a2, 0x248u);
  result[1] = a5;
  result[3] = a6;
  v9 = *(_DWORD *)(v6 + 72);
  *(_DWORD *)(v6 + 72) = result;
  result[2] = a4;
  *result = 0;
  result[8] = a3;
  result[10] = 0;
  result[11] = v9;
  return result;
}
