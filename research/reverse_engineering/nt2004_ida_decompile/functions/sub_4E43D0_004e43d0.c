char __thiscall sub_4E43D0(_DWORD *this, char *String1)
{
  char result; // al
  int v4; // eax
  int v5; // esi
  int v6; // ebx
  int v7; // eax
  const char *v8; // eax
  _DWORD *v9; // eax
  _DWORD *v10; // esi
  _DWORD *v11; // eax
  int v12; // [esp+4h] [ebp-4h]

  result = (char)String1;
  if ( String1 )
  {
    v4 = sub_57AE50(aSeasonraces);
    v5 = v4;
    v12 = v4;
    if ( v4 )
    {
      v6 = 0;
      if ( sub_57A6E0(v4) > 0 )
      {
        do
        {
          v7 = sub_57A700(v6);
          if ( v7 )
          {
            v8 = (const char *)sub_57A6C0(v7);
            if ( !_strcmpi(String1, v8) )
            {
              v9 = operator new(8u);
              v10 = v9;
              if ( v9 )
              {
                *v9 = 0;
                v9[1] = -1;
                sub_578600(String1);
                v11 = operator new(0xCu);
                if ( v11 )
                {
                  *v11 = v10;
                  v11[1] = 0;
                  *((_BYTE *)v11 + 8) = 1;
                }
                else
                {
                  v11 = 0;
                }
                if ( *this )
                {
                  *(_DWORD *)(this[1] + 4) = v11;
                }
                else
                {
                  *this = v11;
                  this[2] = v11;
                }
                this[1] = v11;
                ++this[3];
              }
              v5 = v12;
            }
          }
          ++v6;
        }
        while ( v6 < sub_57A6E0(v5) );
      }
    }
    return sub_4E4250((int)this);
  }
  return result;
}
