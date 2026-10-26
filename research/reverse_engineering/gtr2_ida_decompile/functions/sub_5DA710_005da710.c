_DWORD *__thiscall sub_5DA710(_DWORD *this)
{
  int *v2; // eax
  int i; // eax
  int v4; // eax
  int *v5; // eax
  _DWORD *result; // eax

  v2 = (int *)this[157];
  this[159] = v2;
  if ( v2 )
  {
    for ( i = *v2; i; i = *v5 )
    {
      sub_5DA710(i);
      v4 = this[159];
      if ( !v4 )
        break;
      v5 = *(int **)(v4 + 4);
      this[159] = v5;
      if ( !v5 )
        break;
    }
  }
  result = (_DWORD *)this[133];
  this[135] = result;
  if ( result )
  {
    for ( result = (_DWORD *)*result; result; result = (_DWORD *)*result )
    {
      (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)dword_FB27A4 + 400))(dword_FB27A4, result);
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
