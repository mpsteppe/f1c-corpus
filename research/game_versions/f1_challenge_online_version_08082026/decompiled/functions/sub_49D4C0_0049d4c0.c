int __thiscall sub_49D4C0(_DWORD *this)
{
  BOOL v2; // eax
  int v3; // eax
  bool v4; // al
  bool v5; // al
  int v7; // [esp-4h] [ebp-8h]
  int v8; // [esp-4h] [ebp-8h]
  int v9; // [esp-4h] [ebp-8h]

  if ( sub_49B9A0() )
    sub_49E520(this[12]);
  else
    sub_49E4E0(0, this[12]);
  v7 = this[13];
  v2 = sub_49BA30();
  sub_49E4E0(v2, v7);
  v8 = this[14];
  v3 = sub_49BA30();
  sub_49E4E0(v3 == 2, v8);
  if ( sub_49BA50() )
    sub_49E520(this[15]);
  else
    sub_49E4E0(0, this[15]);
  if ( sub_49BAB0() )
  {
    sub_49E520(this[16]);
  }
  else if ( sub_49BA90() )
  {
    sub_49E4E0(1, this[16]);
  }
  else
  {
    sub_49E4E0(0, this[16]);
  }
  v4 = sub_49BAD0();
  sub_49E4E0(v4, this[17]);
  v9 = this[18];
  v5 = sub_49BB20();
  return sub_49E4E0(v5, v9);
}
