int __thiscall sub_416730(int *this)
{
  int result; // eax

  if ( *this >= 1023 )
    return this[217089];
  ++*this;
  result = this[217089];
  this[217089] = result + 848;
  return result;
}
