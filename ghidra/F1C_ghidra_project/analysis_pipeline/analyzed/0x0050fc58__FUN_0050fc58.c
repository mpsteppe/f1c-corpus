// Function: FUN_0050fc58 @ 0050fc58
// Size (bytes): 37


/* WARNING: Removing unreachable block (ram,0x0050fc64) */

undefined8 __fastcall FUN_0050fc58(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = cpuid_Version_info(1);
  return CONCAT44(param_2,(uint)((*(uint *)(iVar1 + 8) & 0x800000) != 0));
}


