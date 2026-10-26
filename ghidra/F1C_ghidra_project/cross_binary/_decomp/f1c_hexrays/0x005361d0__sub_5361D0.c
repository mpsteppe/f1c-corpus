// f1c  0x005361d0  size=137
char __thiscall sub_5361D0(int this)
{
  int v2; // eax
  int v3; // edi
  int v4; // eax

  if ( !this )
    return -2;
  v2 = *(_DWORD *)(this + 28);
  if ( !v2 )
    return -2;
  v3 = *(_DWORD *)(v2 + 4);
  if ( v3 != 42 && v3 != 113 && v3 != 666 )
    return -2;
  v4 = *(_DWORD *)(v2 + 8);
  if ( v4 )
    (*(void (__fastcall **)(_DWORD, int))(this + 36))(*(_DWORD *)(this + 40), v4);
  if ( *(_DWORD *)(*(_DWORD *)(this + 28) + 58) )
    (*(void (__thiscall **)(_DWORD))(this + 36))(*(_DWORD *)(this + 40));
  if ( *(_DWORD *)(*(_DWORD *)(this + 28) + 54) )
    (*(void (__thiscall **)(_DWORD))(this + 36))(*(_DWORD *)(this + 40));
  if ( *(_DWORD *)(*(_DWORD *)(this + 28) + 46) )
    (*(void (__thiscall **)(_DWORD))(this + 36))(*(_DWORD *)(this + 40));
  (*(void (__fastcall **)(_DWORD, _DWORD))(this + 36))(*(_DWORD *)(this + 40), *(_DWORD *)(this + 28));
  *(_DWORD *)(this + 28) = 0;
  return v3 != 113 ? 0 : 0xFD;
}
