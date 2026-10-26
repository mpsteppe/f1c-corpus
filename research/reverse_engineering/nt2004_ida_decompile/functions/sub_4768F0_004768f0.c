int __thiscall sub_4768F0(_DWORD *this, int a2)
{
  int result; // eax
  char *v4; // edx
  char v5; // cl
  char *v6; // eax
  char v7; // dl
  char *v8; // edi
  int v9; // ecx
  void *v10; // eax
  void *v11; // esi
  char v12[256]; // [esp+8h] [ebp-100h] BYREF

  result = dword_75AAD0[a2];
  if ( result )
  {
    result += 24992;
    if ( result )
    {
      v4 = &v12[-result];
      do
      {
        v5 = *(_BYTE *)result;
        v4[result] = *(_BYTE *)result;
        ++result;
      }
      while ( v5 );
      v6 = &v12[strlen(v12)];
      if ( v6 > v12 )
      {
        while ( *v6 != 46 )
        {
          if ( --v6 <= v12 )
            goto LABEL_10;
        }
        *v6 = 0;
      }
LABEL_10:
      v7 = byte_601470;
      v8 = &v12[strlen(v12) + 1];
      v9 = dword_60146C;
      *(_DWORD *)--v8 = dword_601468;
      *((_DWORD *)v8 + 1) = v9;
      v8[8] = v7;
      result = 0;
      if ( strlen(v12) )
      {
        v10 = operator new(0x28u);
        v11 = v10;
        if ( v10 )
          sub_506720(v10);
        else
          v11 = 0;
        if ( sub_506750(-1, v12, 0, 0, 0, 50, 50, 0, 0) )
        {
          result = sub_506920(v11);
        }
        else
        {
          sub_506980(50, 50);
          result = sub_5069D0(-1, -1, 1, 0);
        }
        if ( v11 )
        {
          result = (int)operator new(0xCu);
          if ( result )
          {
            *(_DWORD *)result = v11;
            *(_DWORD *)(result + 4) = 0;
            *(_BYTE *)(result + 8) = 1;
          }
          else
          {
            result = 0;
          }
          if ( this[104] )
          {
            *(_DWORD *)(this[105] + 4) = result;
          }
          else
          {
            this[104] = result;
            this[106] = result;
          }
          this[105] = result;
          ++this[107];
        }
      }
    }
  }
  return result;
}
