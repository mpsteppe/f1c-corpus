int __thiscall sub_4E1E60(int this, int a2)
{
  int v2; // ebx
  double v4; // st7
  CHAR *v5; // eax
  signed int v6; // ebp
  double v7; // st7
  int v8; // edx
  int v9; // edi
  int v10; // eax
  int v11; // ebx
  int v12; // eax
  double v13; // st7
  double v14; // st7
  unsigned __int8 v16; // c0
  unsigned __int8 v17; // c3
  double v18; // st7
  int result; // eax
  int v20; // ecx
  int v21; // [esp+8h] [ebp-CCh]
  float v22; // [esp+8h] [ebp-CCh]
  float v23; // [esp+Ch] [ebp-C8h]
  float v24; // [esp+Ch] [ebp-C8h]
  signed int v25; // [esp+10h] [ebp-C4h]
  float v26[48]; // [esp+14h] [ebp-C0h] BYREF

  v2 = NumOfElements;
  v25 = NumOfElements;
  sub_4DA4D0(&dword_7D5DA4, 1);
  *(float *)(this + 408) = dbl_7DA9D0;
  *(_DWORD *)(this + 412) = a2;
  v23 = (float)dword_768684;
  if ( *(_DWORD *)dword_7689CC == 8 )
  {
    v4 = (double)dword_7687EC;
  }
  else
  {
    if ( *(_DWORD *)dword_7689CC != 4 )
      goto LABEL_6;
    v4 = (double)dword_768834;
  }
  v23 = v4;
LABEL_6:
  v5 = dword_766594;
  v6 = 0;
  if ( !dword_766594 )
    v5 = &byte_629120;
  sub_4E0F70(this, *(_DWORD *)(this + 420), *(float *)&v5, v23);
  switch ( *(_DWORD *)dword_766B6C )
  {
    case 1:
      if ( dword_75CBB0 != 7 )
        goto LABEL_11;
      v7 = 1.0 / flt_7D74C4;
      break;
    case 2:
LABEL_11:
      v7 = 1.0;
      break;
    default:
      v7 = 0.0;
      break;
  }
  *(float *)&v21 = v7;
  sub_4E14C0(this, 1, v7 != 0.0, v21, 1110704128, *(_DWORD *)dword_7694F4 != 0);
  v8 = 0;
  memset(v26, 0, sizeof(v26));
  do
  {
    *(_DWORD *)(this + 4 * v8) = -1082130432;
    *(_DWORD *)(this + 4 * v8++ + 192) = 0;
  }
  while ( v8 < 48 );
  v22 = flt_6290D0;
  v24 = 0.0;
  if ( v2 > 0 )
  {
    do
    {
      v9 = dword_75AAD0[v6];
      v10 = *(_DWORD *)(v9 + 16584);
      if ( v10 != -1 )
      {
        if ( v10 )
        {
          v11 = *(_DWORD *)(v9 + 20848);
          if ( v11 < *(_DWORD *)(this + 416)
            && *(float *)(v9 + 20856) > 0.0
            && (dword_75CBB0 == 7 || v11 <= sub_428070((_DWORD *)dword_75AAD0[v6]))
            && *(_DWORD *)(dword_75AAD0[v6] + 20892) != 1 )
          {
            v12 = *(_DWORD *)(v9 + 20892);
            if ( v12 != 3 && v12 != 2 )
            {
              *(float *)(this + 4 * v6) = sub_4E1500(this, v9, *(float *)(this + 396));
              v13 = *(float *)(v9 + 20856);
              if ( *(_DWORD *)(v9 + 20952) <= 1u )
                v13 = 0.0;
              ++*(_DWORD *)(v9 + 20848);
              if ( v22 < 10.0 )
                v22 = 400.0;
              v14 = (v22 - v13) * (*(float *)(this + 4 * v6) / v22);
              v26[v6] = v14;
              if ( !(v16 | v17) )
                v24 = v14;
              v18 = v14 + *(float *)(this + 408);
              if ( v18 < 0.0 )
                v18 = 0.0;
              *(float *)(v9 + 20956) = v18;
              if ( *(float *)(v9 + 20960) <= 0.0 || *(float *)(v9 + 20960) > (double)*(float *)(this + 4 * v6) )
                *(float *)(v9 + 20960) = *(float *)(this + 4 * v6);
              *(float *)(v9 + 20988) = *(float *)(this + 408) - flt_7D74BC + v26[v6];
              sub_4E2190(v9);
              if ( *(_DWORD *)(v9 + 20848) >= *(_DWORD *)(this + 416) )
              {
                *(_DWORD *)(this + 4 * v6) = -1082130432;
                sub_4DC390((_DWORD *)(v9 + 20836));
              }
            }
          }
        }
      }
      v2 = v25;
      ++v6;
    }
    while ( v6 < v25 );
  }
  result = 0;
  *(float *)(this + 408) = v24 + *(float *)(this + 408);
  if ( v2 > 0 )
  {
    v20 = this + 192;
    do
    {
      ++result;
      v20 += 4;
      *(float *)(v20 - 4) = v24 - v26[result - 1];
    }
    while ( result < v2 );
  }
  return result;
}
