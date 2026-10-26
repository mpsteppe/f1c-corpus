float *__thiscall sub_44DE80(int this)
{
  float *result; // eax
  int v3; // ebp
  float **v4; // edi
  double v5; // st7
  int v6; // ebx
  float *v7; // ecx
  double v8; // st7
  int v9; // [esp+14h] [ebp-34h]
  int v10; // [esp+18h] [ebp-30h]
  double v11; // [esp+18h] [ebp-30h]
  double v12; // [esp+20h] [ebp-28h]
  double v13; // [esp+28h] [ebp-20h]
  double v14; // [esp+30h] [ebp-18h]
  float v15[4]; // [esp+38h] [ebp-10h] BYREF

  result = *(float **)(this + 4);
  if ( result )
  {
    if ( *(double *)(this + 16) == 0.0 )
      v12 = 0.0;
    else
      v12 = 1.0 / *(double *)(this + 16);
    if ( *(double *)(this + 32) == 0.0 )
      v13 = 0.0;
    else
      v13 = 1.0 / *(double *)(this + 32);
    v3 = 0;
    v10 = 0;
    v4 = (float **)(this + 40);
    do
    {
      v5 = (double)v10;
      v6 = 0;
      v9 = 0;
      v11 = (v5 - 0.5) * v12;
      v14 = (v5 + 0.5) * v12;
      do
      {
        v7 = *(float **)(this + 4);
        v15[0] = v11 + *(double *)(this + 8);
        v15[1] = v14 + *(double *)(this + 8);
        v8 = (double)v9;
        v15[2] = (v8 - 0.5) * v13 + *(double *)(this + 24);
        v15[3] = (v8 + 0.5) * v13 + *(double *)(this + 24);
        result = sub_44CCC0(v7, v15);
        ++v6;
        *v4++ = result;
        v9 = v6;
      }
      while ( v6 < 32 );
      v10 = ++v3;
    }
    while ( v3 < 32 );
  }
  return result;
}
