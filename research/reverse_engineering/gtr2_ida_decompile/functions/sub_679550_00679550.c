int *__stdcall sub_679550(int *a1, int a2, unsigned int a3)
{
  int *v3; // esi
  int v4; // ecx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int *result; // eax

  v3 = a1;
  v4 = a1[5];
  if ( v4 != 101 )
  {
    v5 = *a1;
    *(_DWORD *)(v5 + 20) = 20;
    *(_DWORD *)(v5 + 24) = v4;
    (*(void (__stdcall **)(int *))v5)(v3);
  }
  if ( v3[58] >= (unsigned int)v3[8] )
  {
    v6 = *v3;
    *(_DWORD *)(v6 + 20) = 123;
    (*(void (__stdcall **)(int *, int))(v6 + 4))(v3, -1);
  }
  v7 = v3[2];
  if ( v7 )
  {
    v8 = v3[8];
    *(_DWORD *)(v7 + 4) = v3[58];
    *(_DWORD *)(v7 + 8) = v8;
    (*(void (__stdcall **)(int *))v7)(v3);
  }
  v9 = v3[85];
  if ( *(_DWORD *)(v9 + 12) )
    (*(void (__stdcall **)(int *))(v9 + 4))(v3);
  v10 = a3;
  if ( a3 > v3[8] - v3[58] )
    v10 = v3[8] - v3[58];
  v11 = v3[86];
  a1 = 0;
  (*(void (__stdcall **)(int *, int, int **, int))(v11 + 4))(v3, a2, &a1, v10);
  result = a1;
  v3[58] += (int)a1;
  return result;
}
