char __thiscall sub_608C60(int this, char a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // edi
  int i; // ecx
  int v6; // eax
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v12; // st6
  int *v13; // eax
  int v14; // edi
  int v15; // ebp
  int v16; // edi
  int v17; // eax
  void *v18; // ebx
  int *v19; // eax
  int v20; // edx
  int v21; // eax
  int v23; // [esp+10h] [ebp-1Ch]
  float v24; // [esp+14h] [ebp-18h]
  float v25; // [esp+18h] [ebp-14h]
  float v26; // [esp+1Ch] [ebp-10h]
  int v27; // [esp+30h] [ebp+4h]

  v24 = fabs(*(float *)(this + 24) - *(float *)(this + 48)) * 0.5;
  v25 = fabs(*(float *)(this + 28) - *(float *)(this + 52)) * 0.5;
  v26 = fabs(*(float *)(this + 32) - *(float *)(this + 56)) * 0.5;
  v3 = operator new(0x494u);
  if ( v3 )
  {
    v4 = v3 + 1;
    *v3 = 4;
    sub_630A11(v3 + 1, 292, 4, sub_608B50, sub_608C00);
  }
  else
  {
    v4 = 0;
  }
  *(_DWORD *)(this + 288) = v4;
  for ( i = 0; i < 4; ++i )
  {
    v6 = *(_DWORD *)(this + 288) + 292 * i;
    *(_DWORD *)(v6 + 16) = *(_DWORD *)(this + 16) + 1;
    *(_DWORD *)(v6 + 284) = this;
    switch ( i )
    {
      case 0:
        *(float *)(v6 + 48) = (*(float *)(this + 48) + *(float *)(this + 24)) * 0.5;
        v7 = *(float *)(this + 40) + *(float *)(this + 52);
        goto LABEL_15;
      case 1:
        *(float *)(v6 + 48) = (*(float *)(this + 36) + *(float *)(this + 48)) * 0.5;
        v7 = *(float *)(this + 40) + *(float *)(this + 52);
        goto LABEL_15;
      case 2:
        v8 = *(float *)(this + 36) + *(float *)(this + 48);
        goto LABEL_10;
      case 3:
        v8 = *(float *)(this + 48) + *(float *)(this + 24);
LABEL_10:
        *(float *)(v6 + 48) = v8 * 0.5;
        *(float *)(v6 + 52) = (*(float *)(this + 40) + *(float *)(this + 52)) * 0.5;
        v9 = *(float *)(this + 56) + *(float *)(this + 32);
        goto LABEL_16;
      case 4:
      case 7:
        v10 = *(float *)(this + 48) + *(float *)(this + 24);
        goto LABEL_14;
      case 5:
        v10 = *(float *)(this + 36) + *(float *)(this + 48);
LABEL_14:
        *(float *)(v6 + 48) = v10 * 0.5;
        v7 = *(float *)(this + 52) + *(float *)(this + 28);
LABEL_15:
        *(float *)(v6 + 52) = v7 * 0.5;
        v9 = *(float *)(this + 44) + *(float *)(this + 56);
        goto LABEL_16;
      case 6:
        *(float *)(v6 + 48) = (*(float *)(this + 48) + *(float *)(this + 24)) * 0.5;
        *(float *)(v6 + 52) = (*(float *)(this + 52) + *(float *)(this + 28)) * 0.5;
        v9 = *(float *)(this + 56) + *(float *)(this + 32);
LABEL_16:
        *(float *)(v6 + 56) = v9 * 0.5;
        break;
      default:
        break;
    }
    *(float *)(v6 + 24) = *(float *)(v6 + 48) - v24;
    *(float *)(v6 + 28) = *(float *)(v6 + 52) - v25;
    *(float *)(v6 + 32) = *(float *)(v6 + 56) - v26;
    *(float *)(v6 + 36) = v24 + *(float *)(v6 + 48);
    *(float *)(v6 + 40) = v25 + *(float *)(v6 + 52);
    *(float *)(v6 + 44) = v26 + *(float *)(v6 + 56);
    *(_DWORD *)(v6 + 60) = 1065353216;
    *(_DWORD *)(v6 + 64) = 0;
    *(_DWORD *)(v6 + 68) = 0;
    *(float *)(v6 + 72) = -*(float *)(v6 + 36);
    *(_DWORD *)(v6 + 76) = -1082130432;
    *(_DWORD *)(v6 + 80) = 0;
    *(_DWORD *)(v6 + 84) = 0;
    *(float *)(v6 + 88) = -(*(float *)(v6 + 24) * -1.0);
    *(_DWORD *)(v6 + 92) = 0;
    *(_DWORD *)(v6 + 96) = 0;
    *(_DWORD *)(v6 + 100) = 1065353216;
    *(float *)(v6 + 104) = -*(float *)(v6 + 44);
    *(_DWORD *)(v6 + 108) = 0;
    *(_DWORD *)(v6 + 112) = 0;
    *(_DWORD *)(v6 + 116) = -1082130432;
    *(float *)(v6 + 120) = -(*(float *)(v6 + 32) * -1.0);
    *(_DWORD *)(v6 + 124) = 0;
    *(_DWORD *)(v6 + 128) = 1065353216;
    *(_DWORD *)(v6 + 132) = 0;
    *(float *)(v6 + 136) = -*(float *)(v6 + 40);
    *(_DWORD *)(v6 + 140) = 0;
    *(_DWORD *)(v6 + 144) = -1082130432;
    *(_DWORD *)(v6 + 148) = 0;
    *(float *)(v6 + 152) = -(*(float *)(v6 + 28) * -1.0);
    *(_DWORD *)(v6 + 156) = *(_DWORD *)(v6 + 36);
    *(_DWORD *)(v6 + 160) = *(_DWORD *)(v6 + 28);
    *(_DWORD *)(v6 + 164) = *(_DWORD *)(v6 + 32);
    *(_DWORD *)(v6 + 168) = *(_DWORD *)(v6 + 36);
    *(_DWORD *)(v6 + 172) = *(_DWORD *)(v6 + 28);
    *(_DWORD *)(v6 + 176) = *(_DWORD *)(v6 + 44);
    *(_DWORD *)(v6 + 180) = *(_DWORD *)(v6 + 24);
    *(_DWORD *)(v6 + 184) = *(_DWORD *)(v6 + 28);
    *(_DWORD *)(v6 + 188) = *(_DWORD *)(v6 + 44);
    v11 = *(float *)(v6 + 44) - *(float *)(v6 + 56);
    *(_DWORD *)(v6 + 192) = *(_DWORD *)(v6 + 24);
    v12 = *(float *)(v6 + 36) - *(float *)(v6 + 48);
    *(_DWORD *)(v6 + 196) = *(_DWORD *)(v6 + 28);
    *(_DWORD *)(v6 + 200) = *(_DWORD *)(v6 + 32);
    *(_DWORD *)(v6 + 204) = *(_DWORD *)(v6 + 36);
    *(_DWORD *)(v6 + 208) = *(_DWORD *)(v6 + 40);
    *(_DWORD *)(v6 + 212) = *(_DWORD *)(v6 + 32);
    *(_DWORD *)(v6 + 216) = *(_DWORD *)(v6 + 36);
    *(_DWORD *)(v6 + 220) = *(_DWORD *)(v6 + 40);
    *(_DWORD *)(v6 + 224) = *(_DWORD *)(v6 + 44);
    *(_DWORD *)(v6 + 228) = *(_DWORD *)(v6 + 24);
    *(_DWORD *)(v6 + 232) = *(_DWORD *)(v6 + 40);
    *(_DWORD *)(v6 + 236) = *(_DWORD *)(v6 + 44);
    *(_DWORD *)(v6 + 240) = *(_DWORD *)(v6 + 24);
    *(_DWORD *)(v6 + 244) = *(_DWORD *)(v6 + 40);
    *(_DWORD *)(v6 + 248) = *(_DWORD *)(v6 + 32);
    *(float *)(v6 + 20) = sqrt(v12 * v12 + v11 * v11);
  }
  LOBYTE(v13) = a2;
  if ( a2 )
  {
    v13 = *(int **)(this + 268);
    *(_DWORD *)(this + 276) = v13;
    if ( v13 )
    {
      v13 = (int *)*v13;
      v27 = (int)v13;
      if ( v13 )
      {
        do
        {
          v23 = 0;
          v14 = 0;
          while ( 1 )
          {
            v15 = v14 + *(_DWORD *)(this + 288);
            LOBYTE(v13) = sub_607DB0((float *)v15, v27);
            if ( (_BYTE)v13 )
              break;
            v14 += 292;
            ++v23;
            if ( v14 >= 1168 )
              goto LABEL_49;
          }
          v16 = *(_DWORD *)(this + 268);
          v17 = 0;
          if ( v16 )
          {
            while ( *(_DWORD *)v16 != v27 )
            {
              v17 = v16;
              v16 = *(_DWORD *)(v16 + 4);
              if ( !v16 )
                goto LABEL_40;
            }
            if ( v16 == *(_DWORD *)(this + 276) )
              *(_DWORD *)(this + 276) = *(_DWORD *)(v16 + 4);
            if ( v17 )
              *(_DWORD *)(v17 + 4) = *(_DWORD *)(v16 + 4);
            else
              *(_DWORD *)(this + 268) = *(_DWORD *)(v16 + 4);
            if ( *(_DWORD *)(this + 272) == v16 )
              *(_DWORD *)(this + 272) = v17;
            --*(_DWORD *)(this + 280);
            if ( *(_BYTE *)(v16 + 8) )
            {
              v18 = *(void **)v16;
              if ( *(_DWORD *)v16 )
              {
                sub_5DBA90(*(int **)v16);
                j__free(v18);
              }
            }
            j__free((void *)v16);
          }
LABEL_40:
          v19 = (int *)operator new(0xCu);
          if ( v19 )
          {
            *v19 = v27;
            v19[1] = 0;
            *((_BYTE *)v19 + 8) = 0;
          }
          else
          {
            v19 = 0;
          }
          if ( *(_DWORD *)(v15 + 268) )
          {
            *(_DWORD *)(*(_DWORD *)(v15 + 272) + 4) = v19;
          }
          else
          {
            *(_DWORD *)(v15 + 268) = v19;
            *(_DWORD *)(v15 + 276) = v19;
          }
          v20 = *(_DWORD *)(v15 + 280) + 1;
          *(_DWORD *)(v15 + 272) = v19;
          *(_DWORD *)(v15 + 280) = v20;
          v13 = *(int **)(this + 276);
          if ( v13 )
          {
            v13 = (int *)*v13;
            v27 = (int)v13;
          }
          else
          {
            v27 = 0;
          }
LABEL_49:
          if ( v23 == 4 )
          {
            v21 = *(_DWORD *)(this + 276);
            if ( v21 )
              *(_DWORD *)(this + 276) = *(_DWORD *)(v21 + 4);
            v13 = *(int **)(this + 276);
            if ( !v13 )
              return (char)v13;
            v27 = *v13;
          }
        }
        while ( v27 );
      }
    }
  }
  return (char)v13;
}
