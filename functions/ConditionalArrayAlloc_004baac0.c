char **__thiscall sub_4BAAC0(char **this, char a2)
{
  int v3; // esi
  char *v4; // ebx
  char *v5; // edi

  v3 = a2 != 0 ? 64 : 32;
  v4 = (char *)OperatorNewNhMallocWrapper(12 * v3);
  if ( v4 )
  {
    v5 = v4;
    if ( (a2 != 0 ? 63 : 31) >= 0 )
    {
      do
      {
        WrapperPassThrough(v5);
        v5 += 12;
        --v3;
      }
      while ( v3 );
    }
    *this = v4;
    return this;
  }
  else
  {
    *this = 0;
    return this;
  }
}
