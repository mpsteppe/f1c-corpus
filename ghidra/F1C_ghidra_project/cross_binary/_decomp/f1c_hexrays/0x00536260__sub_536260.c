// f1c  0x00536260  size=145
int __thiscall sub_536260(int this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  int v5; // ecx
  int result; // eax

  v2 = *(_DWORD *)(this + 34);
  v3 = *(_DWORD *)(this + 66);
  *(_DWORD *)(this + 50) = 2 * v2;
  *(_WORD *)(*(_DWORD *)(this + 58) + 2 * v3 - 2) = 0;
  memset(*(void **)(this + 58), 0, 2 * *(_DWORD *)(this + 66) - 2);
  v4 = 6 * *(_DWORD *)(this + 122);
  *(_DWORD *)(this + 118) = (unsigned __int16)word_5B77EA[v4];
  *(_DWORD *)(this + 130) = (unsigned __int16)word_5B77E8[v4];
  *(_DWORD *)(this + 134) = (unsigned __int16)word_5B77EC[v4];
  v5 = (unsigned __int16)word_5B77EE[v4];
  *(_DWORD *)(this + 98) = 0;
  *(_DWORD *)(this + 82) = 0;
  *(_DWORD *)(this + 106) = 0;
  result = 2;
  *(_DWORD *)(this + 94) = 0;
  *(_DWORD *)(this + 62) = 0;
  *(_DWORD *)(this + 114) = v5;
  *(_DWORD *)(this + 110) = 2;
  *(_DWORD *)(this + 86) = 2;
  return result;
}
