int __thiscall sub_49D3F0(_DWORD *this)
{
  int v2; // eax
  _BYTE v4[16]; // [esp+4h] [ebp-10h] BYREF

  if ( byte_7D0474 )
    v2 = sub_49B900();
  else
    v2 = sub_49B950();
  sub_58815F(v4, "%.3d", v2);
  return sub_553070(v4, 4, 43, *(_DWORD *)(this[4] + 84));
}
