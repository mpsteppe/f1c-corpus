char __thiscall sub_454250(char *this, int a2, int a3, int a4)
{
  char *v4; // eax

  v4 = this + 3464;
  if ( a3 )
    v4 = this + 4484;
  if ( (*(float *)&v4[4 * a2 + 920] - *(float *)&v4[4 * a2 + 96]) * *(float *)&v4[4 * a2 + 64] - *(float *)(a4 + 4 * a2) <= 0.34999999 )
    return 0;
  if ( *(float *)(a4 + 4 * a2) >= 0.075000003 )
    dword_7D1490[216 * a3 + 27 * a2] = 1056964608;
  else
    dword_7D1490[216 * a3 + 27 * a2] = 0;
  return 1;
}
