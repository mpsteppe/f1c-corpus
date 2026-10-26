double __thiscall sub_45B5C0(int this)
{
  int v2; // ebx
  int v3; // esi
  float v5; // [esp+8h] [ebp-14h]
  int v6; // [esp+Ch] [ebp-10h] BYREF
  int v7; // [esp+10h] [ebp-Ch] BYREF
  float v8; // [esp+14h] [ebp-8h] BYREF
  int v9; // [esp+18h] [ebp-4h]

  v2 = 0;
  v9 = FloatArrayThresholdSearch();
  v5 = 0.0;
  if ( v9 > 0 )
  {
    do
    {
      v3 = FindActivePhysicsChannelByIndex((float *)this, v2);
      *(float *)&v6 = 0.0;
      DoubleFieldGetterAt0x300x34((_DWORD *)(this + 4), &v8, &v7);
      NormalizedCoordinateCalculator(92 * v3 + this + 60, v8, v7, (int)&v6, 0, 0);
      if ( *(float *)&v6 > (double)v5 )
        v5 = *(float *)&v6;
      ++v2;
    }
    while ( v2 < v9 );
  }
  return v5;
}

