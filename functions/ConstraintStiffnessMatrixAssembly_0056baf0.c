int __thiscall sub_56BAF0(int this)
{
  int result; // eax
  int v3; // ebx
  int v4; // esi
  double v5; // st7
  int v6; // esi
  unsigned __int8 v7; // al
  int v8; // ebp
  double v9; // st7
  double *v10; // eax
  double v11; // st7
  double v12; // st6
  double v13; // st7
  double v14; // st6
  int v15; // esi
  int v16; // eax
  double v17; // st7
  int v18; // eax
  bool v19; // zf
  double v20; // st7
  double v21; // st6
  double v22; // st7
  double v23; // st6
  int v24; // eax
  double v25; // st7
  int v26; // edx
  int v27; // ecx
  double v28; // st6
  double *v29; // eax
  int v30; // eax
  int v31; // ecx
  double *v32; // eax
  unsigned __int8 v33; // [esp+17h] [ebp-81h]
  int v34; // [esp+18h] [ebp-80h]
  int v35; // [esp+1Ch] [ebp-7Ch]
  double v36; // [esp+20h] [ebp-78h] BYREF
  double v37; // [esp+28h] [ebp-70h]
  double v38; // [esp+30h] [ebp-68h]
  double v39; // [esp+38h] [ebp-60h]
  double v40; // [esp+40h] [ebp-58h]
  double v41; // [esp+48h] [ebp-50h]
  double v42[5]; // [esp+50h] [ebp-48h] BYREF
  double v43; // [esp+78h] [ebp-20h]
  double v44; // [esp+80h] [ebp-18h]

  result = *(_DWORD *)(this + 572);
  if ( result > 0 )
  {
    v3 = 1;
    v34 = 0;
    do
    {
      v4 = *(_DWORD *)(this + 576);
      v5 = *(double *)(v4 + v34 + 32);
      v6 = v34 + v4;
      v7 = *(_BYTE *)(v6 + 52);
      v8 = *(_DWORD *)(v6 + 48);
      v42[0] = v5 * *(double *)(v6 + 80) - *(double *)(v6 + 40) * *(double *)(v6 + 72);
      v33 = v7;
      v42[1] = *(double *)(v6 + 64) * *(double *)(v6 + 40) - *(double *)(v6 + 24) * *(double *)(v6 + 80);
      v42[2] = *(double *)(v6 + 24) * *(double *)(v6 + 72) - *(double *)(v6 + 64) * *(double *)(v6 + 32);
      Matrix3x3VectorMultiply((double *)(this + 236), v42, &v36);
      v9 = *(double *)(this + 180);
      v10 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 552) + 4 * v8) + 8 * v8);
      v39 = v9 * *(double *)(v6 + 64);
      v40 = v9 * *(double *)(v6 + 72);
      v41 = v9 * *(double *)(v6 + 80);
      v11 = v37 * *(double *)(v6 + 40) - v38 * *(double *)(v6 + 32);
      v12 = v38 * *(double *)(v6 + 24) - v36 * *(double *)(v6 + 40);
      v43 = v36 * *(double *)(v6 + 32) - v37 * *(double *)(v6 + 24);
      v44 = v11 + v39;
      v13 = v44 * *(double *)(v6 + 64) + (v41 + v43) * *(double *)(v6 + 80);
      v14 = (v12 + v40) * *(double *)(v6 + 72);
      v15 = v3;
      *v10 = v13 + v14 + *v10;
      if ( v3 < *(_DWORD *)(this + 572) )
      {
        v35 = v34 + 88;
        do
        {
          v16 = *(_DWORD *)(this + 576);
          v17 = v37 * *(double *)(v16 + v35 + 40);
          v18 = v35 + v16;
          v19 = v33 == *(_BYTE *)(v18 + 52);
          v20 = v17 - v38 * *(double *)(v18 + 32);
          v21 = v38 * *(double *)(v18 + 24) - v36 * *(double *)(v18 + 40);
          v43 = v36 * *(double *)(v18 + 32) - v37 * *(double *)(v18 + 24);
          v44 = v20 + v39;
          v22 = (v41 + v43) * *(double *)(v18 + 80) + (v21 + v40) * *(double *)(v18 + 72);
          v23 = v44 * *(double *)(v18 + 64);
          v24 = *(_DWORD *)(v18 + 48);
          v25 = v22 + v23;
          if ( v19 )
          {
            v31 = *(_DWORD *)(this + 552);
            if ( v8 <= v24 )
              v32 = (double *)(*(_DWORD *)(v31 + 4 * v24) + 8 * v8);
            else
              v32 = (double *)(*(_DWORD *)(v31 + 4 * v8) + 8 * v24);
            *v32 = v25 + *v32;
          }
          else
          {
            v26 = *(_DWORD *)(this + 552);
            if ( v8 <= v24 )
            {
              v30 = *(_DWORD *)(v26 + 4 * v24);
              v28 = *(double *)(v30 + 8 * v8);
              v29 = (double *)(v30 + 8 * v8);
            }
            else
            {
              v27 = *(_DWORD *)(v26 + 4 * v8);
              v28 = *(double *)(v27 + 8 * v24);
              v29 = (double *)(v27 + 8 * v24);
            }
            *v29 = v28 - v25;
          }
          ++v15;
          v35 += 88;
        }
        while ( v15 < *(_DWORD *)(this + 572) );
      }
      result = v3++;
      v34 += 88;
    }
    while ( v3 - 1 < *(_DWORD *)(this + 572) );
  }
  return result;
}
