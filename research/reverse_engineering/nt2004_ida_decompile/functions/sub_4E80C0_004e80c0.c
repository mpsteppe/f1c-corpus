int __thiscall sub_4E80C0(_DWORD *this, _DWORD *a2, int a3)
{
  _DWORD **v4; // eax
  _DWORD *v5; // ebp
  int v6; // eax
  int v7; // esi
  int v8; // ebx
  int v9; // eax
  _DWORD **v10; // eax
  int v12; // esi
  int v13; // eax

  if ( *a2 )
  {
    if ( a3 > 0 )
    {
      v4 = (_DWORD **)this[2];
      this[4] = v4;
      if ( v4 )
      {
        v5 = *v4;
        if ( *v4 )
        {
          do
          {
            v6 = this[4];
            if ( v6 )
              this[4] = *(_DWORD *)(v6 + 4);
            v7 = 0;
            v8 = dword_7D6A5C + 1232 * *v5 + 630;
            while ( !sub_579060(v8, a2[v7]) )
            {
              if ( ++v7 >= a3 )
              {
                v9 = this[4];
                if ( v9 )
                  this[4] = *(_DWORD *)(v9 + 4);
                v10 = (_DWORD **)this[4];
                goto LABEL_14;
              }
            }
            v12 = this[2];
            v13 = 0;
            if ( v12 )
            {
              while ( *(_DWORD **)v12 != v5 )
              {
                v13 = v12;
                v12 = *(_DWORD *)(v12 + 4);
                if ( !v12 )
                {
                  v10 = (_DWORD **)this[2];
                  this[4] = v10;
                  goto LABEL_14;
                }
              }
              if ( v12 == this[4] )
                this[4] = *(_DWORD *)(v12 + 4);
              if ( v13 )
                *(_DWORD *)(v13 + 4) = *(_DWORD *)(v12 + 4);
              else
                this[2] = *(_DWORD *)(v12 + 4);
              if ( this[3] == v12 )
                this[3] = v13;
              --this[5];
              if ( *(_BYTE *)(v12 + 8) )
                sub_5BE8AE(*(LPVOID *)v12);
              sub_5BE8AE((LPVOID)v12);
            }
            v10 = (_DWORD **)this[2];
            this[4] = v10;
LABEL_14:
            if ( !v10 )
              break;
            v5 = *v10;
          }
          while ( *v10 );
        }
      }
    }
  }
  return this[5];
}
