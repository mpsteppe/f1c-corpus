int __stdcall sub_6B51B0(int *a1)
{
  _DWORD *v1; // edi
  int result; // eax
  int v3; // ebx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax

  v1 = (_DWORD *)a1[110];
  if ( v1[5] )
    return 2;
  v3 = (*(int (__stdcall **)(int *))(a1[111] + 4))(a1);
  if ( v3 == 1 )
  {
    if ( v1[6] )
    {
      sub_6B4D60(a1);
      result = 1;
      v1[6] = 0;
      return result;
    }
    if ( !v1[4] )
    {
      v7 = *a1;
      *(_DWORD *)(v7 + 20) = 35;
      (*(void (__stdcall **)(int *))v7)(a1);
    }
    sub_6B5170((int)a1);
  }
  else if ( v3 == 2 )
  {
    v4 = v1[6];
    v1[5] = 1;
    if ( v4 )
    {
      if ( *(_DWORD *)(a1[111] + 16) )
      {
        v5 = *a1;
        *(_DWORD *)(v5 + 20) = 59;
        (*(void (__stdcall **)(int *))v5)(a1);
        return v3;
      }
    }
    else
    {
      v6 = a1[37];
      if ( a1[39] > v6 )
      {
        a1[39] = v6;
        return v3;
      }
    }
  }
  return v3;
}
