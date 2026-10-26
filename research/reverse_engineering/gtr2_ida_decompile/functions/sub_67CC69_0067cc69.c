int __fastcall sub_67CC69(float *a1)
{
  int v1; // edx
  double v2; // st7
  double v3; // st7
  double v4; // st6
  double v5; // st6

  v1 = 16;
  do
  {
    if ( 0.0 == a1[3] )
    {
      *a1 = 0.0;
      a1[1] = 0.0;
      v2 = 0.0;
    }
    else
    {
      if ( a1[3] >= 1.0 )
        goto LABEL_15;
      v3 = 1.0 / a1[3];
      if ( *a1 >= (double)a1[3] )
        v4 = 1.0;
      else
        v4 = v3 * *a1;
      *a1 = v4;
      if ( a1[1] >= (double)a1[3] )
        v5 = 1.0;
      else
        v5 = v3 * a1[1];
      a1[1] = v5;
      if ( a1[2] >= (double)a1[3] )
        v2 = 1.0;
      else
        v2 = v3 * a1[2];
    }
    a1[2] = v2;
LABEL_15:
    a1 += 4;
    --v1;
  }
  while ( v1 );
  return 0;
}
