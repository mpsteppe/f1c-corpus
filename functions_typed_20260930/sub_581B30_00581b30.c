void __thiscall sub_581B30(int this)
{
  _DWORD *v1; // edi
  _DWORD *v2; // ebp
  _DWORD *v3; // esi
  _DWORD *v4; // edi
  _DWORD *v5; // esi
  _BYTE *v6; // ebp
  _DWORD *v7; // edi

  v1 = (_DWORD *)this;
  if ( *(_BYTE *)(this + 40) && CloseHandle(*(HANDLE *)(this + 32)) )
    v1[8] = 0;
  v2 = v1 + 4;
  v3 = (_DWORD *)v1[4];
  if ( v3 )
  {
    do
    {
      v4 = v3;
      v3 = (_DWORD *)v3[1];
      if ( *((_BYTE *)v4 + 8) && *v4 )
        (**(void (__thiscall ***)(_DWORD, int))*v4)(*v4, 1);
      FreeWrapper_7bcf(v4);
    }
    while ( v3 );
    v1 = (_DWORD *)this;
  }
  *v2 = 0;
  v2[1] = 0;
  v2[2] = 0;
  v2[3] = 0;
  v5 = (_DWORD *)*v1;
  if ( *v1 )
  {
    do
    {
      v6 = v5;
      v5 = (_DWORD *)v5[1];
      if ( v6[8] )
      {
        v7 = *(_DWORD **)v6;
        if ( *(_DWORD *)v6 )
        {
          if ( *v7 )
            (**(void (__thiscall ***)(_DWORD, int))*v7)(*v7, 3);
          FreeWrapper_7bcf(v7);
        }
        v1 = (_DWORD *)this;
      }
      FreeWrapper_7bcf(v6);
    }
    while ( v5 );
  }
  *v1 = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[3] = 0;
}

