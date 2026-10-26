// Function: FUN_0047b910 @ 0047b910
// Size (bytes): 172


int __thiscall FUN_0047b910(int param_1,int param_2,int param_3,int param_4)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  bool bVar5;
  int local_c;
  undefined1 local_4 [4];
  
  iVar2 = param_2;
  puVar4 = (undefined1 *)**(undefined4 **)(param_1 + 0xe0);
  if (puVar4 == (undefined1 *)0x0) {
    puVar4 = &DAT_005ea438;
  }
  iVar3 = param_3 + 1;
  bVar5 = iVar3 == param_4;
  local_c = 0;
  if (iVar3 < param_4) {
    do {
      uVar1 = puVar4[iVar3];
      puVar4[iVar3] = 0;
      FUN_004983b0(puVar4 + param_3,&param_2,local_4,1);
      puVar4[iVar3] = uVar1;
      if (iVar2 <= param_2) {
        if (iVar2 <= (param_2 + local_c) / 2) {
          iVar3 = iVar3 + -1;
        }
        break;
      }
      iVar3 = iVar3 + 1;
      local_c = param_2;
    } while (iVar3 < param_4);
    bVar5 = iVar3 == param_4;
  }
  if (((bVar5) && (param_3 < iVar3)) && (puVar4[iVar3] != '\0')) {
    iVar3 = iVar3 + -1;
  }
  return iVar3;
}


