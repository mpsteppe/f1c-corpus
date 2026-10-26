int __fastcall sub_562090(char *a1, int a2, _BYTE *a3)
{
  int v3; // esi
  int v4; // edi
  _BYTE *v5; // ebp
  int i; // eax
  char v7; // bl
  int j; // esi
  int result; // eax
  _BYTE v10[4]; // [esp+8h] [ebp-Ch]
  char *v11; // [esp+Ch] [ebp-8h]
  int v12; // [esp+10h] [ebp-4h]

  v3 = a2;
  v4 = 0;
  v12 = a2;
  v11 = a1;
  if ( a2 <= 0 )
  {
    result = (int)a3;
    *a3 = 0;
  }
  else
  {
    v5 = a3;
    while ( 1 )
    {
      for ( i = 0; i <= 2; ++i )
      {
        if ( v4 >= v3 )
        {
          *((_BYTE *)&a3 + i) = 0;
        }
        else
        {
          v7 = *a1++;
          *((_BYTE *)&a3 + i) = v7;
        }
        ++v4;
      }
      v11 = a1;
      v10[0] = (unsigned __int8)a3 >> 2;
      v10[1] = (BYTE1(a3) >> 4) + 16 * ((unsigned __int8)a3 & 3);
      v10[3] = BYTE2(a3) & 0x3F;
      v10[2] = (BYTE2(a3) >> 6) + 4 * (BYTE1(a3) & 0xF);
      for ( j = 0; j <= 3; ++j )
      {
        LOBYTE(a1) = v10[j];
        result = sub_564C40(a1);
        *v5++ = result;
      }
      v3 = v12;
      if ( v4 >= v12 )
        break;
      a1 = v11;
    }
    *v5 = 0;
  }
  return result;
}
