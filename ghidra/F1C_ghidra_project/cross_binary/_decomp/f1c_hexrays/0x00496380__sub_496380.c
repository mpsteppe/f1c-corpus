// f1c  0x00496380  size=52
int sub_496380()
{
  int result; // eax

  if ( !dword_7D0398 )
    return sub_4F9D60((int)aGametitleBmp, 0.0, 0);
  result = sub_4F9D60((int)aPmbeltiteMag, 0.0, 0);
  if ( (_BYTE)result != 1 )
    return sub_4F9D60((int)aGametitleBmp, 0.0, 0);
  return result;
}
