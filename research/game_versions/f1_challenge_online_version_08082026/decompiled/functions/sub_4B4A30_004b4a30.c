char __thiscall sub_4B4A30(char *this, _DWORD *a2)
{
  char result; // al
  int v4; // edi
  int v5; // ecx
  int v6; // esi
  char *v7; // ecx
  int v8; // edx
  int v9; // eax
  int v10; // eax

  result = 0;
  switch ( *a2 >> 29 )
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
  v5 = 16 * (v4 + 7);
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
      sub_587BCF(*(LPVOID *)v6);
    sub_587BCF((LPVOID)v6);
    sub_4B47A0((int)this, (unsigned __int8)*a2, 0, v4, (unsigned __int8)*a2);
    v10 = sub_587C03(12);
    if ( v10 )
    {
      *(_DWORD *)v10 = a2;
      *(_DWORD *)(v10 + 4) = 0;
      *(_BYTE *)(v10 + 8) = 0;
    }
    else
    {
      v10 = 0;
    }
    if ( dword_8AB700 )
    {
      *(_DWORD *)(v10 + 4) = dword_8AB700;
    }
    else
    {
      dword_8AB704 = v10;
      dword_8AB708 = v10;
    }
    dword_8AB700 = v10;
    ++dword_8AB70C;
    return 1;
  }
  return result;
}
