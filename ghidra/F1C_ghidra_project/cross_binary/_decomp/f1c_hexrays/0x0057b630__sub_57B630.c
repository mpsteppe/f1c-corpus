// f1c  0x0057b630  size=75
char __thiscall sub_57B630(int this, int a2, int a3)
{
  char result; // al
  int v4; // eax
  int i; // edx

  result = 0;
  if ( a3 <= *(unsigned __int16 *)(this + 4098) )
  {
    v4 = *(__int16 *)(this + 4096);
    for ( i = 0; i < a3; ++i )
    {
      *(_BYTE *)(i + a2) = *(_BYTE *)(v4 + this);
      v4 = (v4 + 1) % 4096;
    }
    return 1;
  }
  return result;
}
