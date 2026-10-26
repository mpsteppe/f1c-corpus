int __fastcall sub_539A10(int a1, int *a2)
{
  int *v2; // eax
  int v3; // ebx
  int v4; // edi
  int v6; // ecx
  int v7; // ebp
  int v8; // eax
  int v9; // ecx
  int i; // ecx
  int v11; // eax
  int v12; // ecx
  int j; // ebx
  int v14; // eax
  int v15; // ebx
  int v16; // ebp
  int v17; // edx
  int v18; // ecx
  char v19; // cl
  int v20; // ecx
  int v22; // [esp+14h] [ebp-8h]

  v2 = (int *)a2[2];
  v3 = *v2;
  v4 = *a2;
  v6 = v2[3];
  v7 = -1;
  v8 = 0;
  v22 = v6;
  *(_DWORD *)(a1 + 5190) = 0;
  for ( *(_DWORD *)(a1 + 5194) = 573; v8 < v6; ++v8 )
  {
    if ( *(_WORD *)(v4 + 4 * v8) )
    {
      v9 = *(_DWORD *)(a1 + 5190) + 1;
      v7 = v8;
      *(_DWORD *)(a1 + 5190) = v9;
      *(_DWORD *)(a1 + 4 * v9 + 2898) = v8;
      v6 = v22;
      *(_BYTE *)(v8 + a1 + 5198) = 0;
    }
    else
    {
      *(_WORD *)(v4 + 4 * v8 + 2) = 0;
    }
  }
  for ( i = *(_DWORD *)(a1 + 5190); i < 2; i = *(_DWORD *)(a1 + 5190) )
  {
    if ( v7 >= 2 )
      v11 = 0;
    else
      v11 = ++v7;
    v12 = i + 1;
    *(_DWORD *)(a1 + 5190) = v12;
    *(_DWORD *)(a1 + 4 * v12 + 2898) = v11;
    *(_WORD *)(v4 + 4 * v11) = 1;
    *(_BYTE *)(a1 + v11 + 5198) = 0;
    --*(_DWORD *)(a1 + 5787);
    if ( v3 )
      *(_DWORD *)(a1 + 5791) -= *(unsigned __int16 *)(v3 + 4 * v11 + 2);
  }
  a2[1] = v7;
  for ( j = *(_DWORD *)(a1 + 5190) / 2; j >= 1; --j )
    sub_539C20(j);
  do
  {
    v14 = *(_DWORD *)(a1 + 5190);
    v15 = *(_DWORD *)(a1 + 2902);
    *(_DWORD *)(a1 + 2902) = *(_DWORD *)(a1 + 4 * v14 + 2898);
    *(_DWORD *)(a1 + 5190) = v14 - 1;
    sub_539C20(1);
    v16 = *(_DWORD *)(a1 + 2902);
    v17 = *(_DWORD *)(a1 + 5194) - 1;
    *(_DWORD *)(a1 + 5194) = v17;
    *(_DWORD *)(a1 + 4 * v17 + 2898) = v15;
    v18 = *(_DWORD *)(a1 + 5194) - 1;
    *(_DWORD *)(a1 + 5194) = v18;
    *(_DWORD *)(a1 + 4 * v18 + 2898) = v16;
    *(_WORD *)(v4 + 4 * v22) = *(_WORD *)(v4 + 4 * v15) + *(_WORD *)(v4 + 4 * v16);
    if ( *(_BYTE *)(a1 + v15 + 5198) < *(_BYTE *)(a1 + v16 + 5198) )
      v19 = *(_BYTE *)(a1 + v16 + 5198);
    else
      v19 = *(_BYTE *)(a1 + v15 + 5198);
    *(_BYTE *)(a1 + v22 + 5198) = v19 + 1;
    *(_WORD *)(v4 + 4 * v16 + 2) = v22;
    *(_WORD *)(v4 + 4 * v15 + 2) = v22;
    *(_DWORD *)(a1 + 2902) = v22++;
    sub_539C20(1);
  }
  while ( *(int *)(a1 + 5190) >= 2 );
  v20 = *(_DWORD *)(a1 + 5194) - 1;
  *(_DWORD *)(a1 + 5194) = v20;
  *(_DWORD *)(a1 + 4 * v20 + 2898) = *(_DWORD *)(a1 + 2902);
  sub_539D00(a1, a2);
  return sub_539F10(a1 + 2866);
}
