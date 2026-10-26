// Function: FUN_0045f030 @ 0045f030
// Size (bytes): 581


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0045f030(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  size_t _Count;
  undefined4 *puVar6;
  undefined2 *local_278;
  int local_274;
  undefined1 local_270;
  undefined4 local_26f;
  undefined1 local_230;
  undefined4 local_22f;
  undefined1 local_1b0 [8];
  char local_1a8 [424];
  
  if (((_DAT_0059f114 <= *(float *)(param_1 + 900)) && (DAT_007ce254 == '\0')) &&
     (local_274 = 0, 0 < DAT_007cb218)) {
    local_278 = &DAT_007cb21c;
    do {
      switch(*local_278) {
      case 0x1002:
        iVar3 = 1;
        break;
      case 0x1003:
        iVar3 = 2;
        break;
      case 0x1004:
        iVar3 = 3;
        break;
      case 0x1005:
        iVar3 = 4;
        break;
      case 0x1006:
        iVar3 = 5;
        break;
      case 0x1007:
        iVar3 = 6;
        break;
      case 0x1008:
        iVar3 = 7;
        break;
      case 0x1009:
        iVar3 = 8;
        break;
      case 0x100a:
        iVar3 = 9;
        break;
      case 0x100b:
        iVar3 = 10;
        break;
      default:
        goto switchD_0045f095_default;
      }
      if (((iVar3 <= *(int *)(param_1 + 0x1b78c)) && (iVar3 = iVar3 + -1, -1 < iVar3)) &&
         (iVar3 < *(int *)(param_1 + 0x1b78c))) {
        puVar6 = *(undefined4 **)(param_1 + 0x1b780);
        for (; 0 < iVar3; iVar3 = iVar3 + -1) {
          if (puVar6 == (undefined4 *)0x0) goto switchD_0045f095_default;
          puVar6 = (undefined4 *)puVar6[1];
        }
        if ((puVar6 != (undefined4 *)0x0) && (piVar2 = (int *)*puVar6, piVar2 != (int *)0x0)) {
          pcVar4 = (char *)*piVar2;
          if (pcVar4 == (char *)0x0) {
            pcVar4 = &DAT_005ea438;
          }
          uVar5 = 0xffffffff;
          do {
            if (uVar5 == 0) break;
            uVar5 = uVar5 - 1;
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar1 != '\0');
          _Count = ~uVar5 - 1;
          if ((int)_Count < 0) {
            _Count = 0;
          }
          else if (0x9f < (int)_Count) {
            _Count = 0x9f;
          }
          FUN_004b33b0(4,6,_Count,0,(float)_DAT_008afea0,1);
          pcVar4 = (char *)*piVar2;
          if (pcVar4 == (char *)0x0) {
            pcVar4 = &DAT_005ea438;
          }
          _strncpy(local_1a8,pcVar4,_Count);
          local_1a8[_Count] = '\0';
          FUN_00462250(local_1b0,0,0xffffffff,0xffffffff);
          local_230 = DAT_005ea438;
          puVar6 = &local_22f;
          for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar6 = 0;
            puVar6 = puVar6 + 1;
          }
          *(undefined2 *)puVar6 = 0;
          *(undefined1 *)((int)puVar6 + 2) = 0;
          local_270 = DAT_005ea438;
          puVar6 = &local_26f;
          for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar6 = 0;
            puVar6 = puVar6 + 1;
          }
          *(undefined2 *)puVar6 = 0;
          *(undefined1 *)((int)puVar6 + 2) = 0;
          FUN_004b0b20(&local_270,0x40);
          FUN_0045bc50(&local_270,local_1a8,&local_230,0x80);
          FUN_004a0df0(&local_230);
          FUN_0045bd10(&local_230,3,0x1020304);
          *(undefined4 *)(param_1 + 900) = 0;
        }
      }
switchD_0045f095_default:
      local_274 = local_274 + 1;
      local_278 = local_278 + 1;
    } while (local_274 < DAT_007cb218);
  }
  return;
}


