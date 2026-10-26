// Function: FUN_00553700 @ 00553700
// Size (bytes): 633


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00553700(uint *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 local_1fc [5];
  undefined4 local_1e8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined1 local_1bc [444];
  
  if (0 < (int)param_1[1]) {
    uVar1 = *param_1;
    if ((char)(uVar1 >> 8) < '\0') {
      *param_1 = uVar1 & 0xffff7fff;
      if ((uVar1 & 1) == 0) {
        if ((uVar1 & 2) != 0) {
          iVar2 = FUN_00540f00(param_1[5],0x60,0,0);
          iVar5 = 0;
          if (0 < (int)param_1[1]) {
            iVar4 = 0;
            puVar3 = (undefined4 *)(iVar2 + 8);
            do {
              puVar3[-2] = *(undefined4 *)(iVar4 + param_1[6]);
              puVar3[-1] = *(undefined4 *)(iVar4 + 4 + param_1[6]);
              *puVar3 = *(undefined4 *)(iVar4 + 8 + param_1[6]);
              puVar3[1] = *(undefined4 *)(iVar4 + 0xc + param_1[6]);
              puVar3[3] = *(undefined4 *)(iVar4 + 0x14 + param_1[6]);
              puVar3[4] = *(undefined4 *)(iVar4 + 0x18 + param_1[6]);
              puVar3[2] = *(undefined4 *)(iVar4 + 0x10 + param_1[6]);
              iVar5 = iVar5 + 1;
              iVar4 = iVar4 + 0x1c;
              puVar3 = puVar3 + 7;
            } while (iVar5 < (int)param_1[1]);
          }
        }
      }
      else {
        iVar2 = FUN_00540f00(param_1[5],0x60,0,0);
        iVar5 = 0;
        if (0 < (int)param_1[1]) {
          iVar4 = 0;
          puVar3 = (undefined4 *)(iVar2 + 8);
          do {
            puVar3[-2] = *(undefined4 *)(iVar4 + param_1[6]);
            puVar3[-1] = *(undefined4 *)(iVar4 + 4 + param_1[6]);
            *puVar3 = *(undefined4 *)(iVar4 + 8 + param_1[6]);
            puVar3[2] = *(undefined4 *)(iVar4 + 0x10 + param_1[6]);
            puVar3[3] = *(undefined4 *)(iVar4 + 0x14 + param_1[6]);
            puVar3[1] = *(undefined4 *)(iVar4 + 0xc + param_1[6]);
            iVar5 = iVar5 + 1;
            iVar4 = iVar4 + 0x18;
            puVar3 = puVar3 + 6;
          } while (iVar5 < (int)param_1[1]);
        }
      }
      FUN_00540f90(param_1[5]);
    }
    if (DAT_008b8df0 == 0) {
      FUN_005550a0();
    }
    if (param_2 != DAT_008b8dc8) {
      FUN_0055cdf0();
      FUN_0053b130();
      FUN_0055ca40(2,local_1fc);
      local_1fc[0] = 0x3f22f983;
      local_1e8 = 0x3f22f983;
      local_1d4 = 0x3de38e39;
      local_1d0 = 0x3f800000;
      local_1c4 = 0xbc360b61;
      local_1c0 = 0;
      FUN_0055ca40(4,local_1fc);
      FUN_0055ca90(param_2,1);
      FUN_0053b160();
    }
    if (1 < DAT_008b8cec) {
      FUN_005418b0();
      FUN_00542200(_DAT_008b8cf0,0,_DAT_008b8cf4,0x3f800000,0);
      FUN_0055cc20(local_1bc);
      FUN_00557470();
    }
    FUN_00541120(DAT_008b8f28,param_1[5],0,param_1[1],param_1[4],param_1[2],param_1[3],3,2);
    if (DAT_008b8df0 == 0) {
      FUN_005550c0();
    }
    if (param_2 != DAT_008b8dc8) {
      FUN_0055ca90(DAT_008b8dc8,1);
      FUN_0055ce50();
    }
  }
  return;
}


