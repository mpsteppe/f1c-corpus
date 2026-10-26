_DWORD *__stdcall sub_5245B0(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v2; // ecx
  _DWORD *v3; // edx
  _DWORD *v4; // edi
  _DWORD *v5; // esi
  _DWORD *v6; // eax
  _DWORD *result; // eax

  v2 = a1;
  if ( !a1 )
    return a2;
  v3 = a2;
  if ( !a2 )
    return a1;
  if ( *(float *)(*a1 + 4) >= (double)*(float *)(*a2 + 4) )
  {
    v4 = a2;
    v5 = a2;
    v3 = (_DWORD *)a2[1];
  }
  else
  {
    v4 = a1;
    v5 = a1;
    v2 = (_DWORD *)a1[1];
  }
  if ( v2 )
  {
    while ( v3 )
    {
      if ( *(float *)(*v2 + 4) >= (double)*(float *)(*v3 + 4) )
      {
        v6 = v3;
        v3 = (_DWORD *)v3[1];
      }
      else
      {
        v6 = v2;
        v2 = (_DWORD *)v2[1];
      }
      v5[1] = v6;
      v5 = v6;
      if ( !v2 )
        goto LABEL_12;
    }
    result = v4;
    v5[1] = v2;
  }
  else
  {
LABEL_12:
    result = v4;
    if ( v3 )
      v5[1] = v3;
    else
      v5[1] = 0;
  }
  return result;
}
