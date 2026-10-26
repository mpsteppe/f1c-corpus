char __thiscall sub_49ADC0(_DWORD *this, __int16 a2, __int16 a3)
{
  _WORD *v4; // esi
  int v5; // eax

  v4 = (_WORD *)sub_587C03(4);
  if ( v4 )
  {
    *v4 = a2;
    v4[1] = a3;
    v5 = sub_587C03(12);
    if ( v5 )
    {
      *(_DWORD *)v5 = v4;
      *(_DWORD *)(v5 + 4) = 0;
      *(_BYTE *)(v5 + 8) = 1;
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
    sub_587BCF(0);
    return 0;
  }
}
