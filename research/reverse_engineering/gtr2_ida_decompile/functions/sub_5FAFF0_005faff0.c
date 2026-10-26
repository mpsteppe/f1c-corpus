int __thiscall sub_5FAFF0(_DWORD *this)
{
  int v1; // edx
  int result; // eax
  int v3; // ecx

  v1 = this[74];
  result = -1;
  if ( v1 )
  {
    v3 = this[72];
    for ( result = 0; v3; ++result )
    {
      if ( v3 == v1 )
        break;
      v3 = *(_DWORD *)(v3 + 4);
    }
  }
  return result;
}
