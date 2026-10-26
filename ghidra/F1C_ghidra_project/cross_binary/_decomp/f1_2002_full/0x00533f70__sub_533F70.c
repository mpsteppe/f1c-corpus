// f1_2002_full  0x00533f70  size=143
_DWORD *__thiscall sub_533F70(_DWORD *this, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  int v5; // eax
  _DWORD *result; // eax

  v5 = this[124];
  if ( (*(_DWORD *)(v5 + 20) & 0x20000000) == 0 )
  {
    (*(void (__cdecl **)(int, int, int, _DWORD *))(*(_DWORD *)dword_6C8CEC + 4))(
      dword_6C8CEC,
      v5 + 220,
      v5 + 232,
      this + 99);
    *(_DWORD *)(this[124] + 20) |= 0x20000000u;
  }
  if ( a2 )
    *a2 = *(_DWORD *)(this[124] + 232);
  if ( a3 )
    *a3 = *(_DWORD *)(this[124] + 236);
  result = a4;
  if ( a4 )
    *a4 = *(_DWORD *)(this[124] + 240);
  return result;
}
