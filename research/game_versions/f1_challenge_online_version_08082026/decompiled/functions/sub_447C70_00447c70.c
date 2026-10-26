char __thiscall sub_447C70(int this, char a2, char a3)
{
  char result; // al
  double v4; // st7
  double v5; // st6
  double v6; // st7
  float v7; // [esp+0h] [ebp-8h]
  float v8; // [esp+4h] [ebp-4h]

  result = a2;
  if ( *(_BYTE *)(this + 7256) != a2 )
  {
    *(_BYTE *)(this + 7256) = a2;
    if ( *(_DWORD *)(this + 7936) )
    {
      result = a3;
      if ( !a3 )
      {
        v4 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
        v5 = v4;
        v6 = flt_8AAE74[(unsigned __int8)dword_8AAE70++];
        v8 = v5 * 0.1 + 1.0;
        v7 = 1.0 - v6 * 0.15000001;
        return sub_4F87C0(40, 2, v7, v8);
      }
    }
  }
  return result;
}
