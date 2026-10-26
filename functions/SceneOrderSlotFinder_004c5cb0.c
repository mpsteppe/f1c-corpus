_DWORD *__thiscall SceneOrderSlotFinder(_DWORD *this)
{
  _DWORD *result; // eax
  int v3; // edi
  int v4; // esi
  _BYTE *v5; // esi
  char *v6; // eax

  this[3] = 0x7FFFFFFF;
  AudioChannelStop(dword_8AD3B4, aSceneorder);
  result = (_DWORD *)dword_8AC490;
  v3 = 0;
  v4 = dword_8AC490 + 396 * *this;
  if ( v4 )
  {
    result = (_DWORD *)NullCheckWrapper(0);
    if ( result )
    {
      v5 = (_BYTE *)(v4 + 260);
      while ( 1 )
      {
        v6 = StringPointerAccessor(result);
        result = (_DWORD *)sub_588410(v6, v5);
        if ( !result )
          break;
        result = (_DWORD *)NullCheckWrapper(++v3);
        if ( !result )
          return result;
      }
      this[3] = v3;
    }
  }
  return result;
}
