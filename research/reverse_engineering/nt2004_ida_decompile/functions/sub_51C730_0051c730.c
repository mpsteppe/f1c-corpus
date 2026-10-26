char __thiscall sub_51C730(int this)
{
  float *v1; // edx
  double v2; // st7
  double v3; // st7
  char result; // al

  v1 = *(float **)(this + 19000);
  if ( !v1 )
    return 0;
  v2 = (*(float *)(this + 17528) - v1[2]) * v1[13]
     + (*(float *)(this + 17524) - v1[1]) * v1[12]
     + (*(float *)(this + 17520) - *v1) * v1[11];
  v3 = v2 >= 0.0 ? v2 - v1[18] : -v2 - v1[17];
  result = 1;
  if ( v3 <= 2.0 )
    return 0;
  return result;
}
