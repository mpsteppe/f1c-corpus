// Function: FUN_004b3bd0 @ 004b3bd0
// Size (bytes): 141


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004b3bd0(float *param_1)

{
  DWORD DVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  undefined1 local_4 [4];
  
  *param_1 = 0.0;
  DVar1 = GetTickCount();
  FUN_005884e0(DVar1);
  iVar3 = 0x100;
  pfVar4 = param_1;
  do {
    pfVar4 = pfVar4 + 1;
    iVar2 = _rand();
    iVar3 = iVar3 + -1;
    *pfVar4 = (float)iVar2 * _DAT_0059e6e0;
  } while (iVar3 != 0);
  iVar3 = 0x100;
  pfVar4 = param_1 + 0x101;
  do {
    iVar2 = _rand();
    iVar3 = iVar3 + -1;
    *pfVar4 = (float)iVar2 * _DAT_005accf0 - _DAT_0059e43c;
    pfVar4 = pfVar4 + 1;
  } while (iVar3 != 0);
  FUN_0055687b(local_4,param_1 + 0x201);
  return;
}


