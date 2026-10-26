// f1c  0x00497ec0  size=208
int __thiscall sub_497EC0(_DWORD *this, const char *a2)
{
  int v2; // ebp
  _BYTE *v5; // eax
  CHAR SrcStr[80]; // [esp+Ch] [ebp-50h] BYREF

  v2 = -1;
  if ( !a2 )
    return -1;
  if ( strlen(a2) )
  {
    strcpy(SrcStr, a2);
    sub_589901(SrcStr);
    if ( sub_497F90(SrcStr) )
      return -1;
    v2 = sub_495810(SrcStr);
    if ( !v2 )
    {
      v5 = (_BYTE *)sub_587C20(SrcStr, &word_5BEB48);
      if ( v5 )
        *v5 = 0;
      strcpy((char *)&this[20 * this[1349]++ + 69], SrcStr);
    }
  }
  return v2;
}
