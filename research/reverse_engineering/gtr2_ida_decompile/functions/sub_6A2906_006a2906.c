int __thiscall sub_6A2906(_DWORD *this)
{
  _DWORD *v2; // edx
  int result; // eax
  _DWORD *v4; // edi
  _DWORD v5[40]; // [esp+8h] [ebp-F4h] BYREF
  _BYTE v6[64]; // [esp+A8h] [ebp-54h] BYREF
  _DWORD v7[4]; // [esp+E8h] [ebp-14h] BYREF
  int v8; // [esp+F8h] [ebp-4h] BYREF

  v8 = 0;
  v7[0] = 0;
  v2 = (_DWORD *)this[64];
  result = 1;
  v7[1] = 1;
  v7[2] = 2;
  v7[3] = 3;
  if ( (*v2 & 0xFFFFF) == 3 )
  {
    result = sub_6BB35B(v2, &unk_7435D8, v6, &v8, v5, v7, 3, 1);
    if ( !result )
    {
      v4 = *(_DWORD **)(this[64] + 8);
      *v4++ = v5[0];
      *v4 = v5[1];
      v4[1] = v5[2];
      return 0;
    }
  }
  return result;
}
