// f1c  0x004060c0  size=63
int __thiscall sub_4060C0(_DWORD *this)
{
  int result; // eax
  unsigned int v3; // ecx
  char *v4; // eax

  result = this[22];
  if ( result )
  {
    result = *(_DWORD *)(result + 16);
    if ( result )
    {
      result = AIL_set_sample_processor(result, 1, this[25]);
      v3 = this[24];
      if ( v3 != -1 )
      {
        v4 = sub_404FC0(v3);
        return AIL_set_filter_sample_preference(*(_DWORD *)(this[22] + 16), v4, this + 26);
      }
    }
  }
  return result;
}
