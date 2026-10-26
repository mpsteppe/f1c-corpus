// f1c  0x0044b910  size=301
void __thiscall sub_44B910(int this, int *a2)
{
  double v2; // st7
  float **v3; // ebx
  int v4; // ebp
  float **v5; // esi
  int v6; // edi
  float *v7; // edx
  double v8; // st7
  float v9; // [esp+4h] [ebp-10h]
  float v10; // [esp+8h] [ebp-Ch]
  float v11; // [esp+Ch] [ebp-8h]
  double v12; // [esp+Ch] [ebp-8h]

  v2 = -3.4028235e38;
  v9 = 3.4028235e38;
  v10 = 3.4028235e38;
  v11 = -3.4028235e38;
  if ( *a2 > 0 )
  {
    v3 = (float **)a2[2];
    v4 = *a2;
    do
    {
      v5 = v3;
      v6 = 3;
      do
      {
        v7 = *v5;
        if ( v9 > (double)**v5 )
          v9 = *v7;
        if ( v2 < *v7 )
          v2 = *v7;
        if ( v10 > (double)v7[3] )
          v10 = v7[3];
        if ( v11 < (double)v7[3] )
          v11 = v7[3];
        v5 += 2;
        --v6;
      }
      while ( v6 );
      v3 += 8;
      --v4;
    }
    while ( v4 );
  }
  v8 = (v2 - v9) * 0.03125;
  v12 = (v11 - v10) * 0.03125;
  *(double *)(this + 8) = 0.5 * v8 + v9;
  *(double *)(this + 24) = v12 * 0.5 + v10;
  if ( v8 == 0.0 )
  {
    *(_DWORD *)(this + 16) = 0;
    *(_DWORD *)(this + 20) = 0;
  }
  else
  {
    *(double *)(this + 16) = 1.0 / v8;
  }
  if ( v12 == 0.0 )
  {
    *(_DWORD *)(this + 32) = 0;
    *(_DWORD *)(this + 36) = 0;
  }
  else
  {
    *(double *)(this + 32) = 1.0 / v12;
  }
}
