// Function: FUN_0057aaf0 @ 0057aaf0
// Size (bytes): 48


bool __fastcall FUN_0057aaf0(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 auStack_40 [12];
  undefined4 *puStack_10;
  
  *param_2 = 0;
  puVar2 = auStack_40;
  puStack_10 = param_2;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  iVar1 = FUN_0057abb0();
  return iVar1 == 0;
}


