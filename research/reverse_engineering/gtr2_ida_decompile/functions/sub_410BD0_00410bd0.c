int __thiscall sub_410BD0(_DWORD *this)
{
  int result; // eax

  result = this[2];
  if ( result )
    result = (*(int (**)(void))(*(_DWORD *)result + 16))();
  if ( dword_FB1D04 )
    return sub_5E5AE0();
  return result;
}
