// f1c  0x004a27d0  size=39
int __thiscall sub_4A27D0(int this)
{
  int result; // eax

  result = this;
  if ( *(_DWORD *)(this + 100) )
    return sub_54B4D0(
             *(_DWORD *)(this + 76),
             *(_DWORD *)(this + 80),
             *(_DWORD *)(this + 84),
             *(float *)(this + 88),
             *(float *)(this + 92),
             *(float *)(this + 96));
  return result;
}
