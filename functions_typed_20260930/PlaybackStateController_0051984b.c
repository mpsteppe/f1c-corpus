int __cdecl sub_51984B(_DWORD *a1, int a2)
{
  int v2; // esi
  int result; // eax

  v2 = a1[96];
  if ( a2 )
  {
    result = a2 - 2;
    if ( a2 == 2 )
    {
      *(_DWORD *)(v2 + 4) = RendererVtableDispatchWrapper;
    }
    else
    {
      *(_DWORD *)(*a1 + 20) = 4;
      return (*(int (__cdecl **)(_DWORD *))*a1)(a1);
    }
  }
  else
  {
    result = a1[103];
    if ( *(_BYTE *)(result + 8) )
    {
      *(_DWORD *)(v2 + 4) = AudioStreamBufferFill;
      result = TextureRowCopy(a1);
      *(_DWORD *)(v2 + 64) = 0;
      *(_DWORD *)(v2 + 68) = 0;
      *(_DWORD *)(v2 + 76) = 0;
    }
    else
    {
      *(_DWORD *)(v2 + 4) = BufferedDataStreamWrite;
    }
    *(_BYTE *)(v2 + 48) = 0;
    *(_DWORD *)(v2 + 52) = 0;
  }
  return result;
}

