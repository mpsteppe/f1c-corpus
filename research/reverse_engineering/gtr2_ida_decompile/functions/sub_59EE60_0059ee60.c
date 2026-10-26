char __thiscall sub_59EE60(int this, int a2)
{
  _DWORD *v5; // ebp
  _DWORD **v6; // eax
  _DWORD *v7; // edi
  _DWORD *v8; // eax
  _DWORD *v9; // esi
  _DWORD *v10; // eax
  int v11; // edx
  int v12; // eax
  _DWORD **v13; // eax
  _DWORD **v14; // eax
  _DWORD *v15; // edi
  _DWORD *v16; // esi
  _DWORD *v17; // eax
  int v18; // edx
  int v19; // eax
  _DWORD **v20; // eax
  _DWORD *v21; // [esp+Ch] [ebp+4h]

  if ( !a2 )
    return 0;
  v5 = (_DWORD *)(this + 8);
  *(_BYTE *)(this + 4) = *(_BYTE *)(a2 + 4);
  sub_525140((int *)(this + 8));
  v21 = (_DWORD *)(this + 24);
  sub_525140((int *)(this + 24));
  v6 = *(_DWORD ***)(a2 + 8);
  *(_DWORD *)(a2 + 16) = v6;
  if ( v6 )
  {
    v7 = *v6;
    if ( *v6 )
    {
      do
      {
        v8 = operator new(0x10u);
        v9 = v8;
        if ( v8 )
        {
          *(_WORD *)v8 = 2;
          v8[1] = htonl(0);
          *((_WORD *)v9 + 1) = htons(0);
        }
        else
        {
          v9 = 0;
        }
        *v9 = *v7;
        v9[1] = v7[1];
        v9[2] = v7[2];
        v9[3] = v7[3];
        v10 = operator new(0xCu);
        if ( v10 )
        {
          *v10 = v9;
          v10[1] = 0;
          *((_BYTE *)v10 + 8) = 1;
        }
        else
        {
          v10 = 0;
        }
        if ( *v5 )
        {
          *(_DWORD *)(v5[1] + 4) = v10;
        }
        else
        {
          *v5 = v10;
          v5[2] = v10;
        }
        v11 = v5[3] + 1;
        v5[1] = v10;
        v5[3] = v11;
        v12 = *(_DWORD *)(a2 + 16);
        if ( !v12 )
          break;
        v13 = *(_DWORD ***)(v12 + 4);
        *(_DWORD *)(a2 + 16) = v13;
        if ( !v13 )
          break;
        v7 = *v13;
      }
      while ( *v13 );
    }
  }
  v14 = *(_DWORD ***)(a2 + 24);
  *(_DWORD *)(a2 + 32) = v14;
  if ( v14 )
  {
    v15 = *v14;
    if ( *v14 )
    {
      do
      {
        v16 = operator new(4u);
        *v16 = *v15;
        v17 = operator new(0xCu);
        if ( v17 )
        {
          *v17 = v16;
          v17[1] = 0;
          *((_BYTE *)v17 + 8) = 1;
        }
        else
        {
          v17 = 0;
        }
        if ( *v21 )
        {
          *(_DWORD *)(v21[1] + 4) = v17;
        }
        else
        {
          *v21 = v17;
          v21[2] = v17;
        }
        v18 = v21[3] + 1;
        v21[1] = v17;
        v21[3] = v18;
        v19 = *(_DWORD *)(a2 + 32);
        if ( !v19 )
          break;
        v20 = *(_DWORD ***)(v19 + 4);
        *(_DWORD *)(a2 + 32) = v20;
        if ( !v20 )
          break;
        v15 = *v20;
      }
      while ( *v20 );
    }
  }
  return 1;
}
