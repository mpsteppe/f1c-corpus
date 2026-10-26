double *__thiscall sub_442F40(int this)
{
  int v1; // edi
  double *v2; // ebp
  int v3; // esi
  double *v4; // ebx
  int v5; // edx
  double *result; // eax
  double *v7; // ecx
  float v8; // [esp+0h] [ebp-18h]
  float v9; // [esp+0h] [ebp-18h]
  float v10; // [esp+0h] [ebp-18h]

  flt_B65F8C = *(double *)(this + 8968);
  flt_B65F90 = *(double *)(this + 8904);
  v1 = 0;
  v2 = (double *)(this + 1920);
  do
  {
    v8 = *(v2 - 5);
    sub_431950((float *)&byte_B64150, v1, v8);
    v9 = *v2;
    sub_431970((float *)&byte_B64150, v1, v9);
    v3 = 0;
    v4 = v2 - 31;
    do
    {
      v10 = *v4;
      sub_4319F0((float *)&byte_B64150, v1, v3++, v10);
      ++v4;
    }
    while ( v3 < 3 );
    flt_B65FE0[++v1] = *(v2 - 26);
    v2 += 160;
  }
  while ( v1 < 4 );
  sub_557150(&dword_903A10);
  sub_43B2D0((double *)(this + 544));
  *(_DWORD *)(this + 9392) = 0;
  sub_61DA10(this + 6244);
  if ( *(_DWORD *)(this + 8816) )
    j_j__free(*(void **)(this + 8816));
  if ( *(_DWORD *)(this + 6376) )
    j_j__free(*(void **)(this + 6376));
  memset((void *)this, 0, 0x2590u);
  *(double *)(this + 8968) = 293.16;
  *(double *)(this + 8904) = 293.16;
  v5 = 0;
  result = (double *)(this + 1880);
  do
  {
    *((_DWORD *)result - 262) = v5;
    *result = 293.16;
    result[5] = 0.028;
    v7 = result - 25;
    ++v5;
    *(result - 26) = 293.16;
    *(_DWORD *)v7 = *((_DWORD *)result - 52);
    *((_DWORD *)v7 + 1) = *((_DWORD *)result - 51);
    *((_DWORD *)v7 + 2) = *(_DWORD *)v7;
    *((_DWORD *)v7 + 3) = *((_DWORD *)result - 49);
    *(result - 21) = 155.0;
    result += 160;
  }
  while ( v5 < 4 );
  return result;
}
