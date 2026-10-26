int __thiscall sub_559350(int this, const char *a2, int a3, int a4)
{
  int result; // eax

  strcpy((char *)this, a2);
  result = a3;
  *(_DWORD *)(this + 20) = a3;
  *(_DWORD *)(this + 24) = a4;
  *(_DWORD *)(this + 28) = 0;
  return result;
}

