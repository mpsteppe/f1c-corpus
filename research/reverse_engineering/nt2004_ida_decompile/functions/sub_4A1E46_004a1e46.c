// positive sp value has been detected, the output may be wrong!
char __usercall sub_4A1E46@<al>(_BYTE *a1@<esi>)
{
  bool v1; // zf
  char result; // al

  v1 = sub_4AD870() == (_DWORD)a1;
  result = a1[268];
  if ( v1 )
  {
    if ( !result )
      return sub_4A1BB0(a1, 1);
    result = a1[269];
    if ( !result )
      return sub_4A1BB0(a1, 1);
  }
  else if ( result )
  {
    result = a1[269];
    if ( result )
      return sub_4A1BB0(a1, 0);
  }
  return result;
}
