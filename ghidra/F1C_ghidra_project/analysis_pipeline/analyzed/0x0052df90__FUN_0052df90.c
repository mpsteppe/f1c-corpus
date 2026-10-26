// Function: FUN_0052df90 @ 0052df90
// Size (bytes): 140


/* WARNING: Removing unreachable block (ram,0x0052dfcc) */

undefined4 FUN_0052df90(void)

{
  int iVar1;
  
  iVar1 = cpuid_Version_info(1);
  if ((*(uint *)(iVar1 + 8) & 0x800000) == 0) {
    return 0xffffff00;
  }
  return 0xffffff01;
}


