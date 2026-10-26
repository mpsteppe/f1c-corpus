int sub_5D8CE0()
{
  int result; // eax
  bool v1; // zf

  if ( dword_FB2758 )
  {
    result = dword_910EE8;
    switch ( dword_910EE8 )
    {
      case -128:
        if ( dword_FB2748 != -1 && dword_FB2748 != -2 )
        {
          v1 = dword_FB2748 == -3;
          goto LABEL_11;
        }
        break;
      case -64:
        if ( dword_FB2748 != -1 )
        {
          v1 = dword_FB2748 == -2;
          goto LABEL_11;
        }
        break;
      case -32:
        result = dword_FB2748;
        v1 = dword_FB2748 == -1;
LABEL_11:
        if ( !v1 )
          return result;
        return dword_FB2758();
      default:
        return result;
    }
    return dword_FB2758();
  }
  return result;
}
