int __stdcall sub_6778B0(int *a1, int a2)
{
  int v2; // ecx
  int v3; // eax
  int result; // eax
  int v5; // eax

  v2 = a1[5];
  if ( v2 != 200 && v2 != 201 )
  {
    v3 = *a1;
    *(_DWORD *)(v3 + 20) = 20;
    *(_DWORD *)(v3 + 24) = v2;
    (*(void (__stdcall **)(int *))v3)(a1);
  }
  result = sub_677730(a1);
  if ( result == 1 )
    return 1;
  if ( result == 2 )
  {
    if ( a2 )
    {
      v5 = *a1;
      *(_DWORD *)(v5 + 20) = 51;
      (*(void (__stdcall **)(int *))v5)(a1);
    }
    sub_6B5EE0(a1);
    return 2;
  }
  return result;
}
