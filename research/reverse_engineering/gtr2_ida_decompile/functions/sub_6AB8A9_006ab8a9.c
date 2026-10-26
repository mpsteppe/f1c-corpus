int __thiscall sub_6AB8A9(_DWORD *this, int a2, unsigned int a3, unsigned int a4, _DWORD *a5)
{
  _DWORD *v5; // edi
  unsigned int v6; // esi
  unsigned int i; // ecx
  int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // ebx
  _DWORD *v11; // edi
  _DWORD *v12; // esi
  int v13; // eax
  _DWORD *v14; // eax
  unsigned int v15; // eax
  int v16; // eax
  int v17; // edx
  int v18; // ecx
  _DWORD *v19; // eax
  int v21; // [esp+8h] [ebp-20h]
  int v22; // [esp+Ch] [ebp-1Ch]
  unsigned int v23; // [esp+10h] [ebp-18h]
  int v24; // [esp+14h] [ebp-14h]
  int v25; // [esp+14h] [ebp-14h]
  int v26; // [esp+18h] [ebp-10h]
  int v27; // [esp+1Ch] [ebp-Ch]
  int *v28; // [esp+20h] [ebp-8h]
  _DWORD *v30; // [esp+34h] [ebp+Ch]
  unsigned int j; // [esp+34h] [ebp+Ch]

  v5 = a5;
  if ( a5 )
    *a5 = 0;
  v6 = a4;
  if ( a4 )
  {
    if ( !a5 )
    {
      for ( i = a3; i < a4; ++i )
      {
        v8 = *(_DWORD *)(a2 + 4 * i);
        if ( v8 )
          *(_DWORD *)(v8 + 36) = 0;
      }
    }
    v9 = a4 - 1;
    v10 = a3;
    if ( a3 < a4 - 1 )
    {
      while ( 1 )
      {
        v11 = *(_DWORD **)(a2 + 4 * v10);
        if ( v11 )
          break;
LABEL_63:
        ++v10;
        v9 = v6 - 1;
        if ( v10 >= v6 - 1 )
        {
          v5 = a5;
          goto LABEL_65;
        }
      }
      v12 = 0;
      if ( a5 )
        ++*a5;
      do
      {
        if ( v10 >= v9 )
          break;
        ++v10;
        v12 = *(_DWORD **)(a2 + 4 * v10);
      }
      while ( !v12 );
      v22 = 0;
      v23 = --v10;
      if ( v12 )
      {
        v21 = 0;
        if ( !a5 )
        {
          v11[9] = 0;
          v12[9] = 0;
        }
        v13 = *v11 & 0xFFFFF;
        if ( v13 == 1 && (*v12 & 0xFFFFFu) < 4 )
        {
          v14 = v11;
          v11 = v12;
          v12 = v14;
          v21 = 1;
LABEL_23:
          if ( (unsigned __int16)this[50] == 260
            || !(*(int (__thiscall **)(_DWORD *, _DWORD *, _DWORD *))(*this + 164))(this, v11, v12) )
          {
            v15 = *v11 & 0xFFF00000;
            if ( v15 != 1913651200
              && v15 != 1912602624
              && v15 != 1615855616
              && v15 != 1621098496
              && v15 != 1610612736
              && v15 != 1626341376
              && v15 != 285212672
              && v15 )
            {
              v27 = 0;
              if ( v11[3] )
              {
                v16 = this[5];
                v28 = (int *)v11[4];
                v24 = v11[3];
                do
                {
                  v17 = *v28;
                  if ( *(_DWORD *)(*(_DWORD *)(v16 + 4 * *v28) + 16) == 3 )
                    v22 = 1;
                  if ( v12[1] )
                  {
                    v30 = (_DWORD *)v12[2];
                    v26 = v12[1];
                    do
                    {
                      if ( *(_DWORD *)(*(_DWORD *)(v16 + 4 * *v30) + 56) == v17 || *v30 == v17 )
                        v27 = 1;
                      ++v30;
                      --v26;
                    }
                    while ( v26 );
                    v10 = v23;
                  }
                  ++v28;
                  --v24;
                }
                while ( v24 );
              }
              for ( j = 0; j < v12[3]; ++j )
              {
                if ( v11[1] )
                {
                  v18 = *(_DWORD *)(v12[4] + 4 * j);
                  v19 = (_DWORD *)v11[2];
                  v25 = v11[1];
                  do
                  {
                    if ( *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v19) + 56) == v18 || *v19 == v18 )
                      v27 = 1;
                    ++v19;
                    --v25;
                  }
                  while ( v25 );
                  v10 = v23;
                }
              }
              if ( !v27 && !v22 && *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)v12[4]) + 16) == 3 )
              {
                if ( !a5 )
                {
                  if ( v21 )
                    v11[9] = 1;
                  else
                    v12[9] = 1;
                }
                ++v10;
              }
            }
          }
          goto LABEL_62;
        }
        if ( v13 != 4 && (*v12 & 0xFFFFF) == 1 )
          goto LABEL_23;
      }
LABEL_62:
      v6 = a4;
      goto LABEL_63;
    }
LABEL_65:
    if ( v10 != v6 && v5 )
      ++*v5;
  }
  return 0;
}
