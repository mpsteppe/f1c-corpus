int __thiscall sbdt::PlayerFile::Create(sbdt::PlayerFile *this, char *a2)
{
  const char *v4; // eax
  const CHAR *v5; // eax
  int v6; // eax

  if ( !a2 )
    return -1;
  v4 = dword_91CB00;
  if ( !dword_91CB00 )
    v4 = WindowName;
  sprintf((char *const)this + 20, "%s%s\\", v4, a2);
  sub_617930(512);
  sub_41B2B0();
  sub_501AC0();
  if ( (byte_B6A7F4 & 1) != 0 )
    sub_50F6B0((int)this, 2, 0.0);
  else
    sub_50F6B0((int)this, 1, 0.0);
  if ( dword_BE1CD0 > 0 )
    sub_53A160(this);
  if ( dword_BE1BD4 > 0 )
  {
    v5 = *(const CHAR **)sub_538790(&unk_BE1CDC);
    if ( !v5 )
      v5 = WindowName;
    sub_615860(v5);
    v6 = sub_538790(&unk_BE1CDC);
    sub_615860(v6 + 1852);
  }
  sub_501770();
  sub_510360(this, 1);
  sub_437A90((int)&dword_B66000);
  sub_501FF0();
  sub_510770(this, 0);
  return 0;
}
