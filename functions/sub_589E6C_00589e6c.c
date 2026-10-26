int *__cdecl sub_589E6C(int a1)
{
  int *v1; // esi
  int v3; // eax
  int *v4; // eax
  int *v5; // esi
  bool v6; // zf
  int v7; // eax
  int v8; // edx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  bool v12; // sf
  int v13; // eax

  v1 = (int *)a1;
  if ( *(int *)a1 < 0 )
    return 0;
  LazyInitSingletonWithFlagGuard();
  v3 = *v1;
  if ( *v1 > 259200 && v3 < 2147224447 )
  {
    a1 = v3 - dword_5E7758;
    v4 = (int *)sub_592787(&a1);
    v5 = v4;
    if ( dword_5E775C )
    {
      if ( CriticalSectionGuardedCall(v4) )
      {
        a1 -= dword_5E7760;
        v5 = (int *)sub_592787(&a1);
        v5[8] = 1;
      }
    }
    return v5;
  }
  v5 = (int *)sub_592787(v1);
  v6 = CriticalSectionGuardedCall(v5) == 0;
  v7 = *v5;
  if ( !v6 )
    v7 -= dword_5E7760;
  a1 = v7 - dword_5E7758;
  v8 = (v7 - dword_5E7758) % 60;
  *v5 = v8;
  if ( v8 < 0 )
  {
    *v5 = v8 + 60;
    a1 -= 60;
  }
  a1 = v5[1] + a1 / 60;
  v9 = a1 % 60;
  v12 = a1 % 60 < 0;
  v5[1] = a1 % 60;
  if ( v12 )
  {
    v5[1] = v9 + 60;
    a1 -= 60;
  }
  a1 = v5[2] + a1 / 60;
  v10 = a1 % 24;
  v12 = a1 % 24 < 0;
  v5[2] = a1 % 24;
  if ( v12 )
  {
    v5[2] = v10 + 24;
    a1 -= 24;
  }
  v11 = a1 / 24;
  v12 = a1 / 24 < 0;
  a1 /= 24;
  if ( a1 <= 0 )
  {
    if ( !v12 )
      return v5;
    v5[6] = (v5[6] + v11 + 7) % 7;
    v5[3] += a1;
    v13 = v5[3];
    if ( v13 <= 0 )
    {
      --v5[5];
      v5[3] = v13 + 31;
      v5[7] = 364;
      v5[4] = 11;
      return v5;
    }
  }
  else
  {
    v5[6] = (v11 + v5[6]) % 7;
    v5[3] += a1;
  }
  v5[7] += a1;
  return v5;
}
