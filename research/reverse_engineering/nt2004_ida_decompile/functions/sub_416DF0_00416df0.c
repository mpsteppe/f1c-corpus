_DWORD *__thiscall sub_416DF0(_DWORD *this, char a2)
{
  int v3; // eax
  _DWORD *v4; // ebp
  _DWORD *v5; // esi
  int v6; // eax
  int v7; // edi

  if ( (a2 & 2) != 0 )
  {
    v3 = *(this - 1);
    v4 = this - 1;
    v5 = &this[199 * v3];
    v6 = v3 - 1;
    if ( v6 >= 0 )
    {
      v7 = v6 + 1;
      do
      {
        v5 -= 199;
        *v5 = &off_5D5B08;
        sub_57BBF0(v5 + 54);
        --v7;
      }
      while ( v7 );
    }
    if ( (a2 & 1) != 0 )
      sub_5BE8AE(v4);
    return v4;
  }
  else
  {
    *this = &off_5D5B08;
    sub_57BBF0(this + 54);
    if ( (a2 & 1) != 0 )
      sub_5BE8AE(this);
    return this;
  }
}
