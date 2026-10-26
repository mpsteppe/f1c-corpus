int __thiscall sub_59E9C0(_DWORD *this)
{
  int result; // eax

  do
  {
    result = this[129];
    if ( result )
    {
      while ( (*(_DWORD *)(result + 20) & 0x80000) == 0 )
      {
        result = *(_DWORD *)(result + 16);
        if ( !result )
          goto LABEL_6;
      }
      *(_DWORD *)(*(_DWORD *)(dword_7E8E5C + 348) + 24 * *(_DWORD *)(dword_7E8E5C + 344) + 16) = this;
      result = dword_7E8E5C;
      ++*(_DWORD *)(dword_7E8E5C + 344);
    }
LABEL_6:
    if ( this[17] )
      result = sub_59E9C0();
    this = (_DWORD *)this[19];
  }
  while ( this );
  return result;
}
