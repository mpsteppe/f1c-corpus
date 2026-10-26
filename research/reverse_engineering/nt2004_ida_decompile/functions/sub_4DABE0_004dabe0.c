void __thiscall sub_4DABE0(int *this)
{
  bool v2; // bl
  float v3; // [esp+0h] [ebp-14h]
  float v4; // [esp+4h] [ebp-10h]
  float v5; // [esp+4h] [ebp-10h]

  if ( *this == 1 )
  {
    v4 = dbl_7DA9C0;
    v2 = sub_4D7C40(this[2], v4);
    sub_4D83D0((_DWORD *)this[2]);
    if ( (double)dword_76854C * 60.0 > *(float *)(this[2] + 2064) - *(float *)(this[2] + 2060) && v2 )
    {
      if ( !byte_75CBB8 )
      {
        v5 = dbl_7DA9D0;
        sub_4D9880(this + 2, &dword_79FC40, (int)&unk_62BF68, v5);
      }
      if ( !sub_463490(dword_764D70) )
      {
        if ( dword_763B58 )
        {
          v3 = (float)dword_768528;
          sub_4D98A0(this + 2, v3, this);
        }
      }
    }
  }
  else if ( *this == 2 )
  {
    sub_4D26F0((int)byte_7D4490);
    if ( !sub_4D9AE0(this + 2) )
      sub_4F78B0(&unk_7D73D0);
  }
}
