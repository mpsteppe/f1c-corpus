_DWORD **__thiscall sub_4D5820(_DWORD *this)
{
  _DWORD **result; // eax
  _DWORD *i; // ebp
  int v4; // esi
  int v5; // eax
  int v6; // eax
  _DWORD *v7; // eax
  int v8; // ecx
  int v9; // edx

  result = (_DWORD **)this[233];
  this[235] = result;
  if ( result )
  {
    for ( i = *result; *result; i = *result )
    {
      v4 = this[233];
      if ( v4 )
      {
        while ( *(_DWORD **)v4 != i )
        {
          v4 = *(_DWORD *)(v4 + 4);
          if ( !v4 )
            goto LABEL_19;
        }
        if ( v4 == this[235] )
          this[235] = *(_DWORD *)(v4 + 4);
        v5 = *(_DWORD *)(v4 + 8);
        if ( v5 )
          *(_DWORD *)(v5 + 4) = *(_DWORD *)(v4 + 4);
        else
          this[233] = *(_DWORD *)(v4 + 4);
        v6 = *(_DWORD *)(v4 + 4);
        if ( v6 )
          *(_DWORD *)(v6 + 8) = *(_DWORD *)(v4 + 8);
        if ( this[234] == v4 )
          this[234] = *(_DWORD *)(v4 + 8);
        --this[236];
        if ( *(_BYTE *)(v4 + 12) )
          sub_5BE8AE(*(LPVOID *)v4);
        sub_5BE8AE((LPVOID)v4);
      }
LABEL_19:
      sub_4D33C0(i);
      v7 = operator new(0xCu);
      if ( v7 )
      {
        *v7 = i;
        v7[1] = 0;
        *((_BYTE *)v7 + 8) = 0;
      }
      else
      {
        v7 = 0;
      }
      v8 = this[12];
      if ( v8 )
      {
        v7[1] = v8;
      }
      else
      {
        this[13] = v7;
        this[14] = v7;
      }
      v9 = this[15] + 1;
      this[12] = v7;
      this[15] = v9;
      result = (_DWORD **)this[235];
      if ( !result )
        break;
    }
  }
  return result;
}
