void __thiscall sub_48F5D0(_DWORD *this, int a2, char a3)
{
  int v4; // eax

  if ( a2 )
  {
    v4 = OperatorNewNhMallocWrapper(16);
    if ( v4 )
    {
      *(_DWORD *)v4 = a2;
      *(_DWORD *)(v4 + 4) = 0;
      *(_DWORD *)(v4 + 8) = 0;
      *(_BYTE *)(v4 + 12) = a3;
    }
    else
    {
      v4 = 0;
    }
    if ( this[60] )
    {
      *(_DWORD *)(this[61] + 4) = v4;
      *(_DWORD *)(v4 + 8) = this[61];
    }
    else
    {
      this[60] = v4;
      this[62] = v4;
    }
    this[61] = v4;
    ++this[63];
  }
}

