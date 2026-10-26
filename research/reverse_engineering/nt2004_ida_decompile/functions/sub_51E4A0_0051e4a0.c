int __thiscall sub_51E4A0(int this, float a2)
{
  int result; // eax

  *(float *)(this + 18708) = a2;
  result = *(_DWORD *)(this + 16500);
  if ( !result )
    dbl_75EADC = a2;
  return result;
}
