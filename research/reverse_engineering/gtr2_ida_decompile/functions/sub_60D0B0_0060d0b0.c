int __thiscall sub_60D0B0(_DWORD *this, int a2, _DWORD *a3, unsigned int a4, int a5)
{
  _DWORD *v6; // ebx
  _DWORD *v7; // edi
  int result; // eax
  int v9; // ebx
  int v10; // ebp
  int v11; // edi
  int v12; // eax
  int v13; // eax
  int v14; // eax

  if ( a2 )
    v6 = *(_DWORD **)(a2 + 88);
  else
    v6 = a3;
  v7 = (_DWORD *)sub_5F7B60(v6, a5, a4);
  result = sub_5F7BF0(v6, a4);
  v9 = 0;
  if ( v7 )
    v9 = v7[89];
  v10 = 0;
  if ( result )
    v10 = *(_DWORD *)(result + 380);
  if ( v9 )
  {
    v11 = v7[88];
    if ( v11 == this[2413] )
      goto LABEL_14;
    v12 = this[2387];
    this[2414] = 0;
    this[2413] = v11;
    result = (*(int (__stdcall **)(int, int))(*(_DWORD *)v12 + 348))(v12, v11);
  }
  else
  {
    if ( v7[90] == this[2414] )
      goto LABEL_14;
    this[2413] = 0;
    this[2414] = v7[90];
    result = (*(int (__stdcall **)(_DWORD, _DWORD))(*(_DWORD *)this[2387] + 356))(this[2387], v7[90]);
  }
  this[2] = result;
LABEL_14:
  if ( v9 != this[2411] )
  {
    v13 = this[2387];
    this[2411] = v9;
    result = (*(int (__stdcall **)(int, int))(*(_DWORD *)v13 + 368))(v13, v9);
    this[2] = result;
  }
  if ( v10 != this[2412] )
  {
    v14 = this[2387];
    this[2412] = v10;
    result = (*(int (__stdcall **)(int, int))(*(_DWORD *)v14 + 428))(v14, v10);
    this[2] = result;
  }
  return result;
}
