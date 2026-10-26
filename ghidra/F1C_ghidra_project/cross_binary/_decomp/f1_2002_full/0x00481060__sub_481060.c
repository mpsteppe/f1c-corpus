// f1_2002_full  0x00481060  size=211
void __thiscall sub_481060(_DWORD *this, int a2, int a3)
{
  int v4; // ecx
  int v5; // eax
  _DWORD *v6; // esi
  _DWORD *v7; // eax
  _DWORD *v8; // edi
  _DWORD *v9; // eax

  v4 = a3;
  if ( a3 <= 0 )
  {
    v7 = operator new(8u);
    v8 = v7;
    if ( v7 )
    {
      *v7 = 0;
      v7[1] = -1;
      sub_55B160(a2);
    }
    else
    {
      v8 = 0;
    }
    if ( v8 )
    {
      v9 = operator new(0xCu);
      if ( v9 )
      {
        *v9 = v8;
        v9[1] = 0;
        *((_BYTE *)v9 + 8) = 1;
      }
      else
      {
        v9 = 0;
      }
      if ( this[17] )
      {
        *(_DWORD *)(this[18] + 4) = v9;
      }
      else
      {
        this[17] = v9;
        this[19] = v9;
      }
      this[18] = v9;
      ++this[20];
    }
  }
  else
  {
    if ( a3 >= this[20] )
    {
      this[19] = 0;
    }
    else
    {
      this[19] = this[17];
      do
      {
        v5 = this[19];
        if ( !v5 )
          break;
        --v4;
        this[19] = *(_DWORD *)(v5 + 4);
      }
      while ( v4 > 0 );
    }
    v6 = (_DWORD *)this[19];
    if ( v6 )
    {
      if ( *v6 )
        sub_55B160(a2);
    }
  }
}
