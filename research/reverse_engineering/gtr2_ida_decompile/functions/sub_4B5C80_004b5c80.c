int __thiscall sub_4B5C80(_DWORD *this, int a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // ecx
  int v5; // edx
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  const char *v13; // eax
  char Buffer[32]; // [esp+4h] [ebp-20h] BYREF

  v3 = (_DWORD *)this[210];
  if ( a2 == 1 )
    *v3 += this[214];
  else
    *v3 -= this[215];
  v4 = (_DWORD *)this[210];
  v5 = this[213];
  if ( *v4 < v5 || (v5 = this[212], *v4 > v5) )
    *v4 = v5;
  v6 = dword_B72F9C;
  dword_B72F94 = *(_DWORD *)this[210];
  if ( dword_B72F94 < dword_B72F9C || (v6 = dword_B72FA0, dword_B72F94 > dword_B72FA0) )
    dword_B72F94 = v6;
  v7 = dword_B72F78;
  dword_B72F70 = *(_DWORD *)this[210];
  if ( dword_B72F70 < dword_B72F78 || (v7 = dword_B72F7C, dword_B72F70 > dword_B72F7C) )
    dword_B72F70 = v7;
  v8 = *(_DWORD *)this[210];
  v9 = dword_B73008;
  dword_B73000 = v8;
  if ( v8 < dword_B73008 || (v9 = dword_B7300C, v8 > dword_B7300C) )
    dword_B73000 = v9;
  v10 = dword_B73050;
  dword_B73048 = *(_DWORD *)this[210];
  if ( dword_B73048 < dword_B73050 || (v10 = dword_B73054, dword_B73048 > dword_B73054) )
    dword_B73048 = v10;
  if ( *(_DWORD *)dword_B72314 == 4 )
  {
    v11 = dword_B71CD4;
    dword_B71CCC = 0;
    if ( dword_B71CD4 > 0 || (v11 = dword_B71CD8, dword_B71CD8 < 0) )
      dword_B71CCC = v11;
  }
  else
  {
    v12 = dword_B71D40;
    dword_B71D38 = 0;
    if ( dword_B71D40 > 0 || (v12 = dword_B71D44, dword_B71D44 < 0) )
      dword_B71D38 = v12;
  }
  v13 = (const char *)sub_4CFC00(dword_B72FB8);
  sprintf(Buffer, v13);
  return sub_4CE770(Buffer);
}
