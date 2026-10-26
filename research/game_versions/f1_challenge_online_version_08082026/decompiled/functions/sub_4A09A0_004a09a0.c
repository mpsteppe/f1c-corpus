int __thiscall sub_4A09A0(void *this)
{
  int v2; // esi
  char **v3; // eax
  char *v4; // eax

  v2 = 1;
  if ( sub_4C2850(&unk_7D2DB0) )
  {
    v2 = 0;
    v3 = (char **)sub_4C29D0(&unk_7D2DB0);
    if ( v3 )
    {
      v4 = *v3;
      if ( !v4 )
        v4 = byte_5EA438;
      sub_4C55B0(v4);
      sub_4A09F0(this);
    }
  }
  return v2;
}
