_DWORD *__thiscall sub_417760(_DWORD *this, int a2, char a3)
{
  char *v3; // ecx
  int v4; // esi
  int *v5; // ebx
  int v6; // ebp
  int v7; // eax
  int v8; // edx
  int i; // edi
  int v10; // eax
  int v11; // edx
  int v12; // esi
  int *v13; // ebx
  int v14; // ebp
  _DWORD *result; // eax
  int v16; // edx

  v3 = (char *)&unk_920F30 + 22616 * a2;
  v4 = 160 * a2;
  v5 = (int *)(v3 + 464);
  v6 = 4;
  do
  {
    v7 = v4 + this[19];
    if ( a3 )
      v8 = *v5;
    else
      v8 = 0;
    switch ( *(_DWORD *)(v7 + 32) )
    {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
        *(_DWORD *)(*(_DWORD *)(v7 + 36) + 216) = v8;
        break;
      default:
        break;
    }
    v4 += 40;
    v5 += 74;
    --v6;
  }
  while ( v6 );
  for ( i = 0; i < 2; ++i )
  {
    v10 = this[22] + 40 * (i + 2 * a2);
    if ( a3 )
    {
      if ( i )
        v11 = *((_DWORD *)v3 + 429);
      else
        v11 = *((_DWORD *)v3 + 412);
    }
    else
    {
      v11 = 0;
    }
    switch ( *(_DWORD *)(v10 + 32) )
    {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
        *(_DWORD *)(*(_DWORD *)(v10 + 36) + 216) = v11;
        break;
      default:
        continue;
    }
  }
  v12 = 320 * a2;
  v13 = (int *)(v3 + 1784);
  v14 = 8;
  do
  {
    result = (_DWORD *)(v12 + this[25]);
    if ( a3 )
      v16 = *v13;
    else
      v16 = 0;
    switch ( result[8] )
    {
      case 0:
      case 2:
      case 4:
      case 6:
        result = (_DWORD *)result[9];
        result[54] = v16;
        break;
      case 1:
      case 3:
      case 5:
        *(_DWORD *)(result[9] + 216) = v16;
        break;
      default:
        break;
    }
    v12 += 40;
    v13 += 17;
    --v14;
  }
  while ( v14 );
  return result;
}
