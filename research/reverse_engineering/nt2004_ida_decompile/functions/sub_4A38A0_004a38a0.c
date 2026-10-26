int __thiscall sub_4A38A0(_DWORD *this)
{
  int v2; // eax
  int v3; // edi
  _BYTE v5[4]; // [esp+8h] [ebp-8h] BYREF
  _BYTE v6[4]; // [esp+Ch] [ebp-4h] BYREF

  sub_4AE870(v6, v5);
  v2 = sub_49D1E0(this);
  v3 = v2;
  if ( !v2 || v2 == 6 || v2 == 7 )
    (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 3);
  if ( v3 == 3 || v3 == 8 || v3 == 9 )
    (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 44))(this, 0);
  return 0;
}
