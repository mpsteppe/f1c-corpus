char __thiscall sub_56AE80(_DWORD *this, int a2, int a3)
{
  int v4; // ebp
  char result; // al
  int v6; // edx
  int v7; // ecx

  v4 = 3;
  if ( (*(_DWORD *)(*this + 22580) & 2) != 0 )
    v4 = a2;
  if ( v4 != this[760] || (result = a3) != 0 )
  {
    this[760] = v4;
    result = byte_B6F118;
    LOBYTE(a3) = 1;
    if ( byte_B6F118 )
      LOBYTE(a3) = *(_DWORD *)dword_B72314 == 6;
    switch ( v4 )
    {
      case 0:
        if ( this[2] )
          sub_5DB320(1, 1, 1);
        if ( this[610] )
          sub_5DB320(0, 0, 0);
        if ( *this == ((_BYTE)dword_757C1C != 0 ? dword_91E084 : 0) )
          sub_4E8280();
        if ( this[619] )
          sub_5DB320(0, 0, 0);
        if ( this[615] && this[616] )
          sub_5DB320(0, 0, 0);
        if ( this[2] )
        {
          v6 = dword_B71230;
          LOBYTE(v6) = dword_B71230 > 0;
          sub_5DA8C0(v6, 1);
        }
        if ( !*((_BYTE *)this + 3049) )
        {
          if ( this[116] )
            sub_5DB320(0, 0, 0);
          if ( this[190] )
            sub_5DB320(0, 0, 0);
          if ( this[264] )
            sub_5DB320(0, 0, 0);
          if ( this[338] )
            sub_5DB320(0, 0, 0);
        }
        if ( dword_91E07C == (char *)*this )
        {
          switch ( sub_410B50(&dword_91BF20) )
          {
            case 2:
            case 4:
            case 7:
            case 8:
              if ( (_BYTE)a2 )
                sub_569640();
              if ( sub_569670(&dword_91BF20) && (byte_B70FC0 & 1) == 0 )
              {
                if ( (unsigned __int8)sub_4166A0((_BYTE *)this + 1716) )
                  sub_5DB320(0, 0, 0);
                if ( this[264] )
                  sub_5DB320(0, 0, 0);
                if ( this[338] )
                  sub_5DB320(0, 0, 0);
              }
              break;
            default:
              goto LABEL_43;
          }
        }
        else
        {
          sub_410B50(&dword_91BF20);
LABEL_43:
          if ( (_BYTE)a2 )
            sub_48D800();
        }
        return off_16C95D0(a2, a3);
      case 1:
        if ( this[2] )
        {
          sub_5DB320(0, 0, 1);
          sub_5DB320(1, 0, 0);
          sub_5DA8C0(0, 1);
        }
        if ( this[619] )
          sub_5DB320(1, 1, 1);
        if ( this[412] && *((_BYTE *)this + 1712) )
          sub_5DB320(1, 1, 0);
        if ( this[531] && *((_BYTE *)this + 2188) && *((_BYTE *)this + 2189) )
          sub_5DB320(1, 1, 0);
        if ( (byte_B70FE4 & 1) != 0 )
        {
          if ( (unsigned __int8)sub_4166A0((_BYTE *)this + 1716) )
            sub_5DB320(1, 1, 0);
          if ( (unsigned __int8)sub_4166A0((_BYTE *)this + 1056) && *((_BYTE *)this + 3049) )
            sub_5DB320(1, 1, 0);
          if ( (unsigned __int8)sub_4166A0((_BYTE *)this + 1352) && *((_BYTE *)this + 3049) )
            sub_5DB320(1, 1, 0);
        }
        if ( *((_BYTE *)this + 3048) )
        {
          if ( (unsigned __int8)sub_4166A0((_BYTE *)this + 464) && *((_BYTE *)this + 3049) )
            sub_5DB320(1, 1, 0);
          if ( (unsigned __int8)sub_4166A0((_BYTE *)this + 532) )
            sub_5DB320(1, 1, 0);
          if ( (unsigned __int8)sub_4166A0((_BYTE *)this + 760) && *((_BYTE *)this + 3049) )
            sub_5DB320(1, 1, 0);
          if ( (unsigned __int8)sub_4166A0((_BYTE *)this + 828) )
            sub_5DB320(1, 1, 0);
          if ( this[611] )
            sub_5DB320(1, 1, 0);
        }
        if ( this[613] && *((_BYTE *)this + 3050) )
          sub_5DB320(1, 1, 0);
        if ( this[615] )
          sub_5DB320(1, 1, 0);
        if ( this[610] )
          sub_5DB320(1, 1, 0);
        if ( *this == ((_BYTE)dword_757C1C != 0 ? dword_91E084 : 0) )
          sub_4E8280();
        if ( this[619] )
          sub_5DB320(1, 1, 1);
        goto LABEL_116;
      case 2:
        if ( this[2] )
        {
          sub_5DB320(0, 0, 1);
          sub_5DB320(1, 0, 0);
          sub_5DA8C0(0, 1);
        }
        if ( (byte_B70FC0 & 1) != 0 )
        {
          if ( (unsigned __int8)sub_4166A0((_BYTE *)this + 1716) )
            sub_5DB320(1, 1, 0);
          if ( (unsigned __int8)sub_4166A0((_BYTE *)this + 1056) && *((_BYTE *)this + 3049) )
            sub_5DB320(1, 1, 0);
          if ( (unsigned __int8)sub_4166A0((_BYTE *)this + 1352) && *((_BYTE *)this + 3049) )
            sub_5DB320(1, 1, 0);
        }
        if ( this[412] && *((_BYTE *)this + 1712) )
          sub_5DB320(1, 1, 0);
        if ( this[610] )
          sub_5DB320(1, 1, 0);
        if ( this[531] && *((_BYTE *)this + 2188) && *((_BYTE *)this + 2189) )
          sub_5DB320(1, 1, 0);
        if ( *this == ((_BYTE)dword_757C1C != 0 ? dword_91E084 : 0) )
          sub_4E8280();
        if ( this[619] )
          sub_5DB320(0, 0, 0);
        goto LABEL_116;
      case 3:
        if ( this[2] )
        {
          sub_5DB320(0, 0, 1);
          sub_5DB320(1, 0, 0);
          sub_5DA8C0(0, 1);
        }
LABEL_116:
        result = a2;
        if ( (_BYTE)a2 )
        {
          result = *(_BYTE *)(*this + 276);
          if ( result != 1 )
            result = sub_58CD40(*this + 24, 1);
        }
        break;
      default:
        break;
    }
    v7 = this[638];
    if ( v7 )
      return sub_54D410(v7, v4);
  }
  return result;
}
