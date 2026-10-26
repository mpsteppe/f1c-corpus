int __thiscall sub_51E230(int this, _DWORD *a2, _DWORD *a3, const void *a4, _DWORD *a5, _DWORD *a6, _DWORD *a7, int a8)
{
  int result; // eax

  *(_DWORD *)(this + 17520) = *a2;
  *(_DWORD *)(this + 17524) = a2[1];
  *(_DWORD *)(this + 17528) = a2[2];
  *(_DWORD *)(this + 17532) = *a3;
  *(_DWORD *)(this + 17536) = a3[1];
  *(_DWORD *)(this + 17540) = a3[2];
  qmemcpy((void *)(this + 17484), a4, 0x24u);
  *(_DWORD *)(this + 17544) = *a5;
  *(_DWORD *)(this + 17548) = a5[1];
  *(_DWORD *)(this + 17552) = a5[2];
  *(float *)(this + 17556) = *(float *)(this + 17508) * *(float *)(this + 17552)
                           + *(float *)(this + 17496) * *(float *)(this + 17548)
                           + *(float *)(this + 17544) * *(float *)(this + 17484);
  *(float *)(this + 17560) = *(float *)(this + 17488) * *(float *)(this + 17544)
                           + *(float *)(this + 17512) * *(float *)(this + 17552)
                           + *(float *)(this + 17500) * *(float *)(this + 17548);
  *(float *)(this + 17564) = *(float *)(this + 17492) * *(float *)(this + 17544)
                           + *(float *)(this + 17516) * *(float *)(this + 17552)
                           + *(float *)(this + 17504) * *(float *)(this + 17548);
  *(_DWORD *)(this + 17568) = *a6;
  *(_DWORD *)(this + 17572) = a6[1];
  *(_DWORD *)(this + 17576) = a6[2];
  *(_DWORD *)(this + 17616) = *a7;
  *(_DWORD *)(this + 17620) = a7[1];
  *(_DWORD *)(this + 17624) = a7[2];
  *(float *)(this + 17628) = *(float *)(this + 17508) * *(float *)(this + 17624)
                           + *(float *)(this + 17496) * *(float *)(this + 17620)
                           + *(float *)(this + 17616) * *(float *)(this + 17484);
  *(float *)(this + 17632) = *(float *)(this + 17512) * *(float *)(this + 17624)
                           + *(float *)(this + 17500) * *(float *)(this + 17620)
                           + *(float *)(this + 17488) * *(float *)(this + 17616);
  result = a8;
  *(float *)(this + 17636) = *(float *)(this + 17516) * *(float *)(this + 17624)
                           + *(float *)(this + 17504) * *(float *)(this + 17620)
                           + *(float *)(this + 17492) * *(float *)(this + 17616);
  *(_DWORD *)(this + 18828) = a8;
  return result;
}
