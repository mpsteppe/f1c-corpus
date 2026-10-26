int __thiscall sub_62A9D0(char *this)
{
  int v2; // eax

  if ( !this || this[92] != 114 )
    return -1;
  v2 = *((_DWORD *)this + 17);
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 1) = 0;
  *(_DWORD *)this = v2;
  *((_DWORD *)this + 19) = sub_62CAA0(0);
  if ( *(_DWORD *)(this + 93) )
  {
    sub_62C500(this);
    return fseek(*((FILE **)this + 16), *(_DWORD *)(this + 93), 0);
  }
  else
  {
    rewind(*((FILE **)this + 16));
    return 0;
  }
}
