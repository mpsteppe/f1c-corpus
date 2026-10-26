int __thiscall sub_501DD0(_DWORD *this)
{
  int v2; // esi
  _DWORD *v3; // edi
  bool v4; // zf
  int result; // eax
  int v6; // eax
  char *v7; // eax
  char *v8; // edx
  char v9; // cl
  char *v10; // eax
  char v11; // dl
  char *v12; // edi
  int v13; // ecx
  void *v14; // eax
  void *v15; // esi
  _DWORD *v16; // eax
  signed int i; // [esp+10h] [ebp-104h]
  char v18[256]; // [esp+14h] [ebp-100h] BYREF

  v2 = this[18];
  while ( v2 )
  {
    v3 = (_DWORD *)v2;
    v4 = *(_BYTE *)(v2 + 8) == 0;
    v2 = *(_DWORD *)(v2 + 4);
    if ( !v4 && *v3 )
      sub_502A10(1);
    sub_5BE8AE();
  }
  this[18] = 0;
  this[19] = 0;
  this[20] = 0;
  this[21] = 0;
  result = 0;
  for ( i = 0; i < (int)NumOfElements; ++i )
  {
    v6 = dword_75AAD0[result];
    if ( v6 )
    {
      v7 = (char *)(v6 + 24992);
      if ( v7 )
      {
        v8 = (char *)(v18 - v7);
        do
        {
          v9 = *v7;
          v7[(_DWORD)v8] = *v7;
          ++v7;
        }
        while ( v9 );
        v10 = &v18[strlen(v18)];
        if ( v10 > v18 )
        {
          while ( *v10 != 46 )
          {
            if ( --v10 <= v18 )
              goto LABEL_16;
          }
          *v10 = 0;
        }
LABEL_16:
        v11 = byte_601470;
        v12 = &v18[strlen(v18) + 1];
        v13 = dword_60146C;
        *(_DWORD *)--v12 = dword_601468;
        *((_DWORD *)v12 + 1) = v13;
        v12[8] = v11;
        if ( strlen(v18) )
        {
          v14 = operator new(0x28u);
          v15 = v14;
          if ( v14 )
            sub_506720(v14);
          else
            v15 = 0;
          if ( sub_506750(-1, v18, 0, 0, 0, 40, 40, 0, 0) )
            sub_506920(v15);
          if ( v15 )
          {
            v16 = operator new(0xCu);
            if ( v16 )
            {
              *v16 = v15;
              v16[1] = 0;
              *((_BYTE *)v16 + 8) = 1;
            }
            else
            {
              v16 = 0;
            }
            if ( this[18] )
            {
              *(_DWORD *)(this[19] + 4) = v16;
            }
            else
            {
              this[18] = v16;
              this[20] = v16;
            }
            this[19] = v16;
            ++this[21];
          }
        }
      }
    }
    result = i + 1;
  }
  return result;
}
