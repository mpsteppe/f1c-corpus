char __thiscall sub_562DD0(_DWORD *this, char a2)
{
  int v2; // eax

  LOBYTE(v2) = a2;
  if ( !a2 )
  {
    this[2] = 0;
    return v2;
  }
  if ( dword_B710B0 != 1 )
  {
    v2 = this[4];
    if ( !v2 )
      return v2;
    v2 = dword_B7108C;
    goto LABEL_11;
  }
  LOBYTE(v2) = dword_B7108C;
  if ( dword_B7108C == 1 )
  {
    v2 = this[4];
LABEL_11:
    if ( v2 )
      this[2] = 1;
    return v2;
  }
  if ( this[5] && dword_B7108C )
    this[2] = 2;
  return v2;
}
