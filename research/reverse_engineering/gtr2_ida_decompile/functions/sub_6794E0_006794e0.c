int __stdcall sub_6794E0(int *a1, int a2)
{
  int v2; // ecx
  int v3; // eax
  int v4; // edx
  int result; // eax

  v2 = a1[5];
  if ( v2 != 100 )
  {
    v3 = *a1;
    *(_DWORD *)(v3 + 20) = 20;
    *(_DWORD *)(v3 + 24) = v2;
    (*(void (__stdcall **)(int *))v3)(a1);
  }
  if ( a2 )
    sub_679390(a1, 0);
  (*(void (__stdcall **)(int *))(*a1 + 16))(a1);
  (*(void (__stdcall **)(int *))(a1[6] + 8))(a1);
  sub_6B7160(a1);
  (*(void (__stdcall **)(int *))a1[85])(a1);
  v4 = a1[44];
  a1[58] = 0;
  result = (v4 != 0) + 101;
  a1[5] = result;
  return result;
}
