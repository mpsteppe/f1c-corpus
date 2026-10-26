int __thiscall sub_644070(FILE **this)
{
  int result; // eax

  result = (int)this[1];
  if ( result )
  {
    result = fclose(this[1]);
    this[1] = 0;
  }
  return result;
}
