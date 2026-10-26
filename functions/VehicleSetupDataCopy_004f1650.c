int __thiscall sub_4F1650(int this, _DWORD *a2, _DWORD *a3, const void *a4, _DWORD *a5, _DWORD *a6, _DWORD *a7, int a8)
{
  int result; // eax

  *(_DWORD *)(this + 13524) = *a2;
  *(_DWORD *)(this + 13528) = a2[1];
  *(_DWORD *)(this + 13532) = a2[2];
  *(_DWORD *)(this + 13536) = *a3;
  *(_DWORD *)(this + 13540) = a3[1];
  *(_DWORD *)(this + 13544) = a3[2];
  qmemcpy((void *)(this + 13488), a4, 0x24u);
  *(_DWORD *)(this + 13548) = *a5;
  *(_DWORD *)(this + 13552) = a5[1];
  *(_DWORD *)(this + 13556) = a5[2];
  *(float *)(this + 13560) = *(float *)(this + 13512) * *(float *)(this + 13556)
                           + *(float *)(this + 13500) * *(float *)(this + 13552)
                           + *(float *)(this + 13548) * *(float *)(this + 13488);
  *(float *)(this + 13564) = *(float *)(this + 13492) * *(float *)(this + 13548)
                           + *(float *)(this + 13516) * *(float *)(this + 13556)
                           + *(float *)(this + 13504) * *(float *)(this + 13552);
  *(float *)(this + 13568) = *(float *)(this + 13496) * *(float *)(this + 13548)
                           + *(float *)(this + 13520) * *(float *)(this + 13556)
                           + *(float *)(this + 13508) * *(float *)(this + 13552);
  *(_DWORD *)(this + 13572) = *a6;
  *(_DWORD *)(this + 13576) = a6[1];
  *(_DWORD *)(this + 13580) = a6[2];
  *(_DWORD *)(this + 13620) = *a7;
  *(_DWORD *)(this + 13624) = a7[1];
  *(_DWORD *)(this + 13628) = a7[2];
  *(float *)(this + 13632) = *(float *)(this + 13512) * *(float *)(this + 13628)
                           + *(float *)(this + 13500) * *(float *)(this + 13624)
                           + *(float *)(this + 13620) * *(float *)(this + 13488);
  *(float *)(this + 13636) = *(float *)(this + 13516) * *(float *)(this + 13628)
                           + *(float *)(this + 13504) * *(float *)(this + 13624)
                           + *(float *)(this + 13492) * *(float *)(this + 13620);
  result = a8;
  *(float *)(this + 13640) = *(float *)(this + 13520) * *(float *)(this + 13628)
                           + *(float *)(this + 13508) * *(float *)(this + 13624)
                           + *(float *)(this + 13496) * *(float *)(this + 13620);
  *(_DWORD *)(this + 14832) = a8;
  return result;
}
