int __thiscall sub_4CF360(_DWORD *this)
{
  int v2; // edi
  _BYTE v4[4]; // [esp+8h] [ebp-8h] BYREF
  _BYTE v5[4]; // [esp+Ch] [ebp-4h] BYREF

  sub_4DE540(v5, v4);
  v2 = this[33];
  if ( !v2 || v2 == 6 || v2 == 7 )
    (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 3);
  if ( v2 == 3 || v2 == 8 || v2 == 9 )
    (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 44))(this, 0);
  return 0;
}
