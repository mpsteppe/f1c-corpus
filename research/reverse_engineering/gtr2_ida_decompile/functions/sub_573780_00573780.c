int __thiscall sub_573780(int this, const void *a2, _DWORD *a3)
{
  int result; // eax

  result = this + 15936;
  qmemcpy((void *)(this + 15936), a2, 0x24u);
  *(_DWORD *)(this + 16072) = *a3;
  *(_DWORD *)(this + 16076) = a3[1];
  *(_DWORD *)(this + 16080) = a3[2];
  *(float *)(this + 16084) = *(float *)(this + 15960) * *(float *)(this + 16080)
                           + *(float *)(this + 15948) * *(float *)(this + 16076)
                           + *(float *)(this + 16072) * *(float *)(this + 15936);
  *(float *)(this + 16088) = *(float *)(this + 15964) * *(float *)(this + 16080)
                           + *(float *)(this + 15952) * *(float *)(this + 16076)
                           + *(float *)(this + 15940) * *(float *)(this + 16072);
  *(float *)(this + 16092) = *(float *)(this + 15968) * *(float *)(this + 16080)
                           + *(float *)(this + 15956) * *(float *)(this + 16076)
                           + *(float *)(this + 15944) * *(float *)(this + 16072);
  return result;
}
