int sub_4B9E50()
{
  int v0; // eax
  const char *v1; // eax
  char String2[128]; // [esp+4h] [ebp-180h] BYREF
  char Buffer[256]; // [esp+84h] [ebp-100h] BYREF

  if ( sub_4E5CB0(&unk_76BB28) == 3 )
  {
    v0 = sub_4E5DA0(&unk_76BB28);
    if ( v0 )
    {
      if ( sub_4E4C50(v0) )
      {
        sub_4E3D70(String2);
        if ( sub_4E4D80(String2) == 1 && dword_7688E8 == 1 )
        {
          v1 = (const char *)dword_62A0A8;
          if ( !dword_62A0A8 )
            v1 = &byte_629120;
          sprintf(Buffer, "%s%s", v1, aWinconstructor);
          sub_527460(Buffer, 1);
        }
      }
    }
  }
  nullsub_6(&unk_629328);
  return 0;
}
