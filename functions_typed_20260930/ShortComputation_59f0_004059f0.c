int __thiscall sub_4059F0(_DWORD *this)
{
  int result; // eax

  result = this[22];
  if ( result )
  {
    result = *(_DWORD *)(result + 16);
    if ( result )
    {
      AIL_end_sample(result);
      result = AIL_init_sample(*(_DWORD *)(this[22] + 16));
    }
    *(_DWORD *)this[22] = 0;
    this[22] = 0;
  }
  return result;
}

