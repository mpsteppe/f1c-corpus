char __thiscall sub_576460(int this)
{
  char result; // al

  result = *(_BYTE *)(this + 8);
  if ( result )
  {
    if ( *(_DWORD *)this )
    {
      sub_576830(*(void **)this);
      return sub_5BE8AE();
    }
  }
  return result;
}
