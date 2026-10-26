int __thiscall sub_694CC7(_DWORD *this, int a2, int a3)
{
  int v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // eax

  v4 = this[4];
  if ( v4 && !a3 )
    a3 = *(_DWORD *)(v4 + 20);
  v5 = (_DWORD *)sub_65B229(36);
  if ( v5 )
    v6 = sub_67F02A(v5, a2, a3, 0, 0, this[4]);
  else
    v6 = 0;
  if ( v6 )
  {
    this[4] = v6;
    return 0;
  }
  else
  {
    sub_694C3A(this, 0, 0, "internal error: out of memory");
    return -2147024882;
  }
}
