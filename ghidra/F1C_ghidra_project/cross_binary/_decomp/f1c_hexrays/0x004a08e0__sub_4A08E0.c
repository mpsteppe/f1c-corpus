// f1c  0x004a08e0  size=177
int sub_4A08E0()
{
  int v0; // eax
  const char *v1; // eax
  _BYTE v3[128]; // [esp+4h] [ebp-180h] BYREF
  _BYTE v4[256]; // [esp+84h] [ebp-100h] BYREF

  if ( sub_4C2760(&unk_7D2DB0) == 3 )
  {
    v0 = sub_4C2850(&unk_7D2DB0);
    if ( v0 )
    {
      if ( sub_4C1390(v0) )
      {
        sub_4C0A20(v3, 128);
        if ( sub_4C1450(v3) == 1 && dword_7D032C == 1 )
        {
          v1 = (const char *)dword_5EC418;
          if ( !dword_5EC418 )
            v1 = byte_5EA438;
          sub_58815F(v4, "%s%s", v1, aWinconstructor);
          sub_4F9B70(v4, 1);
        }
      }
    }
  }
  sub_41E320();
  return 0;
}
