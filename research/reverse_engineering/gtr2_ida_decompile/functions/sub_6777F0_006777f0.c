int __stdcall sub_6777F0(int *a1)
{
  int v1; // ecx
  int v2; // eax
  int v3; // eax

  v1 = a1[5];
  if ( (v1 == 205 || v1 == 206) && !a1[16] )
  {
    if ( a1[35] < (unsigned int)a1[29] )
    {
      v2 = *a1;
      *(_DWORD *)(v2 + 20) = 67;
      (*(void (__stdcall **)(int *))v2)(a1);
    }
    (*(void (__stdcall **)(int *))(a1[106] + 4))(a1);
    a1[5] = 210;
  }
  else if ( v1 == 207 )
  {
    a1[5] = 210;
  }
  else if ( v1 != 210 )
  {
    v3 = *a1;
    *(_DWORD *)(v3 + 20) = 20;
    *(_DWORD *)(v3 + 24) = v1;
    (*(void (__stdcall **)(int *))v3)(a1);
  }
  if ( *(_DWORD *)(a1[110] + 20) )
  {
LABEL_14:
    (*(void (__stdcall **)(int *))(a1[6] + 24))(a1);
    sub_6B5EE0(a1);
    return 1;
  }
  else
  {
    while ( (*(int (__stdcall **)(int *))a1[110])(a1) )
    {
      if ( *(_DWORD *)(a1[110] + 20) )
        goto LABEL_14;
    }
    return 0;
  }
}
