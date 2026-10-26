int __thiscall sub_4E45B0(int this)
{
  int result; // eax
  char *v3; // eax
  int v4; // eax
  bool v5; // cc
  int v6; // eax
  double v7; // st7
  LPVOID v8[3]; // [esp+8h] [ebp-3784h] BYREF
  LPVOID v9; // [esp+14h] [ebp-3778h]
  LPVOID v10; // [esp+1Ch] [ebp-3770h]
  LPVOID v11; // [esp+24h] [ebp-3768h]
  LPVOID v12; // [esp+2Ch] [ebp-3760h]
  LPVOID v13; // [esp+34h] [ebp-3758h]
  int v14; // [esp+F8h] [ebp-3694h]
  double v15; // [esp+FCh] [ebp-3690h]
  char v16[104]; // [esp+1A70h] [ebp-1D1Ch] BYREF
  LPVOID v17; // [esp+1AD8h] [ebp-1CB4h]
  _DWORD v18[235]; // [esp+33E0h] [ebp-3ACh] BYREF

  sub_4E4790(this);
  result = *(_DWORD *)(this + 12988);
  if ( result )
  {
    if ( result <= 0 || result > 3 )
      return result;
  }
  else
  {
    TireModelInit((int)&dbl_7C7428, *(_DWORD *)this);
  }
  SessionStructInit(v16);
  TireModelDataInit(v8);
  v3 = *(char **)(1060 * *(_DWORD *)(*(_DWORD *)this + 18584) + dword_8AC394 + 8);
  if ( !v3 )
    v3 = byte_5EA438;
  TheSvmHdvVehicleFileParser(v3, v16, 0);
  TheSvmHdvVehicleFileParser(*(_DWORD *)this + 18324, v16, 1);
  v4 = v14;
  v5 = v14 < 1;
  *(_DWORD *)(this + 13464) = v14;
  if ( v5 )
  {
    *(_DWORD *)(this + 13464) = 1;
  }
  else if ( v4 > 64 )
  {
    *(_DWORD *)(this + 13464) = 64;
  }
  v6 = *(_DWORD *)(this + 13464);
  *(float *)(this + 13468) = v15 * v15;
  v7 = 1.0 / (double)(40 * v6);
  *(float *)(this + 13472) = v7;
  *(float *)(this + 13476) = 1.0 / (double)(8 * (5 * v6 + 5));
  *(float *)(this + 13480) = v7;
  *(float *)(this + 13484) = dbl_8AFEA0;
  SuspensionAndWheelPhysics(v16, v8);
  TireBrushModelForceSolver(0);
  if ( v13 )
    FreeWrapper_7bcf(v13);
  if ( v12 )
    FreeWrapper_7bcf(v12);
  if ( v11 )
    FreeWrapper_7bcf(v11);
  if ( v10 )
    FreeWrapper_7bcf(v10);
  if ( v9 )
    FreeWrapper_7bcf(v9);
  if ( v8[0] )
    FreeWrapper_7bcf(v8[0]);
  ScoreSlotDeallocator(v18);
  result = (int)v17;
  if ( v17 )
    return FreeWrapper_7bcf(v17);
  return result;
}
