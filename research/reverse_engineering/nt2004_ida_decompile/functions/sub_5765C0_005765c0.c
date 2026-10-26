char __thiscall sub_5765C0(_DWORD *this, int a2, char a3)
{
  char result; // al
  _DWORD *v5; // eax

  result = 0;
  if ( a2 )
  {
    v5 = operator new(0xCu);
    if ( v5 )
    {
      *v5 = a2;
      v5[1] = 0;
      *((_BYTE *)v5 + 8) = a3;
    }
    else
    {
      v5 = 0;
    }
    if ( *this )
    {
      v5[1] = *this;
    }
    else
    {
      this[1] = v5;
      this[2] = v5;
    }
    *this = v5;
    ++this[3];
    return 1;
  }
  return result;
}
