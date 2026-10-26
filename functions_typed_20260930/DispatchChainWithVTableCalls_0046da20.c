int __thiscall DispatchChainWithVTableCalls(_DWORD **this)
{
  _DWORD *v2; // eax

  sub_42D210(&dword_7C569C, 1);
  v2 = (_DWORD *)(*(int (__thiscall **)(_DWORD *, int))(*this[16] + 28))(this[16], 30);
  sub_46BF10(v2, 1);
  sub_4D2450(dword_8ACEE0);
  ((void (__thiscall *)(_DWORD **, int))(*this)[14])(this, 1);
  return 0;
}

