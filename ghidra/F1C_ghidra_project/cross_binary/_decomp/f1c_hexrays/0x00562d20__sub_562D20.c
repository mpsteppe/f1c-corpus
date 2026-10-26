// f1c  0x00562d20  size=102
int __thiscall sub_562D20(_DWORD *this)
{
  int v2; // ebx
  int i; // edi
  int v4; // edx

  v2 = 0;
  if ( (int)this[27] > 0 )
  {
    for ( i = 0; ; i += 28 )
    {
      *(_DWORD *)(i + this[2]) = socket(2, 2, 17);
      v4 = this[2];
      if ( *(_DWORD *)(v4 + i) == -1 )
        break;
      *(_DWORD *)(v4 + i + 4) = 0;
      ++v2;
      *(_DWORD *)(this[2] + i + 8) = 0;
      if ( v2 >= this[27] )
        return 0;
    }
    if ( !v2 )
      return 1;
    this[27] = v2;
  }
  return 0;
}
