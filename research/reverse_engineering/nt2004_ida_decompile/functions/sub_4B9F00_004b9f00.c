int __thiscall sub_4B9F00(void *this)
{
  int v2; // esi
  CHAR **v3; // eax
  CHAR *v4; // eax

  v2 = 1;
  if ( sub_4E5DA0(&unk_76BB28) )
  {
    v2 = 0;
    v3 = (CHAR **)sub_4E5FE0(&unk_76BB28);
    if ( v3 )
    {
      v4 = *v3;
      if ( !v4 )
        v4 = &byte_629120;
      sub_4E8C80(v4);
      sub_4B9F60(this);
      nullsub_6(&unk_629328);
    }
  }
  return v2;
}
