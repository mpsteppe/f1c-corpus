int __stdcall sub_6D9330(int a1)
{
  int v1; // ecx

  v1 = *(_DWORD *)(a1 + 356);
  *(_DWORD *)(*(_DWORD *)(a1 + 340) + 12) = 0;
  (*(void (__stdcall **)(int))(v1 + 4))(a1);
  return (*(int (__stdcall **)(int))(*(_DWORD *)(a1 + 356) + 8))(a1);
}
