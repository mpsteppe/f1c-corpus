int __thiscall sub_4A2BA0(_BYTE *this)
{
  _DWORD *v2; // ecx
  int v4; // eax
  int v5; // [esp+4h] [ebp-8h] BYREF
  int v6; // [esp+8h] [ebp-4h] BYREF

  if ( sub_49D1D0(this) )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)this + 44))(5);
    (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)this + 164))(this);
    return 0;
  }
  if ( sub_49D1E0(v2) == 5
    || (sub_4AE870(&v6, &v5), !(*(int (__thiscall **)(_BYTE *, int, int))(*(_DWORD *)this + 20))(this, v6, v5)) )
  {
    (*(void (__thiscall **)(_BYTE *, _DWORD))(*(_DWORD *)this + 44))(this, 0);
  }
  else
  {
    v4 = sub_49D1E0(this);
    if ( !v4 )
    {
      (*(void (__thiscall **)(_BYTE *, int))(*(_DWORD *)this + 44))(this, 2);
      (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)this + 164))(this);
      return 0;
    }
    if ( v4 == 5 )
      (*(void (__thiscall **)(_BYTE *, int))(*(_DWORD *)this + 44))(this, 2);
  }
  (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)this + 164))(this);
  return 0;
}
