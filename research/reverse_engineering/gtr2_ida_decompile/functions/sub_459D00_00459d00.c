void __thiscall sub_459D00(float *this, int a2, int a3, int a4, char a5)
{
  int v5; // edi
  float *v6; // edx
  unsigned int v7; // esi
  int v8; // esi
  float *v9; // edx
  int v10; // edx
  int v11; // esi
  int v12; // edi
  float *v13; // edx
  unsigned int v14; // esi
  float *v15; // edx
  int v16; // esi
  double v17; // st7
  double v18; // st7
  int v19; // edx
  int v20; // [esp+10h] [ebp-4h]

  v5 = 0;
  v19 = dword_16C9B38;
  *this = 0.0;
  *((_DWORD *)this + 1) = v19;
  this[2] = -1.7014117e38;
  this[3] = 0.0;
  *((_DWORD *)this + 4) = v19;
  this[5] = -1.7014117e38;
  this[6] = 3.4028235e38;
  v20 = 0;
  if ( a3 >= 4 )
  {
    v6 = (float *)(a2 + 8);
    v7 = ((unsigned int)(a3 - 4) >> 2) + 1;
    v5 = 4 * v7;
    do
    {
      if ( *(v6 - 1) < (double)this[1] )
        this[1] = *(v6 - 1);
      if ( *v6 > (double)this[2] )
        this[2] = *v6;
      if ( a5 )
      {
        *(float *)(*((_DWORD *)v6 - 2) + 28) = *this;
        *this = *(v6 - 2);
      }
      if ( v6[3] < (double)this[1] )
        this[1] = v6[3];
      if ( v6[4] > (double)this[2] )
        this[2] = v6[4];
      if ( a5 )
      {
        *(float *)(*((_DWORD *)v6 + 2) + 28) = *this;
        *this = v6[2];
      }
      if ( v6[7] < (double)this[1] )
        this[1] = v6[7];
      if ( v6[8] > (double)this[2] )
        this[2] = v6[8];
      if ( a5 )
      {
        *(float *)(*((_DWORD *)v6 + 6) + 28) = *this;
        *this = v6[6];
      }
      if ( v6[11] < (double)this[1] )
        this[1] = v6[11];
      if ( v6[12] > (double)this[2] )
        this[2] = v6[12];
      if ( a5 )
      {
        *(float *)(*((_DWORD *)v6 + 10) + 28) = *this;
        *this = v6[10];
      }
      v6 += 16;
      --v7;
    }
    while ( v7 );
  }
  if ( v5 < a3 )
  {
    v8 = a3 - v5;
    v9 = (float *)(16 * v5 + a2 + 8);
    v5 = a3;
    do
    {
      if ( *(v9 - 1) < (double)this[1] )
        this[1] = *(v9 - 1);
      if ( *v9 > (double)this[2] )
        this[2] = *v9;
      if ( a5 )
      {
        *(float *)(*((_DWORD *)v9 - 2) + 28) = *this;
        *this = *(v9 - 2);
      }
      v9 += 4;
      --v8;
    }
    while ( v8 );
  }
  if ( v5 < a4 )
  {
    v10 = 16 * v5 + a2 + 4;
    v11 = a4 - v5;
    do
    {
      if ( *(float *)v10 < (double)this[2] )
        ++v20;
      if ( *(float *)v10 < (double)this[4] )
        this[4] = *(float *)v10;
      if ( *(float *)(v10 + 4) > (double)this[5] )
        this[5] = *(float *)(v10 + 4);
      if ( a5 )
      {
        *(float *)(*(_DWORD *)(v10 - 4) + 28) = this[3];
        this[3] = *(float *)(v10 - 4);
      }
      v10 += 16;
      --v11;
    }
    while ( v11 );
  }
  v12 = 0;
  if ( a3 >= 4 )
  {
    v13 = (float *)(a2 + 24);
    v14 = ((unsigned int)(a3 - 4) >> 2) + 1;
    v12 = 4 * v14;
    do
    {
      if ( *(v13 - 4) > (double)this[4] )
        ++v20;
      if ( *v13 > (double)this[4] )
        ++v20;
      if ( v13[4] > (double)this[4] )
        ++v20;
      if ( v13[8] > (double)this[4] )
        ++v20;
      v13 += 16;
      --v14;
    }
    while ( v14 );
  }
  if ( v12 < a3 )
  {
    v15 = (float *)(16 * v12 + a2 + 8);
    v16 = a3 - v12;
    do
    {
      if ( *v15 > (double)this[4] )
        ++v20;
      v15 += 4;
      --v16;
    }
    while ( v16 );
  }
  v17 = this[5] - this[1];
  if ( v17 == 0.0 )
    v18 = 1.0;
  else
    v18 = (this[2] - this[4]) / v17;
  if ( a4 )
    this[6] = (double)v20 / (double)a4 + v18;
  else
    this[6] = v18 + 1.0;
}
