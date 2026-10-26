// Address: 0x004c99d0
// Size: 125 bytes
// Name: sub_4C99D0
// Type: int()
// Source: IDA Hex-Rays decompilation

int sub_4C99D0()
{
  int v0; // esi
  unsigned __int8 v2; // c0
  unsigned __int8 v3; // c2
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  _BYTE v6[4]; // [esp+10h] [ebp-8h] BYREF
  _BYTE v7[4]; // [esp+14h] [ebp-4h] BYREF

  v0 = dword_8AC4C4;
  if ( dword_8AC4C4 )
  {
    (*(void (__thiscall **)(int, _BYTE *, _BYTE *, _BYTE *))(*(_DWORD *)dword_8AC4C4 + 36))(dword_8AC4C4, v5, v6, v7);
    if ( v2 | v3 )
      (*(void (__thiscall **)(int, int, int, int))(*(_DWORD *)v0 + 40))(v0, 1, 1065353216, 1051931443);
  }
  return 0;
}
