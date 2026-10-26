// f1c  0x004c5cb0  size=115
_DWORD *__thiscall sub_4C5CB0(_DWORD *this)
{
  _DWORD *result; // eax
  int v3; // edi
  int v4; // esi
  int v5; // esi
  char *v6; // eax

  this[3] = 0x7FFFFFFF;
  sub_568210(aSceneorder);
  result = (_DWORD *)dword_8AC490;
  v3 = 0;
  v4 = dword_8AC490 + 396 * *this;
  if ( v4 )
  {
    result = (_DWORD *)sub_5679A0(0);
    if ( result )
    {
      v5 = v4 + 260;
      while ( 1 )
      {
        v6 = sub_499E20(result);
        result = (_DWORD *)sub_588410(v6, v5);
        if ( !result )
          break;
        result = (_DWORD *)sub_5679A0(++v3);
        if ( !result )
          return result;
      }
      this[3] = v3;
    }
  }
  return result;
}
