int __thiscall sub_56B8D0(char *this)
{
  *(_DWORD *)this = &off_5F62A0;
  sub_56E560();
  sub_56FC30(this);
  if ( this[3060] && CloseHandle(*((HANDLE *)this + 763)) )
    *((_DWORD *)this + 763) = 0;
  sub_572DB0(this + 3020);
  if ( this[3016] && CloseHandle(*((HANDLE *)this + 752)) )
    *((_DWORD *)this + 752) = 0;
  sub_572CD0(this + 2976);
  if ( this[2972] && CloseHandle(*((HANDLE *)this + 741)) )
    *((_DWORD *)this + 741) = 0;
  sub_5729A0(this + 2932);
  if ( this[2928] && CloseHandle(*((HANDLE *)this + 730)) )
    *((_DWORD *)this + 730) = 0;
  sub_572640(this + 2888);
  if ( this[2884] && CloseHandle(*((HANDLE *)this + 719)) )
    *((_DWORD *)this + 719) = 0;
  if ( this[2868] && CloseHandle(*((HANDLE *)this + 715)) )
    *((_DWORD *)this + 715) = 0;
  sub_571A90(this + 2844);
  if ( this[2840] && CloseHandle(*((HANDLE *)this + 708)) )
    *((_DWORD *)this + 708) = 0;
  sub_571A90(this + 2816);
  if ( this[2812] && CloseHandle(*((HANDLE *)this + 701)) )
    *((_DWORD *)this + 701) = 0;
  sub_5719D0(this + 2788);
  sub_576480(this + 2760);
  sub_5732D0(this + 2760);
  sub_576480(this + 2732);
  sub_573140(this + 2732);
  sub_4B0A60((LPVOID *)this + 670);
  *((_DWORD *)this + 592) = &off_5F6238;
  return sub_573B50(this);
}
