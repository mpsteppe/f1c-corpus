void __thiscall sub_6054E0(_DWORD *this)
{
  int v2; // eax
  int v3; // eax

  if ( (this[1] & 0x10000000) != 0 )
  {
    v2 = this[165];
    if ( v2 )
    {
      (*(void (__thiscall **)(_DWORD *, int, _DWORD))(*this + 408))(this, v2, 0);
      this[165] = 0;
    }
    v3 = this[164];
    if ( v3 )
    {
      (*(void (__thiscall **)(_DWORD *, int, _DWORD))(*this + 408))(this, v3, 0);
      this[164] = 0;
    }
    if ( this[166] )
    {
      (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 448))(this, this[166]);
      this[166] = 0;
    }
    this[2253] = 0;
    this[2254] = 0;
    this[2255] = 0;
    this[2256] = 0;
    this[2257] = 0;
    this[2258] = 0;
    this[1] &= ~0x10000000u;
  }
}
