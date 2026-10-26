int __thiscall std::string::_Copy(int this, unsigned int a2)
{
  unsigned int v2; // edi
  size_t v4; // eax
  size_t v5; // eax
  unsigned int v6; // ebx
  int result; // eax
  _DWORD v8[9]; // [esp+0h] [ebp-24h] BYREF
  _BYTE *v9; // [esp+2Ch] [ebp+8h]

  v2 = a2 | 0x1F;
  v8[5] = v8;
  v8[4] = this;
  if ( (a2 | 0x1F) > 0xFFFFFFFD )
    v2 = a2;
  v8[8] = 0;
  v4 = v2 + 2;
  if ( (int)(v2 + 2) < 0 )
    v4 = 0;
  v9 = (_BYTE *)operator new(v4);
  v5 = *(_DWORD *)(this + 8);
  if ( v5 )
  {
    if ( v5 > v2 )
      v5 = v2;
    memcpy_0(v9 + 1, *(const void **)(this + 4), v5);
  }
  v6 = *(_DWORD *)(this + 8);
  std::string::_Tidy((_DWORD *)this, 1);
  *(_DWORD *)(this + 4) = v9 + 1;
  *v9 = 0;
  *(_DWORD *)(this + 12) = v2;
  if ( v6 <= v2 )
    v2 = v6;
  result = *(_DWORD *)(this + 4);
  *(_DWORD *)(this + 8) = v2;
  *(_BYTE *)(result + v2) = 0;
  return result;
}
