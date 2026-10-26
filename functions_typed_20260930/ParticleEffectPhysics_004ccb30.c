int __usercall sub_4CCB30@<eax>(int a1@<ecx>, double a2@<st0>)
{
  double v3; // st7
  int result; // eax
  int v5; // edi
  int v6; // esi
  long double v7; // st7
  float v8; // eax
  float v9; // eax
  float *v10; // edi
  int j; // ebp
  float v12; // ecx
  long double v13; // st7
  float v14; // edx
  float v15; // edx
  float v16; // eax
  float v17; // [esp+0h] [ebp-64h]
  float v18; // [esp+1Ch] [ebp-48h]
  float v19; // [esp+20h] [ebp-44h]
  int i; // [esp+24h] [ebp-40h]
  float v21; // [esp+28h] [ebp-3Ch]
  float *v22; // [esp+28h] [ebp-3Ch]
  float v23; // [esp+2Ch] [ebp-38h]
  int v24; // [esp+30h] [ebp-34h] BYREF
  float v25; // [esp+34h] [ebp-30h]
  int v26; // [esp+38h] [ebp-2Ch]
  float v27; // [esp+3Ch] [ebp-28h]
  float v28; // [esp+40h] [ebp-24h]
  int v29; // [esp+44h] [ebp-20h]
  float v30; // [esp+48h] [ebp-1Ch]
  float v31[3]; // [esp+4Ch] [ebp-18h] BYREF
  float v32[3]; // [esp+58h] [ebp-Ch] BYREF

  sub_4CC840((float *)a1);
  if ( dword_8AB6E4 == 2 )
    Delegation(&dword_8AB6EC);
  else
    a2 = dbl_8AFEA0;
  v18 = a2;
  if ( dword_8AB6E4 == 2 )
  {
    if ( VehicleDataAccessor(&dword_8AB6EC) == 5 )
    {
      v19 = 0.0;
      goto LABEL_10;
    }
    v3 = FloatDifference(&dword_8AB6EC);
  }
  else
  {
    v3 = dbl_8AFE98;
  }
  v19 = v3;
LABEL_10:
  result = *(_DWORD *)(a1 + 100);
  v5 = 0;
  for ( i = 0; v5 < result; i = v5 )
  {
    v6 = *(_DWORD *)(*(_DWORD *)(a1 + 104) + 4 * v5);
    if ( v18 > (double)*(float *)(v6 + 12) || v18 < (double)*(float *)(v6 + 8) )
    {
      ArrayElementRemoval((_DWORD *)a1, (_DWORD *)v6);
      --v5;
    }
    else
    {
      v21 = v19 * *(float *)(v6 + 60) + *(float *)(v6 + 48);
      *(float *)(v6 + 48) = v21;
      if ( (dword_7CFA04 & 3) != 0 )
      {
        v23 = *(float *)(v6 + 60) * 0.03125;
        if ( dword_7CFA04 == 1 )
        {
          if ( dword_7C54E0 )
          {
            v25 = *(float *)(dword_7C54E0 + 1860);
            v7 = v25 - *(float *)(v6 + 44);
            v8 = *(float *)(dword_7C54E0 + 1868);
            v26 = *(_DWORD *)(dword_7C54E0 + 1864);
            v27 = v8;
            if ( fabs(v7) < 4.0 && fabs(v27 - *(float *)(v6 + 52)) < 4.0 )
            {
              v9 = *(float *)(v6 + 44);
              v31[1] = v21 - v23;
              v31[0] = v9;
              v31[2] = *(float *)(v6 + 52);
              F_3DAABBOverlapTestWithSlidingResponse(v31, (float *)(v6 + 44), (float *)(dword_7C54E0 + 1776));
            }
          }
        }
        else
        {
          v10 = (float *)(v6 + 44);
          v17 = *(float *)(v6 + 44) + *(float *)(v6 + 52);
          v22 = FindDriversInRange(flt_8AC4E0, v17, 5.6568542, &v24);
          for ( j = 0; j < v24; ++j )
          {
            v12 = v22[j];
            v28 = *(float *)(LODWORD(v12) + 1848);
            v13 = v28 - *v10;
            v14 = *(float *)(LODWORD(v12) + 1856);
            v29 = *(_DWORD *)(LODWORD(v12) + 1852);
            v30 = v14;
            if ( fabs(v13) < 4.0
              && fabs(v30 - *(float *)(v6 + 52)) < 4.0
              && ((dword_7CFA4C & 1) != 0 || *(_DWORD *)(LODWORD(v12) + 4) != dword_7C54DC) )
            {
              v15 = *v10;
              v16 = *(float *)(v6 + 52);
              v32[1] = *(float *)(v6 + 48) - v23;
              v32[0] = v15;
              v32[2] = v16;
              F_3DAABBOverlapTestWithSlidingResponse(v32, (float *)(v6 + 44), (float *)(LODWORD(v12) + 1764));
            }
          }
          v5 = i;
        }
      }
      F_3DBoundingBoxRender(
        (float *)v6,
        (float *)(40 * *(_DWORD *)(v6 + 84) + 9095216),
        (float *)(40 * *(_DWORD *)(v6 + 84) + 9095228));
    }
    result = *(_DWORD *)(a1 + 100);
    ++v5;
  }
  return result;
}

