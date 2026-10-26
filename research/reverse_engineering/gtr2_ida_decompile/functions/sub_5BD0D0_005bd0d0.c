void *__thiscall sub_5BD0D0(int this, const void *a2)
{
  float *v3; // eax
  void *result; // eax
  double v5; // st6
  double v6; // st7
  int v7; // edi
  int i; // esi
  float v9; // [esp+14h] [ebp-44h]
  _BYTE v10[64]; // [esp+18h] [ebp-40h] BYREF

  if ( a2 )
    qmemcpy((void *)(this + 4), a2, 0x40u);
  else
    sub_5C00F0();
  v3 = *(float **)(this + 388);
  if ( v3 )
  {
    v9 = v3[65] * *(float *)(this + 248);
    v5 = v3[63] * *(float *)(this + 240);
    v6 = v3[64] * *(float *)(this + 244);
    *(float *)(this + 260) = v9;
    *(float *)(this + 252) = v5;
    *(float *)(this + 256) = v6;
    result = sub_42FBC0((char *)(this + 4), v10, (float *)(*(_DWORD *)(this + 388) + 68));
    qmemcpy((void *)(this + 68), result, 0x40u);
  }
  else
  {
    qmemcpy((void *)(this + 68), (const void *)(this + 4), 0x40u);
    result = *(void **)(this + 240);
    *(_DWORD *)(this + 252) = result;
    *(_DWORD *)(this + 256) = *(_DWORD *)(this + 244);
    *(_DWORD *)(this + 260) = *(_DWORD *)(this + 248);
  }
  v7 = *(_DWORD *)(this + 336);
  for ( i = 0; i < v7; ++i )
    result = (void *)sub_5C0470(*(_DWORD *)(*(_DWORD *)(this + 344) + 4 * i));
  return result;
}
