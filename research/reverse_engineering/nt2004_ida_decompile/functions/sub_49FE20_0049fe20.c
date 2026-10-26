char __thiscall sub_49FE20(_DWORD *this, int a2, CHAR *a3)
{
  char result; // al
  int v4; // eax
  int i; // ecx
  CHAR *v6; // ecx

  result = 0;
  if ( a2 < this[37] && a2 >= 0 )
  {
    v4 = this[36];
    for ( i = 0; v4; ++i )
    {
      if ( i >= a2 )
        break;
      v4 = *(_DWORD *)(v4 + 140);
    }
    v6 = a3;
    if ( !a3 )
      v6 = &byte_629120;
    sub_578600(v6);
    return 1;
  }
  return result;
}
