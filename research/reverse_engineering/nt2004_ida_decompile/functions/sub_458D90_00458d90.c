void __stdcall sub_458D90(float *a1, double a2, double a3, double a4)
{
  double v5; // st7
  double v6; // st7
  float v7; // [esp+4h] [ebp+4h]
  float v8; // [esp+4h] [ebp+4h]

  v5 = *a1;
  if ( v5 < a2 )
  {
    do
    {
      v7 = a4;
      v5 = v5 + v7;
    }
    while ( v5 < a2 );
    *a1 = v5;
  }
  v6 = *a1;
  if ( v6 > a3 )
  {
    do
    {
      v8 = a4;
      v6 = v6 - v8;
    }
    while ( v6 > a3 );
    *a1 = v6;
  }
}
