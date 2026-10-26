int __thiscall sub_64EB2A(_DWORD *this, int a2)
{
  unsigned int v2; // edi
  float *v3; // edx
  int v4; // ebx
  double v5; // st5
  char *v6; // esi
  double v7; // st5
  double v8; // st5
  double v9; // st5
  unsigned int v10; // esi
  int v11; // edx
  float *v12; // eax
  double v13; // st7
  unsigned int v14; // esi
  int v15; // edx
  float *v16; // eax
  double v17; // st5
  unsigned int v18; // edi
  float *v19; // edx
  int v20; // ebx
  double v21; // st5
  char *v22; // esi
  double v23; // st5
  double v24; // st5
  double v25; // st5
  unsigned int v26; // esi
  int v27; // edx
  float *v28; // eax
  double v29; // st7
  unsigned int v30; // esi
  int v31; // edx
  float *v32; // eax
  double v33; // st5
  unsigned int v34; // edi
  float *v35; // edx
  int v36; // ebx
  double v37; // st6
  char *v38; // esi
  double v39; // st6
  double v40; // st6
  double v41; // st6
  unsigned int v42; // esi
  int v43; // edx
  float *v44; // eax
  double v45; // st5
  unsigned int v46; // esi
  int v47; // edx
  float *v48; // eax
  double v49; // st5

  switch ( this[2] )
  {
    case 1:
      switch ( this[21] )
      {
        case 2:
          v46 = 0;
          if ( this[26] )
          {
            v47 = 0;
            v48 = (float *)(a2 + 8);
            do
            {
              ++v46;
              *(float *)(v47 + this[22]) = (*(v48 - 2) + 1.0) * 0.5;
              v47 += 16;
              *(float *)(v47 + this[22] - 12) = (*(v48 - 1) + 1.0) * 0.5;
              v49 = *v48;
              v48 += 4;
              *(float *)(v47 + this[22] - 8) = (v49 + 1.0) * 0.5;
              *(float *)(v47 + this[22] - 4) = *(v48 - 3);
            }
            while ( v46 < this[26] );
          }
          break;
        case 3:
          v42 = 0;
          if ( this[26] )
          {
            v43 = 0;
            v44 = (float *)(a2 + 8);
            do
            {
              ++v42;
              *(float *)(v43 + this[22]) = (*(v44 - 2) + 1.0) * 0.5;
              v43 += 16;
              *(float *)(v43 + this[22] - 12) = (*(v44 - 1) + 1.0) * 0.5;
              v45 = *v44;
              v44 += 4;
              *(float *)(v43 + this[22] - 8) = (v45 + 1.0) * 0.5;
              *(float *)(v43 + this[22] - 4) = (*(v44 - 3) + 1.0) * 0.5;
            }
            while ( v42 < this[26] );
          }
          break;
        case 4:
          v34 = 0;
          if ( this[26] )
          {
            v35 = (float *)(a2 + 8);
            v36 = -8 - a2;
            do
            {
              if ( *(v35 - 2) >= 0.0 )
              {
                if ( *(v35 - 2) >= 1.0 )
                  v37 = 1.0;
                else
                  v37 = *(v35 - 2);
              }
              else
              {
                v37 = 0.0;
              }
              v38 = (char *)v35 + v36;
              *(float *)((char *)v35 + v36 + this[22]) = v37;
              if ( *(v35 - 1) >= 0.0 )
              {
                if ( *(v35 - 1) >= 1.0 )
                  v39 = 1.0;
                else
                  v39 = *(v35 - 1);
              }
              else
              {
                v39 = 0.0;
              }
              *(float *)&v38[this[22] + 4] = v39;
              if ( *v35 >= 0.0 )
              {
                if ( *v35 >= 1.0 )
                  v40 = 1.0;
                else
                  v40 = *v35;
              }
              else
              {
                v40 = 0.0;
              }
              *(float *)&v38[this[22] + 8] = v40;
              if ( v35[1] >= 0.0 )
              {
                if ( v35[1] >= 1.0 )
                  v41 = 1.0;
                else
                  v41 = v35[1];
              }
              else
              {
                v41 = 0.0;
              }
              ++v34;
              *(float *)&v38[this[22] + 12] = v41;
              v35 += 4;
            }
            while ( v34 < this[26] );
          }
          break;
      }
      break;
    case 2:
      switch ( this[21] )
      {
        case 1:
          v30 = 0;
          if ( this[26] )
          {
            v31 = 0;
            v32 = (float *)(a2 + 8);
            do
            {
              ++v30;
              *(float *)(v31 + this[22]) = *(v32 - 2) * 2.0 - 1.0;
              v31 += 16;
              *(float *)(v31 + this[22] - 12) = *(v32 - 1) * 2.0 - 1.0;
              v33 = *v32;
              v32 += 4;
              *(float *)(v31 + this[22] - 8) = v33 * 2.0 - 1.0;
              *(float *)(v31 + this[22] - 4) = *(v32 - 3);
            }
            while ( v30 < this[26] );
          }
          break;
        case 3:
          v26 = 0;
          if ( this[26] )
          {
            v27 = 0;
            v28 = (float *)(a2 + 8);
            do
            {
              *(float *)(v27 + this[22]) = *(v28 - 2);
              ++v26;
              *(float *)(v27 + this[22] + 4) = *(v28 - 1);
              v27 += 16;
              *(float *)(v27 + this[22] - 8) = *v28;
              v29 = v28[1];
              v28 += 4;
              *(float *)(v27 + this[22] - 4) = (v29 + 1.0) * 0.5;
            }
            while ( v26 < this[26] );
          }
          break;
        case 4:
          v18 = 0;
          if ( this[26] )
          {
            v19 = (float *)(a2 + 8);
            v20 = -8 - a2;
            do
            {
              if ( *(v19 - 2) >= -1.0 )
              {
                if ( *(v19 - 2) >= 1.0 )
                  v21 = 1.0;
                else
                  v21 = *(v19 - 2);
              }
              else
              {
                v21 = -1.0;
              }
              v22 = (char *)v19 + v20;
              *(float *)((char *)v19 + v20 + this[22]) = v21;
              if ( *(v19 - 1) >= -1.0 )
              {
                if ( *(v19 - 1) >= 1.0 )
                  v23 = 1.0;
                else
                  v23 = *(v19 - 1);
              }
              else
              {
                v23 = -1.0;
              }
              *(float *)&v22[this[22] + 4] = v23;
              if ( *v19 >= -1.0 )
              {
                if ( *v19 >= 1.0 )
                  v24 = 1.0;
                else
                  v24 = *v19;
              }
              else
              {
                v24 = -1.0;
              }
              *(float *)&v22[this[22] + 8] = v24;
              if ( v19[1] >= 0.0 )
              {
                if ( v19[1] >= 1.0 )
                  v25 = 1.0;
                else
                  v25 = v19[1];
              }
              else
              {
                v25 = 0.0;
              }
              ++v18;
              *(float *)&v22[this[22] + 12] = v25;
              v19 += 4;
            }
            while ( v18 < this[26] );
          }
          break;
      }
      break;
    case 3:
      switch ( this[21] )
      {
        case 1:
          v14 = 0;
          if ( this[26] )
          {
            v15 = 0;
            v16 = (float *)(a2 + 8);
            do
            {
              ++v14;
              *(float *)(v15 + this[22]) = *(v16 - 2) * 2.0 - 1.0;
              v15 += 16;
              *(float *)(v15 + this[22] - 12) = *(v16 - 1) * 2.0 - 1.0;
              v17 = *v16;
              v16 += 4;
              *(float *)(v15 + this[22] - 8) = v17 * 2.0 - 1.0;
              *(float *)(v15 + this[22] - 4) = *(v16 - 3) * 2.0 - 1.0;
            }
            while ( v14 < this[26] );
          }
          break;
        case 2:
          v10 = 0;
          if ( this[26] )
          {
            v11 = 0;
            v12 = (float *)(a2 + 8);
            do
            {
              *(float *)(v11 + this[22]) = *(v12 - 2);
              ++v10;
              *(float *)(v11 + this[22] + 4) = *(v12 - 1);
              v11 += 16;
              *(float *)(v11 + this[22] - 8) = *v12;
              v13 = v12[1];
              v12 += 4;
              *(float *)(v11 + this[22] - 4) = v13 + v13 - 1.0;
            }
            while ( v10 < this[26] );
          }
          break;
        case 4:
          v2 = 0;
          if ( this[26] )
          {
            v3 = (float *)(a2 + 8);
            v4 = -8 - a2;
            do
            {
              if ( *(v3 - 2) >= -1.0 )
              {
                if ( *(v3 - 2) >= 1.0 )
                  v5 = 1.0;
                else
                  v5 = *(v3 - 2);
              }
              else
              {
                v5 = -1.0;
              }
              v6 = (char *)v3 + v4;
              *(float *)((char *)v3 + v4 + this[22]) = v5;
              if ( *(v3 - 1) >= -1.0 )
              {
                if ( *(v3 - 1) >= 1.0 )
                  v7 = 1.0;
                else
                  v7 = *(v3 - 1);
              }
              else
              {
                v7 = -1.0;
              }
              *(float *)&v6[this[22] + 4] = v7;
              if ( *v3 >= -1.0 )
              {
                if ( *v3 >= 1.0 )
                  v8 = 1.0;
                else
                  v8 = *v3;
              }
              else
              {
                v8 = -1.0;
              }
              *(float *)&v6[this[22] + 8] = v8;
              if ( v3[1] >= -1.0 )
              {
                if ( v3[1] >= 1.0 )
                  v9 = 1.0;
                else
                  v9 = v3[1];
              }
              else
              {
                v9 = -1.0;
              }
              ++v2;
              *(float *)&v6[this[22] + 12] = v9;
              v3 += 4;
            }
            while ( v2 < this[26] );
          }
          break;
      }
      break;
  }
  return this[22];
}
