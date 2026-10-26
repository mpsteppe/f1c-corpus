char __thiscall sub_5FDFB0(_DWORD *this, int a2, int a3)
{
  char result; // al
  _DWORD *v5; // eax
  int v6; // ecx

  result = 0;
  if ( a2 )
  {
    v5 = operator new(0xCu);
    if ( v5 )
    {
      LOBYTE(v6) = a3;
      *v5 = a2;
      return off_16C9594(v6, a2, a3);
    }
    else
    {
      if ( *this )
      {
        *(_DWORD *)(this[1] + 4) = 0;
      }
      else
      {
        *this = 0;
        this[2] = 0;
      }
      this[1] = 0;
      ++this[3];
      return 1;
    }
  }
  return result;
}
