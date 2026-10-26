int __thiscall sub_5FE610(_DWORD *this, int a2)
{
  int v2; // edx
  float *i; // ecx

  if ( (*(_BYTE *)a2 & 8) == 0 )
  {
    v2 = 0;
    for ( i = (float *)(this[68] + 252);
          i[1] * *(float *)(a2 + 236) + *(i - 1) * *(float *)(a2 + 228) + *i * *(float *)(a2 + 232) + i[2] <= *(float *)(a2 + 20);
          i += 4 )
    {
      if ( ++v2 >= 6 )
        return 1;
    }
  }
  return 4;
}
