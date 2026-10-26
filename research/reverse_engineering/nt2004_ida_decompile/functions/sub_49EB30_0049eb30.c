int __thiscall sub_49EB30(_BYTE *this)
{
  int v2; // edi
  int v3; // eax
  int v5; // [esp+4h] [ebp-8h] BYREF
  _BYTE v6[4]; // [esp+8h] [ebp-4h] BYREF

  if ( this[280] )
  {
    sub_4AE870(v6, &v5);
    (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)this + 4))(this);
    v2 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 8))(this);
    v3 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 16))(this);
    if ( v5 >= v2 && v5 <= v3 )
      this[281] = 1;
    sub_49EA10(this);
    if ( !(*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 144))(this) )
      sub_49D0F0(this);
  }
  return 0;
}
