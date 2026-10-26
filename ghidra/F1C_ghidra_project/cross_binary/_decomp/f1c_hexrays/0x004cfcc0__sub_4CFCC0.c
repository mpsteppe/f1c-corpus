// f1c  0x004cfcc0  size=519
int __usercall sub_4CFCC0@<eax>(int *a1@<ecx>, double a2@<st0>)
{
  int v3; // ebx
  int v4; // edi
  int v5; // ecx
  double v6; // st7
  float *v7; // eax
  double v8; // st7
  double v9; // st6
  double v10; // st7
  int v11; // edi
  int v12; // ebx
  double v13; // st7
  float *v14; // eax
  double v15; // st7
  double v16; // st7
  double v17; // st7
  long double v18; // st7
  int result; // eax
  int v20; // edi
  int v21; // ebx
  float v22; // [esp+10h] [ebp-20h]
  float v23; // [esp+14h] [ebp-1Ch]
  int v24; // [esp+18h] [ebp-18h]
  int v25; // [esp+18h] [ebp-18h]
  float v26; // [esp+1Ch] [ebp-14h]
  float v27; // [esp+1Ch] [ebp-14h]
  float v28; // [esp+20h] [ebp-10h]
  float v29; // [esp+20h] [ebp-10h]
  int v30; // [esp+24h] [ebp-Ch] BYREF
  float v31; // [esp+28h] [ebp-8h]
  float v32; // [esp+2Ch] [ebp-4h]

  sub_4C9C00(flt_8AC4E0);
  if ( !byte_7C56AC || sub_4B9A00(&dword_8AB6EC) )
  {
    v6 = flt_8AFEE4;
    if ( flt_8AFEE4 > 0.0 && a1[7] )
    {
      v7 = (float *)sub_40C870(&dword_5EA510);
      v8 = v7[9] * 0.25;
      v9 = v7[10] * 0.25;
      v32 = v7[11] * 0.25;
      *(float *)&v24 = v8 - v7[3];
      v10 = v9 - v7[4];
      v30 = v24;
      v26 = v10;
      v31 = v26;
      v28 = v32 - v7[5];
      v6 = flt_8AFEE4;
      v32 = v28;
      sub_4CC970(a1[7], (float *)&v30, flt_8AFEE4);
    }
    v11 = 0;
    if ( a1[4] > 0 )
    {
      v12 = 0;
      do
      {
        sub_4CDB20(v12 + a1[5], v6);
        ++v11;
        v12 += 108;
      }
      while ( v11 < a1[4] );
    }
  }
  else
  {
    v3 = 0;
    if ( a1[4] > 0 )
    {
      v4 = 0;
      do
      {
        v5 = a1[5] + v4;
        if ( *(_DWORD *)(v5 + 4) <= 5u )
          sub_4CDB20(v5, a2);
        ++v3;
        v4 += 108;
      }
      while ( v3 < a1[4] );
    }
  }
  if ( dword_8AB6E4 == 2 )
  {
    if ( sub_4B9E30(&dword_8AB6EC) == 5 )
    {
      v22 = 0.0;
      goto LABEL_21;
    }
    v13 = sub_4B9CF0(&dword_8AB6EC);
  }
  else
  {
    v13 = dbl_8AFE98;
  }
  v22 = v13;
LABEL_21:
  v14 = (float *)sub_40C870(&dword_5EA510);
  *(float *)&v25 = -v14[3];
  v15 = v14[4];
  v30 = v25;
  v27 = -v15;
  v16 = v14[5];
  v31 = v27;
  v29 = -v16;
  v17 = v14[11];
  v32 = v29;
  v18 = 430.0 - sqrt(v14[9] * v14[9] + v14[10] * v14[10] + v17 * v17) * 4.0;
  if ( v18 >= 0.0 )
    v23 = v18;
  else
    v23 = 0.0;
  result = *a1;
  v20 = 0;
  if ( *a1 > 0 )
  {
    v21 = 0;
    do
    {
      sub_4CA2D0(v21 + a1[1], v22, (int)&v30, v23);
      result = *a1;
      ++v20;
      v21 += 60;
    }
    while ( v20 < *a1 );
  }
  return result;
}
