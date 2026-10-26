int __thiscall sub_65A564(_DWORD *this)
{
  _DWORD *v2; // eax
  BOOL v3; // edx
  char v5; // [esp+0h] [ebp-4h]

  v2 = *(_DWORD **)(this[154] + 56);
  v3 = 0;
  if ( !v2 )
  {
    sub_65DD1F((int)(this + 6), (int)(this + 158), 1509, "unexpected #else", v5);
LABEL_5:
    this[17] = 1;
    return -2147467259;
  }
  if ( v2[2] )
  {
    sub_65DD1F((int)(this + 6), (int)(this + 158), 1514, "unexpected #else following #else", v5);
    goto LABEL_5;
  }
  if ( !*v2 )
    v3 = v2[1] != 0;
  this[21] = v3;
  *v2 = 1;
  v2[2] = 1;
  return 0;
}
