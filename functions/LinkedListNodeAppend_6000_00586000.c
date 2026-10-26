char __thiscall sub_586000(_DWORD *this, int a2, char a3)
{
  char result; // al
  int v5; // eax

  result = 0;
  if ( a2 )
  {
    v5 = OperatorNewNhMallocWrapper(12);
    if ( v5 )
    {
      *(_DWORD *)v5 = a2;
      *(_DWORD *)(v5 + 4) = 0;
      *(_BYTE *)(v5 + 8) = a3;
    }
    else
    {
      v5 = 0;
    }
    if ( *this )
    {
      *(_DWORD *)(this[1] + 4) = v5;
    }
    else
    {
      *this = v5;
      this[2] = v5;
    }
    this[1] = v5;
    ++this[3];
    return 1;
  }
  return result;
}
