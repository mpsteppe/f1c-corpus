// f1c  0x00587580  size=50
char __thiscall sub_587580(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  char result; // al

  if ( (int)this[1] > 0 )
  {
    *a2 = *this;
    result = 1;
    *a3 = this[2];
  }
  else
  {
    *a2 = 0;
    result = 0;
    *a3 = 0;
  }
  return result;
}
