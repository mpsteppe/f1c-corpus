int __thiscall sub_40A210(int this, int a2)
{
  char v2; // dl
  int v3; // edi
  int v4; // esi
  __int16 v5; // ax
  int result; // eax
  unsigned __int16 v7; // [esp+10h] [ebp-Ch]
  int v8; // [esp+14h] [ebp-8h]

  v2 = *(_BYTE *)(a2 + 27);
  if ( (v2 & 0x20) != 0 && (v2 & 4) != 0 )
    v3 = *(_DWORD *)(a2 + 32);
  else
    v3 = *(_DWORD *)(a2 + 4);
  v4 = *(unsigned __int16 *)(a2 + 24);
  v5 = *(unsigned __int8 *)(a2 + 26);
  v7 = ((v2 & 1) != 0) + 1;
  v8 = (v7 * *(unsigned __int8 *)(a2 + 26)) >> 3;
  *(_DWORD *)(this + 48) = 1179011410;
  *(_DWORD *)(this + 52) = v3 + 36;
  *(_DWORD *)(this + 56) = 1163280727;
  *(_DWORD *)(this + 60) = 544501094;
  *(_DWORD *)(this + 64) = 16;
  *(_WORD *)(this + 68) = 1;
  *(_WORD *)(this + 70) = v7;
  *(_DWORD *)(this + 72) = v4;
  *(_DWORD *)(this + 76) = v4 * (unsigned __int16)v8;
  *(_WORD *)(this + 80) = v8;
  *(_WORD *)(this + 82) = v5;
  result = this + 84;
  *(_DWORD *)(this + 84) = 1635017060;
  *(_DWORD *)(this + 88) = v3;
  return result;
}
