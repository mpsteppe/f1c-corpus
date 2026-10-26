int __thiscall sub_475350(void *this)
{
  int result; // eax

  sub_4CDC80(0);
  result = sub_4A50D0(this);
  if ( result )
  {
    result = (*(int (__thiscall **)(int))(*(_DWORD *)result + 28))(result);
    if ( result || strlen(0) )
      return sub_4CD9C0(result, 0);
  }
  return result;
}
