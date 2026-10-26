// Function: FUN_004f9200 @ 004f9200
// Size (bytes): 34


undefined4 FUN_004f9200(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_008afe68 != 0) {
    iVar1 = FUN_0055bde0(param_1);
    return *(undefined4 *)(iVar1 + 0x10);
  }
  return 0x10;
}


