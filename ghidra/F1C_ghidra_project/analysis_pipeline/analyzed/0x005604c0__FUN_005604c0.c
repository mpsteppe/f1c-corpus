// Function: FUN_005604c0 @ 005604c0
// Size (bytes): 135


undefined8 __fastcall
FUN_005604c0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8,int param_9,int param_10,int param_11,int param_12,
            short param_13)

{
  short sVar1;
  bool bVar2;
  undefined4 in_EAX;
  int iVar3;
  int iVar4;
  short *psVar5;
  undefined4 *puVar6;
  
  psVar5 = (short *)(param_3 + param_6 * param_5 + param_4 * 2);
  puVar6 = (undefined4 *)(param_7 + param_10 * param_9 + param_8 * 2);
  LOCK();
  UNLOCK();
  iVar3 = param_11 * 2;
  do {
    do {
      sVar1 = *psVar5;
      if (param_13 != sVar1) {
        *puVar6 = CONCAT22(sVar1,sVar1);
        *(uint *)(param_10 + (int)puVar6) = CONCAT22(sVar1,sVar1);
      }
      psVar5 = psVar5 + 1;
      puVar6 = puVar6 + 1;
      iVar4 = iVar3 + -2;
      bVar2 = 1 < iVar3;
      iVar3 = iVar4;
    } while (iVar4 != 0 && bVar2);
    psVar5 = (short *)((int)psVar5 + param_6 + param_11 * -2);
    puVar6 = (undefined4 *)((int)puVar6 + (param_10 + param_11 * -2) * 2);
    iVar4 = param_12 + -1;
    bVar2 = 0 < param_12;
    iVar3 = param_11 * 2;
    param_12 = iVar4;
  } while (iVar4 != 0 && bVar2);
  return CONCAT44(param_2,in_EAX);
}


