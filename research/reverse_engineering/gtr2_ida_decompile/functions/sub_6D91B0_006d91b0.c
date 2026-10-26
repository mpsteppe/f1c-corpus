int __stdcall sub_6D91B0(int a1)
{
  _DWORD *v1; // edi
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int result; // eax
  int v7; // ecx

  v1 = *(_DWORD **)(a1 + 340);
  v2 = v1[5];
  if ( v2 )
  {
    v3 = v2 - 1;
    if ( v3 )
    {
      if ( v3 != 1 )
      {
        v4 = *(_DWORD *)a1;
        *(_DWORD *)(v4 + 20) = 48;
        (*(void (__stdcall **)(int))v4)(a1);
        goto LABEL_18;
      }
    }
    else
    {
      sub_6D8F10();
      sub_6D8FF0((int *)a1);
      if ( *(_DWORD *)(a1 + 324) || !*(_DWORD *)(a1 + 332) || *(_DWORD *)(a1 + 180) )
      {
        (**(void (__stdcall ***)(int, int))(a1 + 372))(a1, 1);
        (**(void (__stdcall ***)(int, int))(a1 + 352))(a1, 2);
        v1[3] = 0;
        goto LABEL_18;
      }
      v5 = v1[6] + 1;
      v1[5] = 2;
      v1[6] = v5;
    }
    if ( !*(_DWORD *)(a1 + 184) )
    {
      sub_6D8F10();
      sub_6D8FF0((int *)a1);
    }
    (**(void (__stdcall ***)(int, _DWORD))(a1 + 372))(a1, 0);
    (**(void (__stdcall ***)(int, int))(a1 + 352))(a1, 2);
    if ( !v1[8] )
      (*(void (__stdcall **)(int))(*(_DWORD *)(a1 + 356) + 4))(a1);
    (*(void (__stdcall **)(int))(*(_DWORD *)(a1 + 356) + 8))(a1);
    v1[3] = 0;
  }
  else
  {
    sub_6D8F10();
    sub_6D8FF0((int *)a1);
    if ( !*(_DWORD *)(a1 + 176) )
    {
      (**(void (__stdcall ***)(int))(a1 + 360))(a1);
      (**(void (__stdcall ***)(int))(a1 + 364))(a1);
      (**(void (__stdcall ***)(int, _DWORD))(a1 + 348))(a1, 0);
    }
    (**(void (__stdcall ***)(int))(a1 + 368))(a1);
    (**(void (__stdcall ***)(int, _DWORD))(a1 + 372))(a1, *(_DWORD *)(a1 + 184));
    (**(void (__stdcall ***)(int, int))(a1 + 352))(a1, v1[7] <= 1 ? 0 : 3);
    (**(void (__stdcall ***)(int, _DWORD))(a1 + 344))(a1, 0);
    v1[3] = *(_DWORD *)(a1 + 184) == 0;
  }
LABEL_18:
  result = v1[6];
  v7 = *(_DWORD *)(a1 + 8);
  v1[4] = result == v1[7] - 1;
  if ( v7 )
  {
    *(_DWORD *)(v7 + 12) = result;
    result = v1[7];
    *(_DWORD *)(v7 + 16) = result;
  }
  return result;
}
