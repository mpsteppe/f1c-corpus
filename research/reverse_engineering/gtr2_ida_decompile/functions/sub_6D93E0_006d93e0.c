int __stdcall sub_6D93E0(int a1, int a2)
{
  int (__stdcall **v2)(int); // edi
  int result; // eax
  bool v4; // zf

  v2 = (int (__stdcall **)(int))(**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 36);
  *(_DWORD *)(a1 + 340) = v2;
  *v2 = sub_6D91B0;
  v2[1] = sub_6D9330;
  v2[2] = (int (__stdcall *)(int))sub_6D9360;
  v2[4] = 0;
  result = sub_6D8A20((int *)a1);
  if ( *(_DWORD *)(a1 + 172) )
  {
    result = sub_6D8BD0((int *)a1);
  }
  else
  {
    *(_DWORD *)(a1 + 236) = 0;
    *(_DWORD *)(a1 + 168) = 1;
  }
  if ( *(_DWORD *)(a1 + 236) )
    *(_DWORD *)(a1 + 184) = 1;
  if ( a2 )
    v2[5] = (int (__stdcall *)(int))((*(_DWORD *)(a1 + 184) == 0) + 1);
  else
    v2[5] = 0;
  v4 = *(_DWORD *)(a1 + 184) == 0;
  v2[8] = 0;
  v2[6] = 0;
  if ( v4 )
  {
    result = *(_DWORD *)(a1 + 168);
    v2[7] = (int (__stdcall *)(int))result;
  }
  else
  {
    v2[7] = (int (__stdcall *)(int))(2 * *(_DWORD *)(a1 + 168));
  }
  return result;
}
