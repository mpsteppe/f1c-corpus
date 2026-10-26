// f1c  0x004f1890  size=33
int __thiscall sub_4F1890(int this, float a2)
{
  int result; // eax

  *(float *)(this + 14712) = a2;
  result = *(_DWORD *)(this + 12988);
  if ( !result )
    dbl_7C75C4 = a2;
  return result;
}
