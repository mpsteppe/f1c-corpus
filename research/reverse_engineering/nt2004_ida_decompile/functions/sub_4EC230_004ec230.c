int *__thiscall sub_4EC230(_DWORD *this)
{
  int *result; // eax
  int i; // ebp
  int v4; // esi
  int v5; // eax
  void *v6; // ebx

  result = (int *)this[20];
  this[22] = result;
  if ( result )
  {
    for ( i = *result; *result; i = *result )
    {
      v4 = this[20];
      v5 = 0;
      if ( v4 )
      {
        while ( *(_DWORD *)v4 != i )
        {
          v5 = v4;
          v4 = *(_DWORD *)(v4 + 4);
          if ( !v4 )
            goto LABEL_18;
        }
        if ( v4 == this[22] )
          this[22] = *(_DWORD *)(v4 + 4);
        if ( v5 )
          *(_DWORD *)(v5 + 4) = *(_DWORD *)(v4 + 4);
        else
          this[20] = *(_DWORD *)(v4 + 4);
        if ( this[21] == v4 )
          this[21] = v5;
        --this[23];
        if ( *(_BYTE *)(v4 + 8) )
        {
          v6 = *(void **)v4;
          if ( *(_DWORD *)v4 )
          {
            j_nullsub_6(*(void **)v4);
            sub_5BE8AE(v6);
          }
        }
        sub_5BE8AE((LPVOID)v4);
      }
LABEL_18:
      sub_592750(i);
      result = (int *)this[20];
      this[22] = result;
      if ( !result )
        break;
    }
  }
  return result;
}
