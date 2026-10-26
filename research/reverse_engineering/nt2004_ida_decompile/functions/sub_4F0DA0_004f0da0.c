int sub_4F0DA0()
{
  int v0; // esi
  unsigned __int8 v2; // c0
  unsigned __int8 v3; // c2
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  _BYTE v6[4]; // [esp+10h] [ebp-8h] BYREF
  _BYTE v7[4]; // [esp+14h] [ebp-4h] BYREF

  v0 = dword_7D6BB0;
  if ( dword_7D6BB0 )
  {
    (*(void (__thiscall **)(int, _BYTE *, _BYTE *, _BYTE *))(*(_DWORD *)dword_7D6BB0 + 40))(dword_7D6BB0, v5, v6, v7);
    if ( v2 | v3 )
      (*(void (__thiscall **)(int, int, int, int))(*(_DWORD *)v0 + 44))(v0, 1, 1065353216, 1051931443);
  }
  return 0;
}
