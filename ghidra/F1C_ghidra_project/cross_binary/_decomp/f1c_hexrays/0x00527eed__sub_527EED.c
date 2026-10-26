// f1c  0x00527eed  size=52
int __cdecl sub_527EED(_DWORD *a1, int a2)
{
  sub_52765A(a1, a2, 0);
  (*(void (__cdecl **)(_DWORD, _DWORD))(a2 + 36))(*(_DWORD *)(a2 + 40), a1[10]);
  (*(void (__cdecl **)(_DWORD, _DWORD))(a2 + 36))(*(_DWORD *)(a2 + 40), a1[9]);
  (*(void (__cdecl **)(_DWORD, _DWORD *))(a2 + 36))(*(_DWORD *)(a2 + 40), a1);
  return 0;
}
