// Function: FUN_00424b20 @ 00424b20
// Size (bytes): 340


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00424b20(int param_1)

{
  float fVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  *(undefined4 *)(param_1 + 0x413c) = 0x7f7fffff;
  *(undefined4 *)(param_1 + 0x4470) = 0;
  *(undefined4 *)(param_1 + 0x4478) = 0;
  *(undefined4 *)(param_1 + 0x4474) = 0x4479c000;
  puVar2 = (undefined4 *)(param_1 + 0x41b4);
  puVar3 = (undefined4 *)(param_1 + 0x42cc);
  iVar4 = 5;
  do {
    puVar2[-3] = 0x497423f0;
    *puVar3 = 0;
    *puVar2 = 0xffffffff;
    puVar2[-0x10] = 0;
    puVar3 = puVar3 + 7;
    puVar2 = puVar2 + 0x11;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *(undefined4 *)(param_1 + 0x443c) = 0;
  *(undefined4 *)(param_1 + 0x4430) = 0;
  *(undefined4 *)(param_1 + 0x4524) = 0;
  *(undefined4 *)(param_1 + 0x4460) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x4464) = 0x3f800000;
  FUN_0042ae00();
  *(undefined4 *)(param_1 + 0x4458) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x44b0) = 0xffffffff;
  fVar1 = (float)-*(int *)(param_1 + 4) * _DAT_0059e864;
  *(undefined4 *)(param_1 + 0x442c) = 0;
  *(undefined4 *)(param_1 + 0x4484) = 0x497423f0;
  *(undefined4 *)(param_1 + 0x4538) = 0x497423f0;
  *(float *)(param_1 + 0x4454) = fVar1;
  *(undefined4 *)(param_1 + 0x4540) = 0x40c00000;
  *(undefined4 *)(param_1 + 0x4544) = 1;
  *(undefined1 *)(param_1 + 0x4548) = 0;
  *(undefined4 *)(param_1 + 0x454c) = 0;
  *(undefined4 *)(param_1 + 0x4550) = 0;
  *(undefined4 *)(param_1 + 0x4554) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x4510) = 0;
  *(undefined4 *)(param_1 + 0x4558) = 0x32;
  *(undefined4 *)(param_1 + 0x4560) = 0;
  *(undefined4 *)(param_1 + 0x4564) = 0;
  *(undefined4 *)(param_1 + 0x4404) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x446c) = 0;
  *(undefined4 *)(param_1 + 0x43f8) = 0;
  *(undefined1 *)(param_1 + 0x45f4) = 0;
  *(undefined4 *)(param_1 + 0x461c) = 0x497423f0;
  FUN_00424cd0(0,0);
  *(undefined4 *)(param_1 + 0x444c) = 0;
  FUN_00424c80();
  FUN_00426430();
  *(undefined1 *)(param_1 + 0x4584) = 0;
  return;
}


