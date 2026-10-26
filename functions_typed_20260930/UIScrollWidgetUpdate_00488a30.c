int __thiscall sub_488A30(_BYTE *this)
{
  int v2; // edi
  int v3; // eax
  int v5; // [esp+4h] [ebp-8h] BYREF
  _BYTE v6[4]; // [esp+8h] [ebp-4h] BYREF

  if ( this[236] )
  {
    DualFieldRead(v6, &v5);
    (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)this + 24))(this);
    v2 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 28))(this);
    v3 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 36))(this);
    if ( v5 >= v2 && v5 <= v3 )
      this[237] = 1;
    DeltaBasedUpdate(this);
    if ( !(*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 152))(this) )
    {
      (*(void (__thiscall **)(_BYTE *, int))(*(_DWORD *)this + 44))(this, 1);
      sub_486600(this);
    }
  }
  return 0;
}

