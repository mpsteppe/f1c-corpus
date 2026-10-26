BOOL sub_409950()
{
  float *v0; // eax
  int v2; // [esp+Ch] [ebp-24h]
  float v3; // [esp+Ch] [ebp-24h]
  float v4; // [esp+10h] [ebp-20h]
  float v5; // [esp+14h] [ebp-1Ch]
  float v6[3]; // [esp+24h] [ebp-Ch] BYREF

  sub_4095D0((int)v6, v2);
  v0 = (float *)sub_4031C0();
  if ( !v0 )
    return 1;
  v3 = v6[0] - v0[1];
  v4 = v6[1] - v0[2];
  v5 = v6[2] - v0[3];
  return v5 * v0[11] + v4 * v0[10] + v3 * v0[9] < 0.0;
}
