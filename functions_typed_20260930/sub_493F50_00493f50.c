char *__thiscall sub_493F50(char *this)
{
  char *result; // eax

  result = this;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  this[12] = 0;
  strcpy(this + 140, "Log\\osc.information");
  strcpy(result + 268, "Log\\osc.err");
  *((_DWORD *)result + 99) = 0;
  *((_DWORD *)result + 100) = 0;
  *((_DWORD *)result + 101) = 0;
  *((_DWORD *)result + 103) = 0;
  result[408] = 0;
  result[409] = 0;
  result[410] = 0;
  return result;
}

