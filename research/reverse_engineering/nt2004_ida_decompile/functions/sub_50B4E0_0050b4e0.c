void __thiscall sub_50B4E0(_DWORD *this, int a2, char a3)
{
  int v4; // eax
  void *v5; // eax
  void *v6; // edi
  CHAR *v7; // eax
  CHAR *v8; // eax
  CHAR *v9; // eax
  int v10; // ecx
  _DWORD *v11; // edi
  int v12; // ebx
  BOOL v13; // edi
  BOOL v14; // ebp
  _DWORD *v15; // edi
  int v16; // ebp

  v4 = 3;
  if ( (*(_DWORD *)(*this + 25296) & 2) != 0 )
    v4 = a2;
  if ( v4 != this[717] || a3 )
  {
    this[717] = v4;
    switch ( v4 )
    {
      case 0:
        if ( this[1] )
          sub_59ECC0(1, 1, 1, 0);
        if ( this[630] )
          sub_59ECC0(0, 0, 0, 0);
        if ( this[1] )
        {
          if ( *(_DWORD *)(*this + 25248) == *(_DWORD *)(dword_75AAD0[dword_75AAC8] + 25248) )
            sub_59EF70(dword_767C58 > 0, 1, 0);
          else
            sub_59EF70(dword_767C58 > 1, 1, 0);
        }
        if ( dword_75AAC4 != *this )
        {
          v10 = *this + 92;
LABEL_23:
          if ( *(_BYTE *)(v10 + 176) )
            sub_524970(0);
          goto LABEL_25;
        }
        v5 = (void *)sub_40C460(&dword_6291CC);
        v6 = v5;
        if ( !v5 )
          goto LABEL_25;
        v7 = sub_459BA0(v5);
        if ( _strcmpi(v7, aDrivable) )
        {
          v8 = sub_459BA0(v6);
          if ( _strcmpi(v8, aOnboard) )
          {
            v9 = sub_459BA0(v6);
            if ( _strcmpi(v9, aSwingman) )
            {
              v10 = *this + 92;
              goto LABEL_23;
            }
          }
        }
        if ( *(_BYTE *)(*this + 268) != 1 )
          sub_524970(1);
LABEL_25:
        if ( !*((_BYTE *)this + 2876) )
        {
          if ( this[85] )
            sub_59ECC0(0, 0, 0, 0);
          if ( this[161] )
            sub_59ECC0(0, 0, 0, 0);
          if ( this[237] )
            sub_59ECC0(0, 0, 0, 0);
          if ( this[313] )
            sub_59ECC0(0, 0, 0, 0);
        }
        if ( !*((_BYTE *)this + 2877) )
        {
          if ( this[632] )
            sub_59ECC0(0, 0, 0, 0);
          if ( this[633] )
            sub_59ECC0(0, 0, 0, 0);
          if ( this[634] )
            sub_59ECC0(0, 0, 0, 0);
          if ( this[635] )
            sub_59ECC0(0, 0, 0, 0);
          if ( this[636] )
            sub_59ECC0(0, 0, 0, 0);
          if ( this[637] )
            sub_59ECC0(0, 0, 0, 0);
        }
        v11 = this + 423;
        v12 = 12;
        do
        {
          if ( *v11 && *((_BYTE *)v11 + 64) && !*((_BYTE *)v11 + 65) )
            sub_59ECC0(0, 0, 0, 0);
          v11 += 17;
          --v12;
        }
        while ( v12 );
        sub_50B400((int)this);
        if ( this[628] && sub_50B100((int)this) || this[629] && !sub_50B100((int)this) )
          sub_59ECC0(0, 0, 0, 0);
        break;
      case 1:
        if ( this[1] )
        {
          sub_59ECC0(0, 0, 1, 0);
          sub_59ECC0(1, 0, 0, 0);
        }
        if ( this[389] && *((_BYTE *)this + 1620) )
          sub_59ECC0(1, 1, 0, 0);
        if ( dword_768108 )
        {
          if ( this[85] && *((_BYTE *)this + 404) && *((_BYTE *)this + 2876) )
            sub_59ECC0(1, 1, 0, 0);
          if ( this[102] && *((_BYTE *)this + 472) )
            sub_59ECC0(1, 1, 0, 0);
          if ( this[161] && *((_BYTE *)this + 708) && *((_BYTE *)this + 2876) )
            sub_59ECC0(1, 1, 0, 0);
          if ( this[178] && *((_BYTE *)this + 776) )
            sub_59ECC0(1, 1, 0, 0);
          if ( this[631] )
            sub_59ECC0(1, 1, 0, 0);
        }
        v13 = dword_7682B8 == 2;
        v14 = dword_7682B8 >= 1;
        if ( this[636] )
          sub_59ECC0(dword_7682B8 == 2, dword_7682B8 == 2, 0, 0);
        if ( this[637] )
          sub_59ECC0(v13, v13, 0, 0);
        if ( this[639] )
          sub_59ECC0(v14, v14, 0, 0);
        if ( this[630] )
          sub_59ECC0(1, 1, 0, 0);
        if ( this[1] )
          sub_59EF70(0, 1, 0);
        sub_50B490((int)this);
        goto LABEL_153;
      case 2:
        if ( this[1] )
        {
          sub_59ECC0(0, 0, 1, 0);
          sub_59ECC0(1, 0, 0, 0);
        }
        if ( this[389] && *((_BYTE *)this + 1620) )
          sub_59ECC0(1, 1, 0, 0);
        if ( this[85] && *((_BYTE *)this + 404) && *((_BYTE *)this + 2876) )
          sub_59ECC0(1, 1, 0, 0);
        if ( this[102] && *((_BYTE *)this + 472) )
          sub_59ECC0(1, 1, 0, 0);
        if ( this[161] && *((_BYTE *)this + 708) && *((_BYTE *)this + 2876) )
          sub_59ECC0(1, 1, 0, 0);
        if ( this[178] && *((_BYTE *)this + 776) )
          sub_59ECC0(1, 1, 0, 0);
        if ( this[631] )
          sub_59ECC0(1, 1, 0, 0);
        if ( this[636] )
          sub_59ECC0(1, 1, 0, 0);
        if ( this[637] )
          sub_59ECC0(1, 1, 0, 0);
        if ( this[639] )
          sub_59ECC0(1, 1, 0, 0);
        if ( this[630] )
          sub_59ECC0(1, 1, 0, 0);
        if ( this[1] )
          sub_59EF70(0, 1, 0);
        if ( this[85] && *((_BYTE *)this + 404) )
        {
          if ( *(_DWORD *)(*this + 25248) == *(_DWORD *)(dword_75AAD0[dword_75AAC8] + 25248) )
            sub_59EF70(dword_767C58 > 1, 0, 0);
          else
            sub_59EF70(dword_767C58 > 2, 0, 0);
        }
        if ( this[161] && *((_BYTE *)this + 708) )
        {
          if ( *(_DWORD *)(*this + 25248) == *(_DWORD *)(dword_75AAD0[dword_75AAC8] + 25248) )
            sub_59EF70(dword_767C58 > 1, 0, 0);
          else
            sub_59EF70(dword_767C58 > 2, 0, 0);
        }
        v15 = this + 423;
        v16 = 12;
        do
        {
          if ( *v15 && *((_BYTE *)v15 + 64) && *((_BYTE *)v15 + 65) )
            sub_59ECC0(1, 1, 0, 0);
          v15 += 17;
          --v16;
        }
        while ( v16 );
        sub_50B490((int)this);
        if ( *(_BYTE *)(*this + 268) != 1 )
          sub_524970(1);
        if ( this[628] && !sub_50B100((int)this) || this[629] && sub_50B100((int)this) )
          sub_59ECC0(1, 1, 0, 0);
        return;
      case 3:
        if ( this[1] )
        {
          sub_59ECC0(0, 0, 1, 0);
          sub_59ECC0(1, 0, 0, 0);
          sub_59EF70(0, 1, 0);
        }
        if ( this[636] )
          sub_59ECC0(1, 0, 0, 0);
        if ( this[637] )
          sub_59ECC0(1, 0, 0, 0);
LABEL_153:
        if ( *(_BYTE *)(*this + 268) != 1 )
          sub_524970(1);
        return;
      default:
        return;
    }
  }
}
