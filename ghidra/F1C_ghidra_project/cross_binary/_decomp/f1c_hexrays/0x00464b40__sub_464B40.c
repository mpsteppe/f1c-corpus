// f1c  0x00464b40  size=100
char __thiscall sub_464B40(int this, int a2)
{
  char result; // al
  int i; // edx
  int v5; // edx

  if ( *(float *)(this + 113) < (double)*(float *)(a2 + 4)
    || (result = *(_BYTE *)(a2 + 3) ^ *(_BYTE *)(this + 112), (result & 7) != 0) )
  {
    if ( ((*(_DWORD *)a2 >> 18) & 0x3F) != 0 )
    {
      if ( ((*(_DWORD *)a2 >> 18) & 0x3F) == 7 )
        sub_4B2DD0(this + 109, *(float *)(a2 + 4));
    }
    else
    {
      sub_4B3A90(a2);
    }
    for ( i = 0; i < 104; i = v5 + 1 )
      result = sub_4649F0((_BYTE *)(i + this), 0);
  }
  return result;
}
