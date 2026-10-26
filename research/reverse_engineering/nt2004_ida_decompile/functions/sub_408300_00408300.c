char __thiscall sub_408300(_DWORD *this, int *a2, int a3)
{
  char result; // al
  int v6; // eax
  bool v7; // zf
  int v8; // esi
  _DWORD **v9; // eax
  _DWORD *v10; // eax
  int v11; // eax
  _DWORD **v12; // eax
  _DWORD *v13; // eax
  _DWORD *v14; // esi
  FILE *v15; // eax
  _DWORD *v16; // eax
  char v17; // [esp+Fh] [ebp-9h]
  char v18; // [esp+1Ch] [ebp+4h]

  result = 0;
  v17 = 0;
  if ( a2 )
  {
    v6 = *a2;
    v7 = *a2 == 0;
    v18 = 0;
    if ( !v7 )
      sub_578600(v6);
    v8 = a2[1];
    if ( v8 )
      sub_578560(v8);
    v9 = (_DWORD **)this[14];
    this[16] = v9;
    if ( v9 )
    {
      v10 = *v9;
      if ( v10 )
      {
        while ( *v10 != a3 )
        {
          v11 = this[16];
          if ( v11 )
            this[16] = *(_DWORD *)(v11 + 4);
          v12 = (_DWORD **)this[16];
          if ( v12 )
          {
            v10 = *v12;
            if ( v10 )
              continue;
          }
          goto LABEL_15;
        }
        v18 = 1;
      }
    }
LABEL_15:
    if ( !_strcmpi(&byte_629120, &byte_629120) )
      return v17;
    if ( v18 )
      return v17;
    v13 = operator new(0x74u);
    if ( !v13 )
      return v17;
    v14 = sub_406090(v13);
    if ( !v14 )
      return v17;
    v15 = fopen(&byte_629120, aRb);
    v14[3] = v15;
    if ( v15 )
    {
      if ( !sub_408ED0(v14) )
      {
        v14[4] = _fileno((FILE *)v14[3]);
        *v14 = a3;
        sub_578600(&byte_629120);
        v16 = operator new(0xCu);
        if ( v16 )
        {
          *v16 = v14;
          v16[1] = 0;
          *((_BYTE *)v16 + 8) = 1;
        }
        else
        {
          v16 = 0;
        }
        if ( this[14] )
        {
          *(_DWORD *)(this[15] + 4) = v16;
        }
        else
        {
          this[14] = v16;
          this[16] = v16;
        }
        this[15] = v16;
        ++this[17];
        return 1;
      }
      fclose((FILE *)v14[3]);
      v14[3] = 0;
    }
    sub_4060C0(v14);
    sub_5BE8AE(v14);
    return v17;
  }
  return result;
}
