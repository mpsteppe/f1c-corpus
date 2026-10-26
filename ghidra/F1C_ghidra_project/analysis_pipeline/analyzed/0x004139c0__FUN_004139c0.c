// Function: FUN_004139c0 @ 004139c0
// Size (bytes): 412


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004139c0(int param_1,int param_2,int param_3,char param_4)

{
  double dVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = 0xffffffff;
  if ((param_2 == 0) && (param_4 == '\0')) {
    dVar1 = (double)param_3;
    if (_DAT_0059e420 <= dVar1) {
      if (_DAT_0059e7e0 <= dVar1) {
        if (_DAT_0059e7d8 <= dVar1) {
          if (_DAT_0059e7d0 <= dVar1) {
            if (_DAT_0059e7c8 <= dVar1) {
              if (_DAT_0059e7c0 <= dVar1) {
                if (_DAT_0059e7b8 <= dVar1) {
                  if (_DAT_0059e7b0 <= dVar1) {
                    if (_DAT_0059e7a8 <= dVar1) {
                      if (_DAT_0059e7a0 <= dVar1) {
                        if (_DAT_0059e798 <= dVar1) {
                          if (_DAT_0059e790 <= dVar1) {
                            if (_DAT_0059e788 <= dVar1) {
                              if (param_3 < 0x4b) {
                                iVar3 = 0x2d;
                              }
                              else if (param_3 < 0x6e) {
                                iVar3 = 0x2e;
                              }
                              else {
                                iVar3 = (0x3e6 < param_3) + 0x2f;
                              }
                            }
                            else {
                              iVar3 = 0x2c;
                            }
                          }
                          else {
                            iVar3 = 0x2b;
                          }
                        }
                        else {
                          iVar3 = 0x2a;
                        }
                      }
                      else {
                        iVar3 = 0x29;
                      }
                    }
                    else {
                      iVar3 = 0x28;
                    }
                  }
                  else {
                    iVar3 = 0x27;
                  }
                }
                else {
                  iVar3 = 0x26;
                }
              }
              else {
                iVar3 = 0x25;
              }
            }
            else {
              iVar3 = 0x24;
            }
          }
          else {
            iVar3 = 0x23;
          }
        }
        else {
          iVar3 = 0x22;
        }
      }
      else {
        iVar3 = 0x21;
      }
    }
    else {
      iVar3 = 0x20;
    }
    *(int *)(param_1 + 8) = iVar3;
    uVar2 = FUN_00414180(0);
    *(undefined4 *)(param_1 + 0xc) = uVar2;
    uVar2 = 1;
  }
  return uVar2;
}


