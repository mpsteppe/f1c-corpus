int __usercall strncnt@<eax>(_BYTE *a1@<eax>, int a2)
{
  int v2; // ecx

  v2 = a2;
  if ( a2 )
  {
    while ( 1 )
    {
      --v2;
      if ( !*a1 )
        break;
      ++a1;
      if ( !v2 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    --v2;
  }
  return a2 - v2 - 1;
}
