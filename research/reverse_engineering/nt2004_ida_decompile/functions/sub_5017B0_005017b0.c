int __stdcall sub_5017B0(int a1, int a2, _DWORD *a3, int a4, _DWORD *a5, int a6)
{
  int result; // eax
  int v7; // ecx

  result = sub_501810(a6);
  if ( result )
  {
    sub_5A41F0(a1, &a6, &a1, 0);
    v7 = a4;
    *a3 = a2 - a6 / 2;
    result = a1 / 2;
    *a5 = v7 - a1 / 2;
  }
  return result;
}
