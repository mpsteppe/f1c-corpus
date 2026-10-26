int __fastcall sub_5BD9A0(int a1, int a2)
{
  _DWORD *v4; // eax
  int v5; // ebx

  v4 = (_DWORD *)sub_5BE1B0(*(_DWORD *)(a1 + 4), a2);
  v5 = *v4;
  (*(void (__fastcall **)(int, int, _DWORD, _DWORD))(a1 + 1152))(a1, 2, *v4, *(_DWORD *)(a1 + 1156));
  sub_5BE2D0(*(_DWORD *)(a1 + 4), a2);
  return sub_5BD9E0(a1, v5);
}
