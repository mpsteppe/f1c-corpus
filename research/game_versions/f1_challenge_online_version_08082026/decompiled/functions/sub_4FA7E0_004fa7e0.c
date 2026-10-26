char __thiscall sub_4FA7E0(void *this)
{
  int v2; // esi
  int i; // esi
  int v4; // eax
  char v5; // cl
  char result; // al

  if ( sub_44F460(byte_7CA594, 29) && sub_44F460(byte_7CA594, 33) )
  {
    if ( dword_8AFCAC )
      sub_4F8F10(&dword_8AFCA8, 0);
    else
      sub_4F8F10(&dword_8AFCA8, 2);
  }
  sub_4F8F50((float *)&dword_8AFCA8, dword_8B8DC8);
  if ( sub_461DB0(dword_7CD25C) || dword_8AB6E4 == 2 )
  {
LABEL_17:
    sub_4F9F70(0);
    goto LABEL_18;
  }
  if ( sub_44F460(byte_7CA594, 29) && sub_44F460(byte_7CA594, 34) )
  {
    if ( dbl_5D6D70 == 1.0 )
      sub_4F9F70(2);
    else
      sub_4F9F70(0);
  }
  if ( sub_44F460(byte_7CA594, 29) && sub_44F460(byte_7CA594, 20) )
  {
    if ( dbl_5D6D70 == 1.0 )
    {
      sub_4F9F70(1);
      goto LABEL_18;
    }
    goto LABEL_17;
  }
LABEL_18:
  if ( byte_8AFE70 )
    goto LABEL_40;
  byte_8AFE70 = 1;
  sub_4F8D70(&dword_8AFCA8, 4, dword_5D6D64 - 48);
  if ( dword_7CE264 == 1 )
    sub_4F8F10(&dword_8AFCA8, 2);
  else
    sub_4F8F10(&dword_8AFCA8, 0);
  if ( dword_7CFC68 )
  {
    if ( dword_7CFC68 == 1 )
      sub_545D00(0, 4096);
  }
  else
  {
    sub_545D00(0, 6144);
  }
  if ( !dword_7CF860 )
  {
    sub_545D00(0, 256);
LABEL_35:
    for ( i = 0; i < dword_5C329C; ++i )
      sub_54C1B0(0, 1, 0);
LABEL_37:
    if ( dword_7CF860 < 1 )
      goto LABEL_40;
    goto LABEL_38;
  }
  if ( dword_7CF860 == 1 )
    goto LABEL_35;
  if ( dword_7CF860 != 2 )
    goto LABEL_37;
  v2 = 0;
  if ( dword_5C329C > 0 )
  {
    do
    {
      if ( *(_DWORD *)(LODWORD(dword_7C54F0[v2]) + 13000) )
        sub_54C1B0(0, 1, 0);
      ++v2;
    }
    while ( v2 < dword_5C329C );
    goto LABEL_37;
  }
LABEL_38:
  if ( (unsigned int)dword_7CFB90 <= 1 )
    sub_545D00(0, 256);
LABEL_40:
  if ( !byte_7CE254 )
    sub_4F9B30(0);
  if ( dword_7CC4F4 && !sub_461DB0(dword_7CD25C) && dword_8AB6E4 != 2 && (dword_7C56A4 != 7 || !byte_7CE254) )
  {
    sub_42D210(&dword_7C569C, byte_7C56AC == 0);
    if ( byte_7C56AC )
      sub_4C8D60();
    else
      sub_4C8D70();
  }
  if ( byte_7C56AC )
  {
    if ( sub_423A00(byte_5EC4C0, aPaused, byte_5EC4CC) )
    {
      v4 = 0;
      do
      {
        v5 = aPaused[v4];
        byte_5EC4CC[v4++] = v5;
      }
      while ( v5 );
    }
    sub_45BD10(&dword_7CD204, (int)byte_5EC4CC, 3, 16909060);
  }
  ++dword_8AFE84;
  sub_53AC70(2, 0);
  dbl_8AFE90 = sub_556730(0);
  dbl_8AFEA8 = dbl_8AFEA8 + dbl_8AFE90;
  if ( byte_7C56AC )
  {
    dbl_8AFE98 = 0.0;
  }
  else if ( dbl_5D6D70 == 1.0 )
  {
    dbl_8AFE98 = dbl_8AFE90;
    dbl_8AFEA0 = dbl_8AFEA0 + dbl_8AFE90;
    sub_568C60(this);
    if ( dbl_8AFE98 > 0.5 )
      dbl_8AFE98 = 0.5;
  }
  else
  {
    dbl_8AFE98 = dbl_5D6D70 * dbl_8AFE90;
    if ( dbl_5D6D70 * dbl_8AFE90 > 0.5 )
      dbl_8AFE98 = 0.5;
    dbl_8AFEA0 = dbl_8AFEA0 + dbl_8AFE98;
  }
  sub_53AC70(1, 0);
  result = byte_8AFE72;
  if ( byte_8AFE72 )
  {
    byte_8AFE72 = 0;
    sub_4CF040(&dword_8ACEA0);
    return sub_4024F0((int)dword_5EA2C0);
  }
  return result;
}
