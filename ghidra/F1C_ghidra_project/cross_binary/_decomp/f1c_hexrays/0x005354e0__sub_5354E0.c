// f1c  0x005354e0  size=108
int __thiscall sub_5354E0(char *this)
{
  int v2; // eax

  if ( !this || this[92] != 114 )
    return -1;
  v2 = *((_DWORD *)this + 17);
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 1) = 0;
  *(_DWORD *)this = v2;
  *((_DWORD *)this + 19) = sub_536E90(0);
  if ( *(_DWORD *)(this + 93) )
  {
    sub_535620(this);
    return sub_587F64(*((_DWORD *)this + 16), *(_DWORD *)(this + 93), 0);
  }
  else
  {
    sub_58AFE1(*((_DWORD *)this + 16));
    return 0;
  }
}
