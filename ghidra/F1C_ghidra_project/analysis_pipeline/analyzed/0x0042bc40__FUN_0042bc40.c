// Function: FUN_0042bc40 @ 0042bc40
// Size (bytes): 50


void FUN_0042bc40(int param_1)

{
  int iVar1;
  
  DAT_007c54e8 = &DAT_005ec6d8 + param_1 * 0x48c0;
  iVar1 = 0;
  do {
    if ((undefined *)(&DAT_007c54f0)[iVar1] == &DAT_005ec6d8 + param_1 * 0x48c0) {
      DAT_007c54e4 = iVar1;
      return;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x68);
  return;
}


