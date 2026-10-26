int __userpurge sub_6797C0@<eax>(int a1@<eax>, int *a2@<ebx>, int *a3, const void *a4)
{
  int v5; // edx
  char v6; // cl
  signed int v7; // esi
  unsigned __int8 *v8; // eax
  int v9; // ecx
  int v10; // edx
  int v11; // edi
  int v12; // eax
  int result; // eax

  if ( !*a2 )
    *a2 = sub_6B5F80(a3);
  v5 = *a2;
  *(_DWORD *)v5 = *(_DWORD *)a1;
  *(_DWORD *)(v5 + 4) = *(_DWORD *)(a1 + 4);
  *(_DWORD *)(v5 + 8) = *(_DWORD *)(a1 + 8);
  v6 = *(_BYTE *)(a1 + 16);
  *(_DWORD *)(v5 + 12) = *(_DWORD *)(a1 + 12);
  *(_BYTE *)(v5 + 16) = v6;
  v7 = 0;
  v8 = (unsigned __int8 *)(a1 + 3);
  v9 = 4;
  do
  {
    v10 = v8[1] + *(v8 - 1) + *(v8 - 2);
    v11 = v7 + *v8;
    v8 += 4;
    --v9;
    v7 = v11 + v10;
  }
  while ( v9 );
  if ( v7 < 1 || v7 > 256 )
  {
    v12 = *a3;
    *(_DWORD *)(v12 + 20) = 8;
    (*(void (__stdcall **)(int *))v12)(a3);
  }
  result = *a2;
  qmemcpy((void *)(*a2 + 17), a4, v7);
  *(_DWORD *)(result + 276) = 0;
  return result;
}
