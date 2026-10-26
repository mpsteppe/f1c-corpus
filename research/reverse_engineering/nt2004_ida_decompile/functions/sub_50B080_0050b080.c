int __thiscall sub_50B080(_DWORD *this, char *String2, char *a3)
{
  int result; // eax
  int i; // esi
  char String1[32]; // [esp+8h] [ebp-20h] BYREF

  result = this[1];
  this[628] = 0;
  this[629] = 0;
  if ( result )
  {
    for ( i = *(_DWORD *)(result + 68); i; i = *(_DWORD *)(i + 76) )
    {
      sub_59EA30(String1);
      if ( !_strcmpi(String1, String2) )
        this[628] = i;
      result = _strcmpi(String1, a3);
      if ( !result )
        this[629] = i;
    }
  }
  return result;
}
