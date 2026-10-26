int __userpurge sub_4D3140@<eax>(int a1@<ecx>, int a2@<ebx>, int *a3@<ebp>, int a4, int a5, int a6, int a7)
{
  const char *v8; // eax
  int v9; // ebp
  int v10; // ebx
  int v11; // edi
  int v12; // eax
  const CHAR *v13; // eax
  const CHAR *v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  const CHAR *v19; // eax
  int v20; // eax
  const CHAR *v21; // eax
  int v22; // eax
  int v23; // eax
  int v25; // eax
  char *v26; // eax
  int v27; // [esp+0h] [ebp-38h]
  char *v28; // [esp+0h] [ebp-38h]
  int v29; // [esp+18h] [ebp-20h]
  int *v30; // [esp+18h] [ebp-20h]
  int *v33; // [esp+28h] [ebp-10h] BYREF
  _DWORD v34[3]; // [esp+2Ch] [ebp-Ch] BYREF

  v8 = *(const char **)(a1 + 160);
  if ( !v8 )
    v8 = WindowName;
  if ( !strlen(v8) )
    return 0;
  v34[0] = 0;
  v34[1] = 0;
  v9 = sub_4CFCC0((_DWORD *)a1, 2);
  v10 = sub_4CFCC0((_DWORD *)a1, 3);
  v11 = sub_4CFD30((_DWORD *)a1, 2);
  v34[2] = sub_4CFD30((_DWORD *)a1, 3);
  v12 = *(_DWORD *)(a1 + 244);
  if ( *(_BYTE *)(a1 + 100) )
  {
    if ( !v12 )
      goto LABEL_12;
    v13 = *(const CHAR **)(v12 + 80);
  }
  else
  {
    if ( !v12 )
      goto LABEL_12;
    v13 = *(const CHAR **)(v12 + 64);
  }
  if ( v13 || (v13 = WindowName) != 0 )
    sub_4DF1B0(*(_DWORD *)(a1 + 48), v13);
LABEL_12:
  v14 = *(const CHAR **)(a1 + 160);
  if ( !v14 )
    v14 = WindowName;
  sub_4E08C0(*(_DWORD *)(a1 + 48), v14, &v33, v34, 1, v29);
  v15 = *v33;
  if ( *v33 >= v11 )
    v15 = v11;
  *v33 = v15;
  v16 = *(_DWORD *)v34[0];
  if ( *(_DWORD *)v34[0] <= a2 )
    v16 = a2;
  *(_DWORD *)v34[0] = v16;
  v17 = *(_DWORD *)(a1 + 272);
  if ( !v17 )
  {
    v28 = (char *)v30 + v9;
    sub_4E0730(*(_DWORD *)(a1 + 48));
    v25 = *v30;
    if ( *v30 >= v9 )
      v25 = v9;
    *v30 = v25;
    v26 = &v28[v9];
    if ( *a3 > (int)&v28[v9] )
      v26 = (char *)*a3;
    *a3 = (int)v26;
    return 0;
  }
  v18 = v17 - 1;
  if ( !v18 )
  {
    v21 = *(const CHAR **)(a1 + 160);
    if ( !v21 )
      v21 = WindowName;
    sub_4E0680(*(_DWORD *)(a1 + 48), v21, v11, (char *)a3 + v11, v9, v10, 1);
    v22 = *v30;
    if ( *v30 >= v9 )
      v22 = v9;
    *v30 = v22;
    goto LABEL_31;
  }
  if ( v18 != 1 )
    return 0;
  v19 = *(const CHAR **)(a1 + 160);
  if ( !v19 )
    v19 = WindowName;
  sub_4E07F0(*(_DWORD *)(a1 + 48), v19, v11, (char *)a3 + v11, v10 - (_DWORD)v30, v10, 1);
  v20 = v10 - v27;
  if ( *v30 < v10 - v27 )
    v20 = *v30;
  *v30 = v20;
LABEL_31:
  v23 = *a3;
  if ( *a3 <= v10 )
    v23 = v10;
  *a3 = v23;
  return 0;
}
