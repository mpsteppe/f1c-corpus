int __thiscall sub_558D10(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // eax
  int v5; // edi

  result = this[8];
  if ( (result & 0x100) == 0 )
  {
    v4 = result | 0x100;
    v5 = a2 << 6;
    this[8] = v4;
    if ( (v4 & 0x80u) == 0 )
      result = sub_540F00(
                 dword_8B78A0,
                 *(_DWORD **)(this[20] + v5 + 28),
                 96,
                 *(_DWORD *)(this[20] + v5 + 44),
                 this[11] * *(_DWORD *)(this[20] + v5 + 8));
    else
      result = sub_540F00(
                 dword_8B78A0,
                 *(_DWORD **)(v5 + this[20] + 28),
                 32,
                 *(_DWORD *)(this[20] + v5 + 44),
                 *(_DWORD *)(this[20] + v5 + 8));
    *(_DWORD *)(this[20] + v5 + 32) = result;
  }
  return result;
}
