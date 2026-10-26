int sub_47B9D0()
{
  char *v0; // eax
  int v1; // esi

  v0 = *(char **)dword_62A0D0;
  v1 = 0;
  if ( !*(_DWORD *)dword_62A0D0 )
    v0 = &byte_629120;
  sub_578A30(aPlr_0, 1, v0, 1);
  sub_578E30(2);
  while ( sub_578D80(&unk_7D7A0C) )
  {
    ++v1;
    sub_5789D0(&unk_7D7A0C);
  }
  sub_578960(&unk_7D7A0C);
  return v1;
}
