// Function: FUN_005567f5 @ 005567f5
// Size (bytes): 101


/* WARNING: Removing unreachable block (ram,0x00556851) */
/* WARNING: Removing unreachable block (ram,0x0055683e) */
/* WARNING: Removing unreachable block (ram,0x00556818) */

undefined8 __fastcall
FUN_005567f5(undefined4 param_1,undefined4 param_2,int *param_3,uint *param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  byte in_CF;
  byte in_PF;
  byte in_AF;
  byte in_ZF;
  byte in_SF;
  byte in_TF;
  byte in_IF;
  byte in_OF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  uint uVar7;
  
  uVar7 = (uint)(in_NT & 1) * 0x4000 | (uint)(in_OF & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
          (uint)(in_TF & 1) * 0x100 | (uint)(in_SF & 1) * 0x80 | (uint)(in_ZF & 1) * 0x40 |
          (uint)(in_AF & 1) * 0x10 | (uint)(in_PF & 1) * 4 | (uint)(in_CF & 1) |
          (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 |
          (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  uVar4 = uVar7 ^ 0x200000;
  uVar5 = 0;
  if (((uint)((uVar4 & 0x4000) != 0) * 0x4000 | (uint)((uVar4 & 0x800) != 0) * 0x800 |
       (uint)((uVar4 & 0x200) != 0) * 0x200 | (uint)((uVar4 & 0x100) != 0) * 0x100 |
       (uint)((uVar4 & 0x80) != 0) * 0x80 | (uint)((uVar4 & 0x40) != 0) * 0x40 |
       (uint)((uVar4 & 0x10) != 0) * 0x10 | (uint)((uVar4 & 4) != 0) * 4 | (uint)((uVar4 & 1) != 0)
       | (uint)((uVar4 & 0x200000) != 0) * 0x200000 | (uint)((uVar4 & 0x40000) != 0) * 0x40000) !=
      uVar7) {
    iVar1 = cpuid_Version_info(1);
    if ((*(uint *)(iVar1 + 8) & 0x10) != 0) {
      uVar3 = rdtsc();
      uVar4 = *param_4;
      *param_3 = ((int)((ulonglong)uVar3 >> 0x20) - *param_3) - (uint)((uint)uVar3 < *param_4);
      *param_4 = (uint)uVar3 - uVar4;
    }
    if (param_5 != (undefined4 *)0x0) {
      iVar1 = cpuid_basic_info(0);
      uVar6 = *(undefined4 *)(iVar1 + 8);
      uVar5 = *(undefined4 *)(iVar1 + 0xc);
      *param_5 = *(undefined4 *)(iVar1 + 4);
      param_5[1] = uVar6;
      param_5[2] = uVar5;
      *(undefined1 *)(param_5 + 3) = 0;
    }
    puVar2 = (undefined4 *)cpuid_Version_info(1);
    uVar5 = *puVar2;
  }
  return CONCAT44(param_2,uVar5);
}


