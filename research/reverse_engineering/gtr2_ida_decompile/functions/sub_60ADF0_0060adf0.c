int __thiscall sub_60ADF0(_DWORD *this, int a2, int a3)
{
  int v3; // eax
  int result; // eax

  v3 = a3;
  if ( !a3 )
    v3 = this[6];
  result = sub_60AC50(this, v3);
  if ( result )
    *(_DWORD *)(result + 20) = a2;
  return result;
}
