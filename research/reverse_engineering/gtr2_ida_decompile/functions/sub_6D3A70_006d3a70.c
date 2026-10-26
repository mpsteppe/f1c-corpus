int __stdcall sub_6D3A70(int a1)
{
  int v1; // eax
  int v2; // edx
  int (__stdcall **v3)(int); // esi
  int v4; // eax
  int v5; // ecx

  v1 = (**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 48);
  v2 = *(_DWORD *)(a1 + 316);
  v3 = (int (__stdcall **)(int))v1;
  v4 = *(_DWORD *)(a1 + 112) * *(_DWORD *)(a1 + 120);
  *(_DWORD *)(a1 + 456) = v3;
  *v3 = sub_6D30A0;
  v3[2] = 0;
  v3[10] = (int (__stdcall *)(int))v4;
  if ( v2 == 2 )
  {
    v5 = *(_DWORD *)(a1 + 4);
    v3[1] = (int (__stdcall *)(int))sub_6D30C0;
    v3[3] = (int (__stdcall *)(int))sub_6D3A20;
    v3[8] = (int (__stdcall *)(int))(*(int (__stdcall **)(int, int, int))(v5 + 4))(a1, 1, v4);
  }
  else
  {
    v3[1] = (int (__stdcall *)(int))sub_6D3190;
    v3[3] = (int (__stdcall *)(int))sub_6D31D0;
    v3[8] = 0;
  }
  return sub_6D2FC0(a1);
}
