int __thiscall sub_611E50(_DWORD *this, int **a2, int a3, int a4, int ***a5, _DWORD *a6, int *a7, char a8)
{
  bool v8; // zf
  int **v10; // ebx
  int v11; // edx
  int v12; // eax
  int v13; // esi
  int *v14; // ebp
  int *v15; // eax
  int v16; // eax
  int *v17; // eax
  int *v18; // eax
  int v19; // eax
  int v21; // eax
  char v22; // [esp+4h] [ebp-10h]

  v8 = a2 == 0;
  v10 = a2;
  v11 = a3;
  a2 = 0;
  if ( v8 )
    v10 = (int **)(this + 178);
  if ( a8 )
    v12 = this[182];
  else
    v12 = this[177];
  if ( a3 >= v12 )
    v11 = v12;
  v13 = a4;
  if ( a4 > v11 )
    v11 = a4;
  v14 = a7;
  if ( a3 > 0 && ((v15 = *v10, v8 = *v10 == 0, v10[2] = *v10, v8) ? (v16 = 0) : (v16 = *v15), (a2 = (int **)v16) != 0) )
  {
    while ( a8 && *(int **)(v16 + 24) != v14 || v13 > *(_DWORD *)(v16 + 4) - *(_DWORD *)(v16 + 8) || *(char *)v16 >= 0 )
    {
      v17 = v10[2];
      if ( v17 && (v18 = (int *)v17[1], (v10[2] = v18) != 0) )
        v16 = *v18;
      else
        v16 = 0;
      a2 = (int **)v16;
      if ( !v16 )
        goto LABEL_24;
    }
  }
  else
  {
LABEL_24:
    v19 = 262146;
    if ( *((char *)this + 4) < 0 )
      v19 = 262210;
    if ( (*(int (__thiscall **)(_DWORD *, int ***, int, int))(*this + 444))(this, &a2, v11, v19) )
    {
      (*(void (__thiscall **)(_DWORD *, int **))(*this + 448))(this, a2);
      sub_5D8C80((int)(this + 1), (char *)0xFFFFFFFF, "Error creating new index buffer for pool", v22);
      return -1;
    }
    a2[6] = v14;
    sub_5FDFB0(v10, (int)a2, 0);
    (*(void (__thiscall **)(_DWORD *, int **, _DWORD, _DWORD))(*this + 452))(this, a2, 0, 0);
    v16 = (int)a2;
    v13 = a4;
  }
  ++*(_DWORD *)(v16 + 12);
  v21 = (int)a2;
  if ( a5 )
    *a5 = a2;
  if ( a6 )
    *a6 = *(_DWORD *)(v21 + 8);
  *(_DWORD *)(v21 + 8) += v13;
  return 0;
}
