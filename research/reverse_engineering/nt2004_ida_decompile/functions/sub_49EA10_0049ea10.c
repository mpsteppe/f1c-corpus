char __thiscall sub_49EA10(_BYTE *this)
{
  int v2; // edi
  int v3; // eax
  int v5; // [esp+8h] [ebp-8h] BYREF
  _BYTE v6[4]; // [esp+Ch] [ebp-4h] BYREF

  sub_4AE870(&v5, v6);
  v2 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 4))(this);
  (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)this + 8))(this);
  (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)this + 16))(this);
  LOBYTE(v3) = this[281];
  if ( (_BYTE)v3 )
  {
    v3 = v5 - v2;
    if ( *((_DWORD *)this + 67) != v5 - v2 )
    {
      *((_DWORD *)this + 67) = v3;
      LOBYTE(v3) = sub_49EA70(this);
    }
  }
  return v3;
}
