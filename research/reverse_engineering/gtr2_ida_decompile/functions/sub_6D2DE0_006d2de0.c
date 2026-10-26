int __stdcall sub_6D2DE0(int a1)
{
  _DWORD *v1; // edi
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  bool v9; // cc
  _DWORD *v10; // eax
  int v11; // ecx
  int result; // eax

  v1 = (_DWORD *)(**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 64);
  v2 = *(_DWORD *)(a1 + 40) - 1;
  *(_DWORD *)(a1 + 460) = v1;
  *v1 = pfnAPC;
  switch ( v2 )
  {
    case 0:
      if ( *(_DWORD *)(a1 + 36) != 1 )
        goto LABEL_9;
      break;
    case 1:
    case 2:
      if ( *(_DWORD *)(a1 + 36) != 3 )
        goto LABEL_9;
      break;
    case 3:
    case 4:
      if ( *(_DWORD *)(a1 + 36) != 4 )
        goto LABEL_9;
      break;
    default:
      if ( *(int *)(a1 + 36) < 1 )
      {
LABEL_9:
        v3 = *(_DWORD *)a1;
        *(_DWORD *)(v3 + 20) = 10;
        (*(void (__cdecl **)(int))v3)(a1);
      }
      break;
  }
  if ( *(_DWORD *)(a1 + 44) == 1 )
  {
    v7 = *(_DWORD *)(a1 + 40);
    *(_DWORD *)(a1 + 120) = 1;
    if ( v7 != 1 && v7 != 3 )
    {
LABEL_34:
      v8 = *(_DWORD *)a1;
      *(_DWORD *)(v8 + 20) = 27;
      (*(void (__cdecl **)(int))v8)(a1);
      goto LABEL_38;
    }
    v9 = *(_DWORD *)(a1 + 36) <= 1;
    v1[1] = sub_6D2440;
    if ( !v9 )
    {
      v10 = (_DWORD *)(*(_DWORD *)(a1 + 220) + 132);
      v11 = *(_DWORD *)(a1 + 36) - 1;
      do
      {
        *v10 = 0;
        v10 += 21;
        --v11;
      }
      while ( v11 );
    }
  }
  else
  {
    if ( *(_DWORD *)(a1 + 44) != 2 )
    {
      if ( *(_DWORD *)(a1 + 44) == 4 )
      {
        v4 = *(_DWORD *)(a1 + 40);
        *(_DWORD *)(a1 + 120) = 4;
        if ( v4 == 5 )
        {
          v1[1] = sub_6D24D0;
          sub_6D2070(a1);
          goto LABEL_38;
        }
        if ( v4 == 4 )
        {
          v1[1] = sub_6D23B0;
          goto LABEL_38;
        }
      }
      else if ( *(_DWORD *)(a1 + 44) == *(_DWORD *)(a1 + 40) )
      {
        *(_DWORD *)(a1 + 120) = *(_DWORD *)(a1 + 36);
        v1[1] = sub_6D23B0;
        goto LABEL_38;
      }
      goto LABEL_34;
    }
    v5 = *(_DWORD *)(a1 + 40);
    *(_DWORD *)(a1 + 120) = 3;
    if ( v5 != 3 )
    {
      switch ( v5 )
      {
        case 1:
          v1[1] = sub_6D2470;
          goto LABEL_38;
        case 2:
          v1[1] = sub_6D23B0;
          goto LABEL_38;
        case 4:
          v1[1] = sub_6D2A30;
          sub_6D2610(a1);
          goto LABEL_38;
        case 5:
          v1[1] = sub_6D2BE0;
          sub_6D2070(a1);
          sub_6D2610(a1);
          goto LABEL_38;
      }
      goto LABEL_34;
    }
    v6 = *(_DWORD *)(a1 + 72);
    if ( v6 == 5 || v6 == 6 )
    {
      v1[1] = sub_6D2270;
      sub_6D2070(a1);
    }
    else
    {
      v1[1] = sub_6D2150;
      sub_6D2070(a1);
    }
  }
LABEL_38:
  result = *(_DWORD *)(a1 + 84);
  if ( result )
    return off_16C94D0(a1);
  *(_DWORD *)(a1 + 124) = *(_DWORD *)(a1 + 120);
  return result;
}
