int __thiscall sub_6CA49D(_DWORD *this, int a2)
{
  int result; // eax
  unsigned int i; // esi
  int v4; // ecx
  _DWORD v5[3]; // [esp+4h] [ebp-Ch]

  v5[0] = this[61];
  v5[1] = this[60];
  v5[2] = this[62];
  result = a2;
  for ( i = 0; i < 3; ++i )
  {
    v4 = v5[i];
    if ( v4 )
    {
      result = sub_6C6925(v4, a2);
      if ( *(_DWORD *)(result + 16) != -1 )
        break;
    }
  }
  return result;
}
