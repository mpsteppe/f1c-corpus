int __thiscall sub_6BBA7B(_DWORD *this, _BYTE *a2, _DWORD *a3, char a4, int a5)
{
  int i; // eax
  int v8; // edx
  int *v9; // eax
  int v10; // esi
  int v11; // eax

  *a3 = 0;
  while ( 1 )
  {
    LOBYTE(i) = *a2;
    if ( !*a2 )
      return -2147467259;
    for ( i = (char)i; !isalnum(i); i = (char)*a2 )
      ++a2;
    if ( sub_635155((char)*a2) == a4 )
      break;
    while ( isalnum((char)*a2) )
      ++a2;
  }
  v8 = 0;
  if ( *a3 )
  {
    if ( !this[2] )
      goto LABEL_18;
    v9 = (int *)this[5];
    v10 = this[2];
    do
    {
      if ( *(_DWORD *)(*v9 + 4) == a5 )
        v8 = *v9;
      ++v9;
      --v10;
    }
    while ( v10 );
    if ( v8 )
      v11 = *(_DWORD *)(v8 + 96);
    else
LABEL_18:
      v11 = 0;
    sub_686791((int)this, v11, 4509, "cannot bind the same variable to multiple constants in the same constant bank");
    return -2147467259;
  }
  *a3 = a2;
  return 0;
}
