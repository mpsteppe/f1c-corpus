char __thiscall sub_488900(_BYTE *this)
{
  int v2; // edi
  int v3; // eax
  int v5; // [esp+8h] [ebp-8h] BYREF
  _BYTE v6[4]; // [esp+Ch] [ebp-4h] BYREF

  DualFieldRead(&v5, v6);
  v2 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 24))(this);
  (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)this + 28))(this);
  (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)this + 36))(this);
  LOBYTE(v3) = this[237];
  if ( (_BYTE)v3 )
  {
    v3 = v5 - v2;
    if ( *((_DWORD *)this + 56) != v5 - v2 )
    {
      *((_DWORD *)this + 56) = v3;
      ShortComputation_8970(this);
      LOBYTE(v3) = (*(int (__thiscall **)(_BYTE *, int))(*(_DWORD *)this + 44))(this, 1);
    }
  }
  return v3;
}

