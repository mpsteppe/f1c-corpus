int __thiscall sub_577510(int this)
{
  float *v2; // edi
  int v3; // ebx
  double v4; // st7
  float *v5; // ecx
  double v6; // st6
  double v7; // st5
  double v8; // st7
  int result; // eax
  double v10; // st7
  float v11; // [esp+Ch] [ebp-34h]
  double v12[3]; // [esp+10h] [ebp-30h] BYREF
  double v13[3]; // [esp+28h] [ebp-18h] BYREF

  v11 = 0.0;
  v2 = (float *)(this + 16156);
  v3 = 4;
  do
  {
    v4 = v2[1];
    v5 = v2 - 2;
    v6 = v2[22];
    v7 = v2[3];
    *v5 = v7 * *(float *)(this + 15944) + v4 * *(float *)(this + 15936) + v6 * *(float *)(this + 15940);
    *(v2 - 1) = v4 * *(float *)(this + 15948) + v6 * *(float *)(this + 15952) + v7 * *(float *)(this + 15956);
    *v2 = v7 * *(float *)(this + 15968) + v4 * *(float *)(this + 15960) + v6 * *(float *)(this + 15964);
    *v5 = *(float *)(this + 15972) + *(v2 - 2);
    *(v2 - 1) = *(float *)(this + 15976) + *(v2 - 1);
    *v2 = *(float *)(this + 15980) + *v2;
    v8 = sub_5745D0(v2 - 2);
    if ( v11 > v8 )
      v11 = v8;
    v2 += 63;
    --v3;
  }
  while ( v3 );
  result = *(_DWORD *)(this + 14804);
  v10 = v11 - 0.050000001 + *(float *)(this + 15976);
  *(float *)(this + 15976) = v10;
  if ( !result )
  {
    v13[0] = *(float *)(this + 15972);
    v13[1] = v10;
    v13[2] = *(float *)(this + 15980);
    v12[0] = *(float *)(this + 15984);
    v12[1] = *(float *)(this + 15988);
    v12[2] = *(float *)(this + 15992);
    return sub_443220((int)&dbl_B66040, v13, (int)v12);
  }
  return result;
}
