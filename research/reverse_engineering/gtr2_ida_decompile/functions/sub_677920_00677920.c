int __usercall sub_677920@<eax>(int *a1@<esi>)
{
  int v1; // eax
  int v2; // eax
  _BYTE *v3; // eax
  int v4; // ecx
  int v5; // ecx

  v1 = *a1;
  *(_DWORD *)(v1 + 20) = 102;
  (*(void (__stdcall **)(int *, int))(v1 + 4))(a1, 1);
  if ( *(_DWORD *)(a1[111] + 12) )
  {
    v2 = *a1;
    *(_DWORD *)(v2 + 20) = 61;
    (*(void (__stdcall **)(int *))v2)(a1);
  }
  v3 = a1 + 62;
  v4 = 16;
  do
  {
    *(v3 - 16) = 0;
    *v3 = 1;
    v3[16] = 5;
    ++v3;
    --v4;
  }
  while ( v4 );
  v5 = a1[111];
  a1[70] = 0;
  a1[10] = 0;
  a1[76] = 0;
  a1[71] = 0;
  *((_BYTE *)a1 + 290) = 0;
  a1[74] = 0;
  *((_BYTE *)a1 + 300) = 0;
  *((_BYTE *)a1 + 288) = 1;
  *((_BYTE *)a1 + 289) = 1;
  *((_WORD *)a1 + 146) = 1;
  *((_WORD *)a1 + 147) = 1;
  *(_DWORD *)(v5 + 12) = 1;
  return 1;
}
