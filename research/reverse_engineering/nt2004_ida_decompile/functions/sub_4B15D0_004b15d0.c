char __thiscall sub_4B15D0(_DWORD *this, __int16 a2, __int16 a3)
{
  _WORD *v4; // esi
  _DWORD *v5; // eax

  v4 = operator new(4u);
  if ( v4 )
  {
    *v4 = a2;
    v4[1] = a3;
    v5 = operator new(0xCu);
    if ( v5 )
    {
      *v5 = v4;
      v5[1] = 0;
      *((_BYTE *)v5 + 8) = 1;
    }
    else
    {
      v5 = 0;
    }
    if ( *this )
    {
      *(_DWORD *)(this[1] + 4) = v5;
    }
    else
    {
      *this = v5;
      this[2] = v5;
    }
    this[1] = v5;
    ++this[3];
    return 1;
  }
  else
  {
    sub_5BE8AE(0);
    return 0;
  }
}
