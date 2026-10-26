char __thiscall sub_4541D0(int this, char *a2, int *a3)
{
  int v3; // eax
  unsigned int v4; // eax
  char *v5; // eax
  int v6; // edx
  char v7; // cl

  if ( *(int *)(this + 3208) <= 0 )
    return 0;
  v3 = *(unsigned __int8 *)(this + 3212);
  *a3 = v3;
  if ( v3 <= 128 )
  {
    if ( (unsigned int)v3 < 0x5A )
    {
      strcpy(a2, &aPause_0[16 * v3]);
      return 1;
    }
    return 0;
  }
  v4 = v3 - 128;
  if ( v4 >= 0x58 )
    return 0;
  v5 = &aEmpty_0[16 * v4];
  v6 = a2 - v5;
  do
  {
    v7 = *v5;
    v5[v6] = *v5;
    ++v5;
  }
  while ( v7 );
  return 1;
}

