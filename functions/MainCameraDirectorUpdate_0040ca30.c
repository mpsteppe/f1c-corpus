char __thiscall sub_40CA30(int this)
{
  int v2; // edi
  int v3; // ebp
  _DWORD *v4; // ecx
  char result; // al
  char v6; // al
  int v7; // eax
  int v8; // edi
  int v9; // ecx
  int v10; // eax
  float *v11; // eax
  int v12; // edx
  long double v13; // st7
  int v14; // eax
  double v15; // st6
  float v16; // [esp+Ch] [ebp-4Ch]
  float v17; // [esp+28h] [ebp-30h] BYREF
  float v18; // [esp+2Ch] [ebp-2Ch]
  float v19; // [esp+30h] [ebp-28h]
  float v20; // [esp+34h] [ebp-24h] BYREF
  float v21; // [esp+38h] [ebp-20h] BYREF
  float v22; // [esp+3Ch] [ebp-1Ch] BYREF
  float v23; // [esp+40h] [ebp-18h] BYREF
  float v24; // [esp+44h] [ebp-14h] BYREF
  float v25; // [esp+48h] [ebp-10h] BYREF
  _BYTE v26[4]; // [esp+4Ch] [ebp-Ch] BYREF
  _BYTE v27[4]; // [esp+50h] [ebp-8h] BYREF
  _BYTE v28[4]; // [esp+54h] [ebp-4h] BYREF

  CameraTargetUpdateOnPlayerChange((_DWORD *)this);
  v2 = 0;
  v3 = 0;
  ShortComputation_c910((_DWORD *)this);
  if ( !*(_BYTE *)(this + 45) )
  {
    v4 = *(_DWORD **)(this + 24);
    *(_BYTE *)(this + 45) = 1;
    sub_409890(v4, 0);
  }
  TripleFieldGetter_2460(&v23, &v24, &v25);
  v20 = -v23;
  v23 = v20;
  v21 = -v24;
  v24 = v21;
  v22 = -v25;
  v25 = v22;
  ConditionalBranchByFlag(0);
  result = *(_BYTE *)(this + 37);
  if ( result )
  {
    *(_BYTE *)(this + 37) = 0;
  }
  else
  {
    v6 = *(_BYTE *)(this + 46);
    *(_DWORD *)(this + 40) = 0;
    if ( v6 )
      v7 = RandomStateMachineWithTimerAndTrigger(this);
    else
      v7 = KeyboardInputActionMapper(this);
    v3 = v7;
    CameraModeChangeRequest((_DWORD *)this);
    if ( v3 == 1 )
    {
      if ( dword_5C329C > 0 )
      {
        do
          sub_4F0D20(dword_7C54F0[v2++] + 12);
        while ( v2 < dword_5C329C );
      }
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(this + 8) + 16))(*(_DWORD *)(this + 8));
    }
    result = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 8) + 12))(*(_DWORD *)(this + 8));
  }
  v8 = dword_8AC4C4;
  if ( dword_8AC4C4 )
  {
    TwoCallDelegation_2420(&v20, &v21, &v22, v26, v27, v28);
    v17 = -v20;
    v20 = v17;
    v18 = -v21;
    v21 = v18;
    v19 = -v22;
    v22 = v19;
    if ( v3 )
    {
      result = (*(int (__thiscall **)(int, float *, _BYTE *))(*(_DWORD *)v8 + 28))(v8, &v20, v26);
      if ( dword_8ACEBC )
        return ParticlePositionAdd(&v23, &v20);
    }
    else
    {
      v9 = *(_DWORD *)(this + 8);
      if ( v9 == *(_DWORD *)(this + 24) )
      {
        v17 = *(float *)(dword_7C54E0 + 88);
        v18 = *(float *)(dword_7C54E0 + 92);
        v19 = *(float *)(dword_7C54E0 + 96);
      }
      else
      {
        v10 = (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 24))(v9);
        if ( v10 )
        {
          v11 = (float *)(v10 + 36);
          v17 = *v11;
          v18 = v11[1];
          v12 = *(_DWORD *)v8;
          v19 = v11[2];
          (*(void (__thiscall **)(int, float *, _BYTE *, float *))(v12 + 32))(v8, &v20, v26, &v17);
        }
      }
      v13 = 0.0;
      if ( !byte_7C56AC )
      {
        v13 = sqrt(v18 * v18 + v19 * v19 + v17 * v17) / (flt_7CFE28 * 0.44704) * *(float *)&dword_7CFE4C;
        if ( v13 >= *(float *)&dword_7CFE54 )
        {
          if ( v13 > *(float *)&dword_7CFE4C )
            v13 = *(float *)&dword_7CFE4C;
        }
        else
        {
          v13 = *(float *)&dword_7CFE54;
        }
      }
      v14 = VirtualDispatchHelper((_DWORD *)this);
      if ( v14 )
        v15 = *(float *)(v14 + 92);
      else
        v15 = 0.0;
      v16 = v15 + v13;
      ShortComputation_d450(LODWORD(v16));
      return (*(int (__thiscall **)(int, float *, _BYTE *, float *))(*(_DWORD *)v8 + 32))(v8, &v20, v26, &v17);
    }
  }
  return result;
}
