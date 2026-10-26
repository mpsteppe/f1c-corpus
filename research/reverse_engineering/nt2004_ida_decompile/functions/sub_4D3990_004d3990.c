char __thiscall sub_4D3990(char *this, _DWORD *a2)
{
  char result; // al
  int v4; // edi
  int v5; // ecx
  int v6; // esi
  char *v7; // ecx
  int v8; // edx
  int v9; // eax
  _DWORD *v10; // eax

  result = 0;
  switch ( *a2 >> 28 )
  {
    case 1:
      v4 = 0;
      break;
    case 2:
    case 3:
      v4 = 1;
      break;
    case 4:
      v4 = 2;
      break;
    case 6:
      v4 = 3;
      break;
    default:
      v4 = -1;
      break;
  }
  v5 = 16 * (v4 + 4);
  v6 = *(_DWORD *)&this[v5];
  v7 = &this[v5];
  v8 = 0;
  if ( v6 )
  {
    while ( *(_DWORD **)v6 != a2 )
    {
      v8 = v6;
      v6 = *(_DWORD *)(v6 + 4);
      if ( !v6 )
        return result;
    }
    if ( v6 == *((_DWORD *)v7 + 2) )
      *((_DWORD *)v7 + 2) = *(_DWORD *)(v6 + 4);
    v9 = *(_DWORD *)(v6 + 4);
    if ( v8 )
      *(_DWORD *)(v8 + 4) = v9;
    else
      *(_DWORD *)v7 = v9;
    if ( *((_DWORD *)v7 + 1) == v6 )
      *((_DWORD *)v7 + 1) = v8;
    --*((_DWORD *)v7 + 3);
    if ( *(_BYTE *)(v6 + 8) )
      sub_5BE8AE(*(LPVOID *)v6);
    sub_5BE8AE((LPVOID)v6);
    sub_4D3700((int)this, *a2 & 0x3F, 0, v4, *a2 & 0x3F);
    v10 = operator new(0xCu);
    if ( v10 )
    {
      *v10 = a2;
      v10[1] = 0;
      *((_BYTE *)v10 + 8) = 0;
    }
    else
    {
      v10 = 0;
    }
    if ( dword_7D5DC0 )
    {
      v10[1] = dword_7D5DC0;
    }
    else
    {
      dword_7D5DC4 = (int)v10;
      dword_7D5DC8 = (int)v10;
    }
    dword_7D5DC0 = (int)v10;
    ++dword_7D5DCC;
    return 1;
  }
  return result;
}
