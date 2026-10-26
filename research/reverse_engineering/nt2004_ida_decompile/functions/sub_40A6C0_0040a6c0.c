void __thiscall sub_40A6C0(_DWORD *this, int a2)
{
  _DWORD *v3; // eax

  if ( a2 )
  {
    v3 = operator new(0x10u);
    if ( v3 )
    {
      *v3 = a2;
      v3[1] = 0;
      v3[2] = 0;
      *((_BYTE *)v3 + 12) = 1;
    }
    else
    {
      v3 = 0;
    }
    if ( *this )
    {
      *(_DWORD *)(this[1] + 4) = v3;
      v3[2] = this[1];
    }
    else
    {
      *this = v3;
      this[2] = v3;
    }
    this[1] = v3;
    ++this[3];
  }
}
