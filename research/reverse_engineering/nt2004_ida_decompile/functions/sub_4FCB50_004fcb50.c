void __thiscall sub_4FCB50(void *this)
{
  sub_4FA130();
  if ( !byte_75CBB8 && dword_7D5DA4 != 2 )
  {
    sub_4FB270((int)this);
    if ( (dword_75CBAC & 1) != 0 )
      sub_4FB930((int)this);
    if ( dword_75CBB0 == 7 )
    {
      if ( byte_766124 )
      {
        if ( *(float *)&dword_766128 <= 20.0 )
          *(float *)&dword_766128 = dbl_7DA9C8 + *(float *)&dword_766128;
        else
          sub_4BA1A0(1, -1.0);
      }
      if ( dword_766120 )
      {
        if ( dword_766120 == 1 )
        {
          sub_506540(&unk_7660D0);
          dword_766120 = 2;
        }
        else if ( dword_766120 == 2 )
        {
          sub_506540(&unk_7660D0);
        }
      }
      else
      {
        dword_766120 = 1;
      }
    }
  }
}
