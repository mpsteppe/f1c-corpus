// f1c  0x00486400  size=89
int __thiscall sub_486400(_DWORD *this, int a2)
{
  int result; // eax
  int v3; // edx

  result = this[36];
  v3 = result;
  if ( !result )
    return 0;
  if ( result == a2 )
  {
    this[36] = *(_DWORD *)(result + 140);
  }
  else
  {
    while ( 1 )
    {
      result = *(_DWORD *)(result + 140);
      if ( result == a2 )
        break;
      v3 = result;
      if ( !result )
        return 0;
    }
    *(_DWORD *)(v3 + 140) = *(_DWORD *)(result + 140);
  }
  *(_DWORD *)(result + 140) = 0;
  --this[37];
  return result;
}
