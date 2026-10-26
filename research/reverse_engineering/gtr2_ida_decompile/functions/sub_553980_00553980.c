void __thiscall sub_553980(_DWORD *this, char a2, int a3)
{
  int v4; // ebx
  int i; // edx
  int v6; // ecx
  int v7; // edi
  char *v8; // ecx

  v4 = this[87];
  for ( i = 0; i < 104; ++i )
  {
    if ( v4 > 1 )
    {
      if ( i < 0
        || (i >= this[538] || (v6 = this[2 * i + 330], v6 < 0)) && (i >= this[329] || (v6 = this[2 * i + 121], v6 < 0)) )
      {
        v6 = 0;
      }
    }
    else
    {
      v6 = *((unsigned __int8 *)this + i + 368);
    }
    if ( v6 < 104 )
    {
      v7 = dword_923E84[5654 * v6];
      if ( v7 != -1 && (v7 != 2 || fabs(*(float *)&dword_925CCC[5654 * v6] - dbl_FB1D18) < 3.0) )
        break;
    }
  }
  if ( v6 < 104 )
  {
    v8 = (char *)&unk_924FE8 + 22616 * v6;
    switch ( v4 )
    {
      case 0:
        if ( a2 )
        {
          sub_54F110();
          sub_5530E0(this, 1, a3);
          this[88] = 3;
        }
        break;
      case 1:
        if ( *((_DWORD *)v8 + 2) == 10 )
        {
          this[88] = (rand() & 1) + 2;
          sub_5530E0(this, 2, -1);
        }
        break;
      case 2:
        if ( sub_5509C0((float *)this, 0) )
        {
          if ( (int)this[88] < 3 )
            goto LABEL_23;
          sub_5530E0(this, 3, -1);
        }
        break;
      case 3:
        if ( sub_5509C0((float *)this, 1) )
LABEL_23:
          sub_5530E0(this, 4, -1);
        break;
      case 4:
      case 5:
        if ( dword_9034DC >= this[88] - 1 )
          sub_5530E0(this, 6, -1);
        break;
      case 6:
        sub_52B2B0();
        if ( sub_5503D0(this) )
          sub_5530E0(this, 7, -1);
        break;
      case 7:
        if ( !byte_9034D0 && *((_DWORD *)v8 + 2) != 10 )
          sub_5530E0(this, 0, -1);
        break;
      default:
        break;
    }
  }
  if ( (int)this[87] >= 2 )
  {
    if ( (unsigned __int8)sub_4735A0() )
      sub_551970((int)this);
  }
}
