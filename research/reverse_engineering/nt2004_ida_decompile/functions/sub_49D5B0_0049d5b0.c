void __thiscall sub_49D5B0(_DWORD *this, int a2, int a3)
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
      sub_578600(a2);
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
      if ( this[13] )
      {
        *(_DWORD *)(this[14] + 4) = v9;
      }
      else
      {
        this[13] = v9;
        this[15] = v9;
      }
      this[14] = v9;
      ++this[16];
    }
  }
  else
  {
    if ( a3 >= this[16] )
    {
      this[15] = 0;
    }
    else
    {
      this[15] = this[13];
      do
      {
        v5 = this[15];
        if ( !v5 )
          break;
        --v4;
        this[15] = *(_DWORD *)(v5 + 4);
      }
      while ( v4 > 0 );
    }
    v6 = (_DWORD *)this[15];
    if ( v6 )
    {
      if ( *v6 )
        sub_578600(a2);
    }
  }
}
