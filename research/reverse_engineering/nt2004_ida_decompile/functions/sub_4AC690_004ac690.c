int __thiscall sub_4AC690(_DWORD *this)
{
  int i; // eax
  int v3; // edi
  _DWORD *v4; // ebp
  bool v5; // zf
  int v6; // edi
  int v7; // ecx
  void (__thiscall **v8)(int, int); // edx
  int v9; // ebp
  LPVOID *v10; // edi
  _DWORD *v11; // edi
  void *v12; // ebp
  int *v13; // eax
  int v14; // edi
  int v15; // eax
  int *v16; // eax
  _BYTE v18[24]; // [esp+Ch] [ebp-18h] BYREF

  nullsub_6(this);
  sub_4AFAB0(v18);
  sub_4AFB50(this);
  for ( i = sub_4AFC50(v18); i; i = sub_4AFC50(v18) )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)i + 128))(i);
    sub_4AFB80(v18);
  }
  v3 = this[1];
  while ( v3 )
  {
    v4 = (_DWORD *)v3;
    v5 = *(_BYTE *)(v3 + 12) == 0;
    v3 = *(_DWORD *)(v3 + 4);
    if ( !v5 && *v4 )
      (**(void (__thiscall ***)(_DWORD, int))*v4)(*v4, 1);
    sub_5BE8AE(v4);
  }
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  v6 = this[7];
  while ( v6 )
  {
    v7 = v6;
    v8 = *(void (__thiscall ***)(int, int))v6;
    v6 = *(_DWORD *)(v6 + 140);
    (*v8)(v7, 1);
  }
  v9 = this[83];
  this[7] = 0;
  while ( v9 )
  {
    v10 = (LPVOID *)v9;
    v9 = *(_DWORD *)(v9 + 40);
    sub_4B0930(1);
    sub_4B0930(1);
    if ( *v10 )
      sub_5BE8AE(*v10);
    sub_5BE8AE(v10);
  }
  v11 = (_DWORD *)this[85];
  while ( v11 )
  {
    v12 = v11;
    v11 = (_DWORD *)v11[21];
    sub_4B0A70(v12);
    sub_5BE8AE(v12);
  }
  sub_4AE540(this);
  if ( this[43] )
  {
    sub_4AB330(this[43]);
    this[43] = 0;
  }
  if ( this[44] )
  {
    sub_4AB330(this[44]);
    this[44] = 0;
  }
  sub_451AC0(dword_762A38);
  v13 = (int *)this[78];
  this[80] = v13;
  if ( v13 )
  {
    v14 = *v13;
    if ( *v13 )
    {
      do
      {
        sub_4AB370(*(_DWORD *)(v14 + 8));
        *(_DWORD *)(v14 + 8) = 0;
        v15 = this[80];
        if ( !v15 )
          break;
        v16 = *(int **)(v15 + 4);
        this[80] = v16;
        if ( !v16 )
          break;
        v14 = *v16;
      }
      while ( *v16 );
    }
  }
  nullsub_6(v18);
  return 0;
}
