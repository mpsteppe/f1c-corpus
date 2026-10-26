int __initstdio()
{
  int v0; // eax
  int v1; // ecx
  _UNKNOWN **v2; // eax
  int v3; // ecx
  _DWORD *v4; // edx
  int result; // eax

  v0 = dword_801500;
  if ( !dword_801500 )
  {
    v0 = 512;
LABEL_5:
    dword_801500 = v0;
    goto LABEL_6;
  }
  if ( dword_801500 < 20 )
  {
    v0 = 20;
    goto LABEL_5;
  }
LABEL_6:
  dword_8004E4 = sub_5C1C71(v0, 4);
  if ( !dword_8004E4 )
  {
    dword_801500 = 20;
    dword_8004E4 = sub_5C1C71(20, 4);
    if ( !dword_8004E4 )
      _amsg_exit(0x1Au);
  }
  v1 = 0;
  v2 = &off_6253F8;
  do
  {
    *(_DWORD *)(v1 + dword_8004E4) = v2;
    v2 += 8;
    v1 += 4;
  }
  while ( (int)v2 < (int)&off_625678 );
  v3 = 0;
  v4 = &unk_625408;
  do
  {
    result = *(_DWORD *)(dword_8003E0[v3 >> 5] + 36 * (v3 & 0x1F));
    if ( result == -1 || !result )
      *v4 = -1;
    v4 += 8;
    ++v3;
  }
  while ( (int)v4 < (int)dword_625468 );
  return result;
}
