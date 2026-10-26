char __thiscall sub_4BBC60(_DWORD *this, const char *a2)
{
  int v2; // eax
  int v3; // eax
  char v4; // cl
  char v6[64]; // [esp+4h] [ebp-140h] BYREF
  char v7[64]; // [esp+44h] [ebp-100h] BYREF
  _BYTE v8[192]; // [esp+84h] [ebp-C0h] BYREF

  v2 = this[12];
  if ( !v2 )
  {
    if ( a2 )
    {
      v2 = *this;
      if ( !*(_DWORD *)(*this + 13000) )
      {
        if ( sub_423A00(byte_5EC4C0, aWarning, byte_5EC4CC) )
        {
          v3 = 0;
          do
          {
            v4 = aWarning[v3];
            byte_5EC4CC[v3++] = v4;
          }
          while ( v4 );
        }
        sub_587DD0(v6, byte_5EC4CC, 63);
        v6[63] = 0;
        if ( sub_423A00(byte_5EC4C0, a2, byte_5EC4CC) )
          strcpy(byte_5EC4CC, a2);
        sub_587DD0(v7, byte_5EC4CC, 63);
        v7[63] = 0;
        sub_58815F(v8, "%s %s", v6, v7);
        LOBYTE(v2) = sub_45BD10(&dword_7CD204, (int)v8, 3, 16909060);
      }
    }
  }
  return v2;
}
