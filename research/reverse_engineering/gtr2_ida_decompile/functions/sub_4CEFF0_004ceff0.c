int __thiscall sub_4CEFF0(_DWORD *this, int a2)
{
  int v2; // eax
  int v3; // eax
  int v5; // eax
  int v6; // esi

  v2 = this[75];
  if ( a2 )
  {
    v5 = v2 + 1;
    v6 = this[74] - 1;
    this[75] = v5;
    if ( v5 > v6 )
      this[75] = 0;
  }
  else
  {
    v3 = v2 - 1;
    this[75] = v3;
    if ( v3 < 0 )
    {
      this[75] = this[74] - 1;
      (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 172))(this, 0);
      return 0;
    }
  }
  (*(void (__thiscall **)(_DWORD *, int))(*this + 172))(this, a2);
  return 0;
}
