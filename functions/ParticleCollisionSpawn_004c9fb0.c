void __thiscall sub_4C9FB0(float *this, int a2)
{
  int v3; // ebp
  double v4; // st7
  double v5; // st6
  double v6; // st7
  double v7; // st6
  double v8; // st6
  long double v9; // st7
  int v10; // ecx
  long double v11; // st7
  double v12; // st6
  double v13; // st5
  long double v14; // st5
  double v15; // st4
  double v16; // st4
  int v17; // edi
  int v18; // ebx
  int v19; // ebp
  int v20; // edi
  float *v21; // ecx
  double v22; // st7
  double v23; // st6
  float *v24; // eax
  double v25; // st7
  float v26; // [esp+10h] [ebp-38h]
  float v27; // [esp+18h] [ebp-30h]
  float v28; // [esp+1Ch] [ebp-2Ch]
  float v29; // [esp+20h] [ebp-28h]
  float v30; // [esp+24h] [ebp-24h] BYREF
  float v31; // [esp+28h] [ebp-20h]
  float v32; // [esp+2Ch] [ebp-1Ch]
  float v33; // [esp+30h] [ebp-18h]
  float v34; // [esp+38h] [ebp-10h]
  float v35; // [esp+3Ch] [ebp-Ch]
  float v36; // [esp+44h] [ebp-4h]

  if ( a2 )
  {
    v3 = LinkedListIndexedAccessor_c230(0);
    if ( v3 )
    {
      *(_DWORD *)this = a2;
      BoundingBoxComputation(&v30);
      TripleFieldQuery(this + 1, this + 2, this + 3);
      v34 = v29 + v32;
      v35 = (v27 + v30) * 0.5;
      v4 = (v31 + v28) * 0.5;
      v5 = v34 * 0.5;
      this[1] = v35 + this[1];
      this[2] = v4 + this[2];
      this[3] = v5 + this[3];
      this[4] = sqrt((v32 - v29) * (v32 - v29) + (v31 - v28) * (v31 - v28) + (v30 - v27) * (v30 - v27)) * 0.5;
      v6 = v31 - v28;
      if ( v6 > 0.0 )
      {
        v7 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
        this[7] = 0.00094;
        this[6] = v7 * 0.15000001 + 1.0;
        v8 = flt_8AB274[(unsigned __int8)dword_8AAE70++] * 0.40000001;
        this[8] = (v8 + 2.8) * 6.283185307179586 / (v6 + 3.0);
        v9 = flt_8AB274[(unsigned __int8)dword_8AAE70++] * 0.5 + 0.69999999;
        v10 = dword_8AAE70 + 1;
        v26 = v9;
        v11 = cos(v9);
        v12 = sin(v26);
        v36 = v12;
        v13 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
        if ( v13 >= 0.2 )
        {
          v12 = -v12;
          v14 = v11;
        }
        else
        {
          v14 = -v11;
        }
        v15 = flt_8AB274[(unsigned __int8)v10];
        dword_8AAE70 = v10 + 1;
        v16 = v15 * 0.2 + 0.5;
        this[10] = v36;
        v33 = v16 * v12;
        this[11] = v33;
        this[9] = v11;
        this[12] = v16 * v14;
        v17 = 0;
        v18 = PackedArrayTotalSize(v3);
        this[13] = 0.0;
        if ( v18 > 0 )
        {
          do
          {
            if ( *(float *)(PackedArrayIndexLookup(v17) + 4) > (double)v28 )
              ++*((_DWORD *)this + 13);
            ++v17;
          }
          while ( v17 < v18 );
        }
        v19 = 0;
        *((_DWORD *)this + 14) = OperatorNewNhMallocWrapper(20 * *((_DWORD *)this + 13));
        if ( v18 > 0 )
        {
          v20 = 0;
          do
          {
            v21 = (float *)PackedArrayIndexLookup(v19);
            if ( v21[1] > (double)v28 )
            {
              *(_DWORD *)(v20 + *((_DWORD *)this + 14)) = v21;
              v22 = v21[2];
              v23 = v21[1];
              v24 = (float *)(v20 + *((_DWORD *)this + 14) + 4);
              *v24 = *v21;
              v20 += 20;
              v24[1] = v23;
              v24[2] = v22;
              v25 = v21[1] - v28;
              *(float *)(v20 + *((_DWORD *)this + 14) - 4) = v25 * v25;
            }
            ++v19;
          }
          while ( v19 < v18 );
        }
      }
    }
  }
}
