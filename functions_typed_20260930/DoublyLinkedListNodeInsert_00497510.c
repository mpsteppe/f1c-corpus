int __thiscall sub_497510(_DWORD *this, int a2)
{
  int v3; // eax

  ++this[11];
  SimpleSetter_fdf0(this);
  SimpleSetter_fc40(1);
  if ( a2 )
  {
    v3 = OperatorNewNhMallocWrapper(16);
    if ( v3 )
    {
      *(_DWORD *)v3 = a2;
      *(_DWORD *)(v3 + 4) = 0;
      *(_DWORD *)(v3 + 8) = 0;
      *(_BYTE *)(v3 + 12) = 1;
    }
    else
    {
      v3 = 0;
    }
    if ( !this[1] )
    {
      this[1] = v3;
      this[3] = v3;
      this[2] = v3;
      ++this[4];
      return a2;
    }
    *(_DWORD *)(this[2] + 4) = v3;
    *(_DWORD *)(v3 + 8) = this[2];
    this[2] = v3;
    ++this[4];
  }
  return a2;
}

