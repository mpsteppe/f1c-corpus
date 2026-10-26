_DWORD *__thiscall sub_5DA8C0(_DWORD *this, int a2, int a3)
{
  _DWORD *v4; // eax
  int v5; // eax
  _DWORD *v6; // eax
  _DWORD *result; // eax
  int v8; // ecx

  if ( (_BYTE)a3 )
  {
    v4 = (_DWORD *)this[157];
    this[159] = v4;
    if ( v4 )
    {
      if ( *v4 )
      {
        do
        {
          sub_5DA8C0(a2, a3);
          v5 = this[159];
          if ( !v5 )
            break;
          v6 = *(_DWORD **)(v5 + 4);
          this[159] = v6;
          if ( !v6 )
            break;
        }
        while ( *v6 );
      }
    }
  }
  result = (_DWORD *)this[133];
  this[135] = result;
  if ( result )
  {
    for ( result = (_DWORD *)*result; result; result = (_DWORD *)*result )
    {
      v8 = result[116];
      if ( v8 )
      {
        if ( (_BYTE)a2 )
          sub_5FF0C0(v8);
        else
          sub_5FF0D0();
      }
      result = (_DWORD *)this[135];
      if ( !result )
        break;
      result = (_DWORD *)result[1];
      this[135] = result;
      if ( !result )
        break;
    }
  }
  return result;
}
