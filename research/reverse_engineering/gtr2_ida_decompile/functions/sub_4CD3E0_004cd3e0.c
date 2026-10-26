int __thiscall sub_4CD3E0(_DWORD *this, int a2)
{
  int result; // eax
  int v3; // edx

  result = this[36];
  v3 = result;
  if ( result )
  {
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
          return result;
      }
      *(_DWORD *)(v3 + 140) = *(_DWORD *)(result + 140);
    }
    *(_DWORD *)(result + 140) = 0;
    --this[37];
  }
  return result;
}
