int __stdcall sub_6DB4D9(_DWORD *a1, int a2)
{
  sub_6DACA9(a1, a2, 0);
  (*(void (__stdcall **)(_DWORD, _DWORD))(a2 + 36))(*(_DWORD *)(a2 + 40), a1[10]);
  (*(void (__stdcall **)(_DWORD, _DWORD))(a2 + 36))(*(_DWORD *)(a2 + 40), a1[9]);
  (*(void (__stdcall **)(_DWORD, _DWORD *))(a2 + 36))(*(_DWORD *)(a2 + 40), a1);
  return 0;
}
