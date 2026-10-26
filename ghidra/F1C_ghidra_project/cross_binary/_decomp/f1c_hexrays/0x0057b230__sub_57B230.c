// f1c  0x0057b230  size=96
int __thiscall sub_57B230(_DWORD *this, int a2)
{
  int result; // eax
  _DWORD *v3; // ecx
  _DWORD *v4; // eax

  result = 1;
  v3 = (_DWORD *)this[6];
  if ( !v3 )
    goto LABEL_7;
  while ( !*v3 || *(_DWORD *)*v3 != a2 )
  {
    v3 = (_DWORD *)v3[1];
    if ( !v3 )
      goto LABEL_7;
  }
  if ( !*v3 )
  {
LABEL_7:
    v4 = (_DWORD *)sub_587C03(4);
    if ( v4 )
    {
      *v4 = a2;
      sub_586000(v4, 1);
    }
    else
    {
      sub_586000(0, 1);
    }
    return 0;
  }
  return result;
}
