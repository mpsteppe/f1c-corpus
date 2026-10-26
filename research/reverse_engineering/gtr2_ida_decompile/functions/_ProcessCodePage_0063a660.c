int __thiscall ProcessCodePage(char *Str1)
{
  const char *v1; // esi
  int result; // eax
  _BYTE v3[8]; // [esp+4h] [ebp-Ch] BYREF
  int v4; // [esp+Ch] [ebp-4h]

  v1 = Str1;
  v4 = dword_912B08;
  if ( Str1 && *Str1 && strcmp(Str1, off_731CD0) )
  {
    if ( strcmp(v1, off_731CCC) )
      return atol(v1);
    result = dword_FB83D8(dword_FB83C0, 11, v3, 8);
  }
  else
  {
    result = dword_FB83D8(dword_FB83C0, 4100, v3, 8);
  }
  if ( !result )
    return result;
  v1 = v3;
  return atol(v1);
}
