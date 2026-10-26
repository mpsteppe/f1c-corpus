// Function: FUN_005896ee @ 005896ee
// Size (bytes): 220


void FUN_005896ee(undefined4 *param_1)

{
  DWORD DVar1;
  undefined4 uVar2;
  _TIME_ZONE_INFORMATION local_d0;
  _SYSTEMTIME local_24;
  _SYSTEMTIME local_14;
  
  GetLocalTime(&local_14);
  GetSystemTime(&local_24);
  if (local_24.wMinute == DAT_008d3e68._2_2_) {
    if (local_24.wHour == (WORD)DAT_008d3e68) {
      if (local_24.wDay == DAT_008d3e64._2_2_) {
        if (local_24.wMonth == DAT_008d3e60._2_2_) {
          if (local_24.wYear == (WORD)DAT_008d3e60) goto LAB_00589798;
        }
      }
    }
  }
  DVar1 = GetTimeZoneInformation(&local_d0);
  if (DVar1 == 0xffffffff) {
    DAT_008d3e58 = 0xffffffff;
  }
  else if (((DVar1 == 2) && (local_d0.DaylightDate.wMonth != 0)) && (local_d0.DaylightBias != 0)) {
    DAT_008d3e58 = 1;
  }
  else {
    DAT_008d3e58 = 0;
  }
  DAT_008d3e60._0_2_ = local_24.wYear;
  DAT_008d3e60._2_2_ = local_24.wMonth;
  DAT_008d3e64._0_2_ = local_24.wDayOfWeek;
  DAT_008d3e64._2_2_ = local_24.wDay;
  DAT_008d3e68._0_2_ = local_24.wHour;
  DAT_008d3e68._2_2_ = local_24.wMinute;
  DAT_008d3e6c._0_2_ = local_24.wSecond;
  DAT_008d3e6c._2_2_ = local_24.wMilliseconds;
LAB_00589798:
  uVar2 = FUN_00591edf(local_14.wYear,local_14.wMonth,local_14.wDay,local_14.wHour,local_14.wMinute,
                       local_14.wSecond,DAT_008d3e58);
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = uVar2;
  }
  return;
}


