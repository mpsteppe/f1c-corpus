int __thiscall sub_46C3C0(_DWORD *this)
{
  int i; // edx
  float *v2; // eax
  int result; // eax
  float v4; // [esp+24h] [ebp-Ch]
  float v5; // [esp+28h] [ebp-8h]
  float v6; // [esp+2Ch] [ebp-4h]

  for ( i = 0; i < this[1]; ++i )
  {
    if ( i )
    {
      v2 = (float *)(*this + 28 * i);
      v4 = *v2 - *(v2 - 7);
      v5 = v2[1] - *(v2 - 6);
      v6 = v2[2] - *(v2 - 5);
      v2[6] = sqrt(v6 * v6 + v5 * v5 + v4 * v4) + *(v2 - 1);
    }
    else
    {
      *(_DWORD *)(*this + 24) = 0;
    }
  }
  result = *this;
  this[2] = *(_DWORD *)(28 * i + *this - 60);
  return result;
}
