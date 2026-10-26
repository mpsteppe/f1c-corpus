char __thiscall sub_4373B0(int this)
{
  char result; // al
  char *v3; // eax

  result = *(_BYTE *)(this + 1);
  if ( !result )
  {
    sub_501F60(-1, 0);
    v3 = (char *)sub_459B80(*(_DWORD *)(this + 8));
    result = sub_40C400((int ***)&dword_6291CC, v3);
    *(_BYTE *)(this + 1) = 1;
  }
  return result;
}
