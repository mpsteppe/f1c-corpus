// Function: FUN_0040de60 @ 0040de60
// Size (bytes): 719


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_0040de60(int *param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int local_8;
  
  if (*param_1 == 4) {
    param_1[0x27] = (int)((float)_DAT_008afe98 + (float)param_1[0x27]);
    param_1[0x26] = (int)((float)_DAT_008afe98 + (float)param_1[0x26]);
    if (param_1[0x22] == 0) {
LAB_0040dea7:
      *param_1 = -1;
      return *param_1;
    }
    local_8 = 0;
    while (iVar4 = local_8 + 1, local_8 < 10) {
      iVar5 = param_1[0x22];
      iVar2 = *(int *)(iVar5 + 0x28);
      local_8 = iVar4;
      if (iVar2 == 2) {
        if (*(int *)(iVar5 + 0x18) < 1) {
switchD_0040df5a_caseD_9:
          *(undefined4 *)(iVar5 + 0x28) = 4;
        }
        else {
          iVar5 = _rand();
          iVar4 = param_1[0x22];
          if (*(float *)(iVar4 + 0xc) <= (float)iVar5 * _DAT_0059e6e0) {
            *(undefined4 *)(iVar4 + 0x28) = 4;
          }
          else {
            if (*(int *)(iVar4 + 0x24) == 10) {
              thunk_FUN_00434860();
            }
            *(undefined4 *)(param_1[0x22] + 0x28) = 3;
          }
          iVar4 = param_1[0x22];
          piVar1 = (int *)(iVar4 + 0x18);
          *piVar1 = *piVar1 + -1;
          if (*piVar1 < 0) {
            *(undefined4 *)(iVar4 + 0x18) = 0;
          }
        }
      }
      else if (iVar2 == 3) {
        if (*(float *)(iVar5 + 0x10) < (float)param_1[0x27] ==
            (*(float *)(iVar5 + 0x10) == (float)param_1[0x27])) break;
        switch(*(undefined4 *)(iVar5 + 0x24)) {
        case 2:
          if (param_1[1] == 0) goto LAB_0040dea7;
          *(undefined1 *)(param_1[1] + 0x24) = 1;
          *(undefined1 *)(param_1 + 0x28) = 1;
          *(undefined4 *)(param_1[0x22] + 0x28) = 4;
          break;
        case 3:
          if (param_1[1] == 0) goto LAB_0040dea7;
          if ((char)param_1[0x28] != '\0') {
            *(undefined1 *)(param_1[1] + 0x24) = 0;
          }
          *(undefined1 *)(param_1 + 0x28) = 0;
          *(undefined4 *)(param_1[0x22] + 0x28) = 4;
          break;
        case 4:
          if (param_1[1] != 0) {
            FUN_0040d1b0(*(undefined4 *)(iVar5 + 0x2c),1);
          }
          *(undefined4 *)(param_1[0x22] + 0x28) = 4;
          break;
        case 5:
          if (param_1[1] != 0) {
            FUN_0042bbd0(*(undefined4 *)(iVar5 + 0x2c));
          }
          *(undefined4 *)(param_1[0x22] + 0x28) = 4;
          break;
        case 6:
          param_1[0x24] = *(int *)(iVar5 + 0x2c);
          *(undefined4 *)(iVar5 + 0x28) = 4;
          break;
        case 7:
          switch(*(undefined4 *)(iVar5 + 0x2c)) {
          case 0:
            FUN_0041c3e0();
            *(undefined4 *)(param_1[0x22] + 0x28) = 4;
            break;
          case 1:
            FUN_0041c440();
            *(undefined4 *)(param_1[0x22] + 0x28) = 4;
            break;
          case 2:
            FUN_0041c4c0(0);
            *(undefined4 *)(param_1[0x22] + 0x28) = 4;
            break;
          case 3:
            FUN_0041be60();
            *(undefined4 *)(param_1[0x22] + 0x28) = 4;
            break;
          case 4:
            FUN_0041c090();
          default:
            *(undefined4 *)(param_1[0x22] + 0x28) = 4;
          }
          break;
        default:
          goto switchD_0040df5a_caseD_8;
        case 9:
          goto switchD_0040df5a_caseD_9;
        case 10:
          iVar4 = FUN_00434460();
          if (iVar4 == 0) goto switchD_0040df5a_caseD_8;
          *(undefined4 *)(param_1[0x22] + 0x28) = 4;
          break;
        case 0xb:
          *(undefined4 *)(param_1[0x22] + 0x28) = 4;
          goto switchD_0040df5a_caseD_8;
        case 0xc:
          *param_1 = 5;
          *(undefined4 *)(iVar5 + 0x28) = 4;
        }
      }
      else {
        if (iVar2 != 4) break;
        if (*(int *)(iVar5 + 0x24) == 10) {
          FUN_004347c0();
        }
        iVar4 = param_1[0x22];
        if (*(char *)(iVar4 + 0x20) != '\0') {
          param_1[0x27] = 0;
        }
        if (*(int *)(iVar4 + 0x18) < 1) {
          cVar3 = FUN_0040dd30();
          if (cVar3 == '\0') {
            *param_1 = -1;
            return *param_1;
          }
        }
        else {
          *(undefined4 *)(iVar4 + 0x28) = 2;
        }
      }
    }
  }
switchD_0040df5a_caseD_8:
  return *param_1;
}


