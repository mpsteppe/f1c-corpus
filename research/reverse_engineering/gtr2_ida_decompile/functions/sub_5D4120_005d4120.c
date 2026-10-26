int __userpurge sub_5D4120@<eax>(int a1@<ecx>, int a2@<edi>, int *a3)
{
  int v4; // ecx
  int v5; // eax
  bool v6; // cc
  int v7; // edi
  int i; // edx
  _DWORD *v9; // eax
  int v11; // [esp-4h] [ebp-Ch]

  if ( a3 == (int *)a1 )
    return a1;
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 4) = 0;
  sub_4F14D0(a2);
  sub_5A8D10(*(void **)(a1 + 8));
  v4 = *(_DWORD *)(a1 + 4);
  *(_DWORD *)(a1 + 8) = 0;
  v5 = *a3;
  v6 = v4 < *a3;
  *(_DWORD *)a1 = *a3;
  if ( v6 )
  {
    v7 = v5 + 1;
    sub_4F14D0(v11);
    *(_DWORD *)(a1 + 8) = sub_5A8CF0(*(void **)(a1 + 8), 4 * v7, 2, 16, 2);
    *(_DWORD *)(a1 + 4) = v7;
  }
  for ( i = 0; i < *(_DWORD *)a1; ++i )
  {
    v9 = (_DWORD *)(4 * i + *(_DWORD *)(a1 + 8));
    if ( v9 )
      *v9 = *(_DWORD *)(4 * i + a3[2]);
  }
  return a1;
}
