char __thiscall sub_4670B0(char *this, int a2, int a3, int a4)
{
  char *v4; // eax
  float *v5; // ecx

  if ( a3 )
  {
    v4 = this + 4496;
    if ( a3 != 1 )
      v4 = this + 5524;
  }
  else
  {
    v4 = this + 3468;
  }
  if ( (*(float *)&v4[4 * a2 + 920] - *(float *)&v4[4 * a2 + 96]) * *(float *)&v4[4 * a2 + 64] - *(float *)(a4 + 4 * a2) >= -0.34999999 )
    return 0;
  v5 = (float *)((char *)&unk_B73AFC + 864 * a3 + 108 * a2);
  if ( *(float *)(a4 + 4 * a2) <= 0.92500001 )
    a3 = 1056964608;
  else
    a3 = 1065353216;
  sub_409B80(v5, (float *)&a3);
  return 1;
}
