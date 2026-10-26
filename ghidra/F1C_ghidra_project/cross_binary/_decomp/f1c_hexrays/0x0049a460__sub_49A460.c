// f1c  0x0049a460  size=46
char *__thiscall sub_49A460(_DWORD *this, LPCSTR lpSrcStr)
{
  _DWORD *v3; // eax

  sub_589901(lpSrcStr);
  v3 = (_DWORD *)sub_49A360(this, lpSrcStr);
  if ( v3 )
    return sub_49A2D0(v3);
  else
    return 0;
}
