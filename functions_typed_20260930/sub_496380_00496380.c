int sub_496380()
{
  int result; // eax

  if ( !dword_7D0398 )
    return ResourceFileLoader((int)aGametitleBmp, 0.0, 0);
  result = ResourceFileLoader((int)aPmbeltiteMag, 0.0, 0);
  if ( (_BYTE)result != 1 )
    return ResourceFileLoader((int)aGametitleBmp, 0.0, 0);
  return result;
}

