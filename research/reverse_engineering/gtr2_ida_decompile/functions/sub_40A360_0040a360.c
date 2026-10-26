int __thiscall sub_40A360(_DWORD *this)
{
  int result; // eax

  result = this[22];
  if ( result )
  {
    result = *(_DWORD *)(result + 16);
    if ( result )
      return AIL_resume_sample(result);
  }
  return result;
}
