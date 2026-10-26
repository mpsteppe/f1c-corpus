char __thiscall sub_57B5C0(_WORD *this, int a2, int a3)
{
  char result; // al
  int i; // eax

  result = 0;
  if ( a3 <= (unsigned __int16)this[2049] )
  {
    for ( i = 0; i < a3; this[2048] = (__int16)(this[2048] + 1) % 4096 )
    {
      *(_BYTE *)(i + a2) = *((_BYTE *)this + (__int16)this[2048]);
      ++i;
    }
    this[2049] -= a3;
    return 1;
  }
  return result;
}
