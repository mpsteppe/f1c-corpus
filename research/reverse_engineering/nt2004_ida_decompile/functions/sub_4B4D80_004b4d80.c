int __thiscall sub_4B4D80(_DWORD *this)
{
  BOOL v2; // eax
  int v3; // eax
  bool v4; // al
  bool v5; // al
  bool v6; // al
  int v8; // [esp-4h] [ebp-8h]
  int v9; // [esp-4h] [ebp-8h]
  int v10; // [esp-4h] [ebp-8h]
  int v11; // [esp-4h] [ebp-8h]
  int v12; // [esp-4h] [ebp-8h]

  if ( sub_4B2EF0() )
    sub_4B5AF0(this[14]);
  else
    sub_4B5AB0(0, this[14]);
  v8 = this[15];
  v2 = sub_4B2F10();
  sub_4B5AB0(v2, v8);
  v9 = this[16];
  v3 = sub_4B2F10();
  sub_4B5AB0(v3 == 2, v9);
  if ( sub_4B2F30() )
    sub_4B5AF0(this[17]);
  else
    sub_4B5AB0(0, this[17]);
  v10 = this[18];
  v4 = sub_4B2FB0();
  sub_4B5AB0(v4, v10);
  v11 = this[19];
  v5 = sub_4B2FD0();
  sub_4B5AB0(v5, v11);
  v12 = this[20];
  v6 = sub_4B2FE0();
  return sub_4B5AB0(v6, v12);
}
