int __thiscall CollisionAnimationTimerUpdate(int this)
{
  double v3; // st7
  unsigned __int8 v5; // c0
  unsigned __int8 v6; // c2
  int v7; // edx
  int v8; // edi
  int v9; // eax
  int v10; // edx

  if ( ByteFieldGetterAt100((_BYTE *)this) )
    return -1;
  if ( !*(_BYTE *)(this + 772) )
    return -1;
  v3 = FloatFieldAccessor((float *)*(_DWORD *)(this + 64)) + *(float *)(this + 792);
  *(float *)(this + 792) = v3;
  if ( v5 | v6 )
    return 0;
  *(float *)(this + 792) = v3 - 0.5 * (v3 - 0.75);
  CRTFtol(v3);
  if ( ShortComputation_6720((_DWORD *)this) && v7 > 0 )
  {
    v8 = v7;
    do
    {
      v9 = ShortComputation_6720((_DWORD *)this);
      (*(void (__stdcall **)(bool))(v10 + 184))(v9 == 4);
      --v8;
    }
    while ( v8 );
  }
  return 0;
}

