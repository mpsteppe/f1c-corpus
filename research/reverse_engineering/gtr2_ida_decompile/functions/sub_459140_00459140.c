char __thiscall sub_459140(_DWORD *this, _DWORD *a2)
{
  _DWORD *v2; // ebx
  int i; // edi
  int v4; // edx
  double *j; // ecx
  int k; // edi
  int v8; // edx
  double *m; // ecx
  int v10; // esi
  int v11; // eax
  float *v12; // edi
  float *v13; // ebx
  int v14; // eax
  int v16; // [esp+10h] [ebp-50h]
  float *v17; // [esp+14h] [ebp-4Ch]
  _BYTE v18[16]; // [esp+18h] [ebp-48h] BYREF
  _BYTE v19[56]; // [esp+28h] [ebp-38h] BYREF

  v2 = this;
  sub_458EB0(this, (int)v18);
  for ( i = 0; i < 3; ++i )
  {
    v4 = 0;
    for ( j = (double *)v19; *(float *)a2[2 * i] * *(j - 2) + *(float *)(a2[2 * i] + 16) * *(j - 1) > *j; j += 3 )
    {
      if ( ++v4 >= 3 )
        return 1;
    }
  }
  sub_458EB0(a2, (int)v18);
  for ( k = 0; k < 3; ++k )
  {
    v8 = 0;
    for ( m = (double *)v19; *(float *)(v2[2 * k] + 16) * *(m - 1) + *(float *)v2[2 * k] * *(m - 2) > *m; m += 3 )
    {
      if ( ++v8 >= 3 )
        return 1;
    }
  }
  v10 = 0;
LABEL_15:
  v17 = (float *)v2[2 * v10];
  if ( v10 == 2 )
    v11 = 0;
  else
    v11 = v10 + 1;
  v12 = (float *)v2[2 * v11];
  v13 = (float *)a2[2 * v10];
  v16 = 0;
  while ( 1 )
  {
    v14 = v10 == 2 ? 0 : v10 + 1;
    if ( sub_458F70(v17, v12, v13, (float *)a2[2 * v14]) )
      return 1;
    if ( ++v16 >= 3 )
    {
      if ( ++v10 < 3 )
      {
        v2 = this;
        goto LABEL_15;
      }
      return 0;
    }
  }
}
