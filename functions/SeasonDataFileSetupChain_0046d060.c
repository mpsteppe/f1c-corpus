LPVOID SeasonDataFileSetupChain()
{
  char *v0; // eax
  LPVOID result; // eax
  char v2[104]; // [esp+0h] [ebp-1D1Ch] BYREF
  LPVOID v3; // [esp+68h] [ebp-1CB4h]
  _DWORD v4[235]; // [esp+1970h] [ebp-3ACh] BYREF

  SessionStructInit(v2);
  v0 = (char *)dword_7CE668;
  if ( !dword_7CE668 )
    v0 = byte_5EA438;
  VehicleSetupFileWriter(v2, (int)v0, 0);
  sub_4B0770((int *)byte_7CE498, 1);
  ScoreSlotDeallocator(v4);
  result = v3;
  if ( v3 )
    return (LPVOID)FreeWrapper_7bcf(v3);
  return result;
}
