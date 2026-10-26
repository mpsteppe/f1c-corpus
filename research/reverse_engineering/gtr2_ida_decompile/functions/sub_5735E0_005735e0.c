int __thiscall sub_5735E0(int this, _DWORD *a2, _DWORD *a3, const void *a4, _DWORD *a5, _DWORD *a6, _DWORD *a7, int a8)
{
  int result; // eax

  *(_DWORD *)(this + 15972) = *a2;
  *(_DWORD *)(this + 15976) = a2[1];
  *(_DWORD *)(this + 15980) = a2[2];
  *(_DWORD *)(this + 15984) = *a3;
  *(_DWORD *)(this + 15988) = a3[1];
  *(_DWORD *)(this + 15992) = a3[2];
  qmemcpy((void *)(this + 15936), a4, 0x24u);
  *(_DWORD *)(this + 15996) = *a5;
  *(_DWORD *)(this + 16000) = a5[1];
  *(_DWORD *)(this + 16004) = a5[2];
  *(float *)(this + 16008) = *(float *)(this + 15960) * *(float *)(this + 16004)
                           + *(float *)(this + 15948) * *(float *)(this + 16000)
                           + *(float *)(this + 15996) * *(float *)(this + 15936);
  *(float *)(this + 16012) = *(float *)(this + 15940) * *(float *)(this + 15996)
                           + *(float *)(this + 15964) * *(float *)(this + 16004)
                           + *(float *)(this + 15952) * *(float *)(this + 16000);
  *(float *)(this + 16016) = *(float *)(this + 15944) * *(float *)(this + 15996)
                           + *(float *)(this + 15968) * *(float *)(this + 16004)
                           + *(float *)(this + 15956) * *(float *)(this + 16000);
  *(_DWORD *)(this + 16020) = *a6;
  *(_DWORD *)(this + 16024) = a6[1];
  *(_DWORD *)(this + 16028) = a6[2];
  *(_DWORD *)(this + 16072) = *a7;
  *(_DWORD *)(this + 16076) = a7[1];
  *(_DWORD *)(this + 16080) = a7[2];
  *(float *)(this + 16084) = *(float *)(this + 15960) * *(float *)(this + 16080)
                           + *(float *)(this + 15948) * *(float *)(this + 16076)
                           + *(float *)(this + 16072) * *(float *)(this + 15936);
  *(float *)(this + 16088) = *(float *)(this + 15964) * *(float *)(this + 16080)
                           + *(float *)(this + 15952) * *(float *)(this + 16076)
                           + *(float *)(this + 15940) * *(float *)(this + 16072);
  result = a8;
  *(float *)(this + 16092) = *(float *)(this + 15968) * *(float *)(this + 16080)
                           + *(float *)(this + 15956) * *(float *)(this + 16076)
                           + *(float *)(this + 15944) * *(float *)(this + 16072);
  *(_DWORD *)(this + 17304) = a8;
  return result;
}
