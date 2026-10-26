int __thiscall sub_54B2B0(_DWORD *this, int a2)
{
  int result; // eax

  result = this[1];
  if ( result )
    return (*(int (__stdcall **)(int))(*(_DWORD *)result + 8))(a2);
  return result;
}
