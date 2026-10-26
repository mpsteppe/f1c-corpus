int __stdcall sub_6773E0(int a1)
{
  int v2; // ecx
  void (__stdcall **v3)(int); // eax
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // eax

  if ( *(_DWORD *)(a1 + 20) == 202 )
  {
    sub_6B4D20(a1);
    if ( *(_DWORD *)(a1 + 64) )
    {
      *(_DWORD *)(a1 + 20) = 207;
      return 1;
    }
    *(_DWORD *)(a1 + 20) = 203;
  }
  v2 = *(_DWORD *)(a1 + 20);
  if ( v2 == 203 )
  {
    if ( *(_DWORD *)(*(_DWORD *)(a1 + 440) + 16) )
    {
      while ( 1 )
      {
        v3 = *(void (__stdcall ***)(int))(a1 + 8);
        if ( v3 )
          (*v3)(a1);
        v4 = (**(int (__stdcall ***)(int))(a1 + 440))(a1);
        if ( !v4 )
          return 0;
        if ( v4 == 2 )
          goto LABEL_17;
        v5 = *(_DWORD *)(a1 + 8);
        if ( v5 && (v4 == 3 || v4 == 1) )
        {
          v6 = *(_DWORD *)(v5 + 4) + 1;
          *(_DWORD *)(v5 + 4) = v6;
          if ( v6 >= *(_DWORD *)(v5 + 8) )
            *(_DWORD *)(v5 + 8) += *(_DWORD *)(a1 + 324);
        }
      }
    }
    else
    {
LABEL_17:
      *(_DWORD *)(a1 + 156) = *(_DWORD *)(a1 + 148);
      return sub_6772E0((int *)a1);
    }
  }
  else
  {
    if ( v2 != 204 )
    {
      v7 = *(_DWORD *)a1;
      *(_DWORD *)(v7 + 20) = 20;
      *(_DWORD *)(v7 + 24) = v2;
      (*(void (__stdcall **)(int))v7)(a1);
    }
    return sub_6772E0((int *)a1);
  }
}
