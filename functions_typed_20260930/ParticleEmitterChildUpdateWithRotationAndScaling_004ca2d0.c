void __thiscall sub_4CA2D0(int this, float a2, int a3, float a4)
{
  unsigned __int8 v5; // c0
  unsigned __int8 v6; // c2
  int v7; // eax
  double v8; // st7
  int v9; // edx
  double v10; // st6
  double v11; // st7
  long double v12; // st6
  long double v13; // st6
  int v14; // esi
  int v15; // eax
  double v16; // st7
  float *v17; // edi
  float *v18; // eax
  int v19; // eax
  float v20; // [esp+0h] [ebp-Ch]
  float v21; // [esp+8h] [ebp-4h]
  float v22; // [esp+14h] [ebp+8h]

  if ( !(v5 | v6) )
  {
    v7 = *(_DWORD *)(this + 52);
    v8 = a2 + *(float *)(this + 20);
    v9 = 0;
    *(float *)(this + 20) = v8;
    v10 = v8;
    v11 = (flt_8AFEE4 * 3.4000001 + *(float *)(this + 24)) * *(float *)(this + 28);
    v12 = v10 * *(float *)(this + 32);
    v22 = sin(v12);
    v13 = cos(v12);
    v20 = (v13 * *(float *)(this + 44) + v22 * *(float *)(this + 36)) * v11;
    v21 = (v13 * *(float *)(this + 48) + v22 * *(float *)(this + 40)) * v11;
    if ( v7 > 0 )
    {
      v14 = 0;
      do
      {
        v15 = *(_DWORD *)(this + 56);
        v16 = v20 * *(float *)(v15 + v14 + 16);
        v17 = *(float **)(v15 + v14);
        v18 = (float *)(v14 + v15);
        ++v9;
        v14 += 20;
        *v17 = v16 + v18[1];
        *(float *)(*(_DWORD *)v18 + 4) = v18[4] * 0.0 + v18[2];
        *(float *)(*(_DWORD *)v18 + 8) = v21 * v18[4] + v18[3];
      }
      while ( v9 < *(_DWORD *)(this + 52) );
    }
    v19 = LinkedListIndexedAccessor_c230(0);
    if ( v19 )
      *(_DWORD *)(v19 + 20) &= 0xFEFFFFDF;
  }
}

