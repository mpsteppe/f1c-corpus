int __thiscall sub_5A45F0(_DWORD *this)
{
  int v2; // eax
  int v3; // eax
  int v5; // eax

  if ( this[1111] )
  {
    v2 = this[1112];
    if ( v2 )
    {
      *this = (*(int (__stdcall **)(int))(*(_DWORD *)v2 + 8))(v2);
      this[1112] = 0;
      memset(this + 1113, 0, 0x34u);
    }
    *this = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)this[1111] + 8))(this[1111]);
    this[1111] = 0;
  }
  this[26] = 0;
  this[25] = 0;
  this[1126] = 0;
  v3 = Direct3DCreate8(220);
  this[1111] = v3;
  if ( v3 )
  {
    v5 = this[1297];
    if ( v5 )
    {
      if ( (unsigned int)(v5 - 1) <= 1 )
        this[1296] = 1;
    }
    else
    {
      this[1296] = 0;
    }
    sub_5A78B0(this);
    this[2135] = 0;
    this[2069] = 0;
    this[2070] = 0;
    this[2071] = 0;
    this[2072] = 0;
    this[2073] = 0;
    this[2074] = 0;
    this[2075] = 0;
    this[2076] = 0;
    this[2145] = 0;
    this[2171] = 0;
    return 0;
  }
  else
  {
    sub_591C60((int)this, -1, aErrorCreatingD);
    return -1;
  }
}
