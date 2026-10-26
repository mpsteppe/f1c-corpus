int __thiscall sub_65A5CE(_DWORD *this)
{
  int v2; // eax
  _DWORD *v3; // ecx
  char v5; // [esp+0h] [ebp-4h]

  v2 = this[154];
  v3 = *(_DWORD **)(v2 + 56);
  if ( v3 )
  {
    this[21] = v3[1];
    *(_DWORD *)(v2 + 56) = v3[3];
    v3[3] = 0;
    sub_659CB7(v3, 1);
    return 0;
  }
  else
  {
    sub_65DD1F((int)(this + 6), (int)(this + 158), 1510, "unexpected #endif", v5);
    this[17] = 1;
    return -2147467259;
  }
}
