int __thiscall sub_59BF20(int this, float a2)
{
  double v2; // st7
  int *v3; // edx
  float *v4; // esi
  float *v5; // edi
  int v6; // ebx
  float *v7; // edx
  bool v8; // zf
  int result; // eax
  int v10; // eax
  float v11; // [esp+0h] [ebp-1Ch]
  float v12; // [esp+4h] [ebp-18h]
  float v13; // [esp+8h] [ebp-14h]
  float v14; // [esp+Ch] [ebp-10h]
  float v15; // [esp+10h] [ebp-Ch]
  int *v16; // [esp+14h] [ebp-8h]
  int v17; // [esp+18h] [ebp-4h]
  float v18; // [esp+18h] [ebp-4h]
  float v19; // [esp+20h] [ebp+4h]

  v2 = -1.0e12;
  v15 = 1.0e12;
  v14 = 1.0e12;
  v12 = 1.0e12;
  v13 = -1.0e12;
  v11 = -1.0e12;
  if ( *(int *)(this + 280) > 0 )
  {
    v3 = (int *)(*(_DWORD *)(this + 284) + 8);
    v16 = v3;
    v17 = *(_DWORD *)(this + 280);
    do
    {
      if ( *v3 > 0 )
      {
        v4 = (float *)v3[1];
        v5 = v4;
        v6 = *v3;
        do
        {
          v7 = v5;
          if ( ((unsigned int)&unk_800000 & *(_DWORD *)(this + 20)) == 0 )
            v7 = v4;
          if ( *v7 < (double)v12 )
            v12 = *v7;
          if ( *v7 > (double)v11 )
            v11 = *v7;
          if ( v7[1] < (double)v14 )
            v14 = v7[1];
          if ( v7[1] > (double)v13 )
            v13 = v7[1];
          if ( v7[2] < (double)v15 )
            v15 = v7[2];
          if ( v2 < v7[2] )
            v2 = v7[2];
          v5 += 16;
          v4 += 12;
          --v6;
        }
        while ( v6 );
        v3 = v16;
      }
      v3 += 16;
      v8 = v17 == 1;
      v16 = v3;
      --v17;
    }
    while ( !v8 );
  }
  *(float *)(this + 48) = v2;
  *(float *)(this + 60) = v2;
  *(float *)(this + 32) = v14;
  *(float *)(this + 96) = v2;
  *(float *)(this + 108) = v2;
  *(float *)(this + 40) = v11;
  *(float *)(this + 52) = v12;
  *(float *)(this + 64) = v12;
  *(float *)(this + 72) = v15;
  *(float *)(this + 28) = v11;
  *(float *)(this + 80) = v13;
  *(float *)(this + 36) = v15;
  *(float *)(this + 88) = v11;
  *(float *)(this + 44) = v14;
  *(float *)(this + 56) = v14;
  *(float *)(this + 68) = v14;
  *(float *)(this + 100) = v12;
  *(float *)(this + 112) = v12;
  *(float *)(this + 76) = v11;
  *(float *)(this + 120) = v15;
  *(float *)(this + 84) = v15;
  *(float *)(this + 92) = v13;
  *(float *)(this + 104) = v13;
  *(float *)(this + 116) = v13;
  if ( v12 == v11 )
  {
    result = *(_DWORD *)(this + 20) & 0xFFFFFFEF;
  }
  else if ( v14 == v13 )
  {
    result = *(_DWORD *)(this + 20) & 0xFFFFFFEF;
  }
  else
  {
    v10 = *(_DWORD *)(this + 20);
    if ( v15 == v2 )
      result = v10 & 0xFFFFFFEF;
    else
      result = v10 | 0x10;
  }
  *(_DWORD *)(this + 20) = result;
  if ( (LOBYTE(a2) & 1) != 0 )
  {
    *(float *)(this + 220) = (v11 + v12) * 0.5;
    *(float *)(this + 224) = (v13 + v14) * 0.5;
    *(float *)(this + 228) = (v15 + v2) * 0.5;
  }
  v18 = (v11 - v12) * 0.5;
  v19 = (v13 - v14) * 0.5;
  *(float *)(this + 24) = sqrt((v2 - v15) * 0.5 * ((v2 - v15) * 0.5) + v19 * v19 + v18 * v18);
  return result;
}
