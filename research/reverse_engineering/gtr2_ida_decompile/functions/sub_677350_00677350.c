int *__stdcall sub_677350(int *a1, int a2, int a3)
{
  int *v3; // esi
  int v4; // ecx
  int v5; // eax
  unsigned int v6; // ecx
  unsigned int v7; // edx
  int v8; // eax
  int *result; // eax
  int v10; // eax
  int v11; // eax

  v3 = a1;
  v4 = a1[5];
  if ( v4 != 205 )
  {
    v5 = *a1;
    *(_DWORD *)(v5 + 20) = 20;
    *(_DWORD *)(v5 + 24) = v4;
    (*(void (__stdcall **)(int *))v5)(v3);
  }
  v6 = v3[35];
  v7 = v3[29];
  if ( v6 < v7 )
  {
    v10 = v3[2];
    if ( v10 )
    {
      *(_DWORD *)(v10 + 4) = v6;
      *(_DWORD *)(v10 + 8) = v7;
      (*(void (__stdcall **)(int *))v10)(v3);
    }
    v11 = v3[107];
    a1 = 0;
    (*(void (__stdcall **)(int *, int, int **, int))(v11 + 4))(v3, a2, &a1, a3);
    result = a1;
    v3[35] += (int)a1;
  }
  else
  {
    v8 = *v3;
    *(_DWORD *)(v8 + 20) = 123;
    (*(void (__stdcall **)(int *, int))(v8 + 4))(v3, -1);
    return 0;
  }
  return result;
}
