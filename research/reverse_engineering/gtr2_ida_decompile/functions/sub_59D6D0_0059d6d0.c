int __thiscall sub_59D6D0(_DWORD *this, int a2)
{
  int **v2; // ecx
  int result; // eax
  _DWORD *v4; // eax

  v2 = (int **)this[6];
  result = 1;
  if ( !v2 )
    goto LABEL_7;
  while ( !*v2 || *v2 != &a2 )
  {
    v2 = (int **)v2[1];
    if ( !v2 )
      goto LABEL_7;
  }
  if ( !*v2 )
  {
LABEL_7:
    v4 = operator new(4u);
    if ( v4 )
    {
      *v4 = a2;
      sub_5FDFB0(v4, 1);
    }
    else
    {
      sub_5FDFB0(0, 1);
    }
    return 0;
  }
  return result;
}
