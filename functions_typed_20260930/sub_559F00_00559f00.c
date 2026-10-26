int __thiscall sub_559F00(_DWORD *this, int a2, _DWORD *a3, _DWORD *a4, _DWORD *a5, _DWORD *a6)
{
  int v7; // edi
  int v8; // eax
  _DWORD *v9; // esi
  int v10; // eax
  int v11; // eax
  int v12; // edx
  _DWORD *v13; // esi
  int v14; // eax
  int v15; // edx
  _DWORD *v16; // esi
  int v17; // eax
  int v18; // edx
  _DWORD *v19; // esi

  v7 = 0;
  if ( sub_559D80(this, a2) )
  {
    v8 = this[195];
    v9 = a3;
    v10 = v8 + 1;
    v7 = 1;
    a2 = v10;
    if ( a3 )
    {
      v11 = CallWrapperWith0(v10, &a2, 10);
      v12 = a2;
      *v9 = v11;
      v10 = v12 + 1;
    }
    v13 = a4;
    if ( a4 )
    {
      v14 = CallWrapperWith0(v10, &a2, 10);
      v15 = a2;
      *v13 = v14;
      v10 = v15 + 1;
    }
    v16 = a5;
    if ( a5 )
    {
      v17 = CallWrapperWith0(v10, &a2, 10);
      v18 = a2;
      *v16 = v17;
      v10 = v18 + 1;
    }
    v19 = a6;
    if ( a6 )
      *v19 = CallWrapperWith0(v10, &a2, 10);
  }
  return v7;
}

