int __thiscall WindowControlTypeDetection(_DWORD *this)
{
  char *v2; // eax
  char *v3; // eax
  char *v4; // eax

  v2 = (char *)this[46];
  if ( !v2 )
    v2 = byte_5EA438;
  if ( !sub_588410(v2, byte_5CC21C) )
    this[195] = 0;
  v3 = (char *)this[46];
  if ( !v3 )
    v3 = byte_5EA438;
  if ( !sub_588410(v3, aR) )
    this[195] = 1;
  v4 = (char *)this[46];
  if ( !v4 )
    v4 = byte_5EA438;
  if ( !sub_588410(v4, aC_0) )
    this[195] = 2;
  return 0;
}

