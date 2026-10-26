char __thiscall sub_4917C0(int *this)
{
  int v2; // esi
  int v3; // edx
  int v4; // edi
  _WORD **v5; // eax
  int *v6; // edi
  _WORD *v7; // ebx
  __int16 v8; // ax
  int v9; // esi
  int v10; // eax
  _WORD **v11; // eax
  int v12; // eax

  if ( (unsigned __int8)sub_4F9B20(&unk_8AFE18) )
    *(_DWORD *)(*this + 4) = (*(_DWORD *)(*this + 4) + 1) % *(_DWORD *)*this;
  ListIteratorFullDestruction(*this + 28);
  ListIteratorFullDestruction(*this + 44);
  v2 = *this;
  v3 = *(_DWORD *)(v2 + 8);
  v4 = 16 * *(_DWORD *)(v2 + 4);
  v5 = *(_WORD ***)(v4 + v3);
  v6 = (int *)(v3 + v4);
  v6[2] = (int)v5;
  if ( v5 )
  {
    v7 = *v5;
    if ( *v5 )
    {
      do
      {
        v8 = v7[4];
        if ( v8 < 3 )
        {
          v7[4] = v8 + 1;
          v12 = v6[2];
          if ( !v12 )
            return 1;
          v11 = *(_WORD ***)(v12 + 4);
          v6[2] = (int)v11;
        }
        else
        {
          v9 = *v6;
          v10 = 0;
          if ( *v6 )
          {
            while ( *(_WORD **)v9 != v7 )
            {
              v10 = v9;
              v9 = *(_DWORD *)(v9 + 4);
              if ( !v9 )
                goto LABEL_9;
            }
            if ( v9 == v6[2] )
              v6[2] = *(_DWORD *)(v9 + 4);
            if ( v10 )
              *(_DWORD *)(v10 + 4) = *(_DWORD *)(v9 + 4);
            else
              *v6 = *(_DWORD *)(v9 + 4);
            if ( v6[1] == v9 )
              v6[1] = v10;
            --v6[3];
            if ( *(_BYTE *)(v9 + 8) && *(_DWORD *)v9 )
              FreeWrapper_7bcf(*(LPVOID *)v9);
            FreeWrapper_7bcf((LPVOID)v9);
          }
LABEL_9:
          LinkedListNodePrepend(v7);
          v11 = (_WORD **)v6[2];
        }
        if ( !v11 )
          break;
        v7 = *v11;
      }
      while ( *v11 );
    }
  }
  return 1;
}

