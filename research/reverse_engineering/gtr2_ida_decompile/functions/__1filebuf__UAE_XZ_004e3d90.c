void __thiscall filebuf::~filebuf(filebuf *this)
{
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = -1;
  sub_615860(WindowName);
  *((_DWORD *)this + 2) = 0;
}
