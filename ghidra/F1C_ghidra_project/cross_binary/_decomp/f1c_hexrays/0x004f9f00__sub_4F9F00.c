// f1c  0x004f9f00  size=41
char sub_4F9F00()
{
  int v0; // eax

  v0 = sub_55C9B0(&unk_8B78A0);
  if ( v0 )
  {
    LOBYTE(v0) = byte_8AFE71;
    if ( !byte_8AFE71 )
    {
      byte_8AFE71 = 1;
      LOBYTE(v0) = sub_5550A0(&unk_8B78A0);
    }
  }
  return v0;
}
