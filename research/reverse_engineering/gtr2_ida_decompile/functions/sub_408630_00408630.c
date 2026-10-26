_DWORD *__thiscall sub_408630(_DWORD *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // edi
  void (__thiscall ***v4)(_DWORD, int); // ecx
  _DWORD **v5; // ecx
  _DWORD *v6; // eax
  bool v7; // zf
  _DWORD *v8; // edi
  _DWORD *v9; // eax
  _DWORD *v10; // edi
  void (__thiscall ***v11)(_DWORD, int); // ecx
  _DWORD **v12; // ecx
  _DWORD *v13; // eax
  _DWORD *v14; // edi
  _DWORD *v15; // eax
  _DWORD *v16; // edi
  void (__thiscall ***v17)(_DWORD, int); // ecx
  _DWORD **v18; // ecx
  _DWORD *result; // eax
  _DWORD *v20; // edi

  v2 = (_DWORD *)this[2];
  v3 = (_DWORD *)*v2;
  if ( (_DWORD *)*v2 != v2 )
  {
    do
    {
      v4 = (void (__thiscall ***)(_DWORD, int))v3[2];
      if ( v4 )
        (**v4)(v4, 1);
      v3 = (_DWORD *)*v3;
    }
    while ( v3 != (_DWORD *)this[2] );
  }
  v5 = (_DWORD **)this[2];
  v6 = *v5;
  *v5 = v5;
  *(_DWORD *)(this[2] + 4) = this[2];
  v7 = v6 == (_DWORD *)this[2];
  this[3] = 0;
  if ( !v7 )
  {
    do
    {
      v8 = (_DWORD *)*v6;
      j__free(v6);
      v6 = v8;
    }
    while ( v8 != (_DWORD *)this[2] );
  }
  v9 = (_DWORD *)this[5];
  v10 = (_DWORD *)*v9;
  if ( (_DWORD *)*v9 != v9 )
  {
    do
    {
      v11 = (void (__thiscall ***)(_DWORD, int))v10[2];
      if ( v11 )
        (**v11)(v11, 1);
      v10 = (_DWORD *)*v10;
    }
    while ( v10 != (_DWORD *)this[5] );
  }
  v12 = (_DWORD **)this[5];
  v13 = *v12;
  *v12 = v12;
  *(_DWORD *)(this[5] + 4) = this[5];
  v7 = v13 == (_DWORD *)this[5];
  this[6] = 0;
  if ( !v7 )
  {
    do
    {
      v14 = (_DWORD *)*v13;
      j__free(v13);
      v13 = v14;
    }
    while ( v14 != (_DWORD *)this[5] );
  }
  v15 = (_DWORD *)this[8];
  v16 = (_DWORD *)*v15;
  if ( (_DWORD *)*v15 != v15 )
  {
    do
    {
      v17 = (void (__thiscall ***)(_DWORD, int))v16[2];
      if ( v17 )
        (**v17)(v17, 1);
      v16 = (_DWORD *)*v16;
    }
    while ( v16 != (_DWORD *)this[8] );
  }
  v18 = (_DWORD **)this[8];
  result = *v18;
  *v18 = v18;
  *(_DWORD *)(this[8] + 4) = this[8];
  v7 = result == (_DWORD *)this[8];
  this[9] = 0;
  if ( !v7 )
  {
    do
    {
      v20 = (_DWORD *)*result;
      j__free(result);
      result = v20;
    }
    while ( v20 != (_DWORD *)this[8] );
  }
  return result;
}
