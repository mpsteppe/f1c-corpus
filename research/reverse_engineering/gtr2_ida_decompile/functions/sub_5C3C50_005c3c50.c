_DWORD *__userpurge sub_5C3C50@<eax>(int a1@<ecx>, int a2@<edi>, int a3)
{
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // edi
  void *v8; // eax
  int v9; // ecx
  _DWORD *result; // eax

  v4 = *(_DWORD *)(a1 + 52);
  v5 = *(_DWORD *)(a1 + 56);
  v6 = v4 + 1;
  *(_DWORD *)(a1 + 52) = v6;
  if ( v5 < v6 )
  {
    v7 = v6 + 1;
    sub_4F14D0(a2);
    v8 = sub_5A8CF0(*(void **)(a1 + 60), 4 * v7, 2, 16, 2);
    *(_DWORD *)(a1 + 56) = v7;
    *(_DWORD *)(a1 + 60) = v8;
  }
  v9 = *(_DWORD *)(a1 + 60);
  result = (_DWORD *)(v9 + 4 * *(_DWORD *)(a1 + 52) - 4);
  if ( v9 + 4 * *(_DWORD *)(a1 + 52) != 4 )
    *result = a3;
  return result;
}
