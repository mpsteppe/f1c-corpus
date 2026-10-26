int __fastcall sub_40E480(int a1, float *a2, float *a3)
{
  int v4; // ebp
  double v5; // st7
  double v6; // st7
  int result; // eax
  double v8; // st7
  float *v9; // ecx
  double v10; // st7
  int v11; // eax
  int v12; // ebx
  int v13; // esi
  float *v14; // eax
  double v15; // st6
  double v16; // st3
  double v17; // st4
  long double v18; // st7
  float v19; // [esp+10h] [ebp-50h]
  int v20; // [esp+14h] [ebp-4Ch]
  int v21; // [esp+18h] [ebp-48h]
  int v22; // [esp+20h] [ebp-40h]
  float v23; // [esp+24h] [ebp-3Ch] BYREF
  float v24; // [esp+28h] [ebp-38h]
  float v25; // [esp+2Ch] [ebp-34h]
  float v26; // [esp+30h] [ebp-30h]
  float v27; // [esp+34h] [ebp-2Ch]
  float v28; // [esp+38h] [ebp-28h]
  float v29; // [esp+3Ch] [ebp-24h]
  float v30; // [esp+40h] [ebp-20h]
  float v31; // [esp+44h] [ebp-1Ch]
  float v32; // [esp+48h] [ebp-18h]
  float v33; // [esp+4Ch] [ebp-14h]
  float v34; // [esp+50h] [ebp-10h]
  float v35; // [esp+5Ch] [ebp-4h]

  BoundingBoxComputation(&v23);
  v29 = v23 - v26;
  v30 = v24 - v27;
  v31 = v25 - v28;
  v22 = LinkedListIndexedAccessor_c230(0);
  v4 = PackedArrayTotalSize(v22);
  v35 = v28 + v25;
  v5 = v27 + v24;
  v32 = (v26 + v23) * 0.5;
  *a2 = v32;
  v33 = v5 * 0.5;
  v6 = v35;
  a2[1] = v33;
  result = 0;
  v21 = 0;
  v34 = v6 * 0.5;
  v8 = v31;
  a2[2] = v34;
  v9 = a3;
  *a3 = sqrt(v8 * v31 + v30 * v30 + v29 * v29) * 0.5;
  do
  {
    v10 = (double)(result - 2);
    v11 = 0;
    v20 = 0;
    v29 = v10 * 0.02 * (v23 - v26) + *a2;
    do
    {
      v12 = 0;
      v30 = (double)(v11 - 2) * 0.02 * (v24 - v27) + a2[1];
      do
      {
        v13 = 0;
        v19 = 0.0;
        v31 = (double)(v12 - 2) * 0.02 * (v25 - v28) + a2[2];
        if ( v4 > 0 )
        {
          do
          {
            v14 = (float *)PackedArrayIndexLookup(v13);
            v15 = v14[1] - v30;
            v16 = v14[2] - v31;
            v17 = (*v14 - v29) * (*v14 - v29) + v15 * v15 + v16 * v16;
            if ( v17 > v19 )
              v19 = v17;
            ++v13;
          }
          while ( v13 < v4 );
          v9 = a3;
        }
        v18 = sqrt(v19);
        if ( v18 < *v9 )
        {
          *a2 = v29;
          a2[1] = v30;
          a2[2] = v31;
          *v9 = v18;
        }
        ++v12;
      }
      while ( v12 < 5 );
      v11 = ++v20;
    }
    while ( v20 < 5 );
    result = ++v21;
  }
  while ( v21 < 5 );
  return result;
}
