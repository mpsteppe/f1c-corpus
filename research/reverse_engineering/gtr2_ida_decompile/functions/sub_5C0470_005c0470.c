void *__thiscall sub_5C0470(int this)
{
  float *v2; // eax
  void *result; // eax
  double v4; // st6
  double v5; // st7
  int v6; // edi
  int i; // esi
  float v8; // [esp+14h] [ebp-44h]
  _BYTE v9[64]; // [esp+18h] [ebp-40h] BYREF

  sub_5C00F0();
  v2 = *(float **)(this + 388);
  if ( v2 )
  {
    v8 = v2[65] * *(float *)(this + 248);
    v4 = v2[63] * *(float *)(this + 240);
    v5 = v2[64] * *(float *)(this + 244);
    *(float *)(this + 260) = v8;
    *(float *)(this + 252) = v4;
    *(float *)(this + 256) = v5;
    result = sub_42FBC0((char *)(this + 4), v9, (float *)(*(_DWORD *)(this + 388) + 68));
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
  v6 = *(_DWORD *)(this + 336);
  for ( i = 0; i < v6; ++i )
    result = (void *)sub_5C0470(*(_DWORD *)(*(_DWORD *)(this + 344) + 4 * i));
  return result;
}
