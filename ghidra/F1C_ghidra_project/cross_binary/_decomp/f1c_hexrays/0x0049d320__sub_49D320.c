// f1c  0x0049d320  size=204
int __thiscall sub_49D320(_DWORD *this)
{
  int v2; // eax
  int v3; // eax
  char v4; // cl
  int v5; // eax
  char v6; // cl
  _BYTE v8[4]; // [esp+4h] [ebp-4h] BYREF

  v2 = sub_49B8F0();
  if ( v2 >= 0 )
  {
    if ( v2 )
    {
      sub_58815F(v8, "%d", v2);
      return sub_553070(v8, 49, 43, *(_DWORD *)(this[4] + 84));
    }
    if ( sub_423A00(byte_5EC4C0, aN, byte_5EC4CC) )
    {
      v5 = 0;
      do
      {
        v6 = aN[v5];
        byte_5EC4CC[v5++] = v6;
      }
      while ( v6 );
    }
  }
  else if ( sub_423A00(byte_5EC4C0, byte_5CCEC4, byte_5EC4CC) )
  {
    v3 = 0;
    do
    {
      v4 = byte_5CCEC4[v3];
      byte_5EC4CC[v3++] = v4;
    }
    while ( v4 );
  }
  sub_587DD0(v8, byte_5EC4CC, 3);
  v8[3] = 0;
  return sub_553070(v8, 49, 43, *(_DWORD *)(this[4] + 84));
}
