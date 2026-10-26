int __userpurge sub_5D6BC0@<eax>(int a1@<ecx>, int a2@<edi>, int *a3)
{
  int v4; // ebx
  int v5; // ecx
  int v6; // eax
  bool v7; // cc
  int v8; // edi
  int i; // edi
  int v11; // [esp-8h] [ebp-10h]

  if ( a3 == (int *)a1 )
    return a1;
  v4 = 0;
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 4) = 0;
  sub_4F14D0(a2);
  sub_5A8D10(*(void **)(a1 + 8));
  v5 = *(_DWORD *)(a1 + 4);
  *(_DWORD *)(a1 + 8) = 0;
  v6 = *a3;
  v7 = v5 < *a3;
  *(_DWORD *)a1 = *a3;
  if ( v7 )
  {
    v8 = v6 + 1;
    sub_4F14D0(v11);
    *(_DWORD *)(a1 + 8) = sub_5A8CF0(*(void **)(a1 + 8), 68 * v8, 2, 16, 2);
    *(_DWORD *)(a1 + 4) = v8;
  }
  for ( i = 0; i < *(_DWORD *)a1; v4 += 68 )
    sub_5D64C0((_DWORD *)a1, i++, (_DWORD *)(v4 + a3[2]));
  return a1;
}
