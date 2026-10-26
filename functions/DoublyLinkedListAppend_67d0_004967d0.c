void __thiscall sub_4967D0(_DWORD *this, int a2)
{
  int v3; // eax

  if ( a2 )
  {
    v3 = OperatorNewNhMallocWrapper(16);
    if ( v3 )
    {
      *(_DWORD *)v3 = a2;
      *(_DWORD *)(v3 + 4) = 0;
      *(_DWORD *)(v3 + 8) = 0;
      *(_BYTE *)(v3 + 12) = 0;
    }
    else
    {
      v3 = 0;
    }
    if ( this[1587] )
    {
      *(_DWORD *)(this[1588] + 4) = v3;
      *(_DWORD *)(v3 + 8) = this[1588];
    }
    else
    {
      this[1587] = v3;
      this[1589] = v3;
    }
    this[1588] = v3;
    ++this[1590];
  }
}
