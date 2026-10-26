_DWORD *__thiscall sub_611A00(_DWORD *this)
{
  int *v2; // eax
  int i; // eax
  int v4; // eax
  int *v5; // eax
  int *v6; // eax
  int j; // eax
  int v8; // eax
  int *v9; // eax
  int *v10; // eax
  int k; // eax
  int v12; // eax
  int *v13; // eax
  _DWORD *result; // eax

  v2 = (int *)this[168];
  this[170] = v2;
  if ( v2 )
  {
    for ( i = *v2; i; i = *v5 )
    {
      (*(void (__thiscall **)(_DWORD *, int, _DWORD, _DWORD, _DWORD))(*this + 412))(this, i, 0, 0, 0);
      v4 = this[170];
      if ( !v4 )
        break;
      v5 = *(int **)(v4 + 4);
      this[170] = v5;
      if ( !v5 )
        break;
    }
  }
  v6 = (int *)this[178];
  this[180] = v6;
  if ( v6 )
  {
    for ( j = *v6; j; j = *v9 )
    {
      (*(void (__thiscall **)(_DWORD *, int, _DWORD, _DWORD))(*this + 452))(this, j, 0, 0);
      v8 = this[180];
      if ( !v8 )
        break;
      v9 = *(int **)(v8 + 4);
      this[180] = v9;
      if ( !v9 )
        break;
    }
  }
  v10 = (int *)this[173];
  this[175] = v10;
  if ( v10 )
  {
    for ( k = *v10; k; k = *v13 )
    {
      (*(void (__thiscall **)(_DWORD *, int, _DWORD, _DWORD, _DWORD))(*this + 412))(this, k, 0, 0, 0);
      v12 = this[175];
      if ( !v12 )
        break;
      v13 = *(int **)(v12 + 4);
      this[175] = v13;
      if ( !v13 )
        break;
    }
  }
  result = (_DWORD *)this[183];
  this[185] = result;
  if ( result )
  {
    for ( result = (_DWORD *)*result; result; result = (_DWORD *)*result )
    {
      (*(void (__thiscall **)(_DWORD *, _DWORD *, _DWORD, _DWORD))(*this + 452))(this, result, 0, 0);
      result = (_DWORD *)this[185];
      if ( !result )
        break;
      result = (_DWORD *)result[1];
      this[185] = result;
      if ( !result )
        break;
    }
  }
  return result;
}
