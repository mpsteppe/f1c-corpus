FILE *__stdcall sub_6D3C50(_DWORD *a1, int (__stdcall **a2)(int *a1, int a2, int a3, int Offset, int a5), int a3)
{
  FILE *result; // eax
  int (__stdcall **v4)(_DWORD *); // eax

  result = tmpfile();
  a2[3] = (int (__stdcall *)(int *, int, int, int, int))result;
  if ( !result )
  {
    v4 = (int (__stdcall **)(_DWORD *))*a1;
    v4[5] = (int (__stdcall *)(_DWORD *))63;
    sub_630FE0((int)(v4 + 6), (int)WindowName, 80);
    result = (FILE *)(*(int (__stdcall **)(_DWORD *))*a1)(a1);
  }
  *a2 = sub_6D3B70;
  a2[1] = sub_6D3BD0;
  a2[2] = (int (__stdcall *)(int *, int, int, int, int))sub_6D3C30;
  return result;
}
