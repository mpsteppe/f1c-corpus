void __thiscall sub_4ACA70(_DWORD *this, int a2)
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
      *((_BYTE *)v3 + 12) = 0;
    }
    else
    {
      v3 = 0;
    }
    if ( this[279] )
    {
      *(_DWORD *)(this[280] + 4) = v3;
      v3[2] = this[280];
    }
    else
    {
      this[279] = v3;
      this[281] = v3;
    }
    this[280] = v3;
    ++this[282];
  }
}
