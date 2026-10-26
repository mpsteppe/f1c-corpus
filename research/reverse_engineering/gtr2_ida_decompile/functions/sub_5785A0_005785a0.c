char __thiscall sub_5785A0(int this)
{
  int v2; // eax
  int v4; // eax
  unsigned __int8 v6; // c0
  unsigned __int8 v7; // c2

  v2 = *(_DWORD *)(this + 14804);
  if ( !v2 )
    return byte_B68208 & byte_B68209;
  if ( v2 >= 3 )
    return *(_BYTE *)(this + 5760);
  v4 = *(_DWORD *)(this + 15560);
  if ( v4 < 2 || v4 > 4 || v6 | v7 && sub_577A80((float *)this) )
    return 0;
  else
    return *(_BYTE *)(this + 17300);
}
