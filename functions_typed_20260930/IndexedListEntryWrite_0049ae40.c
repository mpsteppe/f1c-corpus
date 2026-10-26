char __thiscall sub_49AE40(_DWORD *this, int a2, __int16 a3, __int16 a4)
{
  int v4; // eax
  _DWORD *v5; // ecx
  int v6; // edx
  int v8; // eax
  __int16 **v9; // ecx
  __int16 *v10; // eax

  v4 = ShortComputation_adb0(this);
  v6 = a2;
  if ( a2 == v4 )
    return ObjectConstructor_adc0(v5, a3, a4);
  if ( a2 < 0 || a2 >= v5[3] )
  {
    v5[2] = 0;
  }
  else
  {
    v5[2] = *v5;
    if ( a2 > 0 )
    {
      do
      {
        v8 = v5[2];
        if ( !v8 )
          break;
        --v6;
        v5[2] = *(_DWORD *)(v8 + 4);
      }
      while ( v6 > 0 );
    }
  }
  v9 = (__int16 **)v5[2];
  if ( !v9 )
    return 0;
  v10 = *v9;
  if ( !*v9 )
    return 0;
  *v10 = a3;
  v10[1] = a4;
  return 1;
}

