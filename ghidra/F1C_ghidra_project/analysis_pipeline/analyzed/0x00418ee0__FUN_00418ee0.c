// Function: FUN_00418ee0 @ 00418ee0
// Size (bytes): 468


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00418ee0(undefined4 *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  iVar6 = 0;
  local_14 = -1;
  local_18 = -1;
  local_1c = 0x7fffffff;
  local_20 = 0x7fffffff;
  puVar5 = &DAT_005f0cf8;
  puVar4 = param_1;
  do {
    *puVar4 = 0;
    if (DAT_007d0410 != 2) {
      if (*(int *)(puVar5 + -0x1358) == -1) {
        *puVar4 = 0xffffffff;
      }
      else if ((DAT_007c54e8 == 0) ||
              (DAT_007c54e8 != *(int *)(((int)&DAT_007c54f0 - (int)param_1) + (int)puVar4))) {
        if (*(int *)(DAT_007c54e8 + 0x48a0) ==
            *(int *)(*(int *)(((int)&DAT_007c54f0 - (int)param_1) + (int)puVar4) + 0x48a0)) {
          *puVar4 = 2;
        }
        else if (DAT_007d0410 == 4) {
          iVar2 = FUN_0041e890();
          iVar3 = FUN_0041e840();
          fVar1 = (_DAT_0059e43c - _DAT_0059e7f4) * (float)iVar3;
          if (fVar1 < (float)iVar2 != (fVar1 == (float)iVar2)) {
            iVar2 = FUN_0041e890();
            iVar3 = FUN_0041e840();
            if (((float)iVar2 <= (_DAT_0059e7f4 + _DAT_0059e43c) * (float)iVar3) &&
               (iVar2 = FUN_004c2990(), 2 < iVar2)) {
              iVar2 = *(int *)(puVar5 + 0xf0) - *(int *)(DAT_007c54e8 + 0x4710);
              if (local_20 < 0) {
                if ((iVar2 < 1) && (local_20 < iVar2)) {
LAB_0041902b:
                  local_20 = iVar2;
                  local_18 = iVar6;
                }
              }
              else if (iVar2 < local_20) goto LAB_0041902b;
            }
          }
          iVar2 = FUN_0041e890();
          if (iVar2 != 0) {
            iVar2 = FUN_0041e890();
            iVar3 = FUN_0041e840();
            iVar3 = iVar3 - iVar2;
            if (local_1c < 0) {
              if ((iVar3 < 1) && (local_1c < iVar3)) {
LAB_00419064:
                local_1c = iVar3;
                local_14 = iVar6;
              }
            }
            else if (iVar3 <= local_1c) goto LAB_00419064;
          }
        }
      }
      else {
        *puVar4 = 1;
      }
    }
    puVar5 = puVar5 + 0x48c0;
    iVar6 = iVar6 + 1;
    puVar4 = puVar4 + 1;
    if (0x7c9af7 < (int)puVar5) {
      if (local_18 < 0) {
        if (-1 < local_14) {
          param_1[local_14] = 3;
        }
        return;
      }
      param_1[local_18] = 3;
      return;
    }
  } while( true );
}


