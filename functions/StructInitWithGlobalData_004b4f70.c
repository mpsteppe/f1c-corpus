int __thiscall StructInitWithGlobalData(char *this)
{
  int result; // eax

  ThunkWithStructInitSubCalls(this + 144);
  *this = 0;
  this[1] = 0;
  this[65] = 0;
  this[97] = 0;
  result = -190986834;
  *((_DWORD *)this + 33) = -190986834;
  *((_DWORD *)this + 34) = -190986834;
  *((_DWORD *)this + 35) = -190986834;
  return result;
}
