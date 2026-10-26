int *__thiscall sub_4AC980(_DWORD *this)
{
  int v2; // esi
  int v3; // ebx
  LPVOID *v4; // edi
  int *result; // eax
  int i; // edi
  _DWORD *j; // esi
  int k; // edi
  _DWORD *m; // esi

  v2 = this[83];
  v3 = 0;
  while ( v2 )
  {
    sub_4B0930(0);
    if ( *(_BYTE *)(v2 + 36) )
    {
      v4 = (LPVOID *)v2;
      if ( v3 )
        *(_DWORD *)(v3 + 40) = *(_DWORD *)(v2 + 40);
      else
        this[83] = *(_DWORD *)(v2 + 40);
      v2 = *(_DWORD *)(v2 + 40);
      sub_4B0930(1);
      if ( *v4 )
        sub_5BE8AE(*v4);
      sub_5BE8AE(v4);
    }
    else
    {
      v3 = v2;
      v2 = *(_DWORD *)(v2 + 40);
    }
  }
  result = (int *)this[1];
  this[3] = result;
  if ( result )
  {
    for ( i = *result; *result; i = *result )
    {
      for ( j = *(_DWORD **)(i + 64); j; j = (_DWORD *)j[35] )
        sub_49D6E0(j);
      for ( k = *(_DWORD *)(i + 60); k; k = *(_DWORD *)(k + 56) )
      {
        sub_4AF5B0(k);
        for ( m = *(_DWORD **)(k + 52); m; m = (_DWORD *)m[35] )
          sub_49D6E0(m);
      }
      result = (int *)this[3];
      if ( !result )
        break;
      result = (int *)result[1];
      this[3] = result;
      if ( !result )
        break;
    }
  }
  return result;
}
