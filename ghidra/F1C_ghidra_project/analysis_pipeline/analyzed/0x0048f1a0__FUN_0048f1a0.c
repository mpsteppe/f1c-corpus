// Function: FUN_0048f1a0 @ 0048f1a0
// Size (bytes): 339


undefined4 __fastcall FUN_0048f1a0(int *param_1)

{
  char cVar1;
  int local_8;
  int local_4;
  
  cVar1 = FUN_00486710();
  if (cVar1 == '\0') {
    *(undefined1 *)((int)param_1 + 0x17d) = 1;
    FUN_00498880(&local_4,&local_8);
    if ((((param_1[0x4a] < local_4) && (local_4 < param_1[0x4b])) && (param_1[0x52] < local_8)) &&
       (local_8 < param_1[0x53])) {
      *(undefined1 *)((int)param_1 + 0x17e) = 1;
    }
    if (param_1[0x41] != 4) {
      if (((param_1[0x44] < local_4) && (local_4 < param_1[0x45])) &&
         ((param_1[0x4c] < local_8 && (local_8 < param_1[0x4d])))) {
        param_1[0x41] = 2;
        FUN_0048faf0(0xffffffff);
        param_1[0x43] = 0;
      }
      if (((param_1[0x46] < local_4) && (local_4 < param_1[0x47])) &&
         ((param_1[0x4e] < local_8 && (local_8 < param_1[0x4f])))) {
        param_1[0x41] = 3;
        FUN_0048fb30(0xffffffff);
        param_1[0x43] = 0;
      }
      FUN_0048f870();
    }
    if ((((param_1[0x48] < local_4) && (local_4 < param_1[0x49])) && (param_1[0x50] < local_8)) &&
       ((local_8 < param_1[0x51] && (-1 < param_1[0x5c])))) {
      param_1[0x5d] = param_1[0x5c];
      (**(code **)(*param_1 + 0x2c))(1);
    }
    (**(code **)(*param_1 + 0x40))(param_1[0x41]);
    (**(code **)(*param_1 + 0x98))();
  }
  return 0;
}


