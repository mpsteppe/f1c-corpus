int __thiscall sub_5FB420(int *this, int a2, int ArgList, int a4, int a5, int a6, int a7, int a8)
{
  int v9; // ecx
  int v10; // eax
  _DWORD *v11; // eax

  v9 = a2;
  if ( a2 >= 0 && a2 < this[3] )
  {
    v10 = *this;
    if ( a2 <= 0 )
    {
LABEL_6:
      if ( v10 )
      {
        v11 = *(_DWORD **)v10;
        if ( v11 )
        {
          if ( !sub_5FB2B0(v11, ArgList, a4, a5, a6, a7, a8) )
          {
            dword_FB275C = sub_5F6B50(this, a2);
            return 0;
          }
        }
      }
    }
    else
    {
      while ( v10 )
      {
        v10 = *(_DWORD *)(v10 + 4);
        if ( --v9 <= 0 )
          goto LABEL_6;
      }
    }
  }
  sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error setting video mode %d x %d x %d", ArgList);
  return -1;
}
