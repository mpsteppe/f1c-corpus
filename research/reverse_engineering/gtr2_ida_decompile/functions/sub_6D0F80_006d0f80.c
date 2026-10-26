int __stdcall sub_6D0F80(int *a1, int a2)
{
  int (__stdcall **v2)(int *, int); // edi
  int result; // eax
  int (__stdcall *v4)(int *, int); // eax
  int v5; // eax

  v2 = (int (__stdcall **)(int *, int))(*(int (__stdcall **)(int *, int, int))a1[1])(a1, 1, 28);
  result = a1[21];
  a1[109] = (int)v2;
  *v2 = sub_6D0F00;
  v2[2] = 0;
  v2[3] = 0;
  if ( result )
  {
    v4 = (int (__stdcall *)(int *, int))a1[79];
    v2[4] = v4;
    if ( a2 )
    {
      v5 = *a1;
      *(_DWORD *)(v5 + 20) = 4;
      return (*(int (__stdcall **)(int *))v5)(a1);
    }
    else
    {
      result = (*(int (__stdcall **)(int *, int, int, int (__stdcall *)(int *, int)))(a1[1] + 8))(
                 a1,
                 1,
                 a1[28] * a1[30],
                 v4);
      v2[3] = (int (__stdcall *)(int *, int))result;
    }
  }
  return result;
}
