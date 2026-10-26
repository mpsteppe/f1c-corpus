int __stdcall sub_6B7160(int a1)
{
  int v1; // eax
  BOOL v2; // eax

  sub_6D93E0(a1, 0);
  if ( !*(_DWORD *)(a1 + 176) )
  {
    sub_6D8820(a1);
    sub_6D7FE0(a1);
    sub_6D7520(a1, 0);
  }
  sub_6D6F10(a1);
  if ( *(_DWORD *)(a1 + 180) )
  {
    v1 = *(_DWORD *)a1;
    *(_DWORD *)(v1 + 20) = 1;
    (*(void (__stdcall **)(int))v1)(a1);
  }
  else if ( *(_DWORD *)(a1 + 236) )
  {
    sub_6D6130(a1);
  }
  else
  {
    sub_6D54D0(a1);
  }
  v2 = *(int *)(a1 + 168) > 1 || *(_DWORD *)(a1 + 184);
  sub_6D4610(a1, v2);
  sub_6D3DD0(a1, 0);
  sub_6B7100(a1);
  (*(void (__stdcall **)(int))(*(_DWORD *)(a1 + 4) + 24))(a1);
  return (**(int (__stdcall ***)(int))(a1 + 356))(a1);
}
