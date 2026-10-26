// HUDFlagRendererMain: Collects flag bytes into render buffer. Blue flag = 65 (0x41) from VehicleFlagCheck(). Yellow=62, Black=63, Pit=102, Checkered=66. Renders via sub_553070.
char __thiscall HUDFlagRendererMain(_DWORD *this)
{
  int v1; // eax
  int v3; // esi
  bool v4; // zf
  float v5; // edx
  float v7; // [esp+4h] [ebp-14h]
  float v8; // [esp+8h] [ebp-10h]
  _BYTE v9[12]; // [esp+Ch] [ebp-Ch] BYREF

  LOBYTE(v1) = dword_7CFEA0;
  if ( !dword_7CFEA0 )
    return v1;
  LOBYTE(v1) = ConditionalFlagReturn(&dword_5EA43C);
  if ( (_BYTE)v1 || dword_8AB6E4 == 2 || this[2] != -1 )
    return v1;
  v3 = 0;
  if ( ShortComputation_bad0() )
  {
    v9[0] = 62;
    v3 = 1;
  }
  if ( VehicleFlagCheck() )
    v9[v3++] = 65;
  if ( DisqualificationCheck() )
    v9[v3++] = 63;
  LOBYTE(v1) = PitStateFlagCheck();
  if ( (_BYTE)v1 )
    v9[v3++] = 102;
  if ( dword_7C56A8 == 8 )
    v9[v3++] = 66;
  if ( dword_7CFEA0 == 2 )
  {
    if ( sub_49B9A0() )
      v9[v3++] = -126;
    if ( FuelWeightComputation() )
      v9[v3++] = 68;
    v1 = sub_49BA30();
    if ( v1 == 1 )
    {
      v9[v3] = -116;
LABEL_24:
      ++v3;
      goto LABEL_25;
    }
    v1 = sub_49BA30();
    if ( v1 == 2 )
    {
      v9[v3] = -115;
      goto LABEL_24;
    }
  }
LABEL_25:
  if ( v3 > 0 )
  {
    v1 = dword_8AD394;
    v4 = dword_8AD394 == 0;
    v9[v3] = 0;
    if ( !v4 )
    {
      v5 = *(float *)(v1 + 96);
      v7 = *(float *)(v1 + 92);
      *(_DWORD *)(v1 + 92) = 1069547520;
      *(_DWORD *)(dword_8AD394 + 96) = 1069547520;
      v8 = v5;
      FieldSetterAt0x48(0xFFFFFF);
      sub_553070(v9, 10, 0, dword_8B8DC8);
      LOBYTE(v1) = dword_8AD394;
      *(float *)(dword_8AD394 + 92) = v7;
      *(float *)(dword_8AD394 + 96) = v8;
    }
  }
  return v1;
}
