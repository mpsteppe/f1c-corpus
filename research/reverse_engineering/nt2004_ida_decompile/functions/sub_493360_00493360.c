_DWORD *__stdcall sub_493360(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v2; // esi
  _DWORD *v3; // edi
  _DWORD *v4; // ebp
  _DWORD *v5; // ebx
  _DWORD *v6; // eax
  _DWORD *result; // eax

  v2 = a1;
  if ( !a1 )
    return a2;
  v3 = a2;
  if ( !a2 )
    return a1;
  if ( sub_4A46C0(*a2) )
  {
    v4 = a1;
    v5 = a1;
    v2 = (_DWORD *)a1[1];
  }
  else
  {
    v4 = a2;
    v5 = a2;
    v3 = (_DWORD *)a2[1];
  }
  if ( v2 )
  {
    while ( v3 )
    {
      if ( sub_4A46C0(*v3) )
      {
        v6 = v2;
        v2 = (_DWORD *)v2[1];
      }
      else
      {
        v6 = v3;
        v3 = (_DWORD *)v3[1];
      }
      v5[1] = v6;
      v5 = v6;
      if ( !v2 )
        goto LABEL_12;
    }
    v5[1] = v2;
    return v4;
  }
  else
  {
LABEL_12:
    if ( v3 )
    {
      v5[1] = v3;
      return v4;
    }
    else
    {
      result = v4;
      v5[1] = 0;
    }
  }
  return result;
}
