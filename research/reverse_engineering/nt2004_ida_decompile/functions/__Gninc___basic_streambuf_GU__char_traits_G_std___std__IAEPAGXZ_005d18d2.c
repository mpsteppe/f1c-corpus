int __thiscall std::basic_streambuf<unsigned short>::_Gninc(int **this)
{
  int *v1; // ecx
  int result; // eax

  --*this[11];
  v1 = this[7];
  result = *v1;
  *v1 += 2;
  return result;
}
