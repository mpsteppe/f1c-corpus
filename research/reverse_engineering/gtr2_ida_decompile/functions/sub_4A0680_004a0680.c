int __thiscall sub_4A0680(_DWORD *this)
{
  int v2; // eax
  int v3; // edi
  int v4; // eax
  int v5; // edi
  _BYTE v7[152]; // [esp+0h] [ebp-98h] BYREF

  v2 = sub_4CF9D0(0);
  if ( v2 )
  {
    v3 = sub_4DEF00(this[12], v2);
    if ( v3 )
    {
      (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 44))(this, 0);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 40))(v3, 0);
    }
  }
  (*(void (__thiscall **)(_DWORD *))(*this + 56))(this);
  (*(void (__thiscall **)(_DWORD *))(*this + 152))(this);
  v4 = sub_4CF9D0(0);
  if ( v4 )
  {
    v5 = sub_4DEF00(this[12], v4);
    if ( v5 )
    {
      (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 44))(this, 0);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v5 + 40))(v5, 0);
    }
  }
  sub_501490(v7, 127);
  return sub_4CE770(v7);
}
