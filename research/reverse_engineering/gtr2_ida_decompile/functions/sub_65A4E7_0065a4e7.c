int __thiscall sub_65A4E7(_DWORD *this, int a2)
{
  _DWORD *v3; // eax
  BOOL v5; // ecx
  char v6; // [esp+0h] [ebp-4h]

  v3 = *(_DWORD **)(this[154] + 56);
  if ( !v3 )
  {
    sub_65DD1F((int)(this + 6), (int)(this + 158), 1508, "unexpected #elif", v6);
LABEL_5:
    this[17] = 1;
    return -2147467259;
  }
  if ( v3[2] )
  {
    sub_65DD1F((int)(this + 6), (int)(this + 158), 1513, "unexpected #elif following #else", v6);
    goto LABEL_5;
  }
  v5 = a2 && !*v3 && v3[1];
  this[21] = v5;
  if ( a2 )
    *v3 = 1;
  return 0;
}
