// Function: FUN_0042bbd0 @ 0042bbd0
// Size (bytes): 50


void FUN_0042bbd0(int param_1)

{
  int iVar1;
  
  DAT_007c54e0 = &DAT_005ec6d8 + param_1 * 0x48c0;
  iVar1 = 0;
  do {
    if ((undefined *)(&DAT_007c54f0)[iVar1] == &DAT_005ec6d8 + param_1 * 0x48c0) {
      DAT_007c54dc = iVar1;
      return;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x68);
  return;
}


