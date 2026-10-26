// f1c  0x005878a0  size=131
bool __thiscall sub_5878A0(int this, int a2)
{
  bool v3; // bl
  int v4; // eax
  _DWORD *v5; // eax
  int v6; // edi

  v3 = 0;
  v4 = sub_587880((_DWORD *)this);
  if ( v4 < a2 || v4 <= 0 )
    return 0;
  v5 = (_DWORD *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 1044) + 88))(*(_DWORD *)(this + 1044));
  v6 = (int)v5;
  if ( v5 )
  {
    sub_586800(v5, 0, 13, 0, 1, *(_DWORD *)(this + 1036));
    sub_586A00(this, *(_DWORD *)(this + 1024));
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(v6 + 72) + 12))(
      *(_DWORD *)(v6 + 72),
      *(_DWORD *)(this + 1040));
    v3 = sub_585380(*(_DWORD **)(this + 1044), v6) == 0;
  }
  sub_5879F0(this);
  return v3;
}
