int __usercall sub_4EBA60@<eax>(int a1@<ebp>)
{
  int j; // esi
  int k; // esi
  int m; // esi
  int result; // eax
  double v5; // st7
  int v6; // edi
  int i; // esi

  if ( !byte_B6F121 && !byte_B6F122 )
  {
LABEL_18:
    if ( !byte_B6F124 )
    {
      if ( dword_B6F128 == 1 )
      {
        if ( dword_B6F11C != 1 )
          goto LABEL_27;
      }
      else
      {
        sub_409D90(&dword_91BE54);
        if ( !byte_B6F118 )
          goto LABEL_27;
        ++dword_B6F114;
        result = sub_4BF730(1, a1);
        if ( result != -1 && result != 3 )
        {
          if ( result == 4 )
            return result;
LABEL_27:
          if ( byte_B6F12D && (v5 = flt_B6F130 - dbl_FB1D10, flt_B6F130 = v5, v5 <= 0.0) )
          {
            byte_B6F12D = 0;
            flt_B6F130 = 0.0;
            dword_B6F11C = 1;
          }
          else if ( dword_B6F11C != 1 )
          {
            if ( dword_B6F11C == 2 )
              dword_B6F11C = 1;
            goto LABEL_36;
          }
          if ( dword_B6F128 == 1 )
            dword_B640C0 = 6;
          else
            sub_4EB8C0();
LABEL_36:
          if ( byte_B6F118 )
          {
LABEL_46:
            sub_4EB840();
            return dword_B640C0;
          }
          v6 = 2;
          if ( *(_DWORD *)dword_B72314 == 5 )
            v6 = 3;
          for ( i = 0; ; ++i )
          {
            while ( 1 )
            {
              if ( i >= ((v6 & dword_B698E8) != 0 ? dword_B6A2F4 : 0) )
                goto LABEL_46;
              if ( word_B6A2F8[i] == 1 )
                break;
LABEL_45:
              ++i;
            }
            if ( !sub_409B20(&dword_91BE54) )
            {
              dword_B6F11C = 1;
              goto LABEL_45;
            }
            dword_B640C0 = 6;
            sub_409F60(&dword_91BE54);
          }
        }
      }
      return 6;
    }
LABEL_47:
    byte_B6F122 = 0;
    return 6;
  }
  for ( j = 0; j < 104; ++j )
    sub_552190(j, 0, *(_DWORD *)dword_B640C8 == 6);
  if ( !byte_B6F121 )
  {
    if ( byte_B6F122 )
      goto LABEL_47;
    goto LABEL_18;
  }
  byte_B6F121 = 0;
  if ( *(_DWORD *)dword_B640C8 == 6 )
  {
    for ( k = 0; k < dword_757C10; ++k )
      sub_52C3D0(*(&dword_91E088 + k) + 19272);
  }
  if ( *(_DWORD *)dword_B72314 == 7 )
  {
    sub_52B7E0(dword_91E084 + 19272);
  }
  else
  {
    for ( m = 0; m < dword_757C10; ++m )
      sub_52B7E0(*(&dword_91E088 + m) + 19272);
  }
  if ( (_BYTE)dword_757C1C )
  {
    if ( *(_DWORD *)(dword_91E084 + 14820) == 1 )
      sub_53E6A0(dword_91E084, 0);
  }
  return 4;
}
