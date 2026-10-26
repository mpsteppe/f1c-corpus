char __thiscall sub_4CE3E0(int *this, int a2, float a3, int a4, float *a5, int a6, int a7)
{
  int v8; // eax
  int v9; // ebp
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st6
  int v17; // eax
  double v18; // st7
  double v19; // st7
  double v20; // st7
  double v21; // st7
  double v22; // st7
  double v23; // st6
  int v24; // eax
  double v25; // st7
  double v26; // st7
  double v27; // st7
  double v28; // st7
  int v29; // eax
  float v31; // [esp-18h] [ebp-58h]
  int *v32; // [esp+4h] [ebp-3Ch]
  int v33; // [esp+8h] [ebp-38h]
  int v35; // [esp+10h] [ebp-30h] BYREF
  int v36; // [esp+14h] [ebp-2Ch]
  float v37; // [esp+18h] [ebp-28h]
  int v38; // [esp+1Ch] [ebp-24h] BYREF
  float v39; // [esp+20h] [ebp-20h]
  float v40; // [esp+24h] [ebp-1Ch]
  int v41; // [esp+28h] [ebp-18h]
  float v42; // [esp+2Ch] [ebp-14h]
  float v43; // [esp+30h] [ebp-10h]
  int v44; // [esp+34h] [ebp-Ch]
  float v45; // [esp+38h] [ebp-8h]
  float v46; // [esp+3Ch] [ebp-4h]

  LOBYTE(v8) = ArithmeticComparison_9fb0(&dword_8AB6E4);
  if ( (_BYTE)v8 )
  {
    v8 = this[15];
    v33 = 0;
    if ( v8 > 0 )
    {
      v9 = a7;
      v32 = this + 16;
      do
      {
        v10 = *v32;
        v11 = *(_DWORD *)(*v32 + 4);
        if ( v11 )
        {
          v12 = v11 - 1;
          if ( v12 )
          {
            if ( v12 != 4 || *(float *)(a2 + 48) == 0.0 )
              goto LABEL_42;
            if ( dword_7CF8A8 <= 1 && dword_8AB6E4 != 2 )
            {
              if ( dword_7C5698 % 20 )
                goto LABEL_41;
              v9 = a7;
            }
            v13 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
            v36 = *(_DWORD *)(a4 + 4);
            *(float *)&v35 = v13 * 0.25 + *(float *)a4;
            v14 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
            v31 = *(float *)(a2 + 48);
            v37 = v14 * 0.25 + *(float *)(a4 + 8);
            ParticleCollisionSpark(v10, a3, (float *)&v35, a5, v31, a6, v9);
          }
          else if ( *(float *)(a2 + 40) != 0.0 )
          {
            if ( dword_7CF8A8 <= 2 && dword_8AB6E4 != 2 )
            {
              if ( dword_7C5698 % 20 )
                goto LABEL_41;
              v9 = a7;
            }
            if ( fabs(a3 - *(float *)(a2 + 68)) <= 0.15000001 )
            {
              v16 = *(float *)(a4 + 8) - *(float *)(a2 + 64);
              v15 = *(float *)a4 - *(float *)(a2 + 56);
              if ( v16 * v16 + v15 * v15 <= 1.0 )
                goto LABEL_42;
            }
            *(_DWORD *)(a2 + 56) = *(_DWORD *)a4;
            *(_DWORD *)(a2 + 60) = *(_DWORD *)(a4 + 4);
            v17 = *(_DWORD *)(a4 + 8);
            *(float *)(a2 + 68) = a3;
            *(_DWORD *)(a2 + 64) = v17;
            v18 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
            v36 = *(_DWORD *)(a4 + 4);
            *(float *)&v35 = v18 * 0.25 + *(float *)a4;
            v19 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
            v37 = v19 * 0.25 + *(float *)(a4 + 8);
            *(float *)&v41 = *a5 * 0.1;
            v20 = a5[1];
            v38 = v41;
            v42 = v20 * 0.1;
            v21 = a5[2];
            v39 = v42;
            v43 = v21 * 0.1;
            v40 = v43;
            if ( !byte_7CF9D4 )
            {
              if ( !byte_7CF9EC )
              {
                ParticleTrailEmitter(v10, a3, (float *)&v35, (float *)&v38, *(float *)(a2 + 40), a6, 1, -1);
                goto LABEL_42;
              }
LABEL_24:
              ParticleTrailEmitter(v10, a3, (float *)&v35, (float *)&v38, *(float *)(a2 + 40), a6, 1, v9);
              goto LABEL_42;
            }
            if ( !byte_7CF9EC )
              goto LABEL_24;
            ParticleTrailEmitter(v10, a3, (float *)&v35, (float *)&v38, *(float *)(a2 + 40), a6, 1, 104);
          }
        }
        else if ( *(float *)(a2 + 44) != 0.0 )
        {
          if ( dword_7CF8A8 > 2 || dword_8AB6E4 == 2 )
            goto LABEL_31;
          if ( !(dword_7C5698 % 20) )
          {
            v9 = a7;
LABEL_31:
            if ( fabs(a3 - *(float *)(a2 + 68)) <= 0.15000001 )
            {
              v23 = *(float *)(a4 + 8) - *(float *)(a2 + 64);
              v22 = *(float *)a4 - *(float *)(a2 + 56);
              if ( v23 * v23 + v22 * v22 <= 1.0 )
                goto LABEL_42;
            }
            *(_DWORD *)(a2 + 56) = *(_DWORD *)a4;
            *(_DWORD *)(a2 + 60) = *(_DWORD *)(a4 + 4);
            v24 = *(_DWORD *)(a4 + 8);
            *(float *)(a2 + 68) = a3;
            *(_DWORD *)(a2 + 64) = v24;
            v25 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
            v36 = *(_DWORD *)(a4 + 4);
            *(float *)&v35 = v25 * 0.25 + *(float *)a4;
            v26 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
            v37 = v26 * 0.25 + *(float *)(a4 + 8);
            *(float *)&v44 = *a5 * 0.1;
            v27 = a5[1];
            v38 = v44;
            v45 = v27 * 0.1;
            v28 = a5[2];
            v39 = v45;
            v46 = v28 * 0.1;
            v40 = v46;
            if ( byte_7CF9D4 )
            {
              if ( byte_7CF9EC )
              {
                v29 = 104;
LABEL_39:
                ParticleTrailEmitter(v10, a3, (float *)&v35, (float *)&v38, *(float *)(a2 + 44), a6, 1, v29);
                goto LABEL_42;
              }
            }
            else if ( !byte_7CF9EC )
            {
              v29 = -1;
              goto LABEL_39;
            }
            v29 = v9;
            goto LABEL_39;
          }
LABEL_41:
          v9 = a7;
        }
LABEL_42:
        ++v32;
        LOBYTE(v8) = ++v33;
      }
      while ( v33 < this[15] );
    }
  }
  return v8;
}
