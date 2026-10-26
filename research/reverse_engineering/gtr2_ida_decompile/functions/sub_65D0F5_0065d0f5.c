int __thiscall sub_65D0F5(_DWORD *this, LPCWCH lpWideCharStr, LPSTR FilePart, void **a4, int a5)
{
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  int result; // eax

  v6 = operator new(0x70u);
  if ( v6 )
    v7 = sub_659CD8(v6);
  else
    v7 = 0;
  this[154] = v7;
  if ( !v7 )
    return -2147024882;
  result = sub_659D87((int)v7, lpWideCharStr, FilePart, (int)this, (int)(this + 158), (int)(this + 6), a5, 0, 0);
  if ( result >= 0 )
  {
    result = sub_65C578((int)this, a4);
    if ( result >= 0 )
    {
      this[155] = this[154];
      this[156] = a5;
      return 0;
    }
  }
  return result;
}
