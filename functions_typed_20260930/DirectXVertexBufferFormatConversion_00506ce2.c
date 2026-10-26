int __thiscall sub_506CE2(_DWORD *this, int a2)
{
  unsigned int v2; // esi
  int v3; // edx
  float *v4; // eax
  double v5; // st7
  unsigned int v6; // esi
  int v7; // edx
  float *v8; // eax
  double v9; // st5
  unsigned int v10; // esi
  int v11; // edx
  float *v12; // eax
  double v13; // st7
  unsigned int v14; // esi
  int v15; // edx
  float *v16; // eax
  double v17; // st5
  unsigned int v18; // esi
  int v19; // edx
  float *v20; // eax
  double v21; // st5
  unsigned int v22; // esi
  int v23; // edx
  float *v24; // eax
  double v25; // st5

  switch ( this[2] )
  {
    case 1:
      if ( this[1042] == 2 )
      {
        v22 = 0;
        if ( this[1046] )
        {
          v23 = 0;
          v24 = (float *)(a2 + 8);
          do
          {
            ++v22;
            *(float *)(v23 + this[1043]) = (*(v24 - 2) + 1.0) * 0.5;
            v23 += 16;
            *(float *)(v23 + this[1043] - 12) = (*(v24 - 1) + 1.0) * 0.5;
            v25 = *v24;
            v24 += 4;
            *(float *)(v23 + this[1043] - 8) = (v25 + 1.0) * 0.5;
            *(float *)(v23 + this[1043] - 4) = *(v24 - 3);
          }
          while ( v22 < this[1046] );
        }
      }
      else if ( this[1042] == 3 )
      {
        v18 = 0;
        if ( this[1046] )
        {
          v19 = 0;
          v20 = (float *)(a2 + 8);
          do
          {
            ++v18;
            *(float *)(v19 + this[1043]) = (*(v20 - 2) + 1.0) * 0.5;
            v19 += 16;
            *(float *)(v19 + this[1043] - 12) = (*(v20 - 1) + 1.0) * 0.5;
            v21 = *v20;
            v20 += 4;
            *(float *)(v19 + this[1043] - 8) = (v21 + 1.0) * 0.5;
            *(float *)(v19 + this[1043] - 4) = (*(v20 - 3) + 1.0) * 0.5;
          }
          while ( v18 < this[1046] );
        }
      }
      break;
    case 2:
      if ( this[1042] == 1 )
      {
        v14 = 0;
        if ( this[1046] )
        {
          v15 = 0;
          v16 = (float *)(a2 + 8);
          do
          {
            ++v14;
            *(float *)(v15 + this[1043]) = *(v16 - 2) * 2.0 - 1.0;
            v15 += 16;
            *(float *)(v15 + this[1043] - 12) = *(v16 - 1) * 2.0 - 1.0;
            v17 = *v16;
            v16 += 4;
            *(float *)(v15 + this[1043] - 8) = v17 * 2.0 - 1.0;
            *(float *)(v15 + this[1043] - 4) = *(v16 - 3);
          }
          while ( v14 < this[1046] );
        }
      }
      else if ( this[1042] == 3 )
      {
        v10 = 0;
        if ( this[1046] )
        {
          v11 = 0;
          v12 = (float *)(a2 + 8);
          do
          {
            *(float *)(v11 + this[1043]) = *(v12 - 2);
            ++v10;
            *(float *)(v11 + this[1043] + 4) = *(v12 - 1);
            v11 += 16;
            *(float *)(v11 + this[1043] - 8) = *v12;
            v13 = v12[1];
            v12 += 4;
            *(float *)(v11 + this[1043] - 4) = (v13 + 1.0) * 0.5;
          }
          while ( v10 < this[1046] );
        }
      }
      break;
    case 3:
      if ( this[1042] == 1 )
      {
        v6 = 0;
        if ( this[1046] )
        {
          v7 = 0;
          v8 = (float *)(a2 + 8);
          do
          {
            ++v6;
            *(float *)(v7 + this[1043]) = *(v8 - 2) * 2.0 - 1.0;
            v7 += 16;
            *(float *)(v7 + this[1043] - 12) = *(v8 - 1) * 2.0 - 1.0;
            v9 = *v8;
            v8 += 4;
            *(float *)(v7 + this[1043] - 8) = v9 * 2.0 - 1.0;
            *(float *)(v7 + this[1043] - 4) = *(v8 - 3) * 2.0 - 1.0;
          }
          while ( v6 < this[1046] );
        }
      }
      else if ( this[1042] == 2 )
      {
        v2 = 0;
        if ( this[1046] )
        {
          v3 = 0;
          v4 = (float *)(a2 + 8);
          do
          {
            *(float *)(v3 + this[1043]) = *(v4 - 2);
            ++v2;
            *(float *)(v3 + this[1043] + 4) = *(v4 - 1);
            v3 += 16;
            *(float *)(v3 + this[1043] - 8) = *v4;
            v5 = v4[1];
            v4 += 4;
            *(float *)(v3 + this[1043] - 4) = v5 + v5 - 1.0;
          }
          while ( v2 < this[1046] );
        }
      }
      break;
  }
  return this[1043];
}

