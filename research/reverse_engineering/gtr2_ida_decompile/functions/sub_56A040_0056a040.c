char __thiscall sub_56A040(_DWORD *this, float *a2)
{
  int v2; // esi
  int v3; // edx
  float *v4; // ecx
  float v6; // [esp+14h] [ebp-Ch]
  float v7; // [esp+18h] [ebp-8h]
  float v8; // [esp+1Ch] [ebp-4h]

  v2 = this[4];
  v3 = 0;
  if ( v2 > 0 )
  {
    v4 = (float *)this[5];
    do
    {
      v6 = *v4 - *a2;
      v7 = v4[1] - a2[1];
      v8 = v4[2] - a2[2];
      if ( v8 * v8 + v6 * v6 + v7 * v7 < v4[3] )
        break;
      ++v3;
      v4 += 6;
    }
    while ( v3 < v2 );
  }
  return 1;
}
