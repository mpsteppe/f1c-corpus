char __thiscall sub_56B060(int this, int a2)
{
  _DWORD *v3; // ecx
  int v5; // edi
  int v6; // ebp
  int v7; // edi
  int v8; // ebp
  _DWORD **v9; // eax
  _DWORD *v10; // ebp
  _DWORD *v11; // eax
  _DWORD *v12; // edi
  _DWORD *v13; // eax
  int v14; // edx
  int v15; // eax
  _DWORD **v16; // eax
  _DWORD **v17; // eax
  _DWORD *i; // edi
  _DWORD *v19; // ebp
  _DWORD *v20; // eax
  _DWORD *v21; // eax
  int v22; // ecx
  _DWORD *v23; // [esp+1Ch] [ebp+4h]

  v3 = (_DWORD *)a2;
  if ( !a2 )
    return 0;
  *(_BYTE *)(this + 4) = *(_BYTE *)(a2 + 4);
  v5 = *(_DWORD *)(this + 8);
  if ( v5 )
  {
    do
    {
      v6 = v5;
      v5 = *(_DWORD *)(v5 + 4);
      if ( *(_BYTE *)(v6 + 8) )
        sub_5BE8AE();
      sub_5BE8AE();
    }
    while ( v5 );
    v3 = (_DWORD *)a2;
  }
  *(_DWORD *)(this + 8) = 0;
  *(_DWORD *)(this + 12) = 0;
  *(_DWORD *)(this + 16) = 0;
  *(_DWORD *)(this + 20) = 0;
  v7 = *(_DWORD *)(this + 24);
  if ( v7 )
  {
    do
    {
      v8 = v7;
      v7 = *(_DWORD *)(v7 + 4);
      sub_4A82F0(v8);
      sub_5BE8AE();
    }
    while ( v7 );
    v3 = (_DWORD *)a2;
  }
  *(_DWORD *)(this + 24) = 0;
  *(_DWORD *)(this + 28) = 0;
  *(_DWORD *)(this + 32) = 0;
  *(_DWORD *)(this + 36) = 0;
  v9 = (_DWORD **)v3[2];
  v3[4] = v9;
  if ( v9 )
  {
    v10 = *v9;
    if ( *v9 )
    {
      do
      {
        v11 = operator new(0x10u);
        v12 = v11;
        if ( v11 )
        {
          *(_WORD *)v11 = 2;
          v11[1] = htonl(0);
          *((_WORD *)v12 + 1) = htons(0);
        }
        else
        {
          v12 = 0;
        }
        *v12 = *v10;
        v12[1] = v10[1];
        v12[2] = v10[2];
        v12[3] = v10[3];
        v13 = operator new(0xCu);
        if ( v13 )
        {
          *v13 = v12;
          v13[1] = 0;
          *((_BYTE *)v13 + 8) = 1;
        }
        else
        {
          v13 = 0;
        }
        if ( *(_DWORD *)(this + 8) )
        {
          *(_DWORD *)(*(_DWORD *)(this + 12) + 4) = v13;
        }
        else
        {
          *(_DWORD *)(this + 8) = v13;
          *(_DWORD *)(this + 16) = v13;
        }
        v14 = *(_DWORD *)(this + 20);
        *(_DWORD *)(this + 12) = v13;
        *(_DWORD *)(this + 20) = v14 + 1;
        v15 = *(_DWORD *)(a2 + 16);
        if ( !v15 )
          break;
        v16 = *(_DWORD ***)(v15 + 4);
        *(_DWORD *)(a2 + 16) = v16;
        if ( !v16 )
          break;
        v10 = *v16;
      }
      while ( *v16 );
      v3 = (_DWORD *)a2;
    }
  }
  v17 = (_DWORD **)v3[6];
  v23 = v3 + 6;
  v3[8] = v17;
  if ( v17 )
  {
    for ( i = *v17; i; i = (_DWORD *)sub_50EE10(v23) )
    {
      v19 = operator new(4u);
      *v19 = *i;
      v20 = operator new(0xCu);
      if ( v20 )
        v21 = sub_4DB610(v20, (int)v19, 1);
      else
        v21 = 0;
      if ( *(_DWORD *)(this + 24) )
      {
        *(_DWORD *)(*(_DWORD *)(this + 28) + 4) = v21;
      }
      else
      {
        *(_DWORD *)(this + 24) = v21;
        *(_DWORD *)(this + 32) = v21;
      }
      v22 = *(_DWORD *)(this + 36);
      *(_DWORD *)(this + 28) = v21;
      *(_DWORD *)(this + 36) = v22 + 1;
    }
  }
  return 1;
}
