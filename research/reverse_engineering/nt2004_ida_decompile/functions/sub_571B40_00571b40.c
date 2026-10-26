void __thiscall sub_571B40(int this)
{
  int *v1; // edi
  _DWORD *v2; // ebp
  int v3; // esi
  int v4; // edi
  int v5; // esi
  int v6; // ebp
  _DWORD *v7; // edi

  v1 = (int *)this;
  if ( *(_BYTE *)(this + 40) && CloseHandle(*(HANDLE *)(this + 32)) )
    v1[8] = 0;
  v2 = v1 + 4;
  v3 = v1[4];
  if ( v3 )
  {
    do
    {
      v4 = v3;
      v3 = *(_DWORD *)(v3 + 4);
      if ( *(_BYTE *)(v4 + 8) && *(_DWORD *)v4 )
        (***(void (__thiscall ****)(_DWORD, int))v4)(*(_DWORD *)v4, 1);
      sub_5BE8AE();
    }
    while ( v3 );
    v1 = (int *)this;
  }
  *v2 = 0;
  v2[1] = 0;
  v2[2] = 0;
  v2[3] = 0;
  v5 = *v1;
  while ( v5 )
  {
    v6 = v5;
    v5 = *(_DWORD *)(v5 + 4);
    if ( *(_BYTE *)(v6 + 8) )
    {
      v7 = *(_DWORD **)v6;
      if ( *(_DWORD *)v6 )
      {
        if ( *v7 )
          (**(void (__thiscall ***)(_DWORD, int))*v7)(*v7, 3);
        sub_5BE8AE();
      }
      v1 = (int *)this;
    }
    sub_5BE8AE();
  }
  *v1 = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[3] = 0;
}
