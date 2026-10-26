// Address: 0x00488a30
// Size: 122 bytes
// Name: sub_488A30
// Type: int __thiscall(_BYTE *this)
// Source: IDA Hex-Rays decompilation

int __thiscall sub_488A30(_BYTE *this)
{
  int v2; // edi
  int v3; // eax
  int v5; // [esp+4h] [ebp-8h] BYREF
  _BYTE v6[4]; // [esp+8h] [ebp-4h] BYREF

  if ( this[236] )
  {
    sub_498880(v6, &v5);
    (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)this + 24))(this);
    v2 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 28))(this);
    v3 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 36))(this);
    if ( v5 >= v2 && v5 <= v3 )
      this[237] = 1;
    sub_488900(this);
    if ( !(*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 152))(this) )
    {
      (*(void (__thiscall **)(_BYTE *, int))(*(_DWORD *)this + 44))(this, 1);
      sub_486600(this);
    }
  }
  return 0;
}
