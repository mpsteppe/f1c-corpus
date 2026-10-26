int __thiscall sub_697320(_DWORD *this, int *a2, int *a3, int **a4, int **a5, int *a6)
{
  int **v6; // eax
  int result; // eax
  int *v8; // ebx
  unsigned int v9; // esi
  int *v10; // esi
  int *v11; // edi
  int v12; // eax
  int *v13; // edi
  int v14; // eax

  if ( !a4 )
    return -2147467259;
  v6 = a5;
  if ( !a5 )
    return -2147467259;
  *a4 = 0;
  *v6 = 0;
  if ( a6 )
    *a6 = 0;
  if ( !a2 )
  {
    if ( a3 )
      return -2147467259;
    return 0;
  }
  v8 = a3;
  if ( !a3 )
    return -2147467259;
  v9 = sub_6951CB(this, a2);
  if ( v9 < sub_6951CB(this, v8) || !sub_696CB7(this, a2, v8, 0) )
  {
    if ( sub_696CB7(this, v8, a2, 0) )
    {
      v10 = v8;
      goto LABEL_16;
    }
    if ( !sub_696CB7(this, a2, v8, 0) )
      return -2147467259;
  }
  v10 = a2;
LABEL_16:
  result = sub_6956A9((int)a2, (int)v8, (int *)&a3);
  if ( result >= 0 )
  {
    v11 = a3;
    if ( (int *)v10[5] != a3 )
    {
      v12 = (*(int (__thiscall **)(int *))(*v10 + 4))(v10);
      if ( !v12 )
        return -2147024882;
      *(_DWORD *)(v12 + 20) = v11;
      v10 = (int *)v12;
    }
    v13 = a6;
    if ( a6 )
    {
      v14 = (*(int (__thiscall **)(int *))(*v10 + 4))(v10);
      *v13 = v14;
      if ( !v14 )
        return -2147024882;
      sub_694F9B(this, v14, 1);
    }
    *a4 = v10;
    *a5 = v10;
    return 0;
  }
  return result;
}
