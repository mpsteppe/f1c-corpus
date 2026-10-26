char __usercall sub_5900D0@<al>(int a1@<ecx>, int a2@<ebx>, int a3@<ebp>)
{
  char v4; // bl
  double v5; // st7
  double v6; // st7
  char v7; // bl
  int v8; // ebx
  char result; // al
  int v10; // [esp+4h] [ebp-20h]
  int v12; // [esp+14h] [ebp-10h]
  _BYTE v13[4]; // [esp+18h] [ebp-Ch] BYREF
  _BYTE v14[4]; // [esp+1Ch] [ebp-8h] BYREF
  _BYTE v15[4]; // [esp+20h] [ebp-4h] BYREF

  if ( (dword_B698E8 & 1) != 0 && (byte_B69A09 & 2) != 0 && (dword_B698E8 & 1) != 0 && (byte_B69A0D & 2) != 0 )
  {
    if ( dword_FB1D2C )
    {
      if ( dword_FB1D28 )
      {
        dword_FB1D2C = 0;
        sub_5F5C70(1);
        dword_FB1D34 = 0;
        pfnAPC((ULONG_PTR)"FTFRAMERATE");
      }
    }
    else if ( dword_FB1D28 )
    {
      dword_FB1D2C = 2;
      sub_5F5C70(1);
      dword_FB1D34 = 0;
    }
  }
  sub_58F570(&dword_FB1D28, (int)dword_FB2790);
  if ( (unsigned __int8)sub_4735A0() || dword_BE1204 == 2 )
    goto LABEL_27;
  v4 = byte_B69A09;
  if ( (dword_B698E8 & 1) != 0 && (byte_B69A09 & 2) != 0 && (dword_B698E8 & 1) != 0 && (byte_B69A0E & 2) != 0 )
  {
    if ( sub_439D30() )
      v5 = 1.0;
    else
      v5 = 0.119999997317791;
    dbl_903EC8 = v5;
  }
  if ( (dword_B698E8 & 1) != 0 && (v4 & 2) != 0 && (dword_B698E8 & 1) != 0 && (byte_B69A00 & 2) != 0 || dword_B6BA90 )
  {
    if ( dbl_903EC8 == 1.0 )
    {
      v6 = 30.0;
LABEL_28:
      dbl_903EC8 = v6;
      goto LABEL_29;
    }
LABEL_27:
    v6 = 1.0;
    goto LABEL_28;
  }
LABEL_29:
  if ( !byte_FB1CEC )
  {
    byte_FB1CEC = 1;
    sub_58F430(&dword_FB1D28, 4, dword_903EBC - 48);
    if ( dword_B6F128 == 1 )
    {
      if ( dword_FB1D28 )
      {
        dword_FB1D2C = 2;
        sub_5F5C70(1);
        dword_FB1D34 = 0;
      }
    }
    else if ( dword_FB1D28 )
    {
      dword_FB1D2C = 0;
      sub_5F5C70(1);
      dword_FB1D34 = 0;
      pfnAPC((ULONG_PTR)"FTFRAMERATE");
    }
  }
  if ( !byte_B6F118 && sub_5FB160((dword_FB1CF8 != 0) + 1) == -2 )
    byte_FB1CEE = 1;
  if ( (dword_B698E8 & 1) != 0
    && (byte_B699ED & 2) != 0
    && !byte_B6F118
    && *(_DWORD *)dword_B72314 != 5
    && dword_BE1204 != 2 )
  {
    byte_B699B4 = 0;
    byte_B699BC = 0;
    if ( dword_B6E4D0 == 5 )
    {
      if ( byte_FAEA91 )
      {
        if ( *(_DWORD *)dword_B72314 == 8 && byte_91E04B )
          goto LABEL_58;
        byte_B699B4 = 2;
        byte_B699BC = 2;
        sub_4E5FC0(&dword_B6E4D0, 0);
        if ( !byte_B6413C )
          goto LABEL_58;
      }
      else
      {
        byte_FAEA91 = 1;
        if ( byte_B6413C )
          goto LABEL_58;
      }
LABEL_57:
      sub_590060();
      goto LABEL_58;
    }
    v7 = byte_FAEA90;
    if ( dword_B6E4D0 == 1 )
    {
      sub_4E5FC0(&dword_B6E4D0, 0);
      if ( !(unsigned __int8)sub_4735A0() )
      {
        v10 = 0;
        sub_4304C0();
      }
    }
    else
    {
      sub_5665A0((int)v15, (int)v14, (int)v13, a2);
      dword_B6E4D8 = v12;
      sub_4E5FC0(&dword_B6E4D0, 5);
    }
    if ( !v7 && !byte_B6413C )
      goto LABEL_57;
  }
LABEL_58:
  v8 = v10;
  if ( dword_B6BA64 && !byte_FAEA91 && !byte_B6F118 )
    sub_590060();
  ++dword_FB1D00;
  sub_5D7710(2, 0);
  dbl_FB1D08 = sub_5F5A40(0);
  dbl_FB1D20 = dbl_FB1D20 + dbl_FB1D08;
  if ( byte_B6413C )
  {
    dbl_FB1D10 = 0.0;
  }
  else if ( dbl_903EC8 == 1.0 )
  {
    dbl_FB1D10 = sub_473750(&dword_B6CBA8, dbl_FB1D08);
    dbl_FB1D18 = dbl_FB1D18 + dbl_FB1D10;
    sub_617E70(a1);
    if ( dbl_FB1D10 > 0.5 )
      dbl_FB1D10 = 0.5;
  }
  else
  {
    dbl_FB1D10 = dbl_903EC8 * dbl_FB1D08;
    if ( dbl_903EC8 * dbl_FB1D08 > 0.5 )
      dbl_FB1D10 = 0.5;
    dbl_FB1D18 = dbl_FB1D18 + dbl_FB1D10;
  }
  sub_5D7710(1, 0);
  result = byte_FB1CEE;
  if ( byte_FB1CEE )
  {
    byte_FB1CEE = 0;
    sub_542C40();
    return sub_403D10((int)&flt_91BCA0, v8, a3);
  }
  return result;
}
