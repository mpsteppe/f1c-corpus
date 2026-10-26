int __thiscall sub_4EE120(_DWORD *this, int a2, int a3)
{
  int result; // eax
  int v4; // edx

  result = a3;
  if ( !a3 || !*(_DWORD *)(a3 + 14820) )
  {
    result = a2;
    if ( a2 < 93 )
    {
      v4 = this[a2];
      if ( v4 )
        return (*(int (**)(void))(*(_DWORD *)v4 + 8))();
    }
  }
  return result;
}
