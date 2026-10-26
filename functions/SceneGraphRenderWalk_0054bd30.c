int __thiscall sub_54BD30(_DWORD *this)
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
      *(_DWORD *)(*(_DWORD *)(dword_8B8F28 + 336) + 24 * *(_DWORD *)(dword_8B8F28 + 332) + 16) = this;
      result = dword_8B8F28;
      ++*(_DWORD *)(dword_8B8F28 + 332);
    }
LABEL_6:
    if ( this[17] )
      result = SceneGraphRenderWalk();
    this = (_DWORD *)this[19];
  }
  while ( this );
  return result;
}
