int __thiscall sub_57BCE0(char *this)
{
  *(_DWORD *)this = &off_5B8A68;
  sub_57E530();
  NetworkCleanup_fbe0(this);
  if ( this[3060] && CloseHandle(*((HANDLE *)this + 763)) )
    *((_DWORD *)this + 763) = 0;
  LinkedBufferCleanup(this + 3020);
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
  LinkedListCleanup(this + 2844);
  if ( this[2840] && CloseHandle(*((HANDLE *)this + 708)) )
    *((_DWORD *)this + 708) = 0;
  LinkedListCleanup(this + 2816);
  if ( this[2812] && CloseHandle(*((HANDLE *)this + 701)) )
    *((_DWORD *)this + 701) = 0;
  LinkedListDestroyWithVtableDestructorCall(this + 2788);
  CloseHandleWrapper(this + 2760);
  LinkedListDestructionWithVTableReleaseCall(this + 2760);
  CloseHandleWrapper(this + 2732);
  LinkedListFreeStandard(this + 2732);
  FreeIfNonNull((LPVOID *)this + 670);
  *((_DWORD *)this + 592) = &off_5B8A00;
  return sub_583AE0(this);
}
