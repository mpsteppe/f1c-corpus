int sub_4B44E0()
{
  int result; // eax
  _DWORD *v1; // esi
  _DWORD *v2; // ebp
  int i; // edi
  int v4; // esi

  dword_8AB6F0 = 0;
  dword_8AB6F4 = 0;
  dword_8AB6F8 = 0;
  dword_8AB6FC = 0;
  dword_8AB700 = 0;
  dword_8AB704 = 0;
  dword_8AB708 = 0;
  dword_8AB70C = 0;
  result = OperatorNewNhMallocWrapper(4);
  v1 = (_DWORD *)result;
  if ( result )
  {
    *(_DWORD *)result = OperatorNewNhMallocWrapper(13824);
    v2 = v1;
    result = OperatorNewNhMallocWrapper(12);
    if ( result )
    {
      *(_DWORD *)result = v1;
      *(_DWORD *)(result + 4) = 0;
      *(_BYTE *)(result + 8) = 1;
    }
    else
    {
      result = 0;
    }
    if ( dword_8AB6F0 )
    {
      *(_DWORD *)(dword_8AB6F4 + 4) = result;
    }
    else
    {
      dword_8AB6F0 = result;
      dword_8AB6F8 = result;
    }
    dword_8AB6F4 = result;
    ++dword_8AB6FC;
  }
  else
  {
    v2 = 0;
  }
  for ( i = 0; i < 13824; i += 432 )
  {
    v4 = i + *v2;
    if ( v4 )
    {
      result = OperatorNewNhMallocWrapper(12);
      if ( result )
      {
        *(_DWORD *)result = v4;
        *(_DWORD *)(result + 4) = 0;
        *(_BYTE *)(result + 8) = 0;
      }
      else
      {
        result = 0;
      }
      if ( dword_8AB700 )
      {
        *(_DWORD *)(result + 4) = dword_8AB700;
      }
      else
      {
        dword_8AB704 = result;
        dword_8AB708 = result;
      }
      dword_8AB700 = result;
      ++dword_8AB70C;
    }
  }
  return result;
}
