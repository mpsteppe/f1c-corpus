char *__thiscall VehgenScnFileLoader(int this, char a2)
{
  const char *v3; // eax
  const char *v4; // ecx
  char *v5; // eax
  const char *v6; // eax
  const CHAR *v7; // ecx
  char *v8; // eax
  char *result; // eax
  LPVOID v10[2]; // [esp+4h] [ebp-48h] BYREF
  _BYTE v11[64]; // [esp+Ch] [ebp-40h] BYREF

  v10[0] = (LPVOID)OperatorNewNhMallocWrapper(128);
  *(_BYTE *)v10[0] = 0;
  v3 = dword_5EC438;
  v10[1] = (LPVOID)128;
  if ( !dword_5EC438 )
    v3 = byte_5EA438;
  StringCopyWithBufferRealloc((int)v10, v3);
  sub_5665B0((int)v10, aVehgenScn);
  v4 = (const char *)v10[0];
  if ( !v10[0] )
    v4 = byte_5EA438;
  SceneFileTEAMDIRVEHDIRNOTSPINWriter(v4, *(_DWORD *)(this + 18584), *(_DWORD *)(this + 18580), 0);
  v5 = (char *)v10[0];
  if ( !v10[0] )
    v5 = byte_5EA438;
  sub_4A4900((_DWORD *)(this + 13004), (int)v5);
  v6 = (const char *)v10[0];
  if ( !v10[0] )
    v6 = byte_5EA438;
  VehicleGraphicsSceneLoader((void **)(this + 1776), v6, a2);
  v7 = (const CHAR *)v10[0];
  if ( !v10[0] )
    v7 = byte_5EA438;
  FileAttributesExistenceCheck(v7);
  ArithmeticComparison_8370(this + 20);
  ZeroTwoFields((_DWORD *)(this + 16436));
  *(_DWORD *)(this + 18596) = -1;
  *(_DWORD *)(this + 18600) = -1;
  if ( !*(_DWORD *)(this + 13000) )
  {
    sub_4B0B20(byte_7CE498, v11, 63);
    SetDriverName((char *)this, (int)v11);
    v8 = (char *)dword_7CE684;
    if ( !dword_7CE684 )
      v8 = byte_5EA438;
    sub_587DD0((_BYTE *)(this + 18016), v8, 0x17u);
    *(_BYTE *)(this + 18039) = 0;
  }
  VehicleSetupDriverNumber((F1CVehicle *)this);
  ShortComputation_0b20(dword_5EA560, this + 12);
  result = (char *)v10[0];
  if ( v10[0] )
    return (char *)FreeWrapper_7bcf(v10[0]);
  return result;
}

