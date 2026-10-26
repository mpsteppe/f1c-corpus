int __thiscall sub_57DE20(int this, _DWORD *a2, _DWORD *a3)
{
  float *v4; // edi
  _DWORD *v5; // ecx
  int result; // eax
  double v7[3]; // [esp+10h] [ebp-30h] BYREF
  double v8[3]; // [esp+28h] [ebp-18h] BYREF

  v4 = (float *)(this + 15984);
  v5 = (_DWORD *)(this + 15984);
  *v5 = *a3;
  v5[1] = a3[1];
  v5[2] = a3[2];
  sub_614A90(v5, this + 15936);
  *(_DWORD *)(this + 15972) = *a2;
  *(_DWORD *)(this + 15976) = a2[1];
  *(_DWORD *)(this + 15980) = a2[2];
  *(_DWORD *)(this + 17476) = 0;
  sub_5761B0(this);
  sub_416420((float *)(this + 15936), (float *)(this + 15972), (float *)(this + 17660), (float *)(this + 17672));
  result = *(_DWORD *)(this + 14804);
  if ( !result )
  {
    v8[0] = *(float *)(this + 15972);
    v8[1] = *(float *)(this + 15976);
    v8[2] = *(float *)(this + 15980);
    v7[0] = *v4;
    v7[1] = *(float *)(this + 15988);
    v7[2] = *(float *)(this + 15992);
    return sub_443220((int)&dbl_B66040, v8, (int)v7);
  }
  return result;
}
