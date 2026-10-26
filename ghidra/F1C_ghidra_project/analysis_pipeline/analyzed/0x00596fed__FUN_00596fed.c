// Function: FUN_00596fed @ 00596fed
// Size (bytes): 74


int FUN_00596fed(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_008d41d4 = 1;
                    /* WARNING: Could not recover jumptable at 0x00597007. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_008d41d4 = 1;
                    /* WARNING: Could not recover jumptable at 0x0059701c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_008d3f48;
  }
  DAT_008d41d4 = (uint)bVar2;
  return param_1;
}


