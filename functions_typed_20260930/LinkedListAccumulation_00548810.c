int __thiscall sub_548810(_DWORD *this)
{
  int v2; // ecx
  _DWORD *v3; // ecx
  _DWORD *v4; // edx

  v2 = this[9];
  *this = 0;
  for ( this[1] = 0; v2; v2 = v3[48] )
  {
    FAILCallChainSaysAccumulatesButFunctionZEROS0x94(v2);
    *v4 += v3[37];
    v4[1] += v3[38];
  }
  return 0;
}

