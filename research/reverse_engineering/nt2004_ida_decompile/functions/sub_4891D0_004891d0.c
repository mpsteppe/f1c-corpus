int __thiscall sub_4891D0(_DWORD *this)
{
  char *v1; // eax
  char *v3; // eax
  int v4; // [esp+4h] [ebp-4h] BYREF

  if ( sub_489020(this, &v4) )
  {
    if ( (dword_769920 & v4) != 0 )
    {
      v1 = (char *)sub_49D690(0);
      sub_4A1AC0(v1);
      return 0;
    }
    v3 = (char *)sub_49D690(1);
    sub_4A1AC0(v3);
  }
  return 0;
}
