// Function: FUN_00535390 @ 00535390
// Size (bytes): 321


uint __fastcall FUN_00535390(undefined4 *param_1,uint param_2,int param_3)

{
  undefined4 *puVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  
  if ((((param_1 != (undefined4 *)0x0) && (param_3 != 2)) && (param_1[0xe] != -1)) &&
     (param_1[0xe] != -3)) {
    if (*(char *)(param_1 + 0x17) == 'w') {
      if (param_3 == 0) {
        param_2 = param_2 - param_1[2];
      }
      if (-1 < (int)param_2) {
        if (param_1[0x11] == 0) {
          puVar1 = _malloc(0x4000);
          param_1[0x11] = puVar1;
          for (iVar4 = 0x1000; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar1 = 0;
            puVar1 = puVar1 + 1;
          }
        }
        while( true ) {
          if ((int)param_2 < 1) {
            return param_1[2];
          }
          uVar3 = 0x4000;
          if ((int)param_2 < 0x4000) {
            uVar3 = param_2;
          }
          iVar4 = FUN_00535220(uVar3);
          if (iVar4 == 0) break;
          param_2 = param_2 - iVar4;
        }
      }
    }
    else {
      if (param_3 == 1) {
        param_2 = param_2 + param_1[5];
      }
      if (-1 < (int)param_2) {
        if (param_1[0x16] == 0) {
          if (param_2 < (uint)param_1[5]) {
            iVar4 = FUN_005354e0();
            if (iVar4 < 0) {
              return 0xffffffff;
            }
          }
          else {
            param_2 = param_2 - param_1[5];
          }
          if (param_2 != 0) {
            if (param_1[0x12] == 0) {
              pvVar2 = _malloc(0x4000);
              param_1[0x12] = pvVar2;
            }
            for (; 0 < (int)param_2; param_2 = param_2 - iVar4) {
              uVar3 = 0x4000;
              if ((int)param_2 < 0x4000) {
                uVar3 = param_2;
              }
              iVar4 = FUN_00534f90(uVar3);
              if (iVar4 < 1) {
                return 0xffffffff;
              }
            }
          }
          return param_1[5];
        }
        param_1[1] = 0;
        *param_1 = param_1[0x11];
        iVar4 = FUN_00587f64(param_1[0x10],param_2,0);
        if (-1 < iVar4) {
          param_1[5] = param_2;
          param_1[2] = param_2;
          return param_2;
        }
      }
    }
  }
  return 0xffffffff;
}


