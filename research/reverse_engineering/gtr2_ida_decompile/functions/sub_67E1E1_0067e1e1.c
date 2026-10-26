int __stdcall sub_67E1E1(float *a1, unsigned __int16 *a2)
{
  int result; // eax
  unsigned __int8 v3; // al
  unsigned __int8 v4; // cl
  unsigned int j; // eax
  double v6; // st7
  double v7; // st6
  unsigned int i; // eax
  double v9; // st7
  double v10; // st6
  int v11; // edx
  unsigned int v12; // ecx
  float *v13; // eax
  int v14; // ebx
  int v15; // edx
  unsigned int v16; // ecx
  float *v17; // eax
  int v18; // esi
  float v19; // [esp+8h] [ebp-20h]
  float v20; // [esp+Ch] [ebp-1Ch]
  float v21; // [esp+20h] [ebp-8h]
  float v22; // [esp+24h] [ebp-4h]

  result = sub_67E01A(a1, a2 + 4);
  if ( result >= 0 )
  {
    v3 = *(_BYTE *)a2;
    v4 = *((_BYTE *)a2 + 1);
    v19 = (double)*(unsigned __int8 *)a2 * 0.0039215689;
    v20 = (double)v4 * 0.0039215689;
    if ( v3 <= v4 )
    {
      for ( i = 1; i < 5; *(&v19 + i) = (v9 + v10) * 0.2 )
      {
        v9 = (double)(5 - i) * v19;
        v10 = (double)i++ * v20;
      }
      v21 = 0.0;
      v22 = 1.0;
    }
    else
    {
      for ( j = 1; j < 7; *(&v19 + j) = (v6 + v7) * 0.14285715 )
      {
        v6 = (double)(7 - j) * v19;
        v7 = (double)j++ * v20;
      }
    }
    v11 = 8;
    v12 = *((unsigned __int8 *)a2 + 2) | (*(unsigned __int16 *)((char *)a2 + 3) << 8);
    v13 = a1 + 3;
    do
    {
      v14 = v12 & 7;
      v12 >>= 3;
      *v13 = *(&v19 + v14);
      v13 += 4;
      --v11;
    }
    while ( v11 );
    v15 = 8;
    v16 = *((unsigned __int8 *)a2 + 5) | (a2[3] << 8);
    v17 = a1 + 35;
    do
    {
      v18 = v16 & 7;
      v16 >>= 3;
      *v17 = *(&v19 + v18);
      v17 += 4;
      --v15;
    }
    while ( v15 );
    return 0;
  }
  return result;
}
