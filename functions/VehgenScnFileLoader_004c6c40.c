char *__thiscall sub_4C6C40(int this, char a2)
{
  char *v3; // eax
  char *v4; // eax
  char *v5; // eax
  const CHAR *v6; // ecx
  char *v7; // eax
  char *result; // eax
  char *v9; // [esp+4h] [ebp-48h]
  _BYTE v10[64]; // [esp+Ch] [ebp-40h] BYREF

  v9 = (char *)OperatorNewNhMallocWrapper(128);
  *v9 = 0;
  v3 = (char *)dword_5EC438;
  if ( !dword_5EC438 )
    v3 = byte_5EA438;
  StringCopyWithBufferRealloc(v3);
  sub_5665B0(aVehgenScn);
  SceneFileTEAMDIRVEHDIRNOTSPINWriter(*(_DWORD *)(this + 18580), 0);
  v4 = v9;
  if ( !v9 )
    v4 = byte_5EA438;
  sub_4A4900((_DWORD *)(this + 13004), (int)v4);
  v5 = v9;
  if ( !v9 )
    v5 = byte_5EA438;
  VehicleGraphicsSceneLoader(v5, a2);
  v6 = v9;
  if ( !v9 )
    v6 = byte_5EA438;
  FileAttributesExistenceCheck(v6);
  ArithmeticComparison_8370(this + 20);
  ZeroTwoFields((_DWORD *)(this + 16436));
  *(_DWORD *)(this + 18596) = -1;
  *(_DWORD *)(this + 18600) = -1;
  if ( !*(_DWORD *)(this + 13000) )
  {
    sub_4B0B20(byte_7CE498, v10, 63);
    SetDriverName((char *)this, (int)v10);
    v7 = (char *)dword_7CE684;
    if ( !dword_7CE684 )
      v7 = byte_5EA438;
    sub_587DD0(this + 18016, v7, 23);
    *(_BYTE *)(this + 18039) = 0;
  }
  VehicleSetupDriverNumber(this);
  ShortComputation_0b20(dword_5EA560, this + 12);
  result = v9;
  if ( v9 )
    return (char *)FreeWrapper_7bcf(v9);
  return result;
}
