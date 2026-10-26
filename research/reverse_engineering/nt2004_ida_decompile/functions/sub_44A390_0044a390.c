char __thiscall sub_44A390(_BYTE *this, char a2, char a3)
{
  char result; // al
  double v4; // st7
  double v5; // st6
  double v6; // st7
  float v7; // [esp+0h] [ebp-8h]
  int v8; // [esp+4h] [ebp-4h]

  result = a2;
  if ( this[7933] != a2 )
  {
    this[7933] = a2;
    result = a3;
    if ( !a3 )
    {
      result = this[7932];
      if ( result )
      {
        v4 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
        v5 = v4;
        v6 = flt_7D3C54[(unsigned __int8)dword_7D3C50++];
        *(float *)&v8 = v5 * 0.1 + 1.0;
        v7 = 1.0 - v6 * 0.15000001;
        return sub_526050(41, 2, v7, v8);
      }
    }
  }
  return result;
}
