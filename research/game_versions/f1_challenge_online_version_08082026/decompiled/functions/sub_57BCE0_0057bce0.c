int __thiscall sub_57BCE0(char *this)
{
  *(_DWORD *)this = &off_5B8A68;
  sub_57E530();
  sub_57FBE0(this);
  if ( this[3060] && CloseHandle(*((HANDLE *)this + 763)) )
    *((_DWORD *)this + 763) = 0;
  sub_582DC0(this + 3020);
  if ( this[3016] && CloseHandle(*((HANDLE *)this + 752)) )
    *((_DWORD *)this + 752) = 0;
  sub_582CE0(this + 2976);
  if ( this[2972] && CloseHandle(*((HANDLE *)this + 741)) )
    *((_DWORD *)this + 741) = 0;
  sub_582A10(this + 2932);
  if ( this[2928] && CloseHandle(*((HANDLE *)this + 730)) )
    *((_DWORD *)this + 730) = 0;
  sub_582650(this + 2888);
  if ( this[2884] && CloseHandle(*((HANDLE *)this + 719)) )
    *((_DWORD *)this + 719) = 0;
  if ( this[2868] && CloseHandle(*((HANDLE *)this + 715)) )
    *((_DWORD *)this + 715) = 0;
  sub_581A80(this + 2844);
  if ( this[2840] && CloseHandle(*((HANDLE *)this + 708)) )
    *((_DWORD *)this + 708) = 0;
  sub_581A80(this + 2816);
  if ( this[2812] && CloseHandle(*((HANDLE *)this + 701)) )
    *((_DWORD *)this + 701) = 0;
  sub_5819C0(this + 2788);
  sub_582310(this + 2760);
  sub_581880(this + 2760);
  sub_582310(this + 2732);
  sub_5822B0(this + 2732);
  sub_499AE0((LPVOID *)this + 670);
  *((_DWORD *)this + 592) = &off_5B8A00;
  return sub_583AE0(this);
}
