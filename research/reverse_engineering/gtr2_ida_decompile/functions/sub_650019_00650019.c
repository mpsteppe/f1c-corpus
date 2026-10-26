void __thiscall sub_650019(int this, unsigned int a2)
{
  float *v2; // edx
  unsigned int v3; // esi

  if ( a2 < a2 + 16 * *(_DWORD *)(this + 104) )
  {
    v2 = (float *)(a2 + 8);
    v3 = ((unsigned int)(16 * *(_DWORD *)(this + 104) - 1) >> 4) + 1;
    do
    {
      if ( *(v2 - 2) == *(float *)(this + 36)
        && *(v2 - 1) == *(float *)(this + 40)
        && *v2 == *(float *)(this + 44)
        && v2[1] == *(float *)(this + 48) )
      {
        v2[1] = 0.0;
        *v2 = 0.0;
        *(v2 - 1) = 0.0;
        *(v2 - 2) = 0.0;
      }
      v2 += 4;
      --v3;
    }
    while ( v3 );
  }
}
