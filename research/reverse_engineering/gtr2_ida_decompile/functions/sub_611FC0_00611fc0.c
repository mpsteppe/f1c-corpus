int __fastcall sub_611FC0(char *a1, int a2, int a3, int a4, int a5, int a6, char **a7, _DWORD *a8, char a9)
{
  int *v9; // edi
  bool v10; // zf
  char **v11; // eax
  char *v12; // esi
  int v13; // eax
  char **v14; // eax
  int v15; // ebp
  int v16; // ebp
  _DWORD *v17; // eax
  _DWORD *v19; // edi
  int v20; // eax
  char v21; // [esp+0h] [ebp-20h]
  char *v22; // [esp+10h] [ebp-10h]
  int v23; // [esp+24h] [ebp+4h]
  int v24; // [esp+3Ch] [ebp+1Ch]

  v9 = (int *)a3;
  v10 = a3 == 0;
  v22 = a1;
  v23 = a4;
  if ( v10 )
    v9 = (int *)(a1 + 692);
  if ( a9 )
  {
    v23 = a5;
LABEL_14:
    v16 = 262150;
    if ( a9 )
      v16 = 262158;
    v24 = (int)(a1 + 4);
    if ( a1[4] < 0 )
      v16 |= 0x40u;
    v17 = operator new(0x50u);
    v12 = 0;
    if ( v17 )
      v12 = (char *)sub_60ADA0(v17);
    *(_DWORD *)v12 |= v16;
    if ( sub_60B2D0(v12, *((_DWORD *)v22 + 2387), v23, a6) )
    {
      sub_5D8C80(v24, (char *)0xFFFFFFFF, "Error creating new dynamic vertex buffer", v21);
      return -1;
    }
    sub_5FDFB0(v9, (int)v12, 0);
    sub_60B640(v12, 0x2000, 0, 0, a6);
    v15 = a5;
    v19 = v12 + 8;
    goto LABEL_27;
  }
  v11 = (char **)*v9;
  v10 = *v9 == 0;
  v9[2] = *v9;
  if ( v10 )
    goto LABEL_14;
  v12 = *v11;
  if ( !*v11 )
    goto LABEL_14;
  while ( *((_DWORD *)v12 + 6) != a6 )
  {
    v13 = v9[2];
    if ( v13 )
    {
      v14 = *(char ***)(v13 + 4);
      v9[2] = (int)v14;
      if ( v14 )
      {
        v12 = *v14;
        if ( *v14 )
          continue;
      }
    }
    goto LABEL_14;
  }
  v15 = a5;
  if ( a5 > a4 )
  {
    v23 = a5;
    (*(void (__thiscall **)(char *, char *, int))(*(_DWORD *)a1 + 408))(a1, v12, a6);
    sub_59F730(v9, (int)v12, 1);
    a1 = v22;
    goto LABEL_14;
  }
  v20 = *((_DWORD *)v12 + 2);
  v19 = v12 + 8;
  if ( a5 <= *((_DWORD *)v12 + 1) - v20 )
  {
    sub_60B640(v12, 4096, v20, a5, a6);
    goto LABEL_28;
  }
  sub_60B640(v12, 0x2000, 0, 0, a6);
LABEL_27:
  *v19 = 0;
LABEL_28:
  if ( *v12 >= 0 )
    return -1;
  if ( (*(int (__stdcall **)(_DWORD))(**((_DWORD **)v22 + 2387) + 12))(*((_DWORD *)v22 + 2387)) )
    return -1;
  if ( a7 )
    *a7 = v12;
  if ( a8 )
    *a8 = *v19;
  *v19 += v15;
  return 0;
}
