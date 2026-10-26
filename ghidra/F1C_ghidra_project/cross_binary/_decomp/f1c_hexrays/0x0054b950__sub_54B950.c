// f1c  0x0054b950  size=143
_DWORD *__thiscall sub_54B950(_DWORD *this, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  int v5; // eax
  _DWORD *result; // eax

  v5 = this[129];
  if ( (*(_DWORD *)(v5 + 20) & 0x20000000) == 0 )
  {
    (*(void (__cdecl **)(int, int, int, _DWORD *))(*(_DWORD *)dword_8B8F24 + 4))(
      dword_8B8F24,
      v5 + 220,
      v5 + 232,
      this + 104);
    *(_DWORD *)(this[129] + 20) |= 0x20000000u;
  }
  if ( a2 )
    *a2 = *(_DWORD *)(this[129] + 232);
  if ( a3 )
    *a3 = *(_DWORD *)(this[129] + 236);
  result = a4;
  if ( a4 )
    *a4 = *(_DWORD *)(this[129] + 240);
  return result;
}
