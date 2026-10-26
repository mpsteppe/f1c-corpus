// Function: FUN_0048cb00 @ 0048cb00
// Size (bytes): 281


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0048cb00(int *param_1,float param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_1[0xca] * param_1[0xcb];
  if (0 < iVar4) {
    param_1[0xd0] = (int)(param_2 + (float)param_1[0xd0]);
    iVar2 = __ftol();
    if (0 < iVar2) {
      do {
        iVar1 = param_1[0xcf];
        iVar3 = (param_1[0xce] * param_1[0xcb] + param_1[0xcb] / 2) - param_1[0xcd];
        if ((char)iVar1 == '\0') {
          if (0 < iVar3) {
            iVar3 = -iVar3;
            goto LAB_0048cb7e;
          }
LAB_0048cb84:
          if (iVar3 < 0) {
            iVar3 = -iVar3;
          }
        }
        else if (iVar3 < 0) {
LAB_0048cb7e:
          iVar3 = iVar3 + iVar4;
          goto LAB_0048cb84;
        }
        if (iVar3 != 0) {
          iVar3 = __ftol();
          if (iVar3 < 1) {
            iVar3 = 1;
          }
          iVar3 = param_1[0xcd] + iVar3 * ((uint)((char)iVar1 != '\0') * 2 + -1);
          param_1[0xcd] = iVar3;
          if (iVar4 <= iVar3) {
            do {
              iVar3 = iVar3 - iVar4;
            } while (iVar4 <= iVar3);
            param_1[0xcd] = iVar3;
          }
          iVar3 = param_1[0xcd];
          if (iVar3 < 0) {
            do {
              iVar3 = iVar3 + iVar4;
            } while (iVar3 < 0);
            param_1[0xcd] = iVar3;
          }
          (**(code **)(*param_1 + 0x2c))(1);
        }
        iVar2 = iVar2 + -1;
        param_1[0xd0] = (int)((float)param_1[0xd0] - _DAT_005ac108);
      } while (iVar2 != 0);
    }
  }
  return;
}


