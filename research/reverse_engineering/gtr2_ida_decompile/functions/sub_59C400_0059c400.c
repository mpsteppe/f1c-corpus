char __thiscall sub_59C400(int this, int a2, int a3)
{
  char result; // al
  int i; // eax

  result = 0;
  if ( a3 <= *(unsigned __int16 *)(this + 2052) )
  {
    for ( i = 0; i < a3; *(_DWORD *)(this + 2048) = (*(_DWORD *)(this + 2048) + 1) % 2048 )
    {
      *(_BYTE *)(i + a2) = *(_BYTE *)(this + *(_DWORD *)(this + 2048));
      ++i;
    }
    *(_WORD *)(this + 2052) -= a3;
    return 1;
  }
  return result;
}
