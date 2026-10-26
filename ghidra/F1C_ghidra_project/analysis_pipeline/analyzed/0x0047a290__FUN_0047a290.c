// Function: FUN_0047a290 @ 0047a290
// Size (bytes): 149


undefined4 __fastcall FUN_0047a290(int *param_1)

{
  float fVar1;
  char cVar2;
  int iVar3;
  float *pfVar4;
  
  FUN_00466910();
  iVar3 = (**(code **)(*DAT_007cd8c0 + 0x1c))(9);
  if ((iVar3 != 0) && ((char)param_1[0x40] != '\0')) {
    pfVar4 = (float *)(**(code **)(*param_1 + 0xb4))();
    fVar1 = *pfVar4;
    cVar2 = FUN_00490190();
    if (cVar2 != '\0') {
      pfVar4 = (float *)&DAT_007d17cc;
      do {
        *pfVar4 = fVar1;
        if (pfVar4[2] <= *pfVar4) {
          if (pfVar4[3] < *pfVar4) {
            *pfVar4 = pfVar4[3];
          }
        }
        else {
          *pfVar4 = pfVar4[2];
        }
        pfVar4 = pfVar4 + 0x1b;
      } while ((int)pfVar4 < 0x7d1b2c);
    }
  }
  return 0;
}


