int __thiscall sub_42F2D0(void *this)
{
  int result; // eax

  if ( (int)NumOfElements <= 0 )
  {
    if ( dword_5FD344 > 0 )
    {
      result = *((_DWORD *)off_5FD348 + 6312);
      *(_DWORD *)this = result;
    }
    else
    {
      *(_DWORD *)this = 49;
      return *(_DWORD *)this;
    }
  }
  else
  {
    *(_DWORD *)this = 0;
    return *(_DWORD *)(dword_75AAD0[0] + 25248);
  }
  return result;
}
