int __thiscall sub_411F40(_DWORD *this, char *String1)
{
  int result; // eax
  unsigned __int8 v4; // bl
  int v5; // ecx
  const char ***v6; // eax
  const char **v7; // ebp
  const char *v8; // eax
  int v9; // esi
  int *v10; // eax
  int i; // eax
  int *v12; // ecx
  _BYTE *v13; // eax
  int v14; // edx
  int v15; // eax
  int *v16; // eax
  unsigned __int8 v17; // bl
  int v18; // ebx
  _BYTE *v19; // ebp
  const char *v20; // ecx
  unsigned __int8 v21; // [esp+10h] [ebp-154h]
  unsigned __int8 v22; // [esp+10h] [ebp-154h]
  int v23; // [esp+14h] [ebp-150h] BYREF
  __int16 v24; // [esp+18h] [ebp-14Ch]
  const char **v25; // [esp+1Ch] [ebp-148h]
  char v26[64]; // [esp+24h] [ebp-140h] BYREF
  char Destination[253]; // [esp+64h] [ebp-100h] BYREF
  __int16 v28; // [esp+161h] [ebp-3h]
  char v29; // [esp+163h] [ebp-1h]

  result = this[14];
  v4 = 0;
  if ( result <= 0 )
    return result;
  v5 = 0;
  while ( 1 )
  {
    if ( v5 >= this[14] )
      goto LABEL_8;
    v6 = (const char ***)this[11];
    if ( v5 > 0 )
    {
      while ( v6 )
      {
        v6 = (const char ***)v6[1];
        if ( --v5 <= 0 )
          goto LABEL_7;
      }
LABEL_8:
      v7 = 0;
      v25 = 0;
      goto LABEL_10;
    }
LABEL_7:
    if ( !v6 )
      goto LABEL_8;
    v25 = *v6;
    v7 = v25;
LABEL_10:
    v8 = *v7;
    if ( !*v7 )
      v8 = &byte_629120;
    if ( !_strcmpi(String1, v8) )
      break;
    result = this[14];
    v5 = ++v4;
    if ( v4 >= result )
      return result;
  }
  v9 = (int)v7[2];
  result = sub_410460(this);
  if ( v9 <= (unsigned int)result )
  {
    v10 = (int *)this[3];
    v23 = 16843009;
    v24 = 257;
    this[5] = v10;
    if ( v10 )
    {
      for ( i = *v10; i; i = *v16 )
      {
        v12 = &v23;
        v13 = (_BYTE *)(i + 15);
        v14 = 6;
        do
        {
          if ( *v13 )
            *(_BYTE *)v12 = 0;
          ++v13;
          v12 = (int *)((char *)v12 + 1);
          --v14;
        }
        while ( v14 );
        v15 = this[5];
        if ( !v15 )
          break;
        v16 = *(int **)(v15 + 4);
        this[5] = v16;
        if ( !v16 )
          break;
      }
    }
    v17 = 0;
    v21 = 0;
    while ( 1 )
    {
      result = v17;
      if ( *((_BYTE *)&v23 + v17) )
      {
        *((_BYTE *)v7 + v17 + 15) = 1;
        result = sub_410560(v21);
        v9 -= result;
        if ( v9 <= 0 )
          break;
      }
      v21 = ++v17;
      if ( v17 >= 6u )
      {
        if ( v9 > 0 )
          return result;
        break;
      }
    }
    Destination[0] = byte_629120;
    memset(&Destination[1], 0, 0xFCu);
    v28 = 0;
    v29 = 0;
    result = (int)v7 + 15;
    v22 = 0;
    v18 = 0;
    v23 = (int)v7 + 15;
    v19 = (char *)v7 + 15;
    do
    {
      if ( *v19 )
      {
        (*(void (__thiscall **)(int, char *, int, unsigned __int8))(*(_DWORD *)dword_76BB24 + 4))(
          dword_76BB24,
          v26,
          63,
          v22);
        v20 = *v25;
        if ( !*v25 )
          v20 = &byte_629120;
        strcpy(Destination, v20);
        sub_473E40(Destination);
        strcat(Destination, v26);
        sub_4ED870(Destination, v18);
        result = v23;
      }
      ++v18;
      ++v19;
      ++v22;
    }
    while ( v22 < 6u );
    *(_DWORD *)result = 0;
    *(_WORD *)(result + 4) = 0;
  }
  return result;
}
