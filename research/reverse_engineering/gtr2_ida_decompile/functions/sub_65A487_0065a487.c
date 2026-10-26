int __thiscall sub_65A487(int *this, int a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  BOOL v6; // eax

  v3 = operator new(0x10u);
  if ( v3 )
    v4 = sub_659C7F(v3, a2, this[20]);
  else
    v4 = 0;
  if ( !v4 )
    return -2147024882;
  v4[3] = *(_DWORD *)(this[154] + 56);
  *(_DWORD *)(this[154] + 56) = v4;
  v6 = this[20] && a2;
  this[21] = v6;
  return 0;
}
