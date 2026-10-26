int __thiscall sub_4FBD60(_DWORD *this)
{
  _DWORD *v2; // esi
  int v4; // [esp+8h] [ebp-8h] BYREF
  int v5; // [esp+Ch] [ebp-4h] BYREF

  sub_59EF10(&v4, 2048);
  sub_59EF10(&v5, 2048);
  v2 = (_DWORD *)((char *)&unk_62BF68 + 25304 * v4);
  if ( v5 == -11 )
  {
    sub_421590((int)&unk_62BF68 + 25304 * v4, 4, 0);
    sub_4C19D0(v2 + 4147);
    if ( sub_4EED40(v2) )
      pfnAPC(1u);
  }
  else if ( v5 == -69 )
  {
    if ( v4 != 48 )
    {
      sub_4C1CB0(v2 + 4147);
      sub_5A1290(this[5]);
      return 0;
    }
    if ( dword_7D7928 == 2 && (dword_75CBB4 == 3 || dword_7D7540 >= 6) )
    {
      sub_421590((int)&unk_62BF68 + 25304 * v4, 4, 0);
      sub_4C19D0(v2 + 4147);
      sub_5A1290(this[5]);
      return 0;
    }
  }
  else
  {
    sub_421590((int)&unk_62BF68 + 25304 * v4, 5, 0);
    sub_4C1BA0(v2 + 4147);
    if ( sub_4EED40(v2) )
      pfnAPC(0);
  }
  sub_5A1290(this[5]);
  return 0;
}
