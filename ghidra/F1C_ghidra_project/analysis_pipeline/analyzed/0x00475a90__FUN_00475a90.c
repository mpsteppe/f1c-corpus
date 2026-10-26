// Function: FUN_00475a90 @ 00475a90
// Size (bytes): 489


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00475a90(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  double dVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  float local_6c;
  undefined4 local_68;
  int local_64;
  float local_60;
  undefined4 local_5c;
  int local_58;
  int local_54;
  undefined8 local_50;
  double local_48 [8];
  
  FUN_004881f0(param_1,param_2,param_3,param_4);
  cVar2 = FUN_00487160(0,&local_7c,&local_78);
  if ((cVar2 != '\0') && (cVar2 = FUN_00487160(1,&local_74,&local_70), cVar2 != '\0')) {
    local_50._0_4_ = 0;
    local_50._4_4_ = 0;
    local_58 = 0;
    local_54 = 0;
    local_60 = 0.0;
    local_5c = 0;
    iVar3 = FUN_00431820();
    local_6c = (float)(local_70 - local_78);
    local_64 = __ftol();
    dVar1 = _DAT_0059ea90;
    if (DAT_007d0474 != '\0') {
      dVar1 = _DAT_0059ea98;
    }
    local_6c = (float)dVar1;
    local_50._4_4_ = local_78;
    iVar4 = 0;
    local_50._0_4_ = local_7c;
    if (0 < iVar3) {
      do {
        fVar5 = (float10)FUN_00431850(iVar4);
        iVar4 = iVar4 + 1;
        (&local_50)[iVar4] = (double)(fVar5 * (float10)local_6c);
      } while (iVar4 < iVar3);
    }
    local_58 = (int)local_50;
    local_6c = (float)(local_74 - local_7c);
    local_54 = local_50._4_4_;
    local_60 = (float)__ftol();
    local_5c = local_64;
    FUN_00475c80(&local_58,&local_60);
    iVar4 = 1;
    if (1 < iVar3) {
      do {
        local_6c = local_60;
        local_64 = local_74 - local_7c;
        local_68 = local_5c;
        local_60 = (float)__ftol();
        FUN_00475cc0(local_6c,&local_50,&local_60,&local_58);
        FUN_00475c80(&local_6c,&local_58);
        FUN_00475c80(&local_58,&local_60);
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar3);
    }
  }
  return 0;
}


