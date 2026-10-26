int __thiscall sub_4C6150(_DWORD *this, _DWORD *a2, int a3)
{
  _DWORD **v4; // eax
  _DWORD *v5; // ebp
  int v6; // edx
  int v7; // esi
  int v8; // eax
  _DWORD **v9; // eax
  _DWORD *v11; // esi
  _DWORD *v12; // eax
  LPVOID *v13; // edi
  _BYTE v14[253]; // [esp+10h] [ebp-100h] BYREF
  __int16 v15; // [esp+10Dh] [ebp-3h]
  char v16; // [esp+10Fh] [ebp-1h]

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
            v6 = dword_8AC490 + 396 * *v5;
            if ( !v6
              || (v14[0] = byte_5EA438[0],
                  memset(&v14[1], 0, 0xFCu),
                  v15 = 0,
                  v16 = 0,
                  StringCopyWithValidation((int)v14, 256, (int)aFilterProperti, v6 + 260)) )
            {
LABEL_10:
              v8 = this[4];
              if ( v8 )
                this[4] = *(_DWORD *)(v8 + 4);
              v9 = (_DWORD **)this[4];
            }
            else
            {
              v7 = 0;
              while ( !sub_566810(v14, a2[v7]) )
              {
                if ( ++v7 >= a3 )
                  goto LABEL_10;
              }
              v11 = (_DWORD *)this[2];
              v12 = 0;
              if ( v11 )
              {
                while ( (_DWORD *)*v11 != v5 )
                {
                  v12 = v11;
                  v11 = (_DWORD *)v11[1];
                  if ( !v11 )
                  {
                    v9 = (_DWORD **)this[2];
                    this[4] = v9;
                    goto LABEL_13;
                  }
                }
                if ( v11 == (_DWORD *)this[4] )
                  this[4] = v11[1];
                if ( v12 )
                  v12[1] = v11[1];
                else
                  this[2] = v11[1];
                if ( (_DWORD *)this[3] == v11 )
                  this[3] = v12;
                --this[5];
                if ( *((_BYTE *)v11 + 8) )
                {
                  v13 = (LPVOID *)*v11;
                  if ( *v11 )
                  {
                    ShortComputation_4370(v13 + 1);
                    FreeWrapper_7bcf(v13);
                  }
                }
                FreeWrapper_7bcf(v11);
              }
              v9 = (_DWORD **)this[2];
              this[4] = v9;
            }
LABEL_13:
            if ( !v9 )
              break;
            v5 = *v9;
          }
          while ( *v9 );
        }
      }
    }
  }
  return this[5];
}

