char __thiscall std::string::_Grow(_DWORD *this, unsigned int a2, char a3)
{
  _BYTE *v4; // ecx
  char v5; // al
  unsigned int v7; // eax

  if ( a2 > 0xFFFFFFFD )
    std::_Xlen();
  v4 = (_BYTE *)this[1];
  if ( v4 )
  {
    v5 = *(v4 - 1);
    if ( v5 )
    {
      if ( v5 != -1 )
      {
        if ( !a2 )
        {
          *(v4 - 1) = v5 - 1;
          std::string::_Tidy(this, 0);
          return 0;
        }
        goto LABEL_19;
      }
    }
  }
  if ( !a2 )
  {
    if ( a3 )
    {
      std::string::_Tidy(this, 1);
    }
    else if ( v4 )
    {
      this[2] = 0;
      *v4 = 0;
    }
    return 0;
  }
  if ( a3 )
  {
    v7 = this[3];
    if ( v7 <= 0x1F && v7 >= a2 )
      return 1;
    std::string::_Tidy(this, 1);
    goto LABEL_19;
  }
  if ( this[3] < a2 )
LABEL_19:
    std::string::_Copy(a2);
  return 1;
}
