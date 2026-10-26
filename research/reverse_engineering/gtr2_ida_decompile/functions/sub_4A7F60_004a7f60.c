int __thiscall sub_4A7F60(int this)
{
  int v2; // ecx
  double v3; // st7
  int v4; // eax
  _BYTE v6[61]; // [esp+8h] [ebp-40h] BYREF
  __int16 v7; // [esp+45h] [ebp-3h]
  char i; // [esp+47h] [ebp-1h]

  memset(v6, 0, sizeof(v6));
  v2 = *(_DWORD *)(this + 876);
  v7 = 0;
  for ( i = 0; v2 > 0; --v2 )
  {
    v3 = -1.0;
    if ( v2 == 1 )
    {
      v3 = 1.0;
    }
    else if ( v2 == 2 )
    {
      v3 = 2.0;
    }
    if ( v3 == **(float **)(this + 868) )
      break;
  }
  *(_DWORD *)(this + 872) = v2;
  v4 = sub_4CFC00(v2);
  sub_630FE0(v6, v4, 63);
  i = 0;
  sub_4CE770(v6);
  return 0;
}
