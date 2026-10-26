int __thiscall sub_4B9B20(void *this)
{
  CHAR *v2; // eax
  int v3; // eax
  int v4; // esi
  int v5; // edi
  int v6; // eax

  sub_4E5D60(&unk_76BB28);
  v2 = dword_766594;
  if ( !dword_766594 )
    v2 = &byte_629120;
  sub_4E8C80(v2);
  sub_419110(byte_6292D0);
  sub_4B9F60(this);
  nullsub_6(&unk_629328);
  v3 = sub_4E5DA0(&unk_76BB28);
  v4 = v3;
  if ( v3 )
  {
    v5 = dword_75CBB0;
    if ( sub_4E4970(v3) != v5 )
    {
      v6 = sub_4E4970(v4);
      sub_42F6C0(&dword_75CBA8, v6);
    }
  }
  return 0;
}
