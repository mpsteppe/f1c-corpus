int __thiscall sub_4379D0(void **this)
{
  void *i; // eax

  if ( this[3] )
  {
    sub_40C4A0((void ***)&dword_6291CC, this[3]);
    this[3] = 0;
  }
  for ( i = (void *)sub_40C480((int ***)&dword_6291CC, aGridwalkCam);
        i;
        i = (void *)sub_40C480((int ***)&dword_6291CC, aGridwalkCam) )
  {
    sub_40C4A0((void ***)&dword_6291CC, i);
  }
  return 0;
}
