int __thiscall sub_5E8870(_DWORD *this, int a2, int a3)
{
  int v3; // eax
  int result; // eax

  v3 = a3;
  if ( !a3 )
    v3 = this[63];
  result = v3 - 1;
  if ( !result )
  {
    this[132] = a2;
    goto LABEL_8;
  }
  if ( !--result )
  {
LABEL_8:
    this[199] = a2;
    goto LABEL_9;
  }
  if ( !--result )
LABEL_9:
    this[266] = a2;
  return result;
}
