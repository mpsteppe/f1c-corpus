int __cdecl sub_559AFC(int a1)
{
  void (**v1)(); // edi
  int v2; // eax
  bool v3; // zf
  int result; // eax
  bool v5; // zf
  int v6; // eax
  int v7; // ecx

  v1 = (void (**)())(**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 24);
  *(_DWORD *)(a1 + 416) = v1;
  *v1 = nullsub_8;
  v2 = *(_DWORD *)(a1 + 36);
  if ( v2 == 1 )
  {
    v3 = *(_DWORD *)(a1 + 32) == 1;
LABEL_10:
    if ( v3 )
      goto LABEL_12;
    goto LABEL_11;
  }
  if ( v2 <= 1 )
    goto LABEL_7;
  if ( v2 <= 3 )
  {
    v3 = *(_DWORD *)(a1 + 32) == 3;
    goto LABEL_10;
  }
  if ( v2 <= 5 )
  {
    v3 = *(_DWORD *)(a1 + 32) == 4;
    goto LABEL_10;
  }
LABEL_7:
  if ( *(int *)(a1 + 32) >= 1 )
    goto LABEL_12;
LABEL_11:
  *(_DWORD *)(*(_DWORD *)a1 + 20) = 8;
  (**(void (__cdecl ***)(int))a1)(a1);
LABEL_12:
  if ( *(_DWORD *)(a1 + 40) != 1 )
  {
    if ( *(_DWORD *)(a1 + 40) == 2 )
    {
      result = *(_DWORD *)(a1 + 36);
      *(_DWORD *)(a1 + 100) = 3;
      if ( result == 3 )
      {
        v1[1] = (void (*)())sub_5598DE;
        goto LABEL_23;
      }
      v5 = result == 2;
    }
    else
    {
      if ( *(_DWORD *)(a1 + 40) != 4 )
      {
        if ( *(_DWORD *)(a1 + 40) == *(_DWORD *)(a1 + 36) )
        {
          result = *(_DWORD *)(a1 + 32);
          *(_DWORD *)(a1 + 100) = result;
LABEL_26:
          v1[1] = (void (*)())sub_5595E2;
          goto LABEL_32;
        }
LABEL_17:
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 25;
        result = (**(int (__cdecl ***)(int))a1)(a1);
        goto LABEL_32;
      }
      result = *(_DWORD *)(a1 + 36);
      *(_DWORD *)(a1 + 100) = 4;
      if ( result == 5 )
      {
        v1[1] = (void (*)())sub_559670;
LABEL_23:
        result = sub_559532(a1);
        goto LABEL_32;
      }
      v5 = result == 4;
    }
    if ( v5 )
      goto LABEL_26;
    goto LABEL_17;
  }
  v6 = *(_DWORD *)(a1 + 36);
  *(_DWORD *)(a1 + 100) = 1;
  if ( v6 != 1 && v6 != 3 )
    goto LABEL_17;
  v1[1] = (void (*)())sub_55964D;
  result = 1;
  if ( *(int *)(a1 + 32) > 1 )
  {
    v7 = 84;
    do
    {
      *(_BYTE *)(*(_DWORD *)(a1 + 196) + v7 + 48) = 0;
      ++result;
      v7 += 84;
    }
    while ( result < *(_DWORD *)(a1 + 32) );
  }
LABEL_32:
  if ( *(_BYTE *)(a1 + 74) )
  {
    *(_DWORD *)(a1 + 104) = 1;
  }
  else
  {
    result = *(_DWORD *)(a1 + 100);
    *(_DWORD *)(a1 + 104) = result;
  }
  return result;
}
