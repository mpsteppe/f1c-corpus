void __thiscall sub_591980(int this)
{
  int v1; // edx
  int v2; // esi
  double v3; // st7
  int v4; // ebx
  int v5; // ebp
  int v6; // edi
  int v7; // ecx
  float *v8; // edx
  float *v9; // edx
  float *v10; // edx
  float *v11; // edx
  float *v12; // edx
  int v13; // edi
  int v14; // ecx
  float *v15; // edx
  float *v16; // edx
  float *v17; // edx
  float *v18; // edx
  float *v19; // edx
  _DWORD *v20; // eax
  int v21; // ebx
  _DWORD *v22; // eax
  int v23; // ebp
  int v24; // [esp+4h] [ebp-10h]
  int v25; // [esp+4h] [ebp-10h]
  int v26; // [esp+4h] [ebp-10h]
  int v27; // [esp+4h] [ebp-10h]
  int v29; // [esp+Ch] [ebp-8h]
  int v30; // [esp+Ch] [ebp-8h]

  v1 = this;
  v2 = *(_DWORD *)(this + 276);
  if ( v2 )
  {
    v3 = *(float *)(this + 64);
    v4 = 7;
    v5 = 7;
    if ( v3 >= 500.0 )
    {
LABEL_28:
      if ( v4 >= 0 )
      {
        v20 = (_DWORD *)(v1 + 4 * v4 + 208);
        v21 = v4 + 1;
        do
        {
          *v20-- = 1140457472;
          --v21;
        }
        while ( v21 );
      }
      if ( v5 >= 0 )
      {
        v22 = (_DWORD *)(v1 + 4 * v5 + 240);
        v23 = v5 + 1;
        do
        {
          *v22-- = 1140457472;
          --v23;
        }
        while ( v23 );
      }
    }
    else
    {
      while ( 1 )
      {
        v6 = v4;
        v24 = v4;
        if ( v4 + 1 < 4 )
        {
LABEL_10:
          if ( v6 >= 0 )
          {
            v25 = v6 + 1;
            v12 = (float *)(this + 4 * v4 + 208);
            do
            {
              if ( (double)v25 < *(float *)(v2 + 84) )
                break;
              *v12 = v3;
              --v4;
              --v12;
              --v6;
              --v25;
            }
            while ( v6 >= 0 );
          }
        }
        else
        {
          v7 = v4 - 1;
          v29 = v4 - 1;
          v8 = (float *)(v1 + 4 * v4 + 208);
          while ( (double)(v7 + 2) >= *(float *)(v2 + 84) )
          {
            *v8 = v3;
            --v4;
            v9 = v8 - 1;
            if ( (double)v24 < *(float *)(v2 + 84) )
              break;
            *v9 = v3;
            --v4;
            v10 = v9 - 1;
            if ( (double)v29 < *(float *)(v2 + 84) )
              break;
            *v10 = v3;
            --v4;
            v11 = v10 - 1;
            if ( (double)(v7 - 1) < *(float *)(v2 + 84) )
              break;
            v6 -= 4;
            *v11 = v3;
            v7 -= 4;
            --v4;
            v8 = v11 - 1;
            v24 = v6;
            v29 = v7;
            if ( v6 < 3 )
              goto LABEL_10;
          }
        }
        v13 = v5;
        v26 = v5;
        if ( v5 + 1 < 4 )
        {
LABEL_21:
          if ( v13 >= 0 )
          {
            v27 = v13 + 1;
            v19 = (float *)(this + 4 * v5 + 240);
            do
            {
              if ( (double)v27 < *(float *)(v2 + 88) )
                break;
              *v19 = v3;
              --v5;
              --v19;
              --v13;
              --v27;
            }
            while ( v13 >= 0 );
          }
        }
        else
        {
          v14 = v5 - 1;
          v30 = v5 - 1;
          v15 = (float *)(this + 4 * v5 + 240);
          while ( (double)(v14 + 2) >= *(float *)(v2 + 88) )
          {
            *v15 = v3;
            --v5;
            v16 = v15 - 1;
            if ( (double)v26 < *(float *)(v2 + 88) )
              break;
            *v16 = v3;
            --v5;
            v17 = v16 - 1;
            if ( (double)v30 < *(float *)(v2 + 88) )
              break;
            *v17 = v3;
            --v5;
            v18 = v17 - 1;
            if ( (double)(v14 - 1) < *(float *)(v2 + 88) )
              break;
            v13 -= 4;
            *v18 = v3;
            v14 -= 4;
            --v5;
            v15 = v18 - 1;
            v26 = v13;
            v30 = v14;
            if ( v13 < 3 )
              goto LABEL_21;
          }
        }
        v3 = v3 + *(float *)(v2 + 64);
        v2 = *(_DWORD *)(v2 + 276);
        if ( !v2 || v2 == *(_DWORD *)(v2 + 276) )
          break;
        v1 = this;
        if ( v3 >= 500.0 )
          goto LABEL_28;
      }
    }
  }
}
