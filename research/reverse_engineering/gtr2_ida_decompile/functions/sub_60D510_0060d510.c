void *sub_60D510()
{
  void *result; // eax
  unsigned int *v1; // ecx

  result = dword_FB28AC;
  dword_FB28B4 = (int)dword_FB28AC;
  if ( dword_FB28AC )
  {
    v1 = *(unsigned int **)dword_FB28AC;
    if ( *(_DWORD *)dword_FB28AC )
    {
      do
      {
        sub_5EDEE0(v1);
        result = (void *)dword_FB28B4;
        if ( !dword_FB28B4 )
          break;
        dword_FB28B4 = *(_DWORD *)(dword_FB28B4 + 4);
        result = (void *)dword_FB28B4;
        if ( !dword_FB28B4 )
          break;
        v1 = *(unsigned int **)dword_FB28B4;
      }
      while ( *(_DWORD *)dword_FB28B4 );
    }
  }
  return result;
}
