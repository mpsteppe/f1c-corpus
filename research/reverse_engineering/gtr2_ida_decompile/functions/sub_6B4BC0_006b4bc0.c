int __stdcall sub_6B4BC0(int *a1)
{
  _DWORD *v1; // edi
  int v2; // eax
  int v3; // eax
  int result; // eax
  int v5; // ecx
  int v6; // edx

  v1 = (_DWORD *)a1[106];
  if ( v1[2] )
  {
    v2 = *a1;
    *(_DWORD *)(v2 + 20) = 48;
    (*(void (__stdcall **)(int *))v2)(a1);
  }
  else
  {
    if ( a1[21] && !a1[34] )
    {
      if ( a1[23] && a1[27] )
      {
        a1[116] = v1[6];
        v1[2] = 1;
      }
      else if ( a1[25] )
      {
        a1[116] = v1[5];
      }
      else
      {
        v3 = *a1;
        *(_DWORD *)(v3 + 20) = 46;
        (*(void (__stdcall **)(int *))v3)(a1);
      }
    }
    (*(void (__stdcall **)(int *))a1[113])(a1);
    (*(void (__stdcall **)(int *))(a1[108] + 8))(a1);
    if ( !a1[17] )
    {
      if ( !v1[4] )
        (*(void (__stdcall **)(int *))a1[115])(a1);
      (*(void (__stdcall **)(int *))a1[114])(a1);
      if ( a1[21] )
        (*(void (__stdcall **)(int *, _DWORD))a1[116])(a1, v1[2]);
      (*(void (__stdcall **)(int *, int))a1[109])(a1, v1[2] != 0 ? 3 : 0);
      (*(void (__stdcall **)(int *, _DWORD))a1[107])(a1, 0);
    }
  }
  result = a1[2];
  if ( result )
  {
    *(_DWORD *)(result + 12) = v1[3];
    v5 = v1[3] + (v1[2] != 0) + 1;
    v6 = a1[16];
    *(_DWORD *)(result + 16) = v5;
    if ( v6 )
    {
      if ( !*(_DWORD *)(a1[110] + 20) )
        *(_DWORD *)(result + 16) = v5 + (a1[27] != 0) + 1;
    }
  }
  return result;
}
