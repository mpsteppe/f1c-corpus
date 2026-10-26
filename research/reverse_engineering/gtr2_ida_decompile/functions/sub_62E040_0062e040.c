int __userpurge sub_62E040@<eax>(int a1@<esi>, int *a2)
{
  int v2; // edi
  int *v3; // eax
  int v4; // ecx
  int v5; // ebx
  int v6; // ebp
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  int i; // ebx
  int v12; // ebp
  int v13; // eax
  int v14; // edx
  int v15; // ebx
  int v16; // eax
  int v17; // edx
  int v18; // ecx
  unsigned __int8 v19; // cl
  int v20; // edx
  int v21; // eax
  int v23; // [esp+Ch] [ebp-8h]
  int v24; // [esp+10h] [ebp-4h]

  v2 = *a2;
  v3 = (int *)a2[2];
  v4 = v3[3];
  v5 = *v3;
  v6 = -1;
  v7 = 0;
  v24 = v4;
  v23 = -1;
  *(_DWORD *)(a1 + 5190) = 0;
  for ( *(_DWORD *)(a1 + 5194) = 573; v7 < v24; ++v7 )
  {
    if ( *(_WORD *)(v2 + 4 * v7) )
    {
      v8 = *(_DWORD *)(a1 + 5190) + 1;
      *(_DWORD *)(a1 + 5190) = v8;
      *(_DWORD *)(a1 + 4 * v8 + 2898) = v7;
      v23 = v7;
      *(_BYTE *)(v7 + a1 + 5198) = 0;
      v6 = v7;
    }
    else
    {
      *(_WORD *)(v2 + 4 * v7 + 2) = 0;
    }
  }
  if ( *(int *)(a1 + 5190) < 2 )
  {
    do
    {
      if ( v6 >= 2 )
        v9 = 0;
      else
        v9 = ++v6;
      v10 = *(_DWORD *)(a1 + 5190) + 1;
      *(_DWORD *)(a1 + 5190) = v10;
      *(_DWORD *)(a1 + 4 * v10 + 2898) = v9;
      *(_WORD *)(v2 + 4 * v9) = 1;
      *(_BYTE *)(a1 + v9 + 5198) = 0;
      --*(_DWORD *)(a1 + 5787);
      if ( v5 )
        *(_DWORD *)(a1 + 5791) -= *(unsigned __int16 *)(v5 + 4 * v9 + 2);
    }
    while ( *(int *)(a1 + 5190) < 2 );
    v23 = v6;
  }
  a2[1] = v6;
  for ( i = *(_DWORD *)(a1 + 5190) / 2; i >= 1; --i )
    sub_62CDA0();
  v12 = v24;
  do
  {
    v13 = *(_DWORD *)(a1 + 5190);
    v14 = *(_DWORD *)(a1 + 4 * v13 + 2898);
    v15 = *(_DWORD *)(a1 + 2902);
    *(_DWORD *)(a1 + 5190) = v13 - 1;
    *(_DWORD *)(a1 + 2902) = v14;
    sub_62CDA0();
    v16 = *(_DWORD *)(a1 + 2902);
    v17 = *(_DWORD *)(a1 + 5194) - 1;
    *(_DWORD *)(a1 + 5194) = v17;
    *(_DWORD *)(a1 + 4 * v17 + 2898) = v15;
    v18 = *(_DWORD *)(a1 + 5194) - 1;
    *(_DWORD *)(a1 + 5194) = v18;
    *(_DWORD *)(a1 + 4 * v18 + 2898) = v16;
    *(_WORD *)(v2 + 4 * v12) = *(_WORD *)(v2 + 4 * v15) + *(_WORD *)(v2 + 4 * v16);
    v19 = *(_BYTE *)(a1 + v16 + 5198);
    if ( *(_BYTE *)(a1 + v15 + 5198) >= v19 )
      v19 = *(_BYTE *)(a1 + v15 + 5198);
    *(_BYTE *)(a1 + v12 + 5198) = v19 + 1;
    *(_WORD *)(v2 + 4 * v16 + 2) = v12;
    *(_WORD *)(v2 + 4 * v15 + 2) = v12;
    *(_DWORD *)(a1 + 2902) = v12++;
    sub_62CDA0();
  }
  while ( *(int *)(a1 + 5190) >= 2 );
  v20 = *(_DWORD *)(a1 + 2902);
  v21 = *(_DWORD *)(a1 + 5194) - 1;
  *(_DWORD *)(a1 + 5194) = v21;
  *(_DWORD *)(a1 + 4 * v21 + 2898) = v20;
  sub_62CE70(a1, a2);
  return sub_62DFC0(a1 + 2866, v23, v2);
}
