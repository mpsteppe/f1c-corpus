void *sub_4BC4F6()
{
  if ( (dword_B6D570 & 1) == 0 )
  {
    dword_B6D570 |= 1u;
    sub_484050();
    atexit(sub_6EF9F0);
  }
  return &unk_B6CF20;
}
