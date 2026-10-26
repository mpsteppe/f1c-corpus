int __thiscall sub_4B5B20(_DWORD *this, int a2)
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
  v6 = dword_B72E58;
  dword_B72E50 = *(_DWORD *)this[210];
  if ( dword_B72E50 < dword_B72E58 || (v6 = dword_B72E5C, dword_B72E50 > dword_B72E5C) )
    dword_B72E50 = v6;
  v7 = dword_B72E7C;
  dword_B72E74 = *(_DWORD *)this[210];
  if ( dword_B72E74 < dword_B72E7C || (v7 = dword_B72E80, dword_B72E74 > dword_B72E80) )
    dword_B72E74 = v7;
  v8 = *(_DWORD *)this[210];
  v9 = dword_B72EC4;
  dword_B72EBC = v8;
  if ( v8 < dword_B72EC4 || (v9 = dword_B72EC8, v8 > dword_B72EC8) )
    dword_B72EBC = v9;
  v10 = dword_B72F0C;
  dword_B72F04 = *(_DWORD *)this[210];
  if ( dword_B72F04 < dword_B72F0C || (v10 = dword_B72F10, dword_B72F04 > dword_B72F10) )
    dword_B72F04 = v10;
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
  v13 = (const char *)sub_4CFC00(dword_B72E2C);
  sprintf(Buffer, v13);
  return sub_4CE770(Buffer);
}
