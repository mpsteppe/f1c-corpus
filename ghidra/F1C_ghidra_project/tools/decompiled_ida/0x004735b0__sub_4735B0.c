// Address: 0x004735b0
// Size: 159 bytes
// Name: sub_4735B0
// Type: int __thiscall(_DWORD *this)
// Source: IDA Hex-Rays decompilation

int __thiscall sub_4735B0(_DWORD *this)
{
  int v1; // eax
  int v2; // eax
  int v4; // eax
  _BYTE v5[32]; // [esp+4h] [ebp-20h] BYREF

  v1 = dword_7D0110;
  if ( dword_7D0110 == this[199] )
    return 0;
  this[199] = dword_7D0110;
  if ( !v1 )
  {
    v2 = sub_487010(0);
    sub_58815F(v5, v2);
    sub_48B810(v5);
    return 0;
  }
  if ( v1 != dword_7D011C )
  {
    sub_58815F(v5, "%d", v1);
    sub_48B810(v5);
    return 0;
  }
  v4 = sub_487010(1);
  sub_58815F(v5, v4);
  sub_48B810(v5);
  return 0;
}
