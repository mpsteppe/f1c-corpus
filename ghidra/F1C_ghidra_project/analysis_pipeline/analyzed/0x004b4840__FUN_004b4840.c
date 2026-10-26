// Function: FUN_004b4840 @ 004b4840
// Size (bytes): 158


uint * __thiscall FUN_004b4840(int param_1,int param_2,uint param_3,byte *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  
  iVar1 = ((int)(param_3 + ((int)param_3 >> 0x1f & 7U)) >> 3) + param_1 + param_2 * 0xd;
  uVar4 = param_3 & 0x80000007;
  if ((int)uVar4 < 0) {
    uVar4 = (uVar4 - 1 | 0xfffffff8) + 1;
  }
  if ((*(char *)(iVar1 + 1) >> ((byte)uVar4 & 0x1f) & 1U) != 0) {
    iVar5 = (param_2 + 7) * 0x10;
    puVar2 = *(undefined4 **)(iVar5 + param_1);
    iVar5 = iVar5 + param_1;
    *(undefined4 **)(iVar5 + 8) = puVar2;
    if (puVar2 != (undefined4 *)0x0) {
      puVar3 = (uint *)*puVar2;
      while (puVar3 != (uint *)0x0) {
        if ((*puVar3 & 0xff) == param_3) {
          *param_4 = *(char *)(iVar1 + 0x35) >> ((byte)uVar4 & 0x1f) & 1;
          return puVar3;
        }
        if (*(int *)(iVar5 + 8) != 0) {
          *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(*(int *)(iVar5 + 8) + 4);
        }
        if (*(undefined4 **)(iVar5 + 8) == (undefined4 *)0x0) {
          return (uint *)0x0;
        }
        puVar3 = (uint *)**(undefined4 **)(iVar5 + 8);
      }
    }
  }
  return (uint *)0x0;
}


