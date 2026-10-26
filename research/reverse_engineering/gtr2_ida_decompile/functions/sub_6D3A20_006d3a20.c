char __stdcall sub_6D3A20(int *a1, _DWORD *a2, int a3, __m64 **a4)
{
  int v4; // eax

  v4 = a1[18];
  if ( v4 == 5 || v4 == 6 )
    return sub_6D3510(a4, a3, a1, a2);
  else
    return sub_6D3320(a3, a1, a2, (int)a4);
}
