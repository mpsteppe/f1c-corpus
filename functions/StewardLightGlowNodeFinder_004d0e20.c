int __thiscall sub_4D0E20(_DWORD *this, int a2, int a3)
{
  int v4; // eax
  int result; // eax

  v4 = EvaluateSceneNodeProperty(a2, 0);
  this[1] = v4;
  if ( !v4 && (unsigned __int8)StringSplitLoop(1, aDDevF119992002_3, 642) )
    DebugLogWrite(&dword_8AD25C, aCouldNotFindLi);
  result = EvaluateSceneNodeProperty(a3, 0);
  this[2] = result;
  if ( !result )
  {
    result = StringSplitLoop(1, aDDevF119992002_3, 645);
    if ( (_BYTE)result )
      return DebugLogWrite(&dword_8AD25C, aCouldNotFindGl);
  }
  return result;
}
