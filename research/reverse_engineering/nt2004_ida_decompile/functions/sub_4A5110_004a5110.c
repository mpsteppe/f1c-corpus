void __thiscall sub_4A5110(_DWORD *this, int a2, char a3)
{
  _DWORD *v4; // eax

  if ( a2 )
  {
    v4 = operator new(0x10u);
    if ( v4 )
    {
      *v4 = a2;
      v4[1] = 0;
      v4[2] = 0;
      *((_BYTE *)v4 + 12) = a3;
    }
    else
    {
      v4 = 0;
    }
    if ( this[71] )
    {
      *(_DWORD *)(this[72] + 4) = v4;
      v4[2] = this[72];
    }
    else
    {
      this[71] = v4;
      this[73] = v4;
    }
    this[72] = v4;
    ++this[74];
  }
}
