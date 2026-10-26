int *__thiscall sub_5489A0(_DWORD *this, int a2)
{
  int *v3; // eax
  int *result; // eax
  int v5; // edx
  int i; // ecx

  v3 = (int *)sub_587C03(24);
  if ( v3 )
    result = sub_53AB20(v3, 1024, a2);
  else
    result = 0;
  v5 = this[11];
  if ( v5 )
  {
    for ( i = *(_DWORD *)(v5 + 20); i; i = *(_DWORD *)(i + 20) )
      v5 = i;
    *(_DWORD *)(v5 + 20) = result;
    result[4] = v5;
  }
  else
  {
    this[11] = result;
    result[4] = 0;
  }
  return result;
}
