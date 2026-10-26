int __thiscall StringCursorReset(int *this, char a2)
{
  int v3; // ecx
  _BYTE *v4; // eax
  int result; // eax
  _BYTE *v6; // edi
  bool v7; // zf
  _BYTE *v8; // edi
  int v9; // eax

  v3 = -1;
  if ( a2 )
  {
    v4 = (_BYTE *)this[188];
    this[189] = (int)v4;
    *v4 = 0;
    result = 0;
    v6 = (char *)this + 487;
    do
    {
      if ( !v3 )
        break;
      v7 = *v6++ == 0;
      --v3;
    }
    while ( !v7 );
    if ( -v3 != 2 )
      return EditBufferStringUpdate(this, (const char *)this + 487);
  }
  else
  {
    v8 = (_BYTE *)this[188];
    do
    {
      if ( !v3 )
        break;
      v7 = *v8++ == 0;
      --v3;
    }
    while ( !v7 );
    v9 = *this;
    this[189] = this[188] + -v3 - 2;
    return (*(int (__thiscall **)(int *, int))(v9 + 44))(this, 1);
  }
  return result;
}

