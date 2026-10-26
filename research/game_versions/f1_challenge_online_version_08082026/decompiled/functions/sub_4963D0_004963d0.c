int __thiscall sub_4963D0(_DWORD *this)
{
  int v2; // esi
  _DWORD *v3; // ebp
  char v4; // al
  int v5; // esi
  int v6; // ecx
  void (__thiscall **v7)(int, int); // edx
  int v8; // ebp
  int v9; // esi
  int v10; // eax
  _DWORD *v11; // esi
  void *v12; // ebp
  int *v13; // eax
  int v14; // esi
  int v15; // eax
  int *v16; // eax

  nullsub_3(this);
  v2 = this[1];
  while ( v2 )
  {
    v3 = (_DWORD *)v2;
    v4 = *(_BYTE *)(v2 + 12);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 && *v3 )
      (**(void (__thiscall ***)(_DWORD, int))*v3)(*v3, 1);
    sub_587BCF(v3);
  }
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  v5 = this[7];
  while ( v5 )
  {
    v6 = v5;
    v7 = *(void (__thiscall ***)(int, int))v5;
    v5 = *(_DWORD *)(v5 + 140);
    (*v7)(v6, 1);
  }
  v8 = this[65];
  this[7] = 0;
  while ( v8 )
  {
    v9 = v8;
    v10 = *(_DWORD *)(v8 + 12);
    v8 = *(_DWORD *)(v8 + 16);
    sub_494FD0(v10);
    *(_DWORD *)(v9 + 12) = 0;
    sub_414370((LPVOID *)(v9 + 4));
    sub_587BCF((LPVOID)v9);
  }
  v11 = (_DWORD *)this[67];
  while ( v11 )
  {
    v12 = v11;
    v11 = (_DWORD *)v11[21];
    sub_499AF0(v12);
    sub_587BCF(v12);
  }
  sub_494E60();
  if ( this[43] )
  {
    sub_494FD0(this[43]);
    this[43] = 0;
  }
  if ( this[44] )
  {
    sub_494FD0(this[44]);
    this[44] = 0;
  }
  sub_44F5F0(dword_7CB24C);
  v13 = (int *)this[60];
  this[62] = v13;
  if ( v13 )
  {
    v14 = *v13;
    if ( *v13 )
    {
      do
      {
        sub_495010(*(_DWORD *)(v14 + 8));
        *(_DWORD *)(v14 + 8) = 0;
        v15 = this[62];
        if ( !v15 )
          break;
        v16 = *(int **)(v15 + 4);
        this[62] = v16;
        if ( !v16 )
          break;
        v14 = *v16;
      }
      while ( *v16 );
    }
  }
  return 0;
}
