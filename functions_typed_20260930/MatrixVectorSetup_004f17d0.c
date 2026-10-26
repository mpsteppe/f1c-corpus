int __thiscall sub_4F17D0(int this, const void *a2, _DWORD *a3)
{
  int result; // eax

  result = this + 13488;
  qmemcpy((void *)(this + 13488), a2, 0x24u);
  *(_DWORD *)(this + 13620) = *a3;
  *(_DWORD *)(this + 13624) = a3[1];
  *(_DWORD *)(this + 13628) = a3[2];
  *(float *)(this + 13632) = *(float *)(this + 13512) * *(float *)(this + 13628)
                           + *(float *)(this + 13500) * *(float *)(this + 13624)
                           + *(float *)(this + 13620) * *(float *)(this + 13488);
  *(float *)(this + 13636) = *(float *)(this + 13516) * *(float *)(this + 13628)
                           + *(float *)(this + 13504) * *(float *)(this + 13624)
                           + *(float *)(this + 13492) * *(float *)(this + 13620);
  *(float *)(this + 13640) = *(float *)(this + 13520) * *(float *)(this + 13628)
                           + *(float *)(this + 13508) * *(float *)(this + 13624)
                           + *(float *)(this + 13496) * *(float *)(this + 13620);
  return result;
}

