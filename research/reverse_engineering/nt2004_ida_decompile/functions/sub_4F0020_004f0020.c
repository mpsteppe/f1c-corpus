void sub_4F0020()
{
  bool v0; // bl
  signed int v1; // edi
  signed int i; // esi
  char v3; // [esp+Bh] [ebp-1h]

  v0 = dword_7D5DA4 == 2;
  if ( dword_7D5DA4 != 2 || sub_4DA080(&unk_7D5DAC) == 5 )
  {
    v3 = 0;
    if ( byte_75CBB8 || v0 )
      goto LABEL_11;
  }
  else
  {
    v3 = 1;
  }
  v1 = NumOfElements;
  for ( i = 0; i < v1; ++i )
    sub_525D30(dword_75AAD0[i] + 92);
  if ( dword_7D6BB0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)dword_7D6BB0 + 8))(dword_7D6BB0);
  sub_595470(32, 1);
  sub_4EEFF0(&flt_7D6BA0);
LABEL_11:
  sub_418DB0((int)byte_6292D0);
  if ( !v3 )
  {
    if ( byte_76617C )
      sub_4EFE00();
  }
}
