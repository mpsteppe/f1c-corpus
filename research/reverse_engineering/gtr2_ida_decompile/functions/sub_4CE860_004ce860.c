int __thiscall sub_4CE860(int this, char a2)
{
  _BYTE *v2; // eax
  int result; // eax

  if ( a2 && *(_BYTE *)(this + 271) )
  {
    v2 = *(_BYTE **)(this + 796);
    *(_DWORD *)(this + 800) = v2;
    *v2 = 0;
    result = strlen((const char *)(this + 531));
    if ( result )
      return sub_4CE770((_DWORD *)this, (const char *)(this + 531));
  }
  else
  {
    result = strlen(*(const char **)(this + 796));
    *(_DWORD *)(this + 800) = result + *(_DWORD *)(this + 796);
  }
  return result;
}
