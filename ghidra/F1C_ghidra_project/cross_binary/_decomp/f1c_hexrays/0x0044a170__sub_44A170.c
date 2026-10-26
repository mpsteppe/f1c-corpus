// f1c  0x0044a170  size=349
void __thiscall sub_44A170(float *this, int a2, int a3, int a4, char a5)
{
  int v5; // esi
  float *v6; // edx
  int v7; // edi
  int v8; // edx
  int v9; // edi
  float *v10; // edx
  int v11; // esi
  double v12; // st7
  double v13; // st7
  int v14; // [esp+10h] [ebp-4h]

  v5 = 0;
  *this = 0.0;
  this[1] = 1.7014117e38;
  this[2] = -1.7014117e38;
  this[3] = 0.0;
  this[4] = 1.7014117e38;
  this[5] = -1.7014117e38;
  this[6] = 3.4028235e38;
  v14 = 0;
  if ( a3 > 0 )
  {
    v6 = (float *)(a2 + 8);
    v7 = a3;
    v5 = a3;
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
      v6 += 4;
      --v7;
    }
    while ( v7 );
  }
  if ( v5 < a4 )
  {
    v8 = 16 * v5 + a2 + 4;
    v9 = a4 - v5;
    do
    {
      if ( *(float *)v8 < (double)this[2] )
        ++v14;
      if ( *(float *)v8 < (double)this[4] )
        this[4] = *(float *)v8;
      if ( *(float *)(v8 + 4) > (double)this[5] )
        this[5] = *(float *)(v8 + 4);
      if ( a5 )
      {
        *(float *)(*(_DWORD *)(v8 - 4) + 28) = this[3];
        this[3] = *(float *)(v8 - 4);
      }
      v8 += 16;
      --v9;
    }
    while ( v9 );
  }
  if ( a3 > 0 )
  {
    v10 = (float *)(a2 + 8);
    v11 = a3;
    do
    {
      if ( *v10 > (double)this[4] )
        ++v14;
      v10 += 4;
      --v11;
    }
    while ( v11 );
  }
  v12 = this[5] - this[2];
  if ( v12 == 0.0 )
    v13 = 1.0;
  else
    v13 = (this[2] - this[4]) / v12;
  if ( a4 )
    this[6] = (double)v14 / (double)a4 + v13;
  else
    this[6] = v13 + 1.0;
}
